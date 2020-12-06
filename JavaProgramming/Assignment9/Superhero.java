//Superhero class
//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Assignment 9
//ITP 109, Spring 2015
//Superhero class with
//different methods.
//Date of creation: April 3 2015
//Last modification: April 3 2015

public class Superhero {
	private String name = " "; 						// name of the hero
	private int healthPoints = 0; 					// hero's health points
	private int attackValue = 0;

	public static final int MAX_HEALTHPOINTS = 100;	//constant of max health
	public static final int MAX_ATTACKVALUE = 20;	//constant of max attack value

	public Superhero(String name) {					//initializing the variable
		this.name = name; 							// this.name = name;
		healthPoints = MAX_HEALTHPOINTS;			//setting the maximum healthpoints
		attackValue = ((int) (Math.random() * MAX_ATTACKVALUE)) + 1; //random attackValue
	}

	//set functions
	public void setName(String name){
		this.name = name;
	}
	public void setHealthPoints(int healthPoints) {
		this.healthPoints = healthPoints;
	}
	public void setAttackValue(int attackValue){
		this.attackValue = attackValue;
	}

	//get functions
	public String getName() {
		return this.name;
	}
	public int getHealthPoints(){
		return this.healthPoints;
	}
	public int getAttackValue(){
		return this.attackValue;
	}

	public void displayHero(){					//display the status of the superhero
		System.out.println("Name: " + name);
		System.out.println("Health Points: " + healthPoints);
		System.out.println("Attack Value: " + attackValue);
	}
	
	public boolean isInjured(){					//to keep track if the hero has been injured
		if (healthPoints <= 0){
			return true;
		}
		else {
			return false;
		}
	}

	public void loseHealthPoints(int damage){	//to keep track of the damage and the changing healthPoints	
		healthPoints = healthPoints - damage;
	}
}
