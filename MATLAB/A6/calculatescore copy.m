function adjustedScore = calculatescore(arrayOfCards)
condition = length(arrayOfCards);
sum = 0;
aces = 0;

for index = 1:condition
    sum = sum + arrayOfCards(index).value;
    
    if (strcmp(arrayOfCards(index).number,'Ace'))
        aces = aces + 1;
    end;
    
end; 

    if ((aces > 0) && (sum > 21))
       adjustedScore = sum - 10;
       aces = aces - 1;
       
       if ((aces > 0) && (adjustedScore > 21))
           
           while (true)
               adjustedScore = adjustedScore - 10;
               aces = aces - 1;
               
               if ((aces == 0) || (adjustedScore <= 21))
                   break;
               end;
               
           end;
           
       end;
       
    end;
    
end