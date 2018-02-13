L = 1;
%L = Link([Th d a  alph])
link(1) = Link([0 -L 0 -(pi)/2 0]);
link(2) = Link([-(pi)/2 L 0 -(pi)/2 0]);
link(3) = Link([(pi)/2 0 L 0 1]);
link(4) = Link([0 L L (pi)/2 0]);
link(5) = Link([0 0  L -(pi)/2 0]);
link(6) = Link([0 0 0 0 0]);
 
link(3).qlim = [0 2*L]
robot = SerialLink(link, 'name', 'my_robot')
robot.base = transl(L,0,-L)
robot.tool = transl(L, 0 ,-L)*trotx(pi)
% %plot the simulation of 3D joint
% for i = 0: 0.1: 6*pi
%     robot.plot([0 pi*sin(i)/6-pi/2 L+L*sin(i) 0 0 0],'jointdiam',1,'base','wrist','arrow','workspace', [-100 100 -100 100 -100 100]);
%     hold on;
%     pause(0.02);
% end
 
 
%plot the simulation of joint variable
%plot the trajectory of movement of joint 3
figure(1)
subplot(3,1,1)
t = 0: 0.2: 2*pi
th1 = 0*t;
th2 = pi*sin(t)/6;
th3 = 0*t;
th4 = 0*t;
th5 = 0*t;
th6 = 0*t;
plot(t,th1); hold on;
plot(t,th2,'-+'); hold on;
plot(t,th3,'-o'); hold on;
plot(t,th4); hold on;
plot(t,th5); hold on;
plot(t,th6);
legend('q1','q2','q3','q4','q5','q6')
title('Joint Trajectory with movement of joint 2')
 
subplot(3,1,2)
x=[];y=[];z=[]; rpy_r=[]; rpy_p=[]; rpy_y=[]; 
for i = t
    q = [0 pi*sin(i)/6-pi/2 L 0 0 0] 
    T = robot.fkine(q)
    T_t = T.t
    x = [x, T_t(1)]
    y = [y, T_t(2)]
    z = [z, T_t(3)]
    rpy = tr2rpy(T)
    rpy_r = [rpy_r,rpy(1)];rpy_p = [rpy_p,rpy(2)];rpy_y = [rpy_y,rpy(3)];
end
plot(t,x,'-o'); hold on;
plot(t,y,'-+'); hold on;
plot(t,z,'-.'); hold on;
legend('x','y','z')
 
subplot(3,1,3)
plot(t,rpy_r,'-o'); hold on;
plot(t,rpy_p,'-+'); hold on;
plot(t,rpy_y,'-.'); hold on;
legend('raw','pitch','yaw')
 
 
%plot the trajectory of movement of joint 3
figure(2)
subplot(3,1,1)
t = 0: 0.2: 2*pi
th1 = 0*t;
th2 = 0*t;
th3 = 0.1*sin(t);
th4 = 0*t;
th5 = 0*t;
th6 = 0*t;
plot(t,th1); hold on;
plot(t,th2,'-o'); hold on;
plot(t,th3,'-+'); hold on;
plot(t,th4); hold on;
plot(t,th5); hold on;
plot(t,th6);
legend('q1','q2','q3','q4','q5','q6')
title('Joint Trajectory with movement of joint 3')
 
subplot(3,1,2)
x=[];y=[];z=[]; rpy_r=[]; rpy_p=[]; rpy_y=[]; 
for i = t
    q = [0 -pi/2 L+1*sin(i) 0 0 0] 
    T = robot.fkine(q)
    T_t = T.t
    x = [x, T_t(1)]
    y = [y, T_t(2)]
    z = [z, T_t(3)]
    rpy = tr2rpy(T)
    rpy_r = [rpy_r,rpy(1)];rpy_p = [rpy_p,rpy(2)];rpy_y = [rpy_y,rpy(3)];
end
plot(t,x,'-o'); hold on;
plot(t,y,'-+'); hold on;
plot(t,z,'-.'); hold on;
legend('x','y','z')
 
subplot(3,1,3)
plot(t,rpy_r,'-o'); hold on;
plot(t,rpy_p,'-+'); hold on;
plot(t,rpy_y,'-.'); hold on;
legend('raw','pitch','yaw')




