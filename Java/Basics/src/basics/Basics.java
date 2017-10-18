package basics;
import java.util.Objects;
import java.util.Scanner;
/**
 *
 * @author gutz
 */
public class Basics {
    protected int edad;
    protected String nombre;

    public Basics(int edad, String nombre) {
        this.edad = edad;
        this.nombre = nombre;
    }
    
    public void setEdad(int edad) {
        this.edad = edad;
    }
    
    public void setENombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public String getNombre() {
        return nombre;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Basics other = (Basics) obj;
        if (this.edad != other.edad) {
            return false;
        }
        if (!Objects.equals(this.nombre, other.nombre)) {
            return false;
        }
        return true;
    }
    
    @Override
    public String toString() {
        return "Basics{" + "edad=" + edad + ", nombre=" + nombre + '}';
    }    
    
    public static void main(String[] args) {
        String nombre;
        int edad;
        Scanner s = new Scanner(System.in);
        
        System.out.println("Introduzca su nombre:");
        nombre = s.next();
        
        System.out.println("Introduzca su edad:");
        edad= s.nextInt();
        
        Basics b = new Basics(edad, nombre);
                
        System.out.println(b.toString());
    }
}
