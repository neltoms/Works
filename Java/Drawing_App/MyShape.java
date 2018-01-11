import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.nio.file.DirectoryStream;

import java.text.DecimalFormat;
import java.awt.event.*;
import java.awt.*;
import java.awt.geom.*;
import java.util.*;
import java.io.IOException;
import java.io.EOFException;
import java.io.ObjectInputStream;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JFileChooser;

@SuppressWarnings("serial")
public class MyShape extends JFrame{

		JButton brushBut, lineBut, ellipseBut, rectBut, strokeBut, fillBut;
		DecimalFormat decimal = new DecimalFormat("#.##");
		int currentAction = 1;

		Color strokeColor = Color.BLACK, fillColor = null;

		JSlider transSlide;
		JLabel transLabel;
		Graphics2D graphicsSettings;

		float transVal = 1.0f;

	public static void main(String[] args){
		
		new MyShape();
	}
	public MyShape(){

		this.setSize(1000, 800);
		this.setTitle("Java Paint");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		JPanel buttonPanel = new JPanel();

		Box paintBox = Box.createHorizontalBox();
		JButton brushBut, lineBut, ellipseBut, rectBut, strokeBut, fillBut,
				saveFileBut, openFileBut;

		brushBut = createButtons("brush", 1);
		lineBut = createButtons("line", 2);
		ellipseBut = createButtons("ellipse", 3);
		rectBut = createButtons("rectangle", 4);
		saveFileBut = createButtons("saveFile", 7);
		openFileBut = createButtons("openFile", 8);

		strokeBut = createColorButton("stroke color", 5, true);
		fillBut = createColorButton("fill color", 6, false);
		
		paintBox.add(brushBut);
		paintBox.add(lineBut);
		paintBox.add(ellipseBut);
		paintBox.add(rectBut);
		paintBox.add(strokeBut);
		paintBox.add(fillBut);
		paintBox.add(saveFileBut);
		paintBox.add(openFileBut);

		transLabel = new JLabel("Transparent: 1");
		transSlide = new JSlider(1, 99, 99);
		ListenerForSlider SliderListener = new ListenerForSlider();
		transSlide.addChangeListener(SliderListener);

		paintBox.add(transLabel);
		paintBox.add(transSlide);

		buttonPanel.add(paintBox);

		this.add(buttonPanel, BorderLayout.SOUTH);
		this.add(new DrawingBoard(), BorderLayout.CENTER);
		this.setVisible(true);
	}

    public JButton createButtons(String icon1, final int actionNum){
        
        JButton button = new JButton();
        button.setText(icon1);

        button.addActionListener(new ActionListener(){
              
                public void actionPerformed(ActionEvent e){
                      currentAction = actionNum;
                }

        });

        return button;

    }

    public JButton createColorButton(String icon1, final int actionNum, final boolean stroke){
        
        JButton button = new JButton();
        button.setText(icon1);

        button.addActionListener(new ActionListener(){
              
                public void actionPerformed(ActionEvent e){
                        if(stroke){
                              strokeColor = JColorChooser.showDialog(null, "Pick a Stroke", Color.BLACK);
                        }
                        else{

                              fillColor = JColorChooser.showDialog(null, "Pick a Fill", null);
                        }
                }
        });

        return button;

    }


 private class JFileChooserDemo extends JFrame{

		private final JTextArea outputArea;

		public JFileChooserDemo() throws IOException{
				super("JFileChooser Demo");
				outputArea = new JTextArea();
				add(new JScrollPane(outputArea));
				analyzePath();

		}
		public void analyzePath() throws IOException{

				Path path = getFileOrDirectoryPath();

				if (path != null && Files.exists(path)){
						StringBuilder builder = new StringBuilder();
						builder.append(String.format("%s:%n", path.getFileName()));
						builder.append(String.format("%s a directory%n",
							Files.isDirectory(path) ? "Is" : "Is not"));
						builder.append(String.format("%s an absolute path%n",
						path.isAbsolute() ? "Is" : "Is not"));
						builder.append(String.format("Last modified: %s%n",
							Files.getLastModifiedTime(path)));
						builder.append(String.format("Size: %s%n", Files.size(path)));
						builder.append(String.format("Path: %s%n", path));
						builder.append(String.format("Absolute path: %s%n",
							path.toAbsolutePath()));

						if (Files.isDirectory(path)){
							builder.append(String.format("%nDirectory contents:%n"));

							DirectoryStream<Path> directoryStream =
							Files.newDirectoryStream(path);

							for (Path p : directoryStream)
								builder.append(String.format("%s%n", p));
						}

						outputArea.setText(builder.toString());
				}
				else{
						JOptionPane.showMessageDialog(this, path.getFileName() +
							" does not exist.", "ERROR", JOptionPane.ERROR_MESSAGE);
				}
		}
		private Path getFileOrDirectoryPath(){
			
				JFileChooser fileChooser = new JFileChooser();
				fileChooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
				int result = fileChooser.showOpenDialog(this);
				
				if (result == JFileChooser.CANCEL_OPTION)
					System.exit(1);


				return fileChooser.getSelectedFile().toPath();
	}
}

    private class DrawingBoard extends JComponent{

            ArrayList<Shape> shapes = new ArrayList<Shape>();
            ArrayList<Color> shapeFill = new ArrayList<Color>();
            ArrayList<Color> shapeStroke = new ArrayList<Color>();
			ArrayList<Float> transPercent = new ArrayList<Float>();
            Point beginDraw, endDraw;

            public DrawingBoard(){
                    this.addMouseListener(new MouseAdapter(){
                            public void mouseMovement(MouseEvent e){
									if(currentAction != 1){
                                    beginDraw = new Point(e.getX(), e.getY());
                                    endDraw = beginDraw;
                                    repaint();
                            		}
							}

                            public void mouseReleased(MouseEvent e){
									if(currentAction != 1){

									Shape theShape = null;
									if(currentAction == 2){
										 theShape = drawLine(beginDraw.x,
													beginDraw.y, e.getX(), e.getY());
									}
									else
									if(currentAction == 3){
										 theShape = drawEllipse(beginDraw.x,
													beginDraw.y, e.getX(), e.getY());
									}
									else
									if(currentAction == 4){
									 	theShape = drawRect(beginDraw.x,
													beginDraw.y, e.getX(), e.getY());
									}

									shapes.add(theShape);
									shapeFill.add(fillColor);
									shapeStroke.add(strokeColor);
									transPercent.add(transVal);

									beginDraw = null;
									endDraw = null;
									repaint();
									}
							}
					});   // END OF addMouseListener
                    
                    this.addMouseMotionListener(new MouseMotionAdapter(){
                            public void mouseDragged(MouseEvent e){
								if(currentAction == 1){
									int x = e.getX();
									int y = e.getY();

									Shape theShape = null;
									strokeColor = fillColor;

									theShape = drawBrush(x, y, 1, 1);
									shapes.add(theShape);
									shapeFill.add(fillColor);
									shapeStroke.add(strokeColor);
									transPercent.add(transVal);

									}
                                    endDraw = new Point(e.getX(), e.getY());
                                    repaint();
								
								if(currentAction == 2){
									int x = e.getX();
									int y = e.getY();

									Shape theShape = null;
									strokeColor = fillColor;

									theShape = drawLine(x, y, 1, 1);
									shapes.add(theShape);
									shapeFill.add(fillColor);
									shapeStroke.add(strokeColor);
									transPercent.add(transVal);

									}
                                    endDraw = new Point(e.getX(), e.getY());
                                    repaint();
								
									if(currentAction == 3){
									int x = e.getX();
									int y = e.getY();

									Shape theShape = null;
									strokeColor = fillColor;

									theShape = drawEllipse(x, y, 1, 1);
									shapes.add(theShape);
									shapeFill.add(fillColor);
									shapeStroke.add(strokeColor);
									transPercent.add(transVal);

									}
                                    endDraw = new Point(e.getX(), e.getY());
                                    repaint();
								
									if(currentAction == 4){
									int x = e.getX();
									int y = e.getY();

									Shape theShape = null;
									strokeColor = fillColor;

									theShape = drawRect(x, y, 1, 1);
									shapes.add(theShape);
									shapeFill.add(fillColor);
									shapeStroke.add(strokeColor);
									transPercent.add(transVal);

									}
                                    endDraw = new Point(e.getX(), e.getY());
                                    repaint();

                            }
                    });  // END OF addMouseMotionListener

            }

            public void paint(Graphics g){
                    graphicsSettings = (Graphics2D)g;
                    graphicsSettings.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                                   RenderingHints.VALUE_ANTIALIAS_ON);
                    graphicsSettings.setStroke(new BasicStroke(4));

                    Iterator<Color> strokeCounter = shapeStroke.iterator();
                    Iterator<Color> fillCounter = shapeFill.iterator();
                    Iterator<Float> transCounter = transPercent.iterator();


                    for(Shape s : shapes){
                    		graphicsSettings.setComposite(
											AlphaComposite.getInstance(
													AlphaComposite.SRC_OVER, transCounter.next()));
                            graphicsSettings.setPaint(strokeCounter.next());
                            graphicsSettings.draw(s);
                            graphicsSettings.setPaint(fillCounter.next());
                            graphicsSettings.fill(s);

                    }
                    if(beginDraw != null && endDraw != null){
                            graphicsSettings.setComposite(
                                            AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 0.40f));
                            graphicsSettings.setPaint(Color.LIGHT_GRAY);

							Shape theShape = null;
							if(currentAction == 2){
								theShape = drawLine(beginDraw.x,
										beginDraw.y, endDraw.x, endDraw.y);
							}
							else
							if(currentAction == 3){
								 theShape = drawEllipse(beginDraw.x,
										beginDraw.y, endDraw.x, endDraw.y);
							}
							else
							if(currentAction == 4){
								 theShape = drawRect(beginDraw.x,
										beginDraw.y, endDraw.x, endDraw.y);
							}
							graphicsSettings.draw(theShape);
                   }
            }

            private Rectangle2D.Float drawRect(int x1, int y1, int x2, int y2){
                    int x = Math.min(x1, x2);
                    int y = Math.min(y1, y2);

                    int width = Math.abs(x1-x2);
                    int height = Math.abs(y1-y2);

                    return new Rectangle2D.Float(x, y, width, height);
            }

			private Ellipse2D.Float drawEllipse(int x1, int y1, int x2, int y2){
					int x = Math.min(x1, x2);
					int y = Math.min(y1, y2);
					int width = Math.abs(x1-x2);
					int height = Math.abs(y1-y2);

					return new Ellipse2D.Float(x, y, width, height);
			}

			private Line2D.Float drawLine(int x1, int y1, int x2, int y2){
					
					return new Line2D.Float(x1, y1, x2, y2);
			}

			private Ellipse2D.Float drawBrush(int x1, int y1, int brushSW, int brushSH){

					return new Ellipse2D.Float(x1, y1, brushSW, brushSH);
			}

   	}

	private class ListenerForSlider implements ChangeListener{

			public void stateChanged(ChangeEvent e){
					if(e.getSource() == transSlide){
							transLabel.setText("Transparent: " + decimal.format(transSlide.getValue() * .01));
							transVal = (float) (transSlide.getValue() * .01);
					}
			}
	}

	
}
