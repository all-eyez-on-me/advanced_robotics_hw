function dxdt = q4_system(t,x)
    dxdt = zeros(size(x));
    tau =1;
    dxdt(1) = x(2);
    dxdt(2) = (tau-5-5*x(1)*x(2)+13*x(2)^3)/2;
end