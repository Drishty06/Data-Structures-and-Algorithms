// problem link: https://www.pepcoding.com/resources/online-java-foundation/getting-started/rotate-a-number-official/ojquestion#
import java.util.*;
   
   public class Main{
   
   public static void main(String[] args) {
     
     Scanner scn = new Scanner(System.in);
     int n = scn.nextInt();
     int k = scn.nextInt();
     int temp,count=0,temp1;
     temp1 = n;
     while(temp1 > 0)
     {
        temp1 = temp1 / 10;
        count++;
     }
     if(k > 0)
     {
         k = k % count;
         if(k == 0)
         {
             k = count;
         }
     }
     else
     {
         if(k == 0) k=count;
         else 
         {
             k = (-k) % count;
             k = count - k;
         }
     }
     temp = n % ((int) Math.pow(10,k));
     n = n - temp;
     n  = n / ((int)Math.pow(10,k));
     n = n + (temp * ((int ) Math.pow(10,count-k)));
     System.out.println(n);
    }
   }
