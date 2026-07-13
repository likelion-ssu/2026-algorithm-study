import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int T = sc.nextInt();
        
        for (int tc = 1; tc <= T; tc++) {
            int N = sc.nextInt();
            int[] prices = new int[N];
            
            for (int i = 0; i < N; i++) {
                prices[i] = sc.nextInt();
            }
            
            long totalProfit = 0; 
            int maxPrice = 0;
            
            for (int i = N - 1; i >= 0; i--) {
                int currentPrice = prices[i];
                
                if (currentPrice > maxPrice) {
                    maxPrice = currentPrice; 
                } else {
                    totalProfit += (maxPrice - currentPrice); 
                }
            }
            
            System.out.println("#" + tc + " " + totalProfit);
        }
        
        sc.close();
    }
}