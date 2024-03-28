import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

import java.awt.*;
import java.awt.image.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Timer;
import java.awt.color.*;
import java.awt.event.*;

public class main {

    main(){
        readHighScore();
        game(); 
        
    }
    private int highscore ;
private void game(){
     JFrame game = new JFrame();
        game.setSize(700, 700);
        JPanel gamewindow = new JPanel();
        gamewindow.setBackground(Color.BLACK);
        gamewindow.setLayout(null);

        // Add label to the game
        JLabel Infostart = new JLabel("Welcome To the Game ");
        Infostart.setBounds(100, 100, 700, 200);
        Infostart.setFont(Infostart.getFont().deriveFont(Font.ITALIC, 50));
        Infostart.setForeground(Color.LIGHT_GRAY);

        JLabel Info = new JLabel("Made By:- SUSHIL NAMBERDAR (BUNTY NAMBERRDAR)");
        Info.setBounds(200, 600, 500, 100);

        // start button
        JButton start = new JButton("Start");
        start.setBounds(270, 350, 150, 50);
        start.setBackground(new Color(64, 64, 64));
        // for set the Font size of start button
        start.setFont(start.getFont().deriveFont(Font.BOLD, 30));
        start.setForeground(Color.GRAY);
        //adding high score 
        JLabel highscorLabel = new JLabel("High Score: "+ (highscore*10));
        highscorLabel.setBounds(20, 0, 250, 50); 
        highscorLabel.setFont(highscorLabel.getFont().deriveFont(Font.BOLD,21));
         

       

        // adding component to the gamewindow
        gamewindow.add(highscorLabel);
        gamewindow.add(Infostart);
        gamewindow.add(Info);
        gamewindow.add(start);

        game.setContentPane(gamewindow);
        game.setTitle("Snake Game ");
        game.setLocationRelativeTo(null);
        game.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        game.setVisible(true);

        // adding Action listner
        // to start button

        start.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                game.dispose();
                new main().snakegame();

                
            }
        });
    }

    // making a snakegame 
    private static void snakegame(){
        JFrame snakgame = new JFrame();
        snakgame.setSize(700,700);
        snakgame.setResizable(false);
        Bord bord = new Bord();
        bord.setPreferredSize(new Dimension(700,700));
        bord.setSize(700,700);
        snakgame.add(bord);
        snakgame.pack();
        snakgame.setLocationRelativeTo(null);
        snakgame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        snakgame.setVisible(true);

    }
        // function for showing hight score 
         // get the perivices hight scroe from the text file 
    private void readHighScore(){
        try (BufferedReader reader = new BufferedReader(new FileReader("high_score.txt"))){
            String line = reader.readLine();

            if(line!= null && !line.isEmpty()){
                highscore = Integer.parseInt(line);
            }
        } catch (Exception e) {
            
            e.printStackTrace();
        }
    }
   
    public void showMainFrame(){
        SwingUtilities.invokeLater(this::game);
    }

    public static void main(String args[]){
        new main();
        
    }
}
