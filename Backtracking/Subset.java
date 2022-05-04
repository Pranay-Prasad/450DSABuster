import java.util.*;

public class Subset{
    public static void dfs(int [] arr,int i,List<Integer> res,List<List<Integer>> ans) {
        if(i >= arr.length){
            ans.add(new ArrayList<>(res));
            return;
        }
        res.add(arr[i]);
        dfs(arr,i+1,res,ans);
        res.remove(res.size()-1);
        dfs(arr,i+1,res,ans);
    }
    public static List<List<Integer>> solve(int[] arr){
        List<List<Integer>>ans = new ArrayList<>();
        List<Integer>res = new ArrayList<>();
        dfs(arr,0,res,ans);
        return ans;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int [] arr = new int[n];
        for(int i=  0; i < n;i++){
            arr[i] = sc.nextInt();
        }
        sc.close();
        List<List<Integer>>ans = solve(arr);
        System.out.println(ans);
    }
}