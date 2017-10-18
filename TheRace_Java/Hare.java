// Hare.java: Class for the movements of the Hare


public class Hare{

	private int position;

	public Hare(){
		position = 1;
	}

	public void setPosition(int set){
		position = set;
	}

	public int getPosition(){
		return position;
	}

	public void sleep(){
		position = position;
	}

	public void bigHop(){
		position += 9;
	}

	public void bigSlip(){
		position -= 12;
	}

	public void smallHop(){
		position += 1;
	}

	public void smallSlip(){
		position -= 2;
	}


}
