clc
clear

% rosinit()
% rostopic list
index = 1;
flag =1;

while(flag)

sub_pos = rossubscriber('/dvrk/MTMR/state_joint_desired');
msg = receive(sub_pos);

position(:,index) = msg.Position;
effort(:,index) = msg.Effort;

index = index + 1;
pause(1)

disp(index);
end

