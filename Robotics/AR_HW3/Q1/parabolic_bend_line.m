function [position,velocity,acceleration] = parabolic_bend_position(qi,qf,tf,k,delta)

if nargin==4
    delta=0.05;
end

qc_dot = k*(qf-qi)/tf;
tc = (qi-qf+qc_dot*tf)/qc_dot;
a_c = qc_dot^2/(qi-qf+qc_dot*tf);
for i = 0:delta:tf
    if(i == 0)
        position = [qi];
        velocity = [0];
        acceleration = [a_c];
    else
        [x,y,z] = parabolic_bend_motion(qi,qf,tf,tc,a_c,i);
        position = [position,x];
        velocity = [velocity,y];
        acceleration = [acceleration,z];
    end
end
