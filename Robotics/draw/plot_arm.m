function plot_arm(l1,l2,l3,theta,marker)
x1 = l1*cos(theta(1));
y1 = l1*sin(theta(1));
x2 = x1+l2*cos(theta(1)+theta(2));
y2 = y1+l2*sin(theta(1)+theta(2))
x3 = x2+l3*cos(theta(1)+theta(2)+theta(3));
y3 = y2+l3*sin(theta(1)+theta(2)+theta(3));
quiver(0,0,l1*cos(theta(1)),l1*sin(theta(1)),1,marker)
quiver(x1,y1,l2*cos(theta(1)+theta(2)),l2*sin(theta(1)+theta(2)),1,marker)
quiver(x2,y2,l3*cos(theta(1)+theta(2)+theta(3)),l3*sin(theta(1)+theta(2)+theta(3)),1,marker)
plot(x3,y3,marker)