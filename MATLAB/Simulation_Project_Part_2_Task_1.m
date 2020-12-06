%Task # 1

%part a
a = -0.0381;
b = 0.0128;
c = 0.000042;
d = 0.0115;
e = -0.029;
f = 0;
g = 0.0041;
h = 0;
i = -0.000042;

A = [a b c; d e f; g h i];
aEig = eig(A);
display(aEig);

%part b
newA = -0.0831;

B = [newA b c; d e f; g h i];
bEig = eig(B);
display(bEig);