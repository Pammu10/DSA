import java.util.*;

public class StockSpan {
    static void calculate(int arr[], int n, int S[]){
        Stack<Integer> st = new Stack<Integer>();
        st.push(0);
        S[0] = 1;
        for (int i = 1; i< n; i++){
            while (!st.isEmpty() && arr[st.peek()] <= arr[i]){
                st.pop();
            }
            if (st.isEmpty()){
                S[i] = i + 1;
            }
            else {
                S[i] = i - st.peek();
            }
            st.push(i);
        }
    }    
    static void printArray(int arr[]){
        System.out.println(Arrays.toString(arr));
    }
    public static void main(String[] args){
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        sc.close();        int S[] = new int[n];
        calculate(arr, n, S);
        printArray(S);
    }
}

// Output 
// 6 
// 97 64 32 11 22 56
// [1, 1, 1, 1, 2, 4]