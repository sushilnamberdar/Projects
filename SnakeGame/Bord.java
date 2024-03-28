import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.event.*;
import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import javax.swing.Timer;
import java.awt.Toolkit;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Writer;
import java.nio.Buffer;

import javax.swing.JOptionPane;

public class Bord extends JPanel implements ActionListener{

    private Image apple;
    private Image dot;
    private Image head;
    private final int all_dots = 1960;
    private final int dot_size = 10;
    private final int Random_Position = 48;
    private int apple_x;
    private int apple_y;
    private  Timer timer ;
    private final int x[] = new int[all_dots];
    private final int y[] = new int[all_dots];
    private int dots;
    private boolean leftdirection = false;
    private boolean rightdireciton = true;
    private boolean updirection = false;
    private boolean downdirection = false;
    private boolean Ingame = true;
    private int score = 0;
    private int highscore;
    private static final int SCORE_MULTIPLIER = 10;

    Bord() {
        addKeyListener(new keyhandling());
        setBackground(Color.BLACK);
        setFocusable(true);

        // functions
        loadImages();
        initGame();
        readHighScore();
    }
    // get the perivices hight scroe from the text file 
    public void readHighScore(){
        try (BufferedReader reader = new BufferedReader(new FileReader("high_score.txt"))){
            String line = reader.readLine();

            if(line!= null && !line.isEmpty()){
                highscore = Integer.parseInt(line);
            }
        } catch (Exception e) {
            
            e.printStackTrace();
        }
    }

    public void loadImages() {
        if(Ingame){
        System.out.println("Loading images ...");
        
        ImageIcon i1 = new ImageIcon("apple.png");
        apple = i1.getImage();
        ImageIcon i2 = new ImageIcon("dot.png");
        dot = i2.getImage();
        ImageIcon i3 = new ImageIcon("head.png");
        head = i3.getImage();
        System.out.println("Images loaded successfully");
        }
       
    }

    public void initGame() {
        // for the first snake position whare to start 
        dots = 3;
        for (int i = 0; i < dots; i++) {
            y[i] = 200;
            x[i] = 200 - dot_size * i; 
        }

        locateApple();
        timer = new Timer(100,this);
        timer.start();
    }
    // for apple 
    public void locateApple(){
      int r =  (int) (Math.random()*Random_Position);
      apple_x = r*dot_size;
       r =  (int)  (Math.random()*Random_Position);
       apple_y = r*dot_size;
    }
        // adding image to the bord by graphics clss 
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        draw(g);   
    }
    
    public void draw(Graphics g){
        // for apple draw 
        g.drawImage(apple, apple_x,apple_y,this);
        // for snake print on the bord ;
        for(int i = 0; i<dots;i++){
            if(i==0){
                g.drawImage(head,x[i] , y[i], this);
            }else{
                g.drawImage(dot, x[i], y[i], this);
            }
        }
        // synchronize the graphics state
        Toolkit.getDefaultToolkit().sync();
    }

    
    // move function for impliment direction 
    public void move(){
        // for moving the snake images 
         for(int i = dots; i>0;i--){
             x[i]= x[i-1];
             y[i]=y[i-1];
         }
        
        if(leftdirection){
            x[0]= x[0] - dot_size;
        }
        if(rightdireciton){
            x[0]= x[0] + dot_size;
        }
        if(updirection){
            y[0]= y[0] - dot_size;
        }
        if(downdirection){
            y[0]= y[0] + dot_size;
        }
      
        
    }
    public void checkApple(){
        if((x[0]==apple_x)&& (y[0]==apple_y)){
            dots++;
            score++;
            
            locateApple();
            savehightscore(score);
        }
    }
    public void savehightscore(int score){
        if(score >highscore){
            highscore = score;
            try(BufferedWriter writer = new BufferedWriter(new FileWriter("high_score.txt"))) {
                writer.write(String.valueOf(highscore));
                System.out.println("high score save sucessfull");
            } catch (Exception e) {
                e.printStackTrace();
                System.err.println("Error saving hight score"+e.getMessage());
            }
        }
    }
    public void checkcollision(){
        for(int i = dots;i>0;i--){
            if((i>3)&& (x[0]==x[i])&& (y[0]==y[i])){
                Ingame = false;
            }
        }
        if(y[0] >=700){
            Ingame = false;
        }
        if(x[0] >=700){
            Ingame = false;
        }
        if(x[0] < 0){
            Ingame = false;
        }
        if(y[0] <0){
            Ingame = false;
        }
        if(!Ingame){
            timer.stop();
            showGameOverMessage();
            setVisibility(false);
            repaint();
        }

        
    }
    public void setVisibility(boolean visible){
        this.setVisible(visible);
    }
    public void showGameOverMessage(){
        if(score>highscore){
        JOptionPane.showMessageDialog(null, "Game Over \n You Made new High Score: " + score*10 , "!Oops", JOptionPane.ERROR_MESSAGE);
        }else{
            JOptionPane.showMessageDialog(null, "Game Over \n  Score: " + score*10, "!Oops", JOptionPane.ERROR_MESSAGE);
        }

        // call a method in the maiin class to show the main frame windows 
      
    }
    public void actionPerformed(ActionEvent ae){
        move();
        checkApple();
        checkcollision();
        repaint();
    }
    // for function keyhandling arrow keys  
    // KeyAdapter class in Java is an abstract class that provides a default implementation of the KeyListener interface
    public class keyhandling extends KeyAdapter{
        public void keyPressed(KeyEvent e){
            int key = e.getKeyCode();
            if(key == KeyEvent.VK_LEFT &&(!rightdireciton)){
                leftdirection = true;
                updirection = false;
                downdirection = false;
            }
            if(key == KeyEvent.VK_RIGHT &&(!leftdirection)){
                updirection = false;
                downdirection = false;
                rightdireciton = true;
            }
            if(key== KeyEvent.VK_UP &&(!downdirection)){
                leftdirection = false;
                updirection = true;
                rightdireciton = false;
            }
            if(key == KeyEvent.VK_DOWN &&(!updirection)){
                leftdirection = false;
                downdirection = true;
                rightdireciton = false;
            }

        }
    }
}
