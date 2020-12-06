//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Assignment 7
//ITP 109, Spring 2015
//My program is a rock, paper,
//scissors game. It keeps track
//if the user or the computer won.
//The program uses different methods.
//Date of creation: March 19 2015
//Last modification: March 19 2015
import java.util.Scanner;

public class RockPaperScissors {

	public static void main(String[] args) {

		String userInput = " ";
		int computerNumber = 0;
		int playerNumber = 0;
		int winner = 0;
		int counterComputer = 0;
		int counterPlayer = 0;
		int counterTie = 0;
		boolean userChoice = true;

		while (true){

			displayMenu(); 							//displaying the menu to the user
			computerNumber = getComputerChoice(); 	//get random number for the computer
			playerNumber = getPlayerChoice(); 		//get decision from the user 

			if (playerNumber == 0){						//display to user what was his choice
				System.out.println("You chose Rock.");
			}
			else if (playerNumber == 1){
				System.out.println("You chose Paper");
			}
			else {
				System.out.println("You chose Scissors.");
			}

			if (computerNumber == 0){						//display to user what was the computer's choice
				System.out.println("The computer chose Rock.");
			}
			else if (computerNumber == 1){
				System.out.println("The computer chose Paper.");
			}
			else{
				System.out.println("The computer chose Scissors.");
			}

			winner = playRound(computerNumber, playerNumber);	//who won the game

			if (winner == -1){
				counterComputer = counterComputer + 1;			//it keeps track how many times the computer has won
				System.out.println("Computer wins!");
			}
			else if (winner == 1){
				counterPlayer = counterPlayer + 1;				//it keeps track how many times the player has won
				System.out.println("You win!");
			}
			else {
				counterTie = counterTie + 1;	//it keeps track how many times the player has tied with the computer
				System.out.println("You tie!");
			}

			userChoice = continueGame();		//this tells if the user wants to keep on playing

			if (userChoice == false){	//if the user wants to stop playing, it will display the results before exiting
				System.out.println("You won " + counterPlayer + " game(s)."		//this displays the results of the game
						+ "\nThe computer won " + counterComputer + " game(s)."
						+ "\nYou tied with the computer " + counterTie + " times(s)."
						+ "\n\nThanks for playing!");
				break;
			}
		}

	}

	public static void displayMenu(){	//it displays the menu to the player
		System.out.println("Welcome! Let's play rock, paper, scissors."
				+ " The rules of the game are: \n Rock smashes scissors"
				+ "\n Scissors cut paper \n Paper covers rock"
				+ "\n If both the choices are the same, it's a tie");
	}
	
	public static int getComputerChoice(){	//randomly generate the computer's choice
		int number = 0;
		number = ((int)(Math.random()*3));
		return number;
	}
	
	public static int getPlayerChoice(){	//get the player's choice
		Scanner input = new Scanner(System.in);
		int number = 0;
		while (true){
			System.out.println("Please choose (0) for rock, (1) for paper or (2) for scissors");
			number = input.nextInt();

			if (number >= 0 && number <= 2){
				break;
			}
		}
		return number;
	}
	
	public static int playRound(int computerChoice, int playerChoice){	//compare the values and check who won or if it is a tie
		int number = 0; 
		if (computerChoice > playerChoice || (computerChoice == 0 && playerChoice ==2)){
			number = -1;
		}
		else if(computerChoice < playerChoice || (computerChoice == 2 && playerChoice == 0)){
			number = 1;
		}
		else {
			number  = 0;
		}
		return number;
	}
	
	public static boolean continueGame(){		//ask the player if the he/she wants to play again.
		Scanner input = new Scanner(System.in);
		boolean value = true;
		String userChoice = " ";
		while (true){
			System.out.println("Do you want to continue playing? Enter (Y)"
					+ " for Yes or (N) for No.");
			userChoice = input.nextLine();
			if (userChoice.equalsIgnoreCase("y")){
				value = true;
				break;
			}
			else if (userChoice.equalsIgnoreCase("n")){
				value = false;
				break;
			}
			else{
				System.out.println("You entered an invalid answer.");
			}
		}
		return value;
	}
}
