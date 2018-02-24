close all
clear all
% Set the lengths of each link
l1 = 1;
l2 = 1;
l3 = 1;
% Set arm position
theta1 = 15*pi/180;
theta2 = 100*pi/180;
theta3 = -150*pi/180;
theta = [theta1;theta2;theta3];
% Define the Jacobian matrix
J(1,1) = -l1*sin(theta(1))-l2*sin(theta(1)+theta(2))-l3*sin(theta(1)+theta(2)+theta(3));
J(1,2) = J(1,1) + l1*sin(theta(1));
J(1,3) = J(1,2) + l2*sin(theta(1)+theta(2));
J(2,1)=l1*cos(theta(1))+ l2*cos(theta(1)+theta(2))+l3*cos(theta(1)+theta(2)+theta(3));
J(2,2) = J(2,1) - l1*cos(theta(1));
J(2,3) = J(2,2) - l2*cos(theta(1) +theta(2));
% Perform singular value decomposition
[U,S,V] = svd(J);
% Create the ellipse
sc = 0.3;
a = sc*(S(1,1));
b = sc*(S(2,2));
t = 0:0.01:2*pi;
x = a*cos(t);
y = b*sin(t);
%
A= U*[x;y];
x= A(1,:);
y= A(2,:);

x = x + l1*cos(theta(1)) + l2*cos(theta(1)+theta(2)) + l3*cos(theta(1)+theta(2)+theta(3));
y = y + l1*sin(theta(1)) + l2*sin(theta(1)+theta(2)) + l3*sin(theta(1)+theta(2)+theta(3));
figure
hold on
plot_arm(l1,l2,l3,theta,'-o')
plot(x,y,':')
% Format plot
xlabel('x')
ylabel('y')
axis equal
axis([0 (l1+l2+l3) 0 (l1+l2+l3)])