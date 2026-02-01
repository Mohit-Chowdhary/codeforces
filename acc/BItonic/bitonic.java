
import java.util.*;

public class bitonic{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int[] a = new int[n];

            int ind = 1;

            a[0] = sc.nextInt();

            for(int i=1;i<n;i++){
                a[i] = sc.nextInt();
                if(a[i]>a[i-1]) ind = i+1;
            }

            // Arrays.sort(a);
            // for(int i : a){
            //     System.out.print(i+" ");;
            // }

            int i = 0;
            int j = n-1;

            while(i<ind && j>=ind){
                //System.out.println(" i is "+i+" j is "+j);
                if(i<ind && a[i]<a[j]){
                    System.out.print(a[i]+" ");
                    i++;
                }
                else{
                    System.out.print(a[j]+" ");
                    j--;
                }
            }
            for(int i1 = i; i1<ind; i1++){
                System.out.print(a[i1]+" ");
            }
            for(int j1 =ind; j>=j1; j1--){
                System.out.print(a[j1]+" ");
            }
            System.out.println();
            
        }
    }
}