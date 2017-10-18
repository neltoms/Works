// TheRace.java
// This program simulated the race between the Hare and the Tortoise.  The movements of the 
// players is based on a probabilistic distribution of their individual movements.  These movements
// will either prompt the player forward, backward, or remain in the same position with each 'tick of the
// clock' (or iteration of the while loop).  Once a player has reached positon 70, the winner will be
// announced.


import java.security.SecureRandom;


public class TheRace{

	// create secure random number generator for use in method rollDice
	private static final SecureRandom movements = new SecureRandom();

	public static void main(String[] args){
		
		// Create instances for the two players
		Hare myHare = new Hare();
		Tortoise myTortoise = new Tortoise();

		System.out.println();
		System.out.println("BANG!!!");
		System.out.println("AND THEY'RE OFF!!!");
		System.out.println();
		

		// The while loop will iterate as 'the tick of the clock' as well
		// as the amount of forward steps taken by the participants

		while((myTortoise.getPosition() | myHare.getPosition()) <= 70){
			// the move variable is a random number generator assigned by the
			// function randMove() with values from 1-10.
			int move = randMove();
			// A switch statement is used to assign particular probabilities to 
			// the a players movements
			switch (move){
				case(1):
					myHare.sleep();
					myTortoise.fastPlod();
					break;
				case(2):
					myHare.sleep();
					myTortoise.fastPlod();
					break;
				case(3):
					myHare.bigHop();
					myTortoise.fastPlod();
					break;
				case(4):
					myHare.bigHop();
					myTortoise.fastPlod();
					break;
				case(5):
					myHare.smallHop();
					myTortoise.fastPlod();
					break;
				case(6):
					myHare.smallHop();
					myTortoise.slip();
					break;
				case(7):
					myHare.smallHop();
					myTortoise.slip();
					break;
				case(8):
					myHare.bigSlip();
					myTortoise.slowPlod();
					break;
				case(9):
					myHare.smallSlip();
					myTortoise.slowPlod();
					break;
				case(10):
					myHare.smallSlip();
					myTortoise.slowPlod();
					break;
			}

		// If players are in the same position, the Tortoise will bite the Hare
		if(myHare.getPosition() == myTortoise.getPosition()){
			System.out.print("OUCH!!");
		}
		
		// The following for loops lay out the track and label the players
		// positions
		int hposition = myHare.getPosition();
		for(int i = 0; i < hposition; i++){
			System.out.print('_');
		}
		
		System.out.print('H');
	
		for(int i = hposition +1; i < 70; i++){
			System.out.print('_');
			}
		System.out.println();

		int tposition = myTortoise.getPosition();
		for(int i = 0; i < tposition; i++){
			System.out.print('_');
		}
		
		System.out.print('T');
		
		for(int i = tposition +1; i < 70; i++){
			System.out.print('_');
			}
		System.out.println();
	
		// Once the winning player has reached the finish line, the winner
		// will be announced
		if((myTortoise.getPosition() | myHare.getPosition()) >= 70){
			if (tposition >= hposition){
				System.out.println("TORTOISE WINS!!!");
				System.out.printf("Hare position is: %d%n", hposition);
				System.out.printf("Tortoise position is: %d%n ", tposition);
				System.out.println();
			}
			else{
				System.out.println("HARE WINS!!!");
				System.out.printf("Hare position is: %d%n", hposition);
				System.out.printf("Tortoise position is: %d%n ", tposition);
				System.out.println();
			}
		}
	}
}	
	
	// pick random move positions
	public static int randMove(){
		int move = 1 + movements.nextInt(10);
		return move;

	}

}




