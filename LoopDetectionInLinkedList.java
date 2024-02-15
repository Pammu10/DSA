import java.util.Scanner;

public class LoopDetectionInLinkedList {
    static class Node {
        public int data;
        public Node next;

        public Node(int data) {
            this.data = data;
            this.next = null;
        }


    }
    static Node insertNode(Node head, int data){
        Node newNode = new Node(data);
       if (head == null){
        head  = newNode;
        return head;
        }
        Node tmp = head;
        while (tmp.next != null) {
            tmp = tmp.next;
        }
        tmp.next = newNode;
        return head;
    }

    static void display(Node head){
        Node temp = head;
        while (temp.next != null){
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
        System.out.println(temp.data + "-> NULL");
    }

    static void CreateCycle(Node head, int a, int b){
        int cnta = 0;
        int cntb = 0;
        Node p1 = head;
        Node p2 = head;
        while (cnta != a || cntb != b){
            if (cnta != a){
                p1 = p1.next;
                ++cnta;
            }
            if (cntb != b){
                p2 = p2.next;
                ++cntb;
            }
            p2.next = p1;
        }
    }   

    public static boolean detecytCycle(Node head) {
        if (head == null) return false;
        Node slow = head;
        Node fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            System.out.print("slow: " + slow.data);
            System.out.println(" fast : " + fast.data);
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node head = null;
        for (int i = 0; i < n; i++){
            int data = sc.nextInt();
           head = insertNode(head, data); 
        }
        display(head);  
        int a = sc.nextInt();
        sc.close();
        CreateCycle(head, 1, a);
        if (detecytCycle(head) == true){
            System.out.println("Cycle exists");
        }
        else {
            System.out.println("Cycle does'nt exist");
        }
        
    }

}

// Output

// slow: 2 fast : 3
// slow: 3 fast : 5
// slow: 4 fast : 4
// Cycle detected
