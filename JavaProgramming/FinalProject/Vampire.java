//Javier Jesus Macossay-Hernandez
//macossay@usc.edu
//Final Project
//ITP 109, Spring 2015
//This is the Vampire class,
//which is a child class.
//Date of creation: April 20 2015
//Last modification: April 20 2015
public class Vampire extends Being{
	
	//instance variable
	private String animalForm;
	
	//constructor
	public Vampire(String name, int quarts, String animalForm){
		super(name, quarts);
		this.animalForm = animalForm;
	}

	public String getAnimalForm() {
		return animalForm;
	}

	public void setAnimalForm(String animalForm) {
		this.animalForm = animalForm;
	}
	
	public void suckBlood(){
		int num = 1;
		increaseQuarts(num);
	}
}
