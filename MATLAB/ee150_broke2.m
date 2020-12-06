function avgFlips = ee150_broke2 (ini1, ini2, ini3, p, n)
totalflips = 0;
for sequence = 1:n
    sequenceflips = 0;
    man(1) = ini1;
    man(2) = ini2;
    man(3) = ini3;
    while (man(1)>0 && man(2)>0 && man(3)>0)
        flip(1)=rand;
        flip(2)=rand;
        flip(3)=rand;
        for j=1:3
            if flip(j)<p
                flip(j)=1;
            else
                flip(j)=0;
            end
        end
        test = sum(flip);
        if test == 1 || test == 2
            if test == 1
                for j = 1:3
                    if flip(j) == 0
                        flip(j) = -1;
                    else
                        flip(j) = 2;
                    end
                end
           
            else
                for j = 1:3
                    if flip(j) == 1
                        flip(j) = -1;
                    else
                        flip(j) = 2;
                    end
                end
            end
                for j = 1:3;
                    man(j) = man(j) + flip(j);
                end
            end
            sequenceflips = sequenceflips + 1;
        end
        totalflips = totalflips + sequenceflips;
    end
    avgFlips = totalflips/n;
    disp(avgFlips)