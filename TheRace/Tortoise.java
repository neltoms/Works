// Tortoise.java: The class for the movements of the Tortoise


public class Tortoise{

	private int position;

	public Tortoise(){
		position = 1;
	}
	
	public void setPosition(int set){
		position = set;
	}

	public int getPosition(){
		return position;
	}

	public void fastPlod(){
		position += 3;
	}

	public void slip(){
		position -= 6;
	}

	public void slowPlod(){
		position +=1;
	}
}
