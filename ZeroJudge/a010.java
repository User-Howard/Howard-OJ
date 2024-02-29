import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    scanner.close();
    int r = 2;
    boolean first = true;
    while (N > 1) {
        if(N%r == 0) {

            if (first)
                first = false;
            else
                System.out.print(" * ");
            
            int tmp = 0;
            while(N%r == 0) {N/=r; tmp++;}
            if(tmp != 1)
                System.out.print(r + "^" + tmp);
            else 
                System.out.print(r);
        } else {
            r ++;
        }
    }
  }
}