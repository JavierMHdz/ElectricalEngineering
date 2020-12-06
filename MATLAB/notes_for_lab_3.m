v(1,i+1)-v(1,1)/dt = v(2,1)
v(1,i+1)=v(2,1)*dt*alpha+v(1,1) %x component
v(2,i+1)=v(2,1)+dt*epsilon-dt*alpha*v(1,1) %y component
x(1,i+1)=x(1,1)+dt*v(1,1)
x(2,i+1)=x(2,1)+dt*v(2,1)