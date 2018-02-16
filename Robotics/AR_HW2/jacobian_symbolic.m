%symbolic analysis of robot link
syms pi real
link(1) = Link([0, 0, 0, -pi/2, 0]);
link(2) = Link([0, 0, 1, 0, 0]);
link(3) = Link([0, 0, 1, 0, 0]);
robot_sym = SerialLink(link,'name','three_Joint_Manipulator')
%General Jacobian matrix
syms q1 q2 q3 real
robot_sym.jacob0([q1,q2,q3])

%Configuration 1
q_conf = [-pi/4, 0, pi/4];
q_dot_conf = [pi pi/2 0];
f_conf = [4 1 3 0 0 0]
J = simplify(robot_sym.jacob0(q_conf))
x_dot = simplify(J*q_dot_conf.')
rank(J)
fprintf('the rank of Jacobian is %d\n', rank(J))
fprintf('the applied tau is')
tau = J.'*f_conf.'
%pi = 3.14
%robot_sym.plot([-pi/4+pi/2, 0, pi/4])
% 
% %%
%Configuration 2
q_conf = [-pi/4, pi/4, 0];
q_dot_conf = [pi pi/2 0];
f_conf = [4 1 3 0 0 0]
J = simplify(robot_sym.jacob0(q_conf))
x_dot = simplify(J*q_dot_conf.')
rank(J)
fprintf('the rank of Jacobian is %d\n', rank(J))
fprintf('the applied tau is')
tau = J.'*f_conf.'
%pi = 3.14
%robot_sym.plot([-pi/4+pi/2, 0, pi/4])

