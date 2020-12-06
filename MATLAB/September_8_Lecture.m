% Square root of 2 with Newton's method;
% see Section 2.6.1 in the text.
%
% The next statement nodifies print to screen;
% it suppresses blank lines between output lines. 
format long
a = 2;
x = a/2;
% Newton's method to compute sqrt(2) 
disp(' Newton''s iteration for sqrt(2) ')
for i = 1:6
x = (x + a / x) / 2;
disp( x )
end
%
disp( 'Matlab''s value: ' )
disp( sqrt(2) )
% The following recovers the default format