import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.Checkbox;
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.ActionEvent;
import java.awt.Color;
import java.awt.event.KeyEvent;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JButton;
import javax.swing.BorderFactory;
import javax.swing.JCheckBox;
import javax.swing.Icon;
import javax.swing.JScrollPane;
import javax.swing.JComboBox;
import javax.swing.JPanel;
import javax.swing.DefaultListCellRenderer;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import javax.swing.plaf.basic.BasicComboBoxRenderer;
import javax.swing.JList;
import java.lang.Thread;




public class LargeType extends JFrame implements ActionListener, ItemListener{

		// JComboBox components
		private static final long serialVersionUID = 1L;	
		private final JComboBox<String> box;
		private final JCheckBox boldBox;
		private final JTextArea textArea;
 		private final JButton buttonI;
 		private final JButton buttonD;
		private final JPanel controlPanel;

		int fontSize = 18;
		int fontStyle = Font.PLAIN;

		public LargeType(){
				super("Large Type Area");
				setLayout(new FlowLayout());
				setSize(500, 500);
			
				
				// JComboBox for fonts
				String[] fontTypes = {"Serif", "Sans-serif", "Monospaced"};
				String[] sizeOptions = {"18", "19", "20", "21", "22"};
 				box = new JComboBox<>(fontTypes);
				box.addItemListener(this);
				add(box);

				// JCheckBox for Bold
				boldBox = new JCheckBox("Bold");
				boldBox.addItemListener(this);
				add(boldBox);
				
				// JPanel for control buttons
				controlPanel = new JPanel();
				add(controlPanel, BorderLayout.NORTH);

				// JButton for control buttons
				buttonI = new JButton("Increase Font Size");
				buttonI.addActionListener(this);
				buttonD = new JButton("Decrease Font Size");
				buttonD.addActionListener(this);
				add(buttonI);
				add(buttonD);
				
				// Text Area
				textArea = new JTextArea(5, 20);
				JScrollPane scroll = new JScrollPane(textArea);
				textArea.setEditable(true);
				add(textArea);
				add(textArea, BorderLayout.CENTER);


			//	box.setBounds(100, 50, 100, 30);
			//	box.setSelectedItem(0);
			//	setVisible(true);

				updateState();

				box.addItemListener(
					new ItemListener(){
					@Override
					public void itemStateChanged(ItemEvent event){
						if(event.getStateChange()==ItemEvent.SELECTED){
						   final String fontName = box.getSelectedItem().toString();
						   box.setFont(new Font(fontName, Font.PLAIN, 18));
						}						
					}
				});

				boldBox.addItemListener(
					new ItemListener(){
					@Override
					public void itemStateChanged(ItemEvent event) {
						Font font = null;
						if(boldBox.isSelected()){
							final String fontName = box.getSelectedItem().toString();
							font = new Font(fontName, Font.BOLD, 18);
						}
					}
				});

				buttonI.addItemListener(
					new ItemListener(){
					@Override
					public void itemStateChanged(ItemEvent event) {
							if(buttonI.isSelected()){
								final String fontName = box.getSelectedItem().toString();
								box.setFont(new Font(fontName, Font.PLAIN, 18+1));
							}

					}
				});
}

public static void main(String[] args) {

				LargeType go = new LargeType();
				go.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				go.setSize(500,500);
				go.setVisible(true);
}
	public void actionPerformed(ActionEvent event){
				Object go = event.getSource();
				if(go instanceof JButton){
						if(go.equals(buttonI)){
								fontSize++;
								updateState();
						}
						else if(go.equals(buttonD)){
								fontSize--;
								updateState();
						}
				}
				else if(go instanceof JComboBox){
						updateState();
				}

	}

 	public void updateState(){
				textArea.setFont(new Font((String) box.getSelectedItem(), fontStyle, fontSize));
	}

public void itemStateChanged(ItemEvent event) {
				if(boldBox.isSelected()){
								fontStyle=Font.BOLD;
								updateState();

				}
				else{
								fontStyle=Font.PLAIN;
								updateState();
				}
	}


}	



