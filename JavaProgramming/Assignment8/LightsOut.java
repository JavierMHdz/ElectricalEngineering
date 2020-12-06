import java.util.Scanner;
import java.util.Random;
public class LightsOut {
	public static boolean ON = true;
	public static boolean OFF = false;

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		Random ran = new Random();
		int numLights = 0;
		int userInput = 0;
		numLights = getNumLights();
		boolean[] lights = new boolean [numLights];
		
		while (userInput != -1){
		for (int counter = 0; counter < lights.length; counter++){
			boolean myLight1 = ran.nextBoolean();
			lights[counter] = myLight1;
			System.out.println(lights[counter]);
		}
		printLights(lights);
		userInput = getLightToChange(numLights);
		changeLights(lights, userInput);
		checkWin(lights);
		break;
		}

	}

	public static int getNumLights(){
		Scanner input = new Scanner(System.in);
		int number = 0;
		System.out.println("How long you want your game to be?");
		number = input.nextInt();
		return number;

	}

	public static void printLights(boolean [] lights){

		//Print row of Lights
		for(int i = 0; i < lights.length; i++){
			System.out.print("|"); //opening bar
			if(lights[i] == ON){			// you must have defined boolean constants ON and OFF
				System.out.print("****"); // Print on light
			}
			else{
				System.out.print("    "); //Print Off light
			}
		}
		System.out.println("|"); //Closing bar and skip to next line

		//Print numbers under lights
		for(int i = 0; i < lights.length; i++){ //print light numbers
			if(i < 10){ // two spaces for single digit numbers
				System.out.print("  " + i + "  ");
			}
			else{
				System.out.print("  " + i + " "); 
			}
		}
		System.out.println("");
	}

	public static int getLightToChange(int number){
		Scanner input = new Scanner(System.in);
		int userInput = 0;
		while (true){
			System.out.println("\nWhich light would you like to choose? \nEnter -1 to quit the program.");
			userInput = input.nextInt();
			if (userInput >= number && userInput <= number){
				System.out.println("Thank you");
			}
			else if (userInput == -1){
				System.out.println("Goodbye");
				break;
			}
			else {
				System.out.println("You entered an invalid number");
			}
		}
		return userInput;
	}
	public static void changeLights(boolean [] arrayLights, int numberLightChange){
		Scanner input = new Scanner(System.in);
		int lightNum = 0;
		System.out.println("\nPlease enter 1 if you want to turn on the lights"
				+ "or 0 if you want to turn off the lights");
		lightNum = input.nextInt();

		if (lightNum == 1){
			arrayLights[numberLightChange] = true;
		}
		else {
			arrayLights[numberLightChange] = false;
		}
	}
	public static boolean checkWin (boolean [] arrayLights2){
		boolean state = OFF;
		for (int i = 0; i < arrayLights2.length; i++){
			state = arrayLights2[i];
			if (state == OFF){
				state = OFF;
			}
			else{
				state = ON;
				break;
			}
		}

		return state;
	}
}
