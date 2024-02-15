import java.util.*;

public class MaxSlidingWindow {
    static void findMax(int arr[], int n, int k){
        int maxSum;
        for (int i = 0; i <= n - k; i++){
            maxSum = arr[i];
            for (int j = 1; j < k; j++){
                if (arr[i+j] > maxSum) {
                    maxSum = arr[i+j];
                }
            }
            System.out.print(maxSum + " ");
        }
        
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        sc.close();
        findMax(arr, n, k);
    }
    
}


// Output 

// 8
// 3
// 2 4 7 12 6 8 4 1

// 7 12 12 12 8 8