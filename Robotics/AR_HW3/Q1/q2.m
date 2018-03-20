duration= [2,1,2];
q = [ 0,2*pi,pi/2,pi ]
pos = [0];
vel = [0];
acel = [0];
delta = 0.05;
t = [0];
k = 1.6
for i=1:length(q)-1
    if i==1
        [pos_,vel_,acel_] = parabolic_bend_line(q(i), q(i+1), duration(i), k, delta);
        pos = [pos, pos_];
        vel = [vel, vel_];
        acel = [acel, acel_];
    else
        k_next = -k*(q(i+1)-q(i))/(q(i)-q(i-1))*duration(i)/duration(i-1);
        [pos_,vel_,acel_] = parabolic_bend_line(q(i), q(i+1), duration(i), k_next, delta);
        pos = [pos, pos_(2:end)];
        vel = [vel, vel_(2:end)];
        acel = [acel, acel_(2:end)];        
    end
end
for i=1:length(pos)-1
    t=[t,t(end)+delta];
end
figure(1)
subplot(3,1,1);
plot(t, pos);
subplot(3,1,2);
plot(t, vel);
subplot(3,1,3);
plot(t, acel);