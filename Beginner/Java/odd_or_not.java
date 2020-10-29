import java.util.Scanner;
public class odd_or_not {
 public static void main(String[] args) {
   Scanner sc = new Scanner(System.in);
     System.out.println("Enter a number : ");
     int n = sc.nextInt();
     if(n%2==0)
     {
         System.out.println("Number is not odd.");
     }
     else
     {
         System.out.println("Number is Odd.");
     }
 }
}
