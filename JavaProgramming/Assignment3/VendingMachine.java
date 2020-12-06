//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Assignment 3
//ITP 109, Spring 2015
//My program is a simulation of a Vending Machine
//that asks the user to enter the price of the item
//being bought (between 25 and 100 cents).
//Then, it dispenses the user's change
//in the largest possible units.
//The program repeats itself if the user enters
//an invalid number (a number greater than 100
//or smaller than 25).
//Date of creation: February 5 2015
//Last modification: February 5 2015
import java.util.Scanner;
public class VendingMachine {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		//declaring my constant values, these are the values of my coins
		int dollar = 100;
		int quarter = 25;
		int dime = 10;
		int nickel = 5;
		int penny = 1;

		//declaring my variables
		int price = 0;
		int change = 0;
		int numberQuarters = 0;
		int remainingQuarters = 0;
		int numberDimes = 0;
		int remainingDimes = 0;
		int numberNickels = 0 ;
		int remainingNickels = 0;
		int numberPennies = 0;

		//printing out welcome message and getting input from users
		//the program repeats itself if the user enters an invalid number,
		//such as a number greater than 100 or smaller than 25. 
		while(true){
			System.out.println("Vending Machine \nEnter the price of an item in cents (25 - 100):");
			price = input.nextInt();

			if (price > dollar){
				System.out.println("You entered an invalid number. \n"); //If the user entered a number greater than 100.
			}

			else if (price == dollar){ 								//If the user entered a number equal to 100.
				System.out.println("You bought an item for " + price + " cents and gave me a dollar. \n"
						+ "Therefore, you do not have change.");
				System.out.println("\nThank you for buying food from the best Vending Machine in the world!");
				break;
			}

			else if (price < 25){
				System.out.println("You entered an invalid number. \n"); //If the user entered a number less than 25
			}

			else {
				change = dollar-price; //calculating the change

				numberQuarters = change/quarter; //To get the number of quarters
				remainingQuarters = change%quarter; //To get the remaining amount of money

				numberDimes = remainingQuarters/dime; //To get the number of dimes
				remainingDimes = remainingQuarters%dime; //To get the remaining amount of money

				numberNickels = remainingDimes/nickel; //To get the number of nickels
				remainingNickels = remainingDimes%nickel; //To get the remaining amount of money

				numberPennies = remainingNickels/penny; //To get the number of pennies. I know it is redundant to divide by 1,
				//but we were asked to use the constant penny = 1

				System.out.println("You bought an item for " + price + " cents and gave me a dollar.");
				System.out.println("Your change (" + change + ") is"); //Telling the user his total change
				System.out.println("quarters: " + numberQuarters);
				System.out.println("dimes: " + numberDimes);
				System.out.println("nickels: " + numberNickels);
				System.out.println("pennies: " + numberPennies);
				System.out.println("\nThank you for buying food from the best Vending Machine in the world!");
				break;
			}
		}
	}

}
