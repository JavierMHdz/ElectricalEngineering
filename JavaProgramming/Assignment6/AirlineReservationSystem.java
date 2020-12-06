//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Assignment 6
//ITP 109, Spring 2015
//My program is an Airline Reservation
//System, it lets people reserve
//seats. It prints the seat
//map and boarding pass. 
//Date of creation: March 4 2015
//Last modification: March 4 2015
import java.util.Scanner;
public class AirlineReservationSystem {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String [] seats = new String [10]; //declaring my array
		final int TOTAL_SEATS = 10;        //declaring my constant
		int choice = 0;					   //declaring my variables
		int i = 0;
		String name = " ";
		int option = 0;
		int seatNumber = 0;
		String findSeat = " ";
		int seatClass = 0;
		boolean match = false;
		int k = 0;
		for (int j = 0; j < TOTAL_SEATS; j++){
			seats[j] = "Empty";					//initializing all the elements of my array
		}

		while (choice != -1){	//exit the program when the user enters -1
			System.out.println("Welcome to the Airline Reservation System. \n" 
					+ "1: Assign Seat. \n2: Print Seat Map. \n3: Print Boarding Pass."
					+ "\n-1: Quit.");
			choice = input.nextInt(); //store user's input

			switch (choice){
			case 1:
				System.out.println("Type 1 for First Class or Type 2 for Economy"); //asking for the type of class
				seatClass = input.nextInt();

				if (seatClass == 1){
					System.out.println("What seat do you want? (1-4)");
					i = input.nextInt() - 1; //fitting the number into the array size
					while (i<4){
						if (seats[i].equals("Empty")){ //store the name of the person in the array element
							System.out.println("Please enter your name:");
							name = input.nextLine();
							name = input.nextLine();
							seats[i]= name;
							System.out.println("");
						}

						else { 						   //if the seat is not "Empty"

							if(!seats[0].equals("Empty") && !seats[1].equals("Empty") && !seats[2].equals("Empty") 
									&& !seats[3].equals("Empty") && !seats[4].equals("Empty") && !seats[5].equals
									("Empty") && !seats[6].equals("Empty") && !seats[7].equals("Empty") &&
									!seats[8].equals("Empty") && !seats[9].equals("Empty")){
								System.out.println("Next flight leaves in 3 hours. \n"); //the plane is full
							}
							else if (!seats[0].equals("Empty") && !seats[1].equals("Empty") && !seats[2].equals("Empty") 
									&& !seats[3].equals("Empty")){
								System.out.println("The section is full, please reseve in the second class. \n"); //the section is full
							}
							else{
								System.out.println("Seat " + (i+1) + " is taken.\n");
							}

						}
						break;
					}
				}
				else if (seatClass ==2){
					System.out.println("What seat do you want? (5-10)");
					i = input.nextInt() - 1; //fitting the number into the array size
					while (i>=4){
						if (seats[i].equals("Empty")){ //store the name of the person in the array element
							System.out.println("Please enter your name:");
							name = input.nextLine();
							name = input.nextLine();
							seats[i]= name;
							System.out.println("");
						}

						else {							//if the seat is not "Empty"
							
							if (!seats[0].equals("Empty") && !seats[1].equals("Empty") && !seats[2].equals("Empty") 
									&& !seats[3].equals("Empty") && !seats[4].equals("Empty") && !seats[5].equals
									("Empty") && !seats[6].equals("Empty") && !seats[7].equals("Empty") &&
									!seats[8].equals("Empty") && !seats[9].equals("Empty")){
								System.out.println("Next flight leaves in 3 hours. \n"); //the plane is full
							}
							else if (!seats[4].equals("Empty") && !seats[5].equals("Empty")
									&& !seats[6].equals("Empty") && !seats[7].equals("Empty") && !seats[8].equals("Empty")
									&& !seats[9].equals("Empty")){
								System.out.println("The section is full, please reseve in the first class. \n"); //the section is full
							}
							else {
								System.out.println("Seat " + (i+1) + " is taken.\n");
							}
						}
						break;
					}
				}
				else {
					System.out.println("You entered an invalid number. \n"); //the user entered an invalid number
				}


				break;

			case 2:
				for (int j = 0; j < TOTAL_SEATS; j++){
					System.out.println("Seat " + (j+1) + ": " + seats[j]);  //Print seat map with a for loop
				}
				System.out.println();
				break;
			case 3:
				System.out.println("Type 1 to get Boarding Pass by seat number"		
						+ "\nType 2 to get Boarding Pass by name");
				option = input.nextInt();
				if (option == 1){ 	//print boarding pass by seat number
					System.out.println("Please enter seat number: ");
					seatNumber = input.nextInt();
					seatNumber = seatNumber -1;		//fitting the number into the array size

					for(int e = 1; e <= 75; e++) { 	//giving a nice format to the boarding pass
						System.out.print("*"); 
					} 

					System.out.println("\n*\t" + seats[seatNumber]
							+ "\n*\n*\tSeat: " + (seatNumber+1)
							+ "\n*\n*\tSection: " + seatClass);
					for(int c = 1; c <= 75; c++) { 
						System.out.print("*"); 
					}
					System.out.println("\n");
					if(seats[seatNumber].equals("Empty")){
						System.out.println("No seat is empty. \n");
						break;
					}
				}
				else if (option ==2){	//print boarding pass by name
					System.out.println("Please enter the name:");
					findSeat = input.nextLine();
					findSeat = input.nextLine();	//name of the passenger

					for (int d = 0; d < seats.length; d++){

						if (findSeat.equalsIgnoreCase(seats[d])){
							match = true; //finding if the name of the passenger is in the array
							k = d;
						}

					}

					if (match == true){
						for(int e = 1; e <= 75; e++) {  //printing out the boarding pass if the name is found
							System.out.print("*"); 
						} 
						System.out.println("\n*\t" + seats[k]
								+ "\n*\n*\tSeat: " + (k+1)
								+ "\n*\n*\tSection: " + seatClass);
						for(int c = 1; c <= 75; c++) { 
							System.out.print("*"); 
						}
						System.out.println("\n");
					}
					else{ 							//the name was not found
						System.out.println("No passenger with that information could be found. \n");
						break;
					}			
				}
				else{
					System.out.println("You entered an invalid number. \n"); //the user entered an invalid number
				}
				break;
			case -1:
				System.out.println("Goodbye and have a great day!"); //the user wants to quit the program
				break;
			default:
				System.out.println("You entered an invalid number. \n"); //the user entered an invalid number
				break;

			}
		}
	}

}
