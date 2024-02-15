import java.util.*;
public class FindCelebrity {
    static int findCelebrity(int matrix[][]){
        int candidate = 0;
        for (int i = 1; i < matrix.length; i++){
            if (matrix[candidate][i] == 1){
                candidate = i;
            }
        }
        for (int i = 0; i < matrix.length; i++){
            if (candidate != i && matrix[i][candidate] == 0 || matrix[candidate][i] == 1){
                return -1;
            }
        }
        return candidate;
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
        sc.close();
        int res = findCelebrity(matrix);
        if(res == -1) {
            System.out.println("There is no celebrity in the party");
        } else {
            System.out.println(res + " is the celebrity in the party");
        }
    }
}
