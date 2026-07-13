import java.util.Scanner;

public class Solution {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        
        int T = 10;
        
        for(int tc = 1; tc <= T; tc++){
            int N = sc.nextInt();
            int[] buildings = new int[N];
            
            for (int i = 0; i<N; i++){
                buildings[i] = sc.nextInt();
            }
            
            int total_views = 0;
            
            for(int i = 2; i<N-2; i++){
                int current_height = buildings[i];
                
                int maxAround = Math.max(
                    Math.max(buildings[i-2], buildings[i-1]),
                    Math.max(buildings[i+1], buildings[i+2])
                );
                
                if(current_height>maxAround) {
                    total_views += (current_height-maxAround);
                }
            }
            
            System.out.println("#" + tc + " " + total_views);
            
        }
        
    }
}