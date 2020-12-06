%{
Javier Macossay
ITP 168 - Fall 2015
Homework 6: Functions
macossay@usc.edu
Revision History
Date            Changes                                  Programmer
--------------------------------------------------------------------------
10/17/2015        Original                                 Javier Macossay
10/18/2015        Created calculatescore function          Javier Macossay
%}

playAgain = true;
while (playAgain)
    
    playerCard = [];
    dealerCard = [];
    
    %1)Initialize the deck of cards
    deck = initdeck();
    
    %2)Shuffle the cards
    shuffled = shuffle(deck);
    
    %3)Create the player's cards array by dealing two cards to a structure array
    playerCard = struct('suit',[],'number',[],'value',[]);
    [playerCard(1), cardsLeftOne] = dealcard(shuffled);
    [playerCard(2), cardsLeftTwo] = dealcard(cardsLeftOne);
    
    %4)Print out both cards
    fprintf('Player is dealt:\n\t%s\n\t%s\n',playerCard(1).suit,playerCard(2).suit);
    
    %5)Create the dealer's card array by dealing two cards to a structure array
    dealerCard = struct('suit',[],'number',[],'value',[]);
    [dealerCard(1), cardsLeftThree] = dealcard(cardsLeftTwo);
    [dealerCard(2), cardsLeftFour] = dealcard(cardsLeftThree);
    
    %6)Print out both cards
    fprintf('Dealer is dealt:\n\t%s\n\t%s\n',dealerCard(1).suit,dealerCard(2).suit);
    
    %7)Calculate the score for the player and the dealer
    playerScore = calculatescore(playerCard);
    dealerScore = calculatescore(dealerCard);
    
    %8)If both player and dealer have 21, then it's an automatic tie
    if (playerScore == dealerScore)
        fprintf('It''s a tie\n');
    end;
    
    %9)If the player has 21 and the dealer does not, then the player wins
    %(Blackjack!)
    if ((playerScore == 21) && (dealerScore ~= 21))
        fprintf('Player has Blackjack!\n');
    end;
    
    %10)If the dealer has 21 and the player does not, then the dealer wins
    %(Blackjack!)
    if ((playerScore ~= 21) && (dealerScore == 21))
        fprintf('Dealer has Blackjack!\n');
    end;
    
    %11)If neither have 21, then it's the player's turn
    if ((playerScore ~= 21) && (dealerScore ~= 21))
        %a)Print out the player's score
        fprintf('Player Score: %0.0f',playerScore);
        %b)Ask them to hit or stand
        option = input('Choose an option:\n\t1. Hit\n\t2. Stand\n','s');
        %c)If they choose stand, then it's the dealer's turn (move on to step
        %11e)
        if (strcmpi('Hit',option))
            value = 1;
        elseif (strcmpi('Stand',option))
            value = 2;
        else
            error('You entered an invalid option');
        end;
        %d)If they choose hit, deal a card to the player's structure array and
        %print the card
        switch value
            case 1
                [playerCard(3), cardsLeftFive] = dealcard(cardsLeftFour);
                fprintf('Player is dealt:\n\t%s\n',playerCard(3).suit);
                
                %i)Calculate their score
                playerScore = calculatescore(playerCard);
                
                %ii)If their score is over 21, they lose (move on to step 12)
                if (playerScore > 21)
                    fprintf('Player loses!\n');
                    %iii)If their score is 21 or under, go back to step 11a.
                else
                    [rows, columns] = size(arrayOfCards);
                    rowVector1 = zeros(rows, columns);
                    rowVector1 = arrayOfCards;
                    counter = 5;
                    while (true)
                        
                        fprintf('Player Score: %0.0f',playerScore);
                        option = input('Choose an option:\n\t1. Hit\n\t2. Stand\n','s');
                        
                        if(strcmpi('Hit',option))
                            [playerCard(counter), rowVector1] = dealCard(cardsLeftFive);
                            counter = counter + 1;
                            % change this! to a vector fprintf('Player is dealt:\n\t%s\n',playerCard(3).suit);
                        end;
                        playerScore = calculatescore(playerCard);
                        if (playerScore > 21)
                            fprintf('Player loses!\n');
                            break;
                        end;
                    end;
                end;
                %e)Dealer's turn begins. Print out the dealer's score
            case 2
                fprintf('Dealer Score: %0.0f\n',dealerScore);
                
                %f)If the dealer's score is less than 18, deal a card to the dealer's
                %structure array
                if(dealerScore < 18)
                    [dealerCard(3), cardsLeftFive] = dealcard(cardsLeftFour);
                end;
                %g)Print out the card
                fprintf('Dealer drew:\n\t%s\n',dealerCard(3).suit);
                
                %h)Calculate the dealer's score
                dealerScore = calculatescore(dealerCard);
                %i)If their score is over 21, they lose (move on to step 12)
                %ii)If their score is over 18 and under 22, move on to step 12
                %iii)If their score is still under 18, go back to step 11e
                if(dealerScore > 21)
                    fprintf('Dealer loses!\n');
                elseif((dealerScore > 18) && (dealerScore < 22))
                else
                    flag = true;
                    counter = 4;
                    [rows, columns] = size(arrayOfCards);
                    rowVector = zeros(rows, columns);
                    rowVector = arrayOfCards;
                    while(flag)
                        fprintf('Dealer Score: %0.0f\n',dealerScore);
                        if (dealerScore < 18)
                            
                            
                            [dealerCard(counter), rowVector]= dealCard(cardsLeftFive);
                            counter = counter + 1;
                            %[dealerCard(counter),I have to create an array
                        end;
                        fprintf('Dealer drew:\n\t%s\n',dealerCard(counter).suit);
                        dealerScore = calculatescore(dealerCard);
                        if (dealerScore > 21) || size(rowVector) == 0
                            fprintf('Dealer loses!\n');
                            flag = false;
                        end;
                    end;
                end;
        end;
    end;
    %12)Determine who won
    %a)If the player's score is over 21, the dealers wins
    if (playerScore > 21)
        fprintf('Player loses!\n');
        %b)If the dealer's score is over 21, the player wins
    elseif (dealerScore > 21)
        fprintf('Dealer loses!\n');
        %c)If both are the same score, they tie
    elseif (playerScore == dealerScore)
        fprintf('It''s a tie\n');
        %d)If they're both 21 or less, determine who has the higher score, and
        %that person wins
    else
        if(playerScore > dealerScore)
            winner = 'player';
        else
            winner = 'dealer';
        end;
    end;
    %13)Print out who won
    fprintf('The winner is the %s.\n',winner);
    
    %14)Ask to play again
    %a)If they would like to play again, delete all the cards in the player
    %and dealers arrays and go back to step 1
    decision = input('Would you like to play again? (Y/N): ','s');
    
    if (strcmpi('n',decision))
        playAgain = false;
    end;
    
end;