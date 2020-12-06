%Problem 5.6
id0.5 = 0;
id1 = 0;
id1.5 = 0;
id2 = 0;
id2.5 = 0;

for vds = 0:.001:0.05
    %For Vgs = 0.5
    id0.5 = (5*(0.5-0.5))*vds

    %For Vgs = 1
    id1 = (5*(1-0.5))*vds

    %For Vgs = 1.5
    id1.5 = (5*(1.5-0.5))*vds

    %For Vgs = 2
    id2 = (5*(2-0.5))*vds

    %For Vgs = 2.5
    id2.5 = (5*(2.5-0.5))*vds
end

plot(0.5, id0.5)
hold on
plot(1, id1)
plot(1.5, id1.5)
plot(2, id2)
plot(2.5, id2.5)