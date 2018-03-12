function [pos,  vel, acel] = parabolic_bend_motion(qi,qf,t_f,tc,ac,t)

    if 0<=t && t<=tc
        pos = qi+ac*(t^2)/2;
        vel = ac*t;
        acel = ac;
    elseif tc<t && t<=(t_f-tc)
        pos = qi+ac*tc*(t-tc/2);
        vel = ac*tc;
        acel = 0;
    elseif (t_f-tc)<t && t<=t_f
        pos = qf - ac*(t_f-t)^2/2;
        vel = ac*tc-(t-t_f+tc)*ac;
        acel = -ac;
    else
        pos=0;
        vel=0;
        acel=0;
    end
end