// problem link: https://www.pepcoding.com/resources/online-java-foundation/introduction-to-recursion/print-zig-zag-official/ojquestion
// demonstration of pre-in-post orders
public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        pzz(n);
    }

    public static void pzz(int n)
    {
        if(n == 0) return;
        System.out.print(n + " "); // pre order - element's left side(in recursion tree)
        pzz(n-1); 
        System.out.print(n + " "); // in order - element's inner side(in recursion tree)
        pzz(n-1); 
        System.out.print(n + " "); // post order - element's right side(in recursion tree)
        
    }

}
