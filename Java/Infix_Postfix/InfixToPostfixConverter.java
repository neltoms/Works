import java.awt.*;
import javax.swing.*;
import com.deitel.datastructures.*;
import java.lang.Character;
import java.util.ArrayList;

public class InfixToPostfixConverter{

		private static StringBuffer convertToPostfix(StringBuffer infix){
				StackChar stackChar = new StackChar();
				StringBuffer temp = new StringBuffer("");

				stackChar.charPush('(');
				stackChar.print();
				infix.append(')');

				for(int cIn = 0; !stackChar.isEmpty(); cIn++){
						if(Character.isDigit(infix.charAt(cIn)))
								temp.append(infix.charAt(cIn) + " ");
						else if(infix.charAt(cIn) == '(')
								stackChar.charPush('(');
						else if(isOperator(infix.charAt(cIn))){
								while(isOperator(stackChar.top()) && prec(stackChar.top(),
														infix.charAt(cIn))){
										temp.append(stackChar.charPop() + " ");
								}
								stackChar.charPush(infix.charAt(cIn));

						}
						else if(infix.charAt(cIn) == ')'){
								while(stackChar.top() != '('){
										temp.append(stackChar.charPop() + " ");
								}
								stackChar.charPop();
						}
				}
				return temp;
		}

		public static void main(String arg[]){
				
				StringBuffer infix = new StringBuffer(
				JOptionPane.showInputDialog(
						"Enter the infix expression to be converted (i.e.,:\"(7 + 8) / 12 * (-2)\")"));

				System.out.println("Your infix expression is: " + infix + "\n");

				StringBuffer postfix = convertToPostfix(infix);
				System.out.println("Your expression in postfix is:" + postfix + "\n");

				System.exit(0);
		}

		private static boolean isOperator(char o){
				if(o == '-' || o == '+' || o == '/' || o == '*' || o == '^')
						return true;
				else 
						return false;
		}
		private static boolean prec(char operator1, char operator2){
				if(operator1 == '^')
						return true;
				else if (operator1 == '^')
						return false;
				else if(operator1 == '*' || operator1 == '/')
						return true;
				else if(operator1 == '-' || operator1 == '+')

				if(operator2 == '*' || operator2 == '/')
						return false;
				else
						return true;
				return false;

		}
}
/*
class Stack<T>{
		public int size = 0;
		public Stack<T> root = null;
		

		public T peek(){
				if(isEmpty()) throw new RuntimeException("Stack underflow");
				T item = root.getData();
				return item;
		}

}
*/


@SuppressWarnings("unchecked")
class StackChar extends StackComposition{
		public void charPush(char o){
			super.push(new Character(o));
		}
		public char charPop(){
				return((Character)super.pop()).charValue();
		}
		public char top(){
				char temp = charPop();
				charPush(temp);
				return temp;
		}

}


