import java.util.Scanner;
public class AthleteProgram {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		//creating my variables
		Athlete [] athlete;
		int size = 0;
		String name = " ";
		int yardsRan = 0;
		int choice = 0;
		int totalYards = 0;
		double averageYards = 0;
		int maxIndex = 0;
		int minIndex = 0;
		String addName = " ";
		int addNameIndex = 0;
		int addYards = 0;


		System.out.println("For how many athletes are we going to collect data?");
		size = input.nextInt();

		//size of array of athletes
		athlete = new Athlete [size];

		for (int i = 0; i<athlete.length; i++){
			System.out.println("Please enter the name of the athlete: ");
			name = input.nextLine();
			name = input.nextLine();

			System.out.println("Please enter the number of yards ran by this athlete: ");
			yardsRan = input.nextInt();

			Athlete person = new Athlete(name, yardsRan);
			athlete[i] = person;

		}
		totalYards = getTotalYards(athlete);
		averageYards = getAverageYards(athlete);
		maxIndex = getMaxIndex(athlete);
		minIndex = getMinIndex(athlete);
		while (choice != -1){
			System.out.println("1 -> Print out the total yards"
					+ "\n2 -> Print out the average yards"
					+ "\n3 -> Add yards to a specific athlete"
					+ "\n4 -> Print out the athlete with the most yards"
					+ "\n5 -> Print out the athlete with the least yards"
					+ "\n6 -> Print out the info for all the athletes"
					+ "\n-1 -> Quit");
			choice = input.nextInt();
			System.out.println("");
			if (choice == 1){
				System.out.println("Total yards are " + totalYards + ".\n");
			}
			else if (choice == 2){
				System.out.println("Average yards are " + averageYards + ".\n");
			}
			else if (choice == 3){
				//asking for the name of the athlete
				System.out.println("What is the name of the athlete that you want to add yards?");
				input.nextLine();
				addName = input.nextLine();
				System.out.println("");
				//asking how many yards you want to add
				System.out.println("How many yards do you want to add?");
				addYards = input.nextInt();

				for (int i = 0; i < athlete.length; i++){

					if (addName.equalsIgnoreCase(athlete[i].getName())){
						addNameIndex = i;
					}

				}

				athlete[addNameIndex].addYards(addYards);
				athlete[addNameIndex].display();
				System.out.println("");
			}
			else if (choice == 4){
				maxIndex = getMaxIndex(athlete);
				System.out.println("The athlete with the most yards is " + athlete[maxIndex].getName() + ".\n");
			}
			else if (choice == 5){
				minIndex = getMinIndex(athlete);
				System.out.println("The athlete with the least yards is " + athlete[minIndex].getName() + ".\n");
			}
			else if (choice == 6){
				printAthletes(athlete);
				System.out.println("");
			}
			else if (choice == -1){
				System.out.println("Goodbye!");
			}
			else {
				System.out.println("You entered an invalid number\n");	
			}
		}
	}
	public static int getTotalYards(Athlete[] athlete){
		int totalYards = 0;
		for(int i = 0; i < athlete.length; i++){
			totalYards = totalYards + athlete[i].getYardsRan();
		}
		return totalYards;
	}
	public static double getAverageYards(Athlete[]athlete){
		double averageYards = 0;
		for (int i = 0; i < athlete.length; i++){
			averageYards = averageYards + athlete[i].getYardsRan();
		}
		averageYards = averageYards/athlete.length;
		return averageYards;
	}
	public static int getMaxIndex(Athlete[] athlete){
		int maxIndex = 0;
		int playerMax = 0;
		for (int i = 0; i < athlete.length; i++){
			if (maxIndex < athlete[i].getYardsRan()){
				maxIndex = athlete[i].getYardsRan();
				playerMax = i;
			}
		}
		return playerMax;
	}
	public static int getMinIndex(Athlete[] athlete){
		int minIndex = 1000000000;
		int playerMin = 0;
		for (int i = 0; i < athlete.length; i++){
			if (minIndex > athlete[i].getYardsRan()){
				minIndex = athlete[i].getYardsRan();
				playerMin = i;
			}
		}
		return playerMin;
	}
	public static void printAthletes(Athlete[] athlete){
		for (int i = 0; i < athlete.length; i++){
			System.out.println(athlete[i].getName() + " has run " + athlete[i].getYardsRan() + " yards.");
		}
	}
}
