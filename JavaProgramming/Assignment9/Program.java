//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Assignment 9
//ITP 109, Spring 2015
//This is a main method that uses
//the Superhero class. It will
//create an automated videogame
//and print out who won.
//Date of creation: April 3 2015
//Last modification: April 3 2015
import java.util.Scanner;

public class Program {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		//declaring my variables with their default value
		String playerOneName = " ";
		String playerTwoName = " ";
		
		//get input from user
		System.out.println("Enter superhero #1's name:");
		playerOneName = input.nextLine();

		System.out.println("Enter superhero #2's name:");
		playerTwoName = input.nextLine();
		
		//create the objects using Superhero class
		Superhero player1 = new Superhero (playerOneName);
		Superhero player2 = new Superhero (playerTwoName);
		
		//display initial values
		System.out.println("\nHEROES");
		player1.displayHero();
		player2.displayHero();
		System.out.println("\nFIGHT!\n");

		int i = 1; //counter to keep track of number of rounds
		
		//run the whilee loop until any of the player are injured
		while (player1.isInjured() != true && player2.isInjured() != true){
			
			System.out.println("====== Round " + i + "======");
			
			//lose points according to the attack value of the other Superhero
			player1.loseHealthPoints(player2.getAttackValue());
			player2.loseHealthPoints(player1.getAttackValue());
			
			//display Superhero's current status
			player1.displayHero();
			player2.displayHero();
			
			i++;
			System.out.println("");		//just to keep a nice format
		}
		//if it is a tie, both Superheros are injured
		if (player1.isInjured()==true && player2.isInjured()==true){
			System.out.println("It is a tie!");
		}
		//if player 1 is injured
		else if (player1.isInjured()==true){
			System.out.println(player2.getName() + " won!");
		}
		//if player 2 is injured
		else{
			System.out.println(player1.getName() + " won!");
		}
	}
}

