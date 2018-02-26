clc
syms q1 q2 q3 pi
link(1) = Link([0 0 1 0 0]);
link(2) = Link([0 0 1 0 0]);
link(3) = Link([0 0 1 0 0]);
rob = SerialLink(link);

%Secondary objective function of the joint variables
q1_min = -2*pi;
q1_max = 2*pi;
q2_min = 0;
q2_max = pi;
q3_min = -3*pi/2 ;
q3_max = -pi/2;
%Secondary objective function of the joint variables
w = -(1/6)*(((q1-0)/(q1_max-q1_min))^2+((q2-0)/(q2_max-q2_min))^2+((q3+pi)/(q3_max-q3_min)^2));
q_0_dot = simplify([diff(w,q1);diff(w,q2);diff(w,q3)]);

figure; 
q = [-pi/2;pi/4;pi/4];
x_end = [];
xd_all = [];
NORM = [];
Q1 = [];Q2 = [];Q3 = [];
% simulation closed-loop
for t = 0 : 0.01 : 5
    delta_t = 0.001;
    K = diag([500,500]);
    xd = [0.25*(1-cos(pi*t)); 0.25*(1-sin(pi*t))];
    xd_dot = [0.25*pi*sin(pi*t); -0.25*pi*cos(pi*t)];
    flag = 0;
    while flag == 0
        
        q1 = q(1); q2 = q(2); q3 = q(3);
        q0_dot = eval(q_0_dot);
%       forward kinematics
        T0_1 = rob.A(1:1,q);
        T1_2 = rob.A(2:2,q);
        T2_3 = rob.A(3:3,q);
        T_01 = T0_1;
        T_02 = T0_1 * T1_2;
        T_03 = T_02 * T2_3;
        P0 = [0,0];
        P1 = [T_01.t(1),T_01.t(2)];
        P2 = [T_02.t(1),T_02.t(2)];
        P3 = [T_03.t(1),T_03.t(2)];
        
        % Jacobian 
        J = rob.jacob0(q);
        J = J(1:2,1:3);
        
        % Closed-loop Algrithom
        xe = P3.';
        err = xd - xe;
        norm = sqrt(err(1)^2 + err(2)^2);
        NORM = [NORM, norm];
        J_w = pseudo_inverse_w(J);
        q_dot = J_w * (xd_dot + K * err)+250*(eye(3)-J_w*J)*q0_dot;
        q = q + q_dot * delta_t;
        
        % Set the smallest errors
        if err(1) <= 0.01 && err(2) <= 0.01
            
            flag = 1;
            x_end = [x_end , P3.'];
            xd_all = [xd_all, xd];
            Joint_x = [P0(1,1),P1(1,1),P2(1,1),P3(1,1)];
            Joint_y = [P0(1,2),P1(1,2),P2(1,2),P3(1,2)];
            Q1 = [Q1, q1];Q2 = [Q2, q2];Q3 = [Q3, q3];
            plot(Joint_x,Joint_y,'-o',x_end(1,:),x_end(2,:),'r',xd_all(1,:),xd_all(2,:),'g')
            axis([-1.5 1.5 -1.5 1.5]);
            % plot(NORM ,'-b');
            % plot(Q,'-b');
            pause(0.001);        
        end        
        
    end    
        
end
figure(2);
plot(T,Q1);
hold on;
plot(T,Q2);
hold on;
plot(T,Q3);
hold on;
function J_pinv = pseudo_inverse_w(J)
W = [1 0 0; 0 1 0; 0 0 1];
A = J * inv(W) * J.';
[U,S,V] = svd(A);
J_pse = V * pinv(S) * U.';
J_pinv = inv(W)*J.'*J_pse;
end
