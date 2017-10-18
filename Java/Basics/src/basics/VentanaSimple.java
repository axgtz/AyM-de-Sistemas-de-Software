package basics;
import javax.swing.JFrame;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;

/**
 *
 * @author gutz
 */
public class VentanaSimple extends JFrame{
    public VentanaSimple(){
        super("Ventana");
	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        setBounds(50,50,500,500);
        
        JTextField nombre= new JTextField(10);
        JLabel l = new JLabel("Escribe tu nombre");
        JLabel saludo = new JLabel("");
        JButton button = new JButton("Saludo");
        
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                saludo.setText("Hola " + nombre.getText());
            }
        });
        
        setLayout(new FlowLayout());
        
        add(l);
        add(nombre);
        add(button);
        add(saludo);
            
        this.setVisible(true); //el default es false
    }
    
    public static void main(String[] args) {
        VentanaSimple v = new VentanaSimple();
    }
}
