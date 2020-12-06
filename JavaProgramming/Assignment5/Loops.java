//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Assignment 5
//ITP 109, Spring 2015
//My program is a menu calculator.
//If the user enters a list of integers,
//it will print out the largest number.
//It can also calculate the factorial of
//the integer the user entered.
//The program was written with different
//types of loops.
//Date of creation: February 13 2015
//Last modification: February 13 2015
import java.util.Scanner;
public class Loops {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int choice = 0;				//declaring all my variables

		while (choice != -1){  //the condition will end the program if the user enters -1

			int number = 0;
			int large = 0;
			int numberFactorial = 0;
			int i = 0;
			long factorial = 1;  //factorial = 1 because I will multiply this value with the counter "i"

			System.out.println("Please enter one of the following choices:"  //the user chooses the calculation he desires
					+ "\n 1 --> Largest Number \n 2 --> Factorials \n-1 --> Quit");
			choice=input.nextInt();

			switch(choice){   //the condition sends you to the different cases
			case 1:
				System.out.println("Input an integer greater than or equal to 0 or -1 to quit:");
				while (number != -1){
					number = input.nextInt();	//creating the list of integers
					if (number > large){
						large = number;		//storing the largest value
					}
				}
				System.out.println("The Largest Number is " + large + " \n"); //printing out the largest value
				break;
			case 2:
				do {
					System.out.println("Input an integer to calculate the factorial:");
					numberFactorial = input.nextInt();

					if (numberFactorial < 0){
						System.out.println("Error! Invalid Input! \n"); //the user entered a negative integer
					}
					else if (numberFactorial == 0){
						System.out.println("The factorial of 0 is 1 \n"); //the user entered 0 to calculate its factorial
					}
					else {
						for (i=1 ; i <= numberFactorial; i++){
							factorial = i*factorial; //multiplying the counter times the product of the previous factorial
						}
						System.out.println("The factorial of " + numberFactorial + " is " + factorial + "\n");
					}
				} while (numberFactorial < 0); //the program will repeat if the user enters an invalid number
				break;

			case -1:
				System.out.println("Goodbye and have a great day!"); //the user wants to quit the program
				break;

			default:
				System.out.println("You entered an invalid number \n"); //the user entered an invalid number
				break;													//the program will repeat itself

			}
		}
	}
}
