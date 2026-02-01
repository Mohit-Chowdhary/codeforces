import java.util.*;

public class minstack{
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
            Arrays.sort(a);
            for(int i:a) System.out.print(i+" ");
            System.out.println();
        }
    }
}