%create x variable
%x= 0:0.1:2*pi; %semicolon = does not show the output

%compute y1 and y2
%y1 = sin(x);
%y2 = cos(x);

%plot the results
%plot(x,y1)
%hold on %plot on the same graph
%plot(x,y2, 'xk')
%grid
%xlabel('x')
%ylabel('y1 and y2')
%axis([0 2*pi -1.25 1.25]) %change the x and y axis
%legend('y1','y2')

%///////////////////////////////////////////////////////////////////%
%create the x variable
%x = -10:.1:10;

%compute the results
%y1 = sin(x)./(1+x.^2); %syntax problems with the dots, keep it in mind
%y2 = cos(x)./(1+x.^2);

%plot the results
%plot(x,y1)
%hold on
%plot(x,y2,'-xk')

%///////////////////////////////////////////////////////////////////%
%exp(x) is used for exponenial functions

x = 0:.1:10;

y1 = exp(-x).*sin(x);
y2 = exp(-x).*cos(x);

plot(x,y1);
hold on
plot(x,y2,'-xk');
grid
