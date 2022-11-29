import java.util.*;

public class B {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int i=0; i<t; i++) {
            int n = sc.nextInt();
            Set<Integer> a = new HashSet<Integer>();
            for(int j=0; j<n; j++) {
                int input = sc.nextInt();
                a.add(input);
            }
            int unique = a.size();
            if(unique==2) System.out.println((n/2)+1);
            else if(unique>=3) System.out.println(n);
            else System.out.println(1);
        }

        sc.close();
	}
}