import java.util.*;

public class oddevenLL{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            //System.out.println(t);
            int[] a = new int[n];

            for(int i=0;i<n;i++){
                a[i] = sc.nextInt();
            }
            for(int i=0;i<n;i++){
                if( a[i]%2==0) System.out.print(a[i]+" ");
            }
            for(int i=0;i<n;i++){
                if( a[i]%2==1) System.out.print(a[i]+" ");
            }
            System.out.println();
        }
    }
}