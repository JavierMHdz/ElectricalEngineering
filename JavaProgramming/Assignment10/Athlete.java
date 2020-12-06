//Athlete Class
public class Athlete {
	private String name;
	private int yardsRan;

	//default constructor
	public Athlete(){
		this.name = " ";
		this.yardsRan = -1;
	}

	//overloaded constructor
	public Athlete(String name){
		this.name = name;
	}

	//overloaded constructor
	public Athlete(String name, int yardsRan){
		this.name = name;
		this.yardsRan = yardsRan;
	}

	//mutators
	public void setName(String name){
		this.name = name;
	}
	public void setYardsRan(int yardsRan){
		this.yardsRan = yardsRan;
	}

	//accessors
	public String getName(){
		return this.name;
	}
	public int getYardsRan(){
		return this.yardsRan;
	}

	//updating the current status of the yards ran
	public void addYards(int yardsRan){
		this.yardsRan += yardsRan;
	}

	//display message for user
	public void display(){
		System.out.println(name + " has run " + yardsRan + " yards.");
	}
}
