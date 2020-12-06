//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Assignment 4
//ITP 109, Spring 2015
//My program offers the use several
//options to choose.
//Once the user selects and option,
//it will will run until the user wants to exit.
//Date of creation: February 11 2015
//Last modification: February 13 2015
import java.util.Scanner;
public class MathEquations {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		double temperature = 0;    					//declaring all my variables
		double convertedTemperature = 0;
		double numberOne = 0;
		double numberTwo = 0;
		double numberThree = 0;
		double average  = 0;
		double choiceThreeNumberOne = 0;
		double choiceThreeNumberTwo = 0;
		double toleranceOne = 0;
		double toleranceTwo = 0;
		int choice = 0;
		String unitsOfTemperature = " ";

		while (choice != 4){   //the program will stop running when the user enters the number 4

			System.out.println("\nWelcome to the Math Equations Calculator. \n"
					+ "To convert temperature, please type in \"1\". \n"
					+ "To average three numbers, please type in \"2\". \n"
					+ "To compare to numbers, please type in \"3\". \n"
					+ "To exit the calculator, please type in \"4\"");
			choice = input.nextInt();

			switch (choice){         //I am using a switch statement to know which option the user wants

			case 1:
				System.out.println("Choice 1: Temperature Converter \n"
						+ "Please enter the temperature");
				temperature = input.nextDouble();             //getting an integer value

				System.out.println("Please enter the units of temperature: C (Celsius) or F (Fahrenheit).");
				unitsOfTemperature = input.next();    //getting the units

				if (unitsOfTemperature.equalsIgnoreCase("c")){  //changing temperature
					convertedTemperature = (9*(temperature)/5)+32;
					System.out.println("The Converted Temperature is "
							+ convertedTemperature + " F");
				}
				else if (unitsOfTemperature.equalsIgnoreCase("f")){
					convertedTemperature = 5*(temperature-32)/9;
					System.out.println("The Converted Temperature is "
							+ convertedTemperature + " C");
				}
				else {
					System.out.println("You entered an invalid unit of temperature");
				}
				break;

			case 2:
				System.out.println("Choice 2: Average Three Numbers \n"
						+ "Please enter three numbers (press enter after every number)");
				numberOne = input.nextDouble();
				numberTwo = input.nextDouble();
				numberThree = input.nextDouble();

				average = (numberOne+numberTwo+numberThree)/3;         //math calculations to get the average
				System.out.println("The three numbers you entered are "
						+ numberOne + ", " + numberTwo + ", and " +numberThree
						+ "\nThe average of those numbers is " + average);
				break;

			case 3:
				System.out.println("Choice 3: Greater Than, Less Than, or Approximately Equal to \n"
						+ "Please enter two numbers (press enter after every number)");
				choiceThreeNumberOne = input.nextDouble();    //getting input from the user
				choiceThreeNumberTwo = input.nextDouble();

				toleranceOne = choiceThreeNumberOne + 0.1;    //setting the tolerance
				toleranceTwo = choiceThreeNumberOne - 0.1;

				if (choiceThreeNumberTwo < toleranceOne && choiceThreeNumberTwo > toleranceTwo){
					System.out.println("Both numbers are approximately equal");
				}
				else if (choiceThreeNumberTwo > choiceThreeNumberOne){
					System.out.println("The second number (" +choiceThreeNumberTwo+
							") is greater than the first number (" + choiceThreeNumberOne+")");
				}
				else {
					System.out.println("The second number (" +choiceThreeNumberTwo+
							") is less than the first number (" +choiceThreeNumberOne+")");
				}
				break;

			case 4:
				System.out.println("Goodbye!");
				break;

			default:
				System.out.println("You entered an invalid number.");
				break;
			}
		}
	}

}
