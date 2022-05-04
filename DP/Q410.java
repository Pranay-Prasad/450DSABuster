import java.util.*;
// Coin change problem unlimited coin supplies
// DYNAMIC PROGRAMMING
public class Q410 {
    static long solve(int coins[],int n,int m){
        long [][] dp = new long [n+1][m+1];
        for(int i = 0; i <= n;i++) dp[i][0] = 1;
        for(int i = 0; i <= m;i++) dp[0][i] = 0;
        for(int i = 1; i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int [] coins = new int [n];
            for(int i = 0; i < n;i++){
                coins[i] = sc.nextInt();
            }
            long ans = solve(coins,n,m);
            System.out.println(ans);
            sc.close();
        }
    }

}