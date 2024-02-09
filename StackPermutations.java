import java.util.*;

public class StackPermutations {
    static Boolean stackPermute(int input[], int output[], int n){
        Stack<Integer> st = new Stack<Integer>();
        int j = 0;
        
        for (int i = 0; i < n; i++){
            st.push(input[i]);
            while (!st.isEmpty() && st.peek() == output[j]){
                st.pop();
                j++;
            }
            
        }
        if (st.isEmpty()){
                return true;
            }
            return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int input[] = new int[n];
        int output[] = new int[n];
        for (int i = 0; i < n; i++){
            input[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++){
            output[i] = sc.nextInt();
        }
        sc.close();
        if (stackPermute(input, output, n)){
            System.out.println("Yes");
        }
        else {
            System.out.println("No");
        }
    }
}


// Output 

// 3
// 1 2 3
// 2 1 3

// Yes