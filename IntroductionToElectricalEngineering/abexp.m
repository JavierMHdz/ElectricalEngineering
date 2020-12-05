%********************************************
% filename: abexp.m
% This script generates vector a and b
% and calculates the element-wise g = a^b
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
%Generate a
a = [3,1,2,-1];
% Generate b
b = [2,0,2,3];
% Generate a^b element-wise
g = a.^b;