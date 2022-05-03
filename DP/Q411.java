import java.util.*;
//Knapsack Problem 
public class Q411{
    static int solve(int arr[],int brr[],int n,int w){
        int [][] dp = new int [n+1][w+1];
        Arrays.stream(dp).forEach(a -> Arrays.fill(a, 0));
        if(n == 0 || w == 0) return 0;
        for(int i = 1;i <=n;i++){
            for(int j = 1; j <= w;j++){
                if(brr[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else if(brr[i-1] <= j){
                    dp[i][j] = Math.max(arr[i-1]+dp[i-1][j-brr[i-1]],dp[i-1][j]);
                }
            }
        }
        return dp[n][w];
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();
        int [] arr = new int [n];
        int [] brr = new int [n];
        for(int i = 0; i < n;i++){
            arr[i] = sc.nextInt();
        }
        for(int i = 0;i<n;i++){
            brr[i] = sc.nextInt();
        }
        int ans = solve(arr,brr,n,w);
        System.out.println(ans);
    }
}