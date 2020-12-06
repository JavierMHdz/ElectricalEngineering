function arrayOfCards = initdeck()

for i = 1:52
arrayOfCards(i) = struct('suit',[],'number',[],'value',[]);
end;

flag = true;
runs = 1;

while(flag);
    
    if(runs == 1)
        min = 1;
        max = 13;
        suit = 'Diamonds';
    elseif(runs == 2)
        min = 14;
        max = 26;
        suit = 'Hearts';
    elseif(runs == 3)
        min = 27;
        max = 39;
        suit = 'Spades';
    else
        min = 40;
        max = 52;
        suit = 'Clubs';
    end;
    
    cases = 1;
    for counter = min:max
        
    arrayOfCards(counter).suit = suit;
    
    %creating the string that contains the number of the card
    switch cases
        case 1
            arrayOfCards(counter).number = '2';
            arrayOfCards(counter).value = 2;
        case 2
            arrayOfCards(counter).number = '3';
            arrayOfCards(counter).value = 3;
        case 3
            arrayOfCards(counter).number = '4';
            arrayOfCards(counter).value = 4;
        case 4
            arrayOfCards(counter).number = '5';
            arrayOfCards(counter).value = 5;
        case 5
            arrayOfCards(counter).number = '6';
            arrayOfCards(counter).value = 6;
        case 6
            arrayOfCards(counter).number = '7';
            arrayOfCards(counter).value = 7;
        case 7
            arrayOfCards(counter).number = '8';
            arrayOfCards(counter).value = 8;
        case 8
            arrayOfCards(counter).number = '9';
            arrayOfCards(counter).value = 9;
        case 9
            arrayOfCards(counter).number = '10';
            arrayOfCards(counter).value = 10;
        case 10
            arrayOfCards(counter).number = 'Jack';
            arrayOfCards(counter).value = 10;
        case 11
            arrayOfCards(counter).number = 'Queen';
            arrayOfCards(counter).value = 10;
        case 12
            arrayOfCards(counter).number = 'King';
            arrayOfCards(counter).value = 10;
        case 13
            arrayOfCards(counter).number = 'Ace';
            arrayOfCards(counter).value = 11;
    end;
    cases = cases + 1;
    end;
    
    runs = runs + 1;
    
    if (runs > 4)
        flag = false;
    end;
end