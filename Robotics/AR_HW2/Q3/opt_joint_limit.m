clear; clc;
q_lim_max =  sym('q_lim_max',[3,1]);
q_lim_min =  sym('q_lim_min',[3,1]);
q =  sym('q',[3,1]);
w = 0;
for i=1:1:length(q_lim_min)
    mean = (q_lim_max(i) + q_lim_min(i))/2;
    dist = (q_lim_max(i) - q_lim_min(i))^2;
    w = w + (q(i)-mean)^2/dist;
end
w = simplify(-w/(2*length(q)));
for i=1:1:length(q_lim_min)
    q_dot(i,:) = diff(w,q(i));
end  
simplify(q_dot)

