td_ij= [2,1,2];
q = [ 0,2*pi,pi/2,pi ]
ac_abs = [15,40,30,5]
delta = 0.001;
t_abs = [0];
t_sum = [0]
k = 1.6
len = length(q);

delta_element = 100;

i = 1
if i == 1
    ac(i) = sign(q(i+1)-q(i))*ac_abs(i);
    t_i(i) = td_ij(i) - sqrt(td_ij(i)^2-2*(q(i+1)-q(i))/ac(i))
    vel_ij(i) = (q(i+1)-q(i))/(td_ij(i) - t_i(i)/2);
    t_i(i+1) = abs((q(i+1)-q(i))/ac(i));
end
i = len
if i == len
    ac(i) = sign(q(i-1)-q(i))*ac_abs(i);
    t_i(i) = td_ij(i-1) - sqrt(td_ij(i-1)^2+2*(q(i)-q(i-1))/ac(i));
    vel_ij(i-1) = (q(i)-q(i-1))/(td_ij(i-1) - t_i(i)/2);
end 

for i=2:len-1
    vel_ij(i) = (q(i+1)-q(i))/td_ij(i);
    ac(i)=sign(vel_ij(i)-vel_ij(i-1))*ac_abs(i);
    t_i(i) = (vel_ij(i)-vel_ij(i-1))/ac(i);

end
for i=1:len-1
    if i==1
        t_ij(i) = td_ij(i)-t_i(i)-t_i(i+1)/2;
    elseif i==len-1
        t_ij(i) = td_ij(i)-t_i(i)/2-t_i(i+1);
    else
        t_ij(i) = td_ij(i)-t_i(i)/2-t_i(i+1)/2;
    end
end


pos=[0];
vel=[0];
acel=[0];
for k = 1:len
   if k==1
       for t=linspace(delta,t_i(1),delta_element)
           pos = [pos, (ac(1)*t^2)/2];   
           vel = [vel, ac(1)*t];
           acel = [acel, ac(1)];
           t_abs = [t_abs, t];
       end
       s_point = pos(end);
       v_point = vel(end);
       t_point = t_abs(end);
       for t=linspace(delta,t_ij(1),delta_element)
           pos = [pos, s_point+t*vel_ij(1)];
           vel = [vel, v_point];
           acel = [acel, 0];
           t_abs = [t_abs, t+t_point];
       end
   elseif k==len
         s_point = pos(end);
         v_point = vel(end);
         t_point = t_abs(end);
         for  t=linspace(delta,t_i(k),delta_element)
             pos_ = vel_ij(k-1)*t+ac(k)*t^2/2;
             pos = [pos, pos_+s_point]; 
             vel = [vel, v_point+ac(k)*t];
             acel = [acel, ac(k)];
             t_abs = [t_abs, t+t_point];
         end
   else
       s_point = pos(end);
       v_point = vel(end);
       t_point = t_abs(end);
       for t=linspace(delta,t_i(k),delta_element)
           pos_ = vel_ij(k-1)*t+ac(k)*t^2/2;
           pos = [pos, pos_+s_point];
           vel = [vel, v_point+ac(k)*t];
           acel = [acel, ac(k)];
           t_abs = [t_abs, t+t_point];
       end
       s_point = pos(end);
       v_point = vel(end);
       t_point = t_abs(end);
       for t=linspace(delta,t_ij(k),delta_element)
           pos_ = vel_ij(k)*t
           pos = [pos, pos_+s_point];
           vel = [vel, v_point];
           acel = [acel, 0];
           t_abs = [t_abs, t+t_point];
       end       
   end
end
figure(1)
subplot(3,1,1)

p1 = plot(t_abs,pos);
title('Position of trajectory using linear function of parabolic bend');
xlabel('time (s)');
ylabel('Position (rad)');

subplot(3,1,2)
p2 =plot(t_abs,vel);
title('Velocity of trajectory using linear function of parabolic bend');
xlabel('time (s)');
ylabel('Velocity (rad/s)');

subplot(3,1,3);
p3 = plot(t_abs,acel);
title('Acceleraton of trajectory using linear function of parabolic bend');
xlabel('time (s)');
ylabel('Acceleration (rad/s^2)');






