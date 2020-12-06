%Lab 1.5

%Part d (probability transition matrix applied two times to a starting
%vector at C that gives a probability vector in agreement with the results
%obtained from your probability tree in Part b)
P=[0 1/2 1/3 1 0; 1 0 1/3 0 1/3; 0 1/2 0 0 1/3; 0 0 0 0 1/3; 0 0 1/3 0 0]
p0=[0;0;1;0;0]
(P^2)*p0

%Part e (for loop that results in raising the Markov Transition matrix
%above to a power)
Q=[1 0 0 0 0;0 1 0 0 0;0 0 1 0 0; 0 0 0 1 0; 0 0 0 0 1];
P=[0 1/2 1/3 1 0; 1 0 1/3 0 1/3; 0 1/2 0 0 1/3; 0 0 0 0 1/3; 0 0 1/3 0 0];
for i = 1:100
    Q=Q*P;
    disp(Q);
end
Z=[Q(1,1),Q(2,1),Q(3,1),Q(4,1),Q(5,1)]';
disp(Z);
[q,R]=sort(Z,'descend')

%Part f (Part f is the same as Part e, but it has a while loop instead of a
%for loop)
eps=1e-7;
Q=[1 0 0 0 0;0 1 0 0 0;0 0 1 0 0; 0 0 0 1 0; 0 0 0 0 1];
P=[0 1/2 1/3 1 0; 1 0 1/3 0 1/3; 0 1/2 0 0 1/3; 0 0 0 0 1/3; 0 0 1/3 0 0];
while abs (Q(1,1)-Q(1,2))>eps
    Q=Q*P;
    disp(Q);
end
Z=[Q(1,1),Q(2,1),Q(3,1),Q(4,1),Q(5,1)]';
disp(Z);
[q,R]=sort(Z,'descend');
disp(R)

%Part g (adjusted the condition in the while loop so that the condition
%is true for all of the elements in the resulting 5 x 5 matrices generated
%from the loop)
eps=1e-9;
Q=[1 0 0 0 0;0 1 0 0 0;0 0 1 0 0; 0 0 0 1 0; 0 0 0 0 1];
P=[0 1/2 1/3 1 0; 1 0 1/3 0 1/3; 0 1/2 0 0 1/3; 0 0 0 0 1/3; 0 0 1/3 0 0];
while abs (Q(2,1)-Q(2,2))>eps
    Q=Q*P;
    disp(Q);
end
Z=[Q(1,1),Q(2,1),Q(3,1),Q(4,1),Q(5,1)]';
disp(Z);
[q,R]=sort(Z,'descend');
disp(R)
format long

%Part h (column vector whose elements are the probability of being on each
%page after crawling through the web for a long time)
Vector=[0.292682926829268; 0.390243902439024; 0.219512195121951; 0.024390243902439; 0.073170731707317];
P=[0 1/2 1/3 1 0; 1 0 1/3 0 1/3; 0 1/2 0 0 1/3; 0 0 0 0 1/3; 0 0 1/3 0 0];
P*Vector

%Part i (rankings of pages)
eps = 1e-9;
Q=[1 0 0 0 0;0 1 0 0 0;0 0 1 0 0; 0 0 0 1 0; 0 0 0 0 1];
P=[0 1/2 1/3 1 0; 1 0 1/3 0 1/3; 0 1/2 0 0 1/3; 0 0 0 0 1/3; 0 0 1/3 0 0];
while abs(Q(2,1)-Q(2,2))>eps
    Q=Q*P;
    disp(Q);
end
Z=[Q(1,1),Q(2,1),Q(3,1),Q(4,1),Q(5,1)]';
disp(Z);
[q,R]=sort(Z,'descend');
disp(R);
for i=1:5
   if R(i)== 1
       disp('A');
   elseif R(i)==2
       disp('B');
   elseif R(i)==3
       disp('C');
   elseif R(i)==4
       disp('D');
   elseif R(i)==5
       disp('E')
   end
end





