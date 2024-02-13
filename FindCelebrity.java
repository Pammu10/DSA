import java.util.Scanner;

public class FindCelebrity {

    public boolean celebrityFinder(int[][] matrix, int n){
        int a = 0;
        int b = n - 1;
        while (a < b){
            if (matrix[a][b] == 1){
                b++;
            }
        }
        return true;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int matrix[][] = new int[n][n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                matrix[i][j] = sc.nextInt();
            }
        }
        if (celebrityFinder(matrix, n) == true){
            System.out.println("Celebrity found");
        }
        else {
            System.out.println("Celebrity not found");
        }
    }
}
