function y=dyew2poss(n,k)
format long
red=zeros(1,n);
game=zeros(1,10000);
for m=1:10000;
    for i=1:n;
        r=floor(rand*3)+1;
        if r==1 || r==2
            red(i)=1;
        else red(i)=0;
        end
    end
    numred=sum(red);
    if numred==k
        game(m)=1;
    else game (m)=0;
    end
end
S=sum(game);
y=S/10000;