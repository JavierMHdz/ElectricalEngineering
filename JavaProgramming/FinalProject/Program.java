//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Final Project
//ITP 109, Spring 2015
//This is the main program where
//the objects are created and user
//gives input.
//Date of creation: May 5 2015
//Last modification: April 20 2015
import java.util.Scanner;
public class Program {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		//variables
		String name = " ";
		int quarts = 0;
		String animal = " ";
		int choice = 0;
		int indexOfHuman = 0;

		Human []human = new Human[3];
		//Use the constructor with 3 parameters to create these Humans.
		human[0]= new Human ("Strigoi", 4, "A-");
		human[1]= new Human ("Muroni", 7, "AB+");
		human[2]= new Human ("Nosferatu", 5, "B+");

		System.out.println("You are a vampire. It's time for dinner."
				+ "\nPlease enter your name:");
		name = input.nextLine();

		System.out.println("How many quarts of blood do you have?");
		quarts = input.nextInt();

		System.out.println("What animal form do you take?");
		animal = input.nextLine();
		animal = input.nextLine();
		System.out.println("");
		//creating the vampire method
		Vampire vampire = new Vampire(name, quarts, animal);

		while(choice != -1){
			System.out.println("Please enter one of the following choices:"
					+ "\n 1 --> List of Viable Humans \n 2 --> Suck Blood"
					+ "\n-1 --> Quit");
			choice = input.nextInt();
			System.out.println("");

			switch(choice){
			case 1:
				System.out.println("0: " + human[0].getName() + " has " + human[0].getQuarts()
						+ " quarts of " + human[0].getBloodType() + " blood.");
				System.out.println("1: " + human[1].getName() + " has " + human[1].getQuarts()
						+ " quarts of " + human[1].getBloodType() + " blood.");
				System.out.println("2: " + human[2].getName() + " has " + human[2].getQuarts()
						+ " quarts of " + human[2].getBloodType() + " blood.");
				System.out.println("");
				break;
			case 2:
				System.out.println("You have " + vampire.getQuarts() + " quarts of blood.");
				System.out.println("Enter the index of the human to suck blood from:");
				indexOfHuman = input.nextInt();

				if (human[indexOfHuman].suckBlood() == true){
					vampire.suckBlood();
					System.out.println("You now have " + vampire.getQuarts() + " quarts of blood.");
					System.out.println(human[indexOfHuman].getName() + " now has " + human[indexOfHuman].getQuarts()
							+ " quarts of blood.");
				}
				else{
					System.out.println("You cannot suck more blood from this human.");
					System.out.println("You have " + vampire.getQuarts() + "quarts of blood.");
				}
				System.out.println("");
				break;
			case -1:
				System.out.println(vampire.getName() + " transformed back into a " + vampire.getAnimalForm() + ".");
				break;
			default:
				System.out.println("You entered an invalid option.");
				break;
			}
		}
	}

}
