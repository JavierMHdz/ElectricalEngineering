%{
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 0
Average: 8.000
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 0.1
Average: 7.238
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 0.2
Average: 6.324
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 0.3
Average: 5.297
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 0.4
Average: 4.189
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 0.5
Average: 3.139
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 0.6
Average: 2.281
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 0.7
Average: 1.691
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 0.8
Average: 1.329
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 0.9
Average: 1.125
student@student-VirtualBox:~/Dropbox/ee355/pa1$ ./tp 8 1
Average: 1.000
%}

Y = [8.000 7.238 6.324 5.297 4.189 3.139 2.281 1.691 1.329 1.125 1.000];
X = [0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1];

plot(X,Y,'b--o');
title('Spare a Square');
xlabel('p');
ylabel('Number of remaining squares');
grid;