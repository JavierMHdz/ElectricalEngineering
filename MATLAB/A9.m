%Part 1: Load data
load('HW9.mat');
radiusOfEarth = 6371000;

%Part 2: Convert X and Y values to Meters
xVec = zeros(1,335);
yVec = zeros(230,1);

for i = 2:length(xVec)
    xVec(i) = xVec(i-1) + radiusOfEarth*tand(X(i)-X(i-1));
end;

for i = 2:length(yVec)
    yVec(i) = yVec(i-1) + radiusOfEarth*tand(Y(i)-Y(i-1));
end;

%Part 3: Plot Contour, Surface, and Boundary Box
sizeBoundary = 50;
startX = 1;
startY = 1;
moveFactor = 10;
endX = startX + sizeBoundary - 1;
endY = startY + sizeBoundary - 1;

%Top Line
xTopLine = xVec(startX:endX);
yTopLine(1:length(xTopLine)) = yVec(endY);


%Bottom Line
xBottomLine = xVec(startX:endX);
yBottomLine(1:length(xBottomLine)) = yVec(startY);


%Left Line
yLeftLine = yVec(startY:endY);
xLeftLine(1:length(yLeftLine)) = xVec(startX);

%Right Line
yRightLine = yVec(startY:endY);
xRightLine(1:length(yRightLine)) = xVec(endX);

%Subplot Array
[xMesh,yMesh] = meshgrid(xVec,yVec);
figure
subplot(2,1,1);

pHandle = surf(xMesh(1:sizeBoundary,1:sizeBoundary),yMesh(1:sizeBoundary,1:sizeBoundary),ELEV(1:sizeBoundary,1:sizeBoundary));
colormap(parula)

% Hint: Remember the X and Y starting and ending points, use that.
% Hint: Remember that Y values translate to ROWS, X values translate to COLUMNS

subplot(2,1,2);
pHandle2 = contour(xMesh,yMesh,ELEV);
hold on
plotHandle1 = plot(xTopLine,yTopLine);
plotHandle2 = plot(xBottomLine,yBottomLine);
plotHandle3 = plot(xLeftLine,yLeftLine);
plotHandle4 = plot(xRightLine,yRightLine);

[rowsELEV,colELEV] = size(ELEV);


while (true)

    decision = input('Choose an option:\n   1. North\n   2. South\n   3. East\n   4. West \n   0. Quit\nChoose:\n');

    switch decision
        case 1
            if (endY + moveFactor) > rowsELEV
                endY = rowsELEV;
                startY = rowsELEV - sizeBoundary + 1;
            else
                startY = startY + moveFactor;
            end;
            
        case 2
            startY = startY - moveFactor;
            if (startY - moveFactor) < 1
                startY = 1;
                endY = sizeBoundary;
            else
                startY = startY - moveFactor;
            end;
            
        case 3
            if (endX + moveFactor) > colELEV
                endX = colELEV;
                startX = colELEV - sizeBoundary + 1;
            else
                startX = startX + moveFactor;
            end;
            
        case 4
            if (startX - moveFactor) < 1
                startX = 1;
                endX = sizeBoundary;
            else
                startX = startX - moveFactor;
            end;
            
        case 0
            fprintf('Goodbye\n');
            break;
        otherwise
            fprintf('Your input is invalid.\n');
    end;
    
    endX = startX + sizeBoundary - 1;
    endY = startY + sizeBoundary - 1;
    
    %Top Line
    xTopLine = xVec(startX:endX);
    yTopLine(1:length(xTopLine)) = yVec(endY);
    
    
    %Bottom Line
    xBottomLine = xVec(startX:endX);
    yBottomLine(1:length(xBottomLine)) = yVec(startY);
    
    
    %Left Line
    yLeftLine = yVec(startY:endY);
    xLeftLine(1:length(yLeftLine)) = xVec(startX);
    
    %Right Line
    yRightLine = yVec(startY:endY);
    xRightLine(1:length(yRightLine)) = xVec(endX);
    
    %Subplot Array
    [xMesh,yMesh] = meshgrid(xVec,yVec);

   
        set(plotHandle1,'XData',xTopLine);
        set(plotHandle1,'YData',yTopLine);
        set(plotHandle2,'XData',xBottomLine);
        set(plotHandle2,'YData',yBottomLine);
        set(plotHandle3,'XData',xLeftLine);
        set(plotHandle3,'YData',yLeftLine);
        set(plotHandle4,'XData',xRightLine);
        set(plotHandle4,'YData',yRightLine);
        set(pHandle,'XData',xMesh(startY:endY,startX:endX));
        set(pHandle,'YData',yMesh(startY:endY,startX:endX));
        set(pHandle,'ZData',ELEV(startY:endY,startX:endX));
        drawnow;
  
end;