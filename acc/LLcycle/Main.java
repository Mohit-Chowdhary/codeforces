// //package acc;

// import java.util.*;

// public class Main{
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int t = sc.nextInt();
//         while(t-- > 0){
//             int n = sc.nextInt();
//             //System.out.println(t);
//             int[] a = new int[n];

//             for(int i=0;i<n;i++){
//                 a[i] = sc.nextInt();
//             }

//             // System.err.println(n);

//             // for(int i : a){
//             //     System.err.println(i);
//             // }

//             int slow = a[0], fast = a[0];

//             boolean valid = false;

//             while(fast !=n && a[fast]!=n){
//                 fast = a[a[fast]];
//                 slow = a[slow];
//                 //System.out.println("slow is "+slow+" fast is "+fast);
//                 if(fast == slow){
//                     valid = true;
//                     break;
//                 }
//             }
            
//             if(valid) System.out.println("YES");
//             else System.out.println("NO");
//         }
//     }
// }





import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            
            int[] a = new int[n];
            for(int i=0;i<n;i++){
                a[i] = sc.nextInt();
            }
            
            boolean valid = true;
            int slow = 0;
            int fast = 0;
            
            while(fast<n && a[fast]<n){
                fast = a[a[fast]];
                slow = a[slow];
                if(fast == slow){
                    valid = false;
                    break;
                }
            }
            
            if(valid) System.out.println("NO");
            else System.out.println("YES");
        }

    }
}