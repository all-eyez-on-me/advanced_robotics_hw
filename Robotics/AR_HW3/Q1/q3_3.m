T = 3;
M = 4*[1,1.25,1.5,1.75];
J = 1;

r_norm = zeros(length(M),1)
a_norm = zeros(length(M),1)
delta = 0.02

line_legend = ['1','2','3','4'];
line_style = {'-x','-o','--','-.'}


r_opt = sqrt(J/M(1))

for t = delta:delta:5
    r_ = t*r_opt;
    a_tmp =zeros(1,4);
    r_tmp =zeros(1,4);
    for j = 1:length(M)
        a_norm_ = (T/(J/r_+r_*M(j)));
        a_tmp(j) = a_norm_;
        r_tmp(j) = t;
    end
    r_norm = [r_norm, r_tmp.'];
    a_norm = [a_norm, a_tmp.'];
end

[n_max,i_max] = max(a_norm(1,:));
for  j = 1:length(M)    
    [n__,i_max] = max(a_norm(j,:));
    a_norm(j,:) = a_norm(j,:)/n_max;
    x_max(j) = (i_max-1)*delta;   
    y_max(j) = n__/n_max;
end
for j = 1:length(M)
    plot(r_norm(j,:),a_norm(j,:),line_style{j})
    hold on
end
legend('k=1','k=1.25','k=1.5','k=1.75');

for j = 1:length(M)
    plot([x_max(j) x_max(j)],[0 y_max(j)],'--k');
end

title('Plot of normalized transmission ratio r* against normalized acceleration a* with different k, M_{new}=k*M');
% x_ticks = sort([x_max(2:end),0:0.5:5]);
% xticks(x_ticks);
ylim([0,1.2]);
xlabel('r *');
ylabel('a *');