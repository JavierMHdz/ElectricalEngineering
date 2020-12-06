function y = filltank(t)
stepsize=input ('the value is: 100,10,.1');

A=1250; %units (m^2)
Q=450; %units (m^3/h)
y_out=10; %units (m) f
n=100/stepsize;
disp(num2str(n));
y=0;
for i=1:stepsize:100;
    t=1:stepsize:100;
    if y>y_out
        y=y+(3*Q.*sin(t).^2-3*(y-y_out)^1.5)*stepsize/A;
    else
        y=y+3*Q.*sin(t).^2*stepsize/A;
        
    end
end

end