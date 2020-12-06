function avgflips=ee150_broke(initP1,initP2,initP3,p,n) 
%initP1, initP2, initP3 are initial number of coins for person 
%p is probability of a coin, and n is the number of games
totflips=0;      %number of flips 
for i=1:n
    c=0; 
    Y(1)=initP1;
    Y(2)=initP2;
    Y(3)=initP3;
while Y(1)>0 && Y(2)>0 && Y(3)>0 
    %condition while everyone has at least one coin
    r(1)=rand;  %generate random numbers for r(1), r(2), and r(3)
    r(2)=rand;
    r(3)=rand;
for j=1:3
    if r(j)>p
        r(j)=1; %heads
    else
        r(j)=0; %tails
    end
end
if ((r(1)==r(3)) && (r(2)~=r(1))) 
    %one and three are equal and two is unequal
    Y(1)=Y(1)-1;
    Y(2)=Y(2)+2;
    Y(3)=Y(3)-1;
elseif ((r(1)==r(2)) && (r(3)~=r(2))) 
    %one and two are equal and three is unequal
    Y(1)=Y(1)-1;
    Y(2)=Y(2)-1;
    Y(3)=Y(3)+2;
elseif ((r(2)==r(3)) && (r(1)~=r(3))) 
    %two and three are equal and one is unequal
    Y(1)=Y(1)+2;
    Y(2)=Y(2)-1;
    Y(3)=Y(3)-1;
end
c=c+1;
end
totflips=totflips+c;
end
avgflips=totflips/n; %average flips 

end

