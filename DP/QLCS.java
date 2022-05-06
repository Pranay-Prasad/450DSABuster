import java.util.*;

public class QLCS{
    public static int LCS(String a,String b){
        int n = a.length();
        int m = b.length();
        int [][]dp = new int[n+1][m+1];
        for(int i = 0; i <= n;i++) dp[i][0] = 0;
        for(int i = 0; i <= m;i++) dp[0][i] = 0;
        if(n == 0 || m == 0) return 0;
        for(int i = 1; i <=n;i++){
            for(int j = 1; j <= m;j++){
                if(a.charAt(i-1) == b.charAt(j-1)){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        int ans = LCS(a,b);
        sc.close();
        System.out.println(ans); 
    }
}