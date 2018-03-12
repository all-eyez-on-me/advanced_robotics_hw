qi = 15; 
qf = 75;
tf = 3;
k = 1.2
delta = 0.05;
qc_dot = k*(qf-qi)/tf
tc = (qi-qf+qc_dot*tf)/qc_dot
a_c = qc_dot^2/(qi-qf+qc_dot*tf)

line = []
for i = 0:delta:tf
    [a,b,c] = parabolic_bend_motion(qi,qf,tf,tc,a_c,i);
    line = [line,a];
end
figure(1)
subplot(2,1,1);
x = 0:delta:tf
plot(x,line)
subplot(2,1,2);
[p,v,a]= parabolic_bend_line(qi,qf,tf,k);
plot(x,p)
