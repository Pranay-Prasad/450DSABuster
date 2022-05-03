import java.util.*;

public class Q412{
    public static int solve(int r,int n){
        if(n < r) return 0;
        if((n-r) < r) r = n-r;
        int []dp = new int[r+1];
        int md = 1000000007;
        Arrays.fill(dp, 0);
        dp[0] = 1;
        for(int i = 1; i <= n;i++){
            for(int j = Math.min(r,i);j>0;j--){
                dp[j] = (dp[j]+dp[j-1])%md;
            }
        }
        return dp[r];
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n,r;
        n = sc.nextInt();
        r = sc.nextInt();
        sc.close();
        int ans = solve(r,n);
        System.out.println(ans);
    }
}