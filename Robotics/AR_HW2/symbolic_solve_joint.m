%L = Link([Th d a  alph])
link(1) = Link([0, 0, 0, -pi/2, 0]);
link(2) = Link([0, 0, 1, 0, 0]);
link(3) = Link([0, 0, 1, 0, 0]);
robot_sym = SerialLink(link,'name','three_Joint_Manipulator')


%%
%Simulation of Configuration
syms q2 q3 real
syms pi real
q_conf = [-pi/4, q2, q3]
f_kine = robot_sym.fkine(q_conf)
eq_q2_q3 = f_kine.t(2)
q3_e = solve(eq_q2_q3, q3)