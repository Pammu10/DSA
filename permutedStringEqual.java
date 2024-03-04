import java.util.Scanner;

public class permutedStringEqual {
    static boolean permutation(String s, String t){
        if (s.length() != t.length()){
            return false;
        }
        int letters[] = new int[128];
        char s_array[] =  s.toCharArray();
        for (char c : s_array){
            letters[c]++;
        }
        for (int i = 0; i < t.length(); i++){
            int c = (int) t.charAt(i);
            letters[c]--;
            if (letters[c] < 0){
                return false;
            }
        }

        return true;

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String t = sc.nextLine();
        if (permutation(s, t)){
            System.out.println("Strings are permutations of each other");
        }
        else {
            System.out.println("Strings are'nt permutations of each other");
        }
        sc.close();
    }
}


//Output 
// Pramodh
// dhomarP
// Strings are permutations of each other
