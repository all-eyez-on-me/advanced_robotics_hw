%L = Link([Th d a  alph])
clearvars;
link(1) = Link([0, 0, 0, -pi/2, 0]);
link(2) = Link([0, 0, 1, 0, 0]);
link(3) = Link([0, 0, 1, 0, 0]);
robot_2 = SerialLink(link,'name','three_Joint_Manipulator')
robot_2.plot([pi/2, 0, 0],'jointdiam',1,'base','wrist','arrow')

for i= 0:0.1:pi/2
    q2 = i
    q3 = pi-q2-acos(cos(q2))
    q_conf_n = [-pi/4, q2, q3];
    robot_2.plot(q_conf_n);
    robot_2.vellipse(q_conf_n,'alpha',0.5,'edgecolor', 'r', 'fillcolor', 'b');
    robot_2.fellipse(q_conf_n,'alpha',0.5,'edgecolor', 'r', 'fillcolor', 'b');
    %pause(0.1)
end
    
