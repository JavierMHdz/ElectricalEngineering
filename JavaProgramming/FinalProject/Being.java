//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Final Project
//ITP 109, Spring 2015
//This is the Being class,
//which is the parent class.
//Date of creation: April 20 2015
//Last modification: April 20 2015
public class Being {
	
	//instance variables 
	private String name;  //beings name
	private int quarts;		//number of quarts of blood the being has
	
	//constructors
	public Being() {
		this.name = "";
		this.quarts = 0;
	}

	public Being(String name, int quarts){
		this.name =  name;
		this.quarts = quarts;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getQuarts() {
		return quarts;
	}

	public void setQuarts(int quarts) {
		if (quarts > 0){
			this.quarts = quarts;
		}
	}

	public void increaseQuarts(int num){
		this.quarts += num;
	}
	
	public boolean decreaseQuarts(int num){
		if (this.quarts >= 0){
			this.quarts -=num;
			return true;
		}
		else{
			return false;
		}
	}
}
