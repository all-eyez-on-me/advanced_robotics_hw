tstart = 0;
tend = 5;
delta = 0.01;
tspan = tstart:delta:tend;
%define the initial conditions making sure to use the right ordering
xinit = [0;0];

[t,x] = ode45(@t_system, tspan, xinit);

theta = x(:,1)


plot(tspan,theta);
hold on
title('Step response of system of question4 with step disturbance using nonlinear controller to achieve critically damping');
xlabel('time');
ylabel('theta');
plot([tstart tend],[1.005, 1.005], '--k')
yticks([0 1.005])
hold off
% system performance
function dxdt = t_system(t,x)
    dxdt = zeros(size(x));
    tau =c_d_controller(x);
    dxdt(1) = x(2);
    dxdt(2) = (tau-5-5*x(1)*x(2)+13*x(2)^3)/2;
end

% critical controller 
function tau = c_d_controller(x)
    alpha =2;
    kv = 2*sqrt(10);
    kp = 10;
    xd(1)=1;
    xd(2)=0;
    xd(3)=0;
    tau_dist = 0.1;
    beta = 5*x(1)*x(2)-13*x(2)^3+5;
    
    tau_design = xd(3)+kv*(xd(2)-x(2))+kp*(xd(1)-x(1));
    tau = tau_design*alpha + beta+tau_dist;
end