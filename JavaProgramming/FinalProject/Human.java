//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Final Project
//ITP 109, Spring 2015
//This is the Human class,
//which is a child class.
//Date of creation: May 5 2015
//Last modification: April 20 2015
public class Human extends Being{

	//instance variables
	private String bloodType;	//to hold the human's type of blood
	
	//constructor
	public Human(String name, int quarts, String bloodType){
		super(name, quarts);
		this.bloodType = bloodType;
	}

	public String getBloodType() {
		return bloodType;
	}

	public void setBloodType(String bloodType) {
		this.bloodType = bloodType;
	}
	
	public boolean suckBlood(){
		int num =1;
		if (decreaseQuarts(num) == true){
			return true;
		}
		else{
			return false;
		}
	}
}
