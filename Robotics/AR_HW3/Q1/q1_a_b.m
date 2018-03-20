syms a0 a1 a2 a3 a4 a5 t real

duration=[3,1];
q0 = [15,10];
q1 = [75,100];
q0_dot = [0,0];
q1_dot = [0,0];

postion_limit = [0 100];
velocity_limit = [0 3];
acceleration_limit = [-10,10]

title1_cell = {'Position of Single Cubic Polynomial from 15-75 degree within 3 seconds','Position of Single Cubic Polynomial from 10-100 degree within 1 seconds'};
title2_cell = {'Velocity of Single Cubic Polynomial from 15-75 degree within 3 seconds','Velocity of Single Cubic Polynomial from 10-100 degree within 1 seconds'};
title3_cell = {'Acceleration of Single Cubic Polynomial from 15-75 degree within 3 seconds','Acceleration of Single Cubic Polynomial from 10-100 degree within 1 seconds'};


q_t = a3*t^3+a2*t^2+a1*t^1+a0;
q_dot_t = diff(q_t,t);
q_dot_dot_t = diff(q_dot_t,t);

hold on;
for s=1:1:2
    equation_1 = subs(q_t,t,0)== q0(s);
    equation_2 = subs(q_t,t,duration(s))==q1(s);
    equation_3 = subs(q_dot_t,t,0)== q0_dot(s);
    equation_4 = subs(q_dot_t,t,duration(s))== q1_dot(s);
    [A,B] = equationsToMatrix([equation_1,equation_2,equation_3,equation_4],[a0,a1,a2,a3])
    X = linsolve(A,B)

    delta = 0.1;

    figure(1);
    q_var = symvar(q_t);
    q_dot_var = symvar(q_dot_t);
    q_dot_dot_var = symvar(q_dot_dot_t);

    q_t_plot = subs(q_t,q_var(1:end-1),X.')
    q_t_dot_plot = subs(q_dot_t, q_dot_var(1:end-1), X(2:end).')
    q_t_dot_dot_plot = subs(q_dot_dot_t,q_dot_dot_var(1:end-1),X(3:end).')
    i = 0:delta:duration(s);
    q_t_plot = subs(q_t_plot,t,i);
    q_t_dot_plot = subs(q_t_dot_plot,t,i)*pi/180;
    q_t_dot_dot_plot = subs(q_t_dot_dot_plot,t,i)*pi/180;
    subplot(3,2,s+0);
    p1 = plot(i,q_t_plot);
    set(p1,'Color','black'); 
    set(p1,'LineStyle','--');
    if exist('position_limit')
        ylim(postion_limit)
    end
    ylabel('Angle [Deg]');
    title(title1_cell(s));

    subplot(3,2,s+length(q0));
    p2 = plot(i,q_t_dot_plot);
    ylabel('Velocity [rad/sec]');
    if exist('velocity_limit')
        ylim(velocity_limit)
    end
    title(title2_cell(s));
    subplot(3,2,s+length(q0)*2);
    p3 = plot(i,q_t_dot_dot_plot);
    ylabel('Acceleration [rad/sec^2]');
    if exist('acceleration_limit')
        ylim(acceleration_limit)
    end
    title(title3_cell(s));
    xlabel('time');
end
