function[avgflip]=ee150_brokeprueba(initP1, initP2, initP3, P, n)
for i=1:n
player1=initP1;
player2=initP2;
player3=initP3;
totalflip=0;
while (player1>0 && player2>0 && player3>0)
        p(1)=rand;
        if p(1)>P
            p(1)=1; %1=heads
        else p(1)=0; %0=tails
        end
            p(2)=rand;
           if p(2)>P
               p(2)=1;
           else p(2)=0;
           end
           p(3)=rand;
           if p(3)>P
               p(3)=1;
           else p(3)=0;
           end
             if p(1)+p(2)+ p(3)==1
                   for k =1:3;
                   if p(k)==1
                   p(k)=p(k)+2;
                   end
               end
         else p(1)+p(2)+p(3)==2
                for h = 1:3;
                    if p(h)==0
                    p(h)=p(h)+2;
                end
                end
         player1=player1+p(1);
         player2=player2+p(2);
         player3=player3+p(3);
           totalflip = totalflip+1;
end
       
end
avgflip=totalflip/n;
disp(avgflip);
end             
                