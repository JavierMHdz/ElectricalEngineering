//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Assignment 2
//ITP 109, Spring 2015
//My program asks for input from the user,
//four words and one number, and outputs
//a funny story to the user.
//Date of creation: January 25 2015
//Last modification: January 26 2015
import java.util.Scanner;
public class MadLibs {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		//First, declare variable
		String animal = " ";
		String adjective = " ";
		String color = " ";
		String sport = " ";
		String message = " ";
		int age = 0;
		
		//Now, get input from the user
		System.out.println("Please enter your favorite animal: ");
		animal = input.next();
		System.out.println("Please enter an adjective: ");
		adjective = input.next();
		System.out.println("Please enter your favorite color: ");
		color = input.next();
		System.out.println("Please enter your favorite sport: ");
		sport = input.next();
		System.out.println("Please enter your age: ");
		age = input.nextInt();
		
		//Output the story to the user
		message = "My best friend has a \"" + color + "\" car. "
				+ "\nHis car is very \"" + adjective + "\" and is a gift \n"
				+ "from his \"" + animal + "\" who loves to play \"" + sport 
				+ "\" \nwith my grandma. My grandma is \""+ age + "\" years "
				+ "\nold and she has beautiful \"" + color + "\" eyes.";
		System.out.println(message);
	}

}
