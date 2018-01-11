import java.awt.BorderLayout;

import java.awt.Checkbox;

import java.awt.Color;

import java.awt.Container;

import java.awt.Font;

import java.awt.event.ActionEvent;

import java.awt.event.ActionListener;

import java.awt.event.ItemEvent;

import java.awt.event.ItemListener;

import javax.swing.BorderFactory;

import javax.swing.JButton;

import javax.swing.JColorChooser;

import javax.swing.JComboBox;

import javax.swing.JFrame;

import javax.swing.JPanel;

import javax.swing.JTextArea;

public class LowVisionGUI extends JFrame implements ActionListener, ItemListener{

	private static final long serialVersionUID = 1L;	
      /**

      * declaring UI component objects

      */

      JButton increaseSize,decreaseSize;

      JComboBox<String> fonts;

      Checkbox bold;

      JPanel controls,colorControls;

      JTextArea textArea;

      JButton textColorChooser,backgroundColorChooser;

      /**

      * default text attributes

      */

      int fontStyle=Font.PLAIN;

      int fontSize=18;

      public LowVisionGUI() {

            setDefaultCloseOperation(EXIT_ON_CLOSE);

            setSize(500,500);

            Container pane=getContentPane();

            pane.setBackground(Color.WHITE);

            pane.setLayout(new BorderLayout());

           

            textArea=new JTextArea();

            /**

            * setting some space as padding for the text area

            */

            textArea.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

            /**

            * Panel to include controls

            */

            controls=new JPanel();

            increaseSize=new JButton("Increase Font Size");

            decreaseSize=new JButton("Decrease Font Size");

            /**

            * 3 of the java built-in logical fonts, setting it to the JComboBox object

            */

            String[] fontsList=new String[]{"Serif","SansSerif","Monospaced"};

            fonts=new JComboBox<>(fontsList);

            /**

            * Checkbox for bold option

            */

            bold=new Checkbox("Bold");

            bold.setState(false);/*default state- unchecked*/

            /**

            * Adding components to the controls panel

            */

            controls.add(increaseSize);

            controls.add(decreaseSize);

            controls.add(fonts);

            controls.add(bold);

           

            /**

            * a panel of Buttons to handle text/background color changes using JColorChooser dialog

            */

            colorControls=new JPanel();

            textColorChooser=new JButton("Choose text color");

            backgroundColorChooser=new JButton("Choose background color");

           

            colorControls.add(textColorChooser);

            colorControls.add(backgroundColorChooser);

            /**

            * Adding the panels to the content pane using BorderLayout

            */

            pane.add(controls,BorderLayout.NORTH);

            pane.add(textArea,BorderLayout.CENTER);

            pane.add(colorControls,BorderLayout.PAGE_END);

            /**

            * making UI visible

            */

            setVisible(true);

            /**

            * Adding listeners

            */

            increaseSize.addActionListener(this);

            decreaseSize.addActionListener(this);

            textColorChooser.addActionListener(this);

            backgroundColorChooser.addActionListener(this);

            fonts.addActionListener(this);

            bold.addItemListener(this);

            /**

            * setting the initial state of text attributes

            */

            updateTextAttributes();

      }

      public static void main(String[] args) {

            /**

            * invoking the Frame

            */

            new LowVisionGUI();

      }

      public void actionPerformed(ActionEvent ae) {

            Object o=ae.getSource();

            if(o instanceof JButton){

                  if(o.equals(increaseSize)){

                        /**

                        * font size increase

                        */

                        fontSize++;

                        updateTextAttributes();

                  }else if(o.equals(decreaseSize)){

                        /**

                        * font size decrease

                        */

                        fontSize--;

                        updateTextAttributes();

                  }else if(o.equals(textColorChooser)){

                        /**

                        * color chooser for text color

                        */

                        Color color=JColorChooser.showDialog(null, "Choose a color", textArea.getForeground());

                        textArea.setForeground(color);

                       

                  }else if(o.equals(backgroundColorChooser)){

                        /**

                        * color chooser for background color

                        */

                        Color color=JColorChooser.showDialog(null, "Choose a color", textArea.getBackground());

                        textArea.setBackground(color);

                  }

            }else if(o instanceof JComboBox){

                  /**

                  * calling the method to make the changes visible

                  */

                  updateTextAttributes();

            }

           

      }

      /**

      * Method to update the text attributes after each event

      */

      public void updateTextAttributes(){

            textArea.setFont(new Font((String) fonts.getSelectedItem(), fontStyle, fontSize));

      }

      public void itemStateChanged(ItemEvent ie) {

            if(bold.getState()){

                  /**

                  * bold checkbox is checked

                  */

                  fontStyle=Font.BOLD;

                  updateTextAttributes();

            }else {

                  /**

                  * bold checkbox is unchecked

                  */

                  fontStyle=Font.PLAIN;

                  updateTextAttributes();

            }

           

      }

}
