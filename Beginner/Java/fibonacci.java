public class fibonacci {
public static void main(String[] args) {
   int a, b, c;
   a=0;
   b=1;
    System.out.print(a+","+b);
    int i=1;
    do{
        c=a+b;
        System.out.print(","+c);
        a=b;
        b=c;
        i++;
      }while(i<=10);
}   
}
