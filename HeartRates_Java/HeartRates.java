// Problem 3.16: HeartRates
// Author: Nel Toms September 20, 2017
//
// HeartReates.java is designed to take in from standard input, the users name year of birth (YYYY),
// month of birth (MM), and date of birth (DD). If entered correctly the output will be the current time and
// date, the users age (in years), the users date of birth (MM/DD/YYYY format), the users max heartrate,
// and the users target heartrate.  The program will continue until the user answers 'N' or 'n'.  If the
// information is entered incorrectly, the are exception errors in place to prompt the user to reenter the
// information correctly.

import java.lang.Math.*;
import java.util.Scanner;
import java.util.*;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Date;


public class HeartRates {
	private String name;
	private Date dateOfBirth;
	private double mRate;
	private double tRate;

	public HeartRates(String name, int year, int month, int day) {
		setName(name);
		setDob(year, month, day);
	
	}
	
	// method to set first and last name
	public void setName(String name) {
		this.name = name;
	}	

	public int calcAge() {
		Calendar today = Calendar.getInstance();
		Calendar birthday = new GregorianCalendar();
		birthday.setTime(dateOfBirth);

		int yearCalc = today.get(Calendar.YEAR) - birthday.get(Calendar.YEAR);

		if(today.get(Calendar.YEAR) < birthday.get(Calendar.YEAR)) {
			yearCalc = yearCalc - 1;
		}
		else if(today.get(Calendar.MONTH) == birthday.get(Calendar.MONTH) &&
				today.get(Calendar.DATE) < birthday.get(Calendar.DATE)) {
			yearCalc = yearCalc - 1;
		}
		
		return yearCalc;
	}

	// method to set date of birth
	public void setDob(int year, int month, int day) {
		assert month <= 12;
		Calendar cal = Calendar.getInstance();
		cal.set(year, month - 1, day);
		dateOfBirth = cal.getTime();
	}
	
	// method to retrieve date of birth
	public Date getDob() {
		return dateOfBirth;
	}

	// method to retrieve first and last name
	public String getName() {
		return name;
	}
	
	// method to calculte maximum heartrate
	public double maxRate()	{
		mRate = 220.00 - calcAge();
		return mRate; 
	}
	
	// method to calculate target heartrate
	public void tarRate() {
		System.out.printf("%s - %.2f%n%n", (0.50*mRate), (0.85*mRate));
	}
}
