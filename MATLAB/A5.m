%{
Javier Macossay
ITP 168 - Fall 2015
Homework 5: Structures
macossay@usc.edu
Revision History
Date            Changes             Programmer
----------------------------------------------------
10/8/2015        Original            Javier Macossay
%}

%Setup
%Shape Structure
shape = struct('circle',[],'triangle',[],'square',[]);

%Circle Structure
circle = struct('radius',[],'center',[],'area',[]);
%Right Triangle Structure
triangle = struct('length',[],'center',[],'area',[]);
%Square Structure
square = struct('length',[],'center',[],'area',[]);

%Part 1: Creating Shapes
choice1 = input('Would you like to create a circle? (Y/N): ','s');
choice2 = input('Would you like to make a triangle? (Y/N): ','s');
choice3 = input('Would you like to make a square? (Y/N): ','s');

fprintf('You created these shapes:\n');

condition1 = 0;
condition2 = 0;
condition3 = 0;

if strcmpi(choice1,'y')
    fprintf('circle\n');
    
    condition1 = 1;
end;
if strcmpi(choice2,'y')
    fprintf('triangle\n');
        
    condition2 = 2;
end;
if strcmpi(choice3,'y')
    fprintf('square\n');
        
    condition3 = 4;
end;

if strcmpi(choice1,'n') && strcmpi(choice2,'n') && strcmpi(choice3,'n')
fprintf('No shapes created\n');

end;

switch (condition1+condition2+condition3)
    case 1
        %circle
       fprintf('You only created a single shape: circle\n');
        
       %creating the circle
        circle.radius = randi(10);
        circle.center = [randi(10) randi(10)];
        circle.area = pi*circle.radius^2;
    case 2
        %triangle
        fprintf('You only created a single shape: triangle\n');
        
        %creating the triangle
        triangle.length = [randi(10) randi(10)];
        triangle.center = [randi(10) randi(10)];
        triangle.area = (length(1)*length(2))/2;
    case 3
        %circle and triangle
        fprintf('Choose two shapes to calculate the distance between centers.\nYou must spell them EXACTLY as they were written.\n');
        distanceShapeOne = input('First shape: ');    
        distanceShapeTwo = input('Second shape: ');
        
        %creating the circle
        distanceShapeOne.radius = randi(10);
        distanceShapeOne.center = [randi(10) randi(10)];
        distanceShapeOne.area = pi*circle.radius^2;
        
        %creating the triangle
        distanceShapeTwo.length = [randi(10) randi(10)];
        distanceShapeTwo.center = [randi(10) randi(10)];
        distanceShapeTwo.area = (length(1)*length(2))/2;
        
        %Calculate the distance between their centers
        distance = sqrt((distanceShapeOne.center(1)-distanceShapeTwo.center(1))^2+(distanceShapeOne.center(2)-distanceShapeTwo.center(2))^2);
        fprintf('The distance between the circle and the triangle is %0.3f\n',distance);
        
        %Calculate the area ratio
        fprintf('Choose two shapes to calculate the ratio of the areas.\nYou must spell them EXACTLY as they were written\n');
        ratioShapeOne = input('First shape: ');
        ratioShapeTwo = input('Second shape: ');
        
        if strcmp('circle',ratioShapeOne)
            ratioShapeOne.radius = randi(10);
            ratioShapeOne.area = pi*ratioShapeOne.radius^2;

        elseif strcmp('triangle',ratioShapeOne)
            ratioShapeOne.length = [randi(10) randi(10)];
            ratioShapeOne.area = (length(1)*length(2))/2;
            
        elseif strcmp('square',ratioShapeOne)
            ratioShapeOne.length = randi(10);
            ratioShapeOne.area = ratioShapeTwo.length^2;
        else
            fprintf('No shape by that name!\n');
        end;
        
        if strcmp('circle',ratioShapeTwo)
            ratioShapeTwo.radius = randi(10);
            ratioShapeTwo.area = pi*ratioShapeTwo.radius^2;
            
        elseif strcmp('triangle',ratioShapeTwo)
            ratioShapeTwo.length = [randi(10) randi(10)];
            ratioShapeTwo.area = (length(1)*length(2))/2;
            
        elseif strcmp('square',ratioShapeTwo)
            ratioShapeTwo.length = randi(10);
            ratioShapeTwo.area = ratioShapeTwo.length^2;
            
        else
            fprintf('No shape by that name!\n');
        end;
        
        ratio = ratioShapeOne.area/ratioShapeTwo.area;
        fprintf('The ratio of the areas (%s:%s) is %0.3f',ratioShapeOne, ratioShapeTwo, ratio);
        
    case 4
        %square
        fprintf('You only created a single shape: square\n');
        
        %creating the square
        square.length = randi(10);
        square.center = [randi(10) randi(10)];
        square.area = square.length^2;
    case 5
        %circle and square
        fprintf('Choose two shapes to calculate the distance between centers.\nYou must spell them EXACTLY as they were written.\n');
        distanceShapeOne = input('First shape: ');    
        distanceShapeTwo = input('Second shape: ');
        
        %creating the circle
        distanceShapeOne.radius = randi(10);
        distanceShapeOne.center = [randi(10) randi(10)];
        distanceShapeOne.area = pi*circle.radius^2;
        
        %creating the square
        distanceShapeTwo.length = randi(10);
        distanceShapeTwo.center = [randi(10) randi(10)];
        distanceShapeTwo.area = distanceShapeTwo.length^2;
        
        %Calculate the distance between their centers
        distance = sqrt((distanceShapeOne.center(1)-distanceShapeTwo.center(1))^2+(distanceShapeOne.center(2)-distanceShapeTwo.center(2))^2);
        fprintf('The distance between the circle and the square is %0.3f\n',distance);
        
        %Calculate the area ratio
        fprintf('Choose two shapes to calculate the ratio of the areas.\nYou must spell them EXACTLY as they were written\n');
        ratioShapeOne = input('First shape: ');
        ratioShapeTwo = input('Second shape: ');
                 
        if strcmp('circle',ratioShapeOne)
            ratioShapeOne.radius = randi(10);
            ratioShapeOne.area = pi*ratioShapeOne.radius^2;

        elseif strcmp('triangle',ratioShapeOne)
            ratioShapeOne.length = [randi(10) randi(10)];
            ratioShapeOne.area = (length(1)*length(2))/2;
            
        elseif strcmp('square',ratioShapeOne)
            ratioShapeOne.length = randi(10);
            ratioShapeOne.area = ratioShapeTwo.length^2;
        else
            fprintf('No shape by that name!\n');
        end;
        
        if strcmp('circle',ratioShapeTwo)
            ratioShapeTwo.radius = randi(10);
            ratioShapeTwo.area = pi*ratioShapeTwo.radius^2;
            
        elseif strcmp('triangle',ratioShapeTwo)
            ratioShapeTwo.length = [randi(10) randi(10)];
            ratioShapeTwo.area = (length(1)*length(2))/2;
            
        elseif strcmp('square',ratioShapeTwo)
            ratioShapeTwo.length = randi(10);
            ratioShapeTwo.area = ratioShapeTwo.length^2;
            
        else
            fprintf('No shape by that name!\n');
        end;
        
        ratio = ratioShapeOne.area/ratioShapeTwo.area;
        %fprintf('The ratio of the areas (%s:%s) is %0.3f'%,%ratioShapeOne, ratioShapeTwo,% ratio);
        
    case 6
        %triangle and square
        fprintf('Choose two shapes to calculate the distance between centers.\nYou must spell them EXACTLY as they were written.\n');
        distanceShapeOne = input('First shape: ');    
        distanceShapeTwo = input('Second shape: ');
        
        %creating the triangle
        distanceShapeOne.length = [randi(10) randi(10)];
        distanceShapeOne.center = [randi(10) randi(10)];
        distanceShapeOne.area = (length(1)*length(2))/2;
        
        %creating the square
        distanceShapeTwo.length = randi(10);
        distanceShapeTwo.center = [randi(10) randi(10)];
        distanceShapeTwo.area = distanceShapeTwo.length^2;
        
        %Calculate the distance between their centers
        distance = sqrt((distanceShapeOne.center(1)-distanceShapeTwo.center(1))^2+(distanceShapeOne.center(2)-distanceShapeTwo.center(2))^2);
        fprintf('The distance between the triangle and the square is %0.3f\n',distance);
        
        %Calculate the area ratio
        fprintf('Choose two shapes to calculate the ratio of the areas.\nYou must spell them EXACTLY as they were written\n');
        ratioShapeOne = input('First shape: ');
        ratioShapeTwo = input('Second shape: ');
        
                
        if strcmp('circle',ratioShapeOne)
            ratioShapeOne.radius = randi(10);
            ratioShapeOne.area = pi*ratioShapeOne.radius^2;

        elseif strcmp('triangle',ratioShapeOne)
            ratioShapeOne.length = [randi(10) randi(10)];
            ratioShapeOne.area = (length(1)*length(2))/2;
            
        elseif strcmp('square',ratioShapeOne)
            ratioShapeOne.length = randi(10);
            ratioShapeOne.area = ratioShapeTwo.length^2;
        else
            fprintf('No shape by that name!\n');
        end;
        
        if strcmp('circle',ratioShapeTwo)
            ratioShapeTwo.radius = randi(10);
            ratioShapeTwo.area = pi*ratioShapeTwo.radius^2;
            
        elseif strcmp('triangle',ratioShapeTwo)
            ratioShapeTwo.length = [randi(10) randi(10)];
            ratioShapeTwo.area = (length(1)*length(2))/2;
            
        elseif strcmp('square',ratioShapeTwo)
            ratioShapeTwo.length = randi(10);
            ratioShapeTwo.area = ratioShapeTwo.length^2;
            
        else
            fprintf('No shape by that name!\n');
        end;
        
        ratio = ratioShapeOne.area/ratioShapeTwo.area;
        fprintf('The ratio of the areas (%s:%s) is %0.3f',ratioShapeOne, ratioShapeTwo, ratio);
    case 7
        %Part 3
        fprintf('Choose two shapes to calculate the distance between centers.\nYou must spell them EXACTLY as they were written\n');
        
        run = true;
        while (run)
        firstShape = input('First shape: ');
            if strcmp('circle',firstShape)||strcmp('triangle',firstShape)||strcmp('square',firstShape)
            run = false;
            else
                fprintf('No shape by that name!\n');
            end;
        end;
        
        condition = true;
        while (condition)
        secondShape = input('Second shape: ');
            if strcmp('circle',secondShape)||strcmp('triangle',secondShape)||strcmp('square',secondShape)
            condition = false;
            else
                fprintf = ('No shape by that name!\n');
            end;
        end
        
        firstShape.center = [randi(10) randi(10)];
        secondShape.center = [randi(10) randi(10)];
            
        %Calculate the distance between their centers
        distance = sqrt((firstShape.center(1)-secondShape.center(1))^2+(firstShape.center(2)-secondShape.center(2))^2);
        
        %Calculate the area ratio
        fprintf('Choose two shapes to calculate the ratio of the areas.\nYou must spell them EXACTLY as they were written\n');
        ratioShapeOne = input('First shape: ','s');
        ratioShapeTwo = input('Second shape: ','s');
        
        if strcmp('circle',ratioShapeOne)
            ratioShapeOne.radius = randi(10);
            ratioShapeOne.area = pi*ratioShapeOne.radius^2;

        elseif strcmp('triangle',ratioShapeOne)
            ratioShapeOne.length = [randi(10) randi(10)];
            ratioShapeOne.area = (length(1)*length(2))/2;
            
        elseif strcmp('square',ratioShapeOne)
            ratioShapeOne.length = randi(10);
            ratioShapeOne.area = ratioShapeTwo.length^2;
        else
            fprintf('No shape by that name!\n');
        end;
        
        if strcmp('circle',ratioShapeTwo)
            ratioShapeTwo.radius = randi(10);
            ratioShapeTwo.area = pi*ratioShapeTwo.radius^2;
            
        elseif strcmp('triangle',ratioShapeTwo)
            ratioShapeTwo.length = [randi(10) randi(10)];
            ratioShapeTwo.area = (length(1)*length(2))/2;
            
        elseif strcmp('square',ratioShapeTwo)
            ratioShapeTwo.length = randi(10);
            ratioShapeTwo.area = ratioShapeTwo.length^2;
            
        else
            fprintf('No shape by that name!\n');
        end;
        
        ratio = ratioShapeOne.area/ratioShapeTwo.area;
        fprintf('The ratio of the areas (%s:%s) is %0.3f',ratioShapeOne, ratioShapeTwo, ratio);
end;