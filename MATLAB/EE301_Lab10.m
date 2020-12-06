%% EE301 Lab10
% Javier Macossay-Hernandez,
% USC ID 9907093913,
% Lab Section 30813

clc;
clear all;
close all;

%%Question 1
for imnum = 1:3
fname = sprintf('0%d.gif',imnum);
im = imread(fname,'gif');
figure
imshow(im);
title(num2str(imnum));
pause(0.2);

%%Question 2

figure
% Compute the Fourier
ftx = fft2(im);
subplot(131);
% Image
imshow(im,[0 256]);
title('Image');
subplot(132);
% Fourier Log-Magnitude
imshow(log(fftshift(abs(ftx))),[-4 10]);
title('Fourier log magnitude');
subplot(133);
% Fourier phase
imshow(angle(ftx),[-pi pi]); 
title('Fourier phase');
end

%Do you see any common trends among all (or most) images?
%A commont trend among the images is the area of the center because it has
%more intesity. Therefore, the image locks brighter.

%Do you see any unique features in the Fourier domain? Do they relate to
%features in the image domain?
%In the Fourier domain, it can be seen the information in the intensity.
%In the lower frequency, it can be perceived more energy.
%Unique features in the Fourier domain can be seen, but it is not easy to
%interpret them to relate them in the image domain.

%%Question 3
fname = sprintf('01.gif',imnum);
im1 = imread(fname,'gif');


fname = sprintf('02.gif',imnum);
im2 = imread(fname,'gif');

% compute the Fourier
ft1= fft2(im1);
% compute the Fourier
ft2= fft2(im2); 

mag01=abs(ft1);
pha02=angle(ft2);
total=mag01.*exp(j*pha02);
new=ifft2(total);
figure
% image
imshow(abs(new),[0 256]);

%From this process, can you infer the type of information contained in the
%magnitude versus phase of the Fourier transform?
%In this case, the information contained in the magnitude is less relevant
%than the information contained in the phase of the Fourier transform.

%%Question 4
fname = sprintf('01.gif',imnum);
im = imread(fname,'gif');

m = [2 1 0 0 0;
 1 2 1 0 0;
 0 1 2 1 0;
 0 0 1 2 1;
 0 0 0 1 2];
figure
% normalized matrix
m = m/sum(m(:));
im4 = conv2(double(im),m,'same');
subplot(121);
% show original image
imshow(im,[0 256]);
subplot(122);
% show the one after convolution
imshow(im4,[0 256]);

%from left to right
fname = sprintf('01.gif',imnum);
im = imread(fname,'gif');

m = [0 0 0 0 0;
 0 0 0 0 0;
 5 5 2 5 5;
 0 0 0 0 0;
 0 0 0 0 0];
figure
% normalized matrix
m = m/sum(m(:));
im4 = conv2(double(im),m,'same');
subplot(121);
% show original image
imshow(im,[0 256]);
subplot(122);
% show the one after convolution
imshow(im4,[0 256]);

%from up to down
fname = sprintf('01.gif',imnum);
im = imread(fname,'gif');

m = [0 0 5 0 0;
 0 0 5 0 0;
 0 0 2 0 0;
 0 0 5 0 0;
 0 0 5 0 0];
figure
% normalized matrix
m = m/sum(m(:));
im4 = conv2(double(im),m,'same');
subplot(121);
% show original image
imshow(im,[0 256]); 
subplot(122);
% show the one after convolution
imshow(im4,[0 256]);

%%Open Ended Problems
% Removing "Camera Shake" Blur

m = [2 1 0 0 0;
     1 2 1 0 0;
     0 1 2 1 0;
     0 0 1 2 1;
     0 0 0 1 2];

% Finding the determinant of the matrix m
l= det(m); 
l= l/sum(l(:));
m = m/sum(m(:));

im2 = conv2(double(im),m,'same');
im3= conv2(double(im),l, 'same');

figure 
subplot(1,3,1)
imshow(im,[0 256])
title('Image without changes')

subplot(1,3,2)
imshow(im2,[0 256])
title('Image with shake blur')

subplot(1,3,3)
imshow(im3, [0 256])
title('Image with shake blur removed')