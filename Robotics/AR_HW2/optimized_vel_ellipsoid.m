%symbolic analysis of robot link
syms pi real
link(1) = Link([0, 0, 0, -pi/2, 0]);
link(2) = Link([0, 0, 1, 0, 0]);
link(3) = Link([0, 0, 1, 0, 0]);
robot_sym = SerialLink(link,'name','three_Joint_Manipulator')
%General Jacobian matrix
syms q1 q2 q3 real
q1 = -pi/4
q3 =  pi-2*q2
Jac = simplify(robot_sym.jacob0([q1,q2,q3]))
J = Jac(1,1:3)
J = [J; Jac(3,1:3)]
v_ellipse = J*J.'

d = det(v_ellipse)
d_dot = diff(d)
solve(d_dot==0,q2)
i = 0:0.05: pi/2
 d_n = subs(d,q2, i)
 plot(i, d_n)

