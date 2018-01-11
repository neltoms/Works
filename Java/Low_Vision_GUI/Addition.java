

import javax.swing.JOptionPane;

public class Addition{
		public static void main(String[] args){
				String first = JOptionPane.showInputDialog("Enter first integer");
				String second = JOptionPane.showInputDialog("Enter second integer");

				int num1 = Integer.parseInt(first);
				int num2 = Integer.parseInt(second);

				int sum = num1 + num2;

				JOptionPane.showMessageDialog(null, "The sum is " + sum,
							   "Sum of Two Integers", JOptionPane.PLAIN_MESSAGE);
		}
}
