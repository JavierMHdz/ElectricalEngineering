function arrayOfCards = shuffle(arrayOfCards)

%Number of cards in my deck
cardNumber =  length(arrayOfCards);

for index = 1:1000

        %Creating indices of the cards that will swap
        randOne = randi(cardNumber);
        randTwo = randi(cardNumber);

        %Shuffling my cards
        variable = arrayOfCards(randOne);
        arrayOfCards(randOne) = arrayOfCards(randTwo);
        arrayOfCards(randTwo) = variable;

end;
end