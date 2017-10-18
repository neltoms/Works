// Problem 3.16 HeartRateTest
import java.util.Calendar;
import java.util.Scanner;
import java.util.Date;
import java.util.*;
import java.util.GregorianCalendar;
import java.lang.Math.*;
import javax.swing.JOptionPane;
import java.io.InputStream;
import java.util.concurrent.TimeUnit;


public class HeartRateTest
{
	static String answer;
	static int year, month, day, e;

	public static void main(String[] args)
	{
		String client;
		

		Scanner keyboard = new Scanner(System.in);
		Calendar cal = Calendar.getInstance();
		
	while(true){
		System.out.print("\nWould You Like To Get Your Heartrate Info (Y/N)? ");
			Scanner ans = new Scanner(System.in);
			answer = ans.nextLine();
			if(answer.equalsIgnoreCase("Y")){
				while(true){
					System.out.printf("Please enter your first name only: ");
					try{
						Thread.sleep(1000);
					}
					catch(InterruptedException ex){
						Thread.currentThread().interrupt();
					}
					client = keyboard.nextLine();
					if (! client.matches("[a-zA-Z]+")){ // only letters are allowed for name
						JOptionPane.showMessageDialog(null, "Name has to be letters");
						System.out.println("Please try again...");
						continue;
					} 
					else {
						break;
					}
				}

				while(true){
					try{
						System.out.printf("Please enter year of birth (YYYY): ");
						year = keyboard.nextInt(); 
						if (year > 2017){ 				// the year has to be less than the current year
							JOptionPane.showMessageDialog(null, "You cannot be born in the future...duh!");
							System.out.println("Please try again...");
							continue;
						} 
						break;
					} 									// the date format must be entered (YYYY)
					catch(InputMismatchException | NumberFormatException ex){
						JOptionPane.showMessageDialog(null, "I said a number in the format (YYYY)");
						System.out.println("Please try again...");
						keyboard.next();
						continue;
					}
				}
				
				while(true){
					try{
						System.out.printf("Please enter month of birth as an integer (MM): ");
						month = keyboard.nextInt();
						if (month > 12){ 				// the month input cannot be greater than 12
							JOptionPane.showMessageDialog(null, "The month cannot be greater than 12!");
							System.out.println("Please try again...");
							continue;
						}
						break;
					} 									// only integers can be entered for the month
					catch(InputMismatchException | NumberFormatException ex){
						JOptionPane.showMessageDialog(null, "I said an INTEGER in the format (MM)");
						System.out.println("Please try again...");
						keyboard.next();
						continue;	
					}
				}
					
				while(true){
					try{
						System.out.printf("Please enter date of birth as an integer (DD): ");
						day = keyboard.nextInt(); 
						if (day > 31){ 					// there cannot be more than 31 days in a month
							JOptionPane.showMessageDialog(null, "There cannot be more than 31 days in the month");
							System.out.println("Please try again...");
							continue;
						}
						break;
					} 									// the date must be a number
					catch(InputMismatchException | NumberFormatException ex){
						JOptionPane.showMessageDialog(null, "I said an integer in the format (DD)");
						System.out.println("Please try again...");
						keyboard.next();
						continue;
					}
				}
			
					HeartRates client1 = new HeartRates(client, year, month, day);
					
					System.out.println();
					System.out.println("*****************************************************");
					System.out.println("*                                                   *");
					System.out.printf("* The current date is: %tc * %n", cal.getTime());
					System.out.println("*                                                   *");
					System.out.println("*****************************************************");
					System.out.printf("%s's age is: %d%n", client1.getName(), client1.calcAge());
					System.out.printf("%s's DOB is: %tD %n", client1.getName(), client1.getDob()); 
					System.out.println();
					System.out.printf("%s's max heart rate is: %.2f%n", client1.getName(), client1.maxRate());
					System.out.printf("%s's target heartrate is: ", client1.getName()); client1.tarRate();
				}
			else if(answer.equalsIgnoreCase("N")){
				System.out.printf("Thank You!! See you next time! %n%n");
				break;
			}
			else{
				System.out.printf("Try again with (Y/N) only!%n%n");
			}

		}
	}
}	


