import java.util.*;
public class FindCelebrity {
    public static int celebritySolution(int[][] mat) {
        Stack<Integer> stk = new Stack<>();
        for(int i=0;i<mat.length;i++) {
            stk.push(i);// stack = 0 1 2 3
        }
        while(stk.size() > 1) {
            int col = stk.pop(); // col = 1
            int row = stk.pop(); // row = 0
            if(mat[row][col] == 1) // mat[0][1] == 1
	 {
                stk.push(col);  //stack = 1
            } 
	else {
                stk.push(row); // stack = 0 1
            }
        }
        int x = stk.pop(); // x =  1
        for(int j=0;j<mat.length;j++) {
            if(mat[x][j] == 1) {
                return -1;
            }
        }
        
        for(int i=0;i<mat.length;i++) {
            if(i == x) continue;
            if(mat[i][x] == 0) {
                return -1;
            }
        }
        return x;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int matrix[][]=new int[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=sc.nextInt();
            }
        }
        int res = celebritySolution(matrix);
        if(res == -1) {
            System.out.println("There is no celebrity in the party");
        } else {
            System.out.println(res + " is the celebrity in the party");
        }
    }
}
