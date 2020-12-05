%********************************************
% filename: homework#8.m
% This script generates vector Z and C
% and calculates the element-wise of A.*B
%
% Author: Javier Macossay-Hernandez
% Created on: 05-MAR-2013
% Last revised on: 05-MAR-2013
% Revision History:
%*******************************************


% Clear the workspace
clear;
% Refresh the command window
clc;
% Generate Z
Z = 5^.5*[1+cosd(30)]/[exp(.5)-20*log10(2)]
% Generate C
C = [3,4,4;6,6,8;1,2,3] + [1,2,3;4,5,6;7,8,9]
% Generate A.*B element-wise
A = [-3,-2,-1,0,1,2,3]
B = [1,2,3,4,5,6,7]
A.*B