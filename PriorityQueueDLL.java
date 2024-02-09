import java.util.*;

public class PriorityQueueDLL {
    static class Node {
        int data;
        int priority;
        Node next, prev;
        public Node(int data, int priority){
            this.data = data;
            this.priority = priority;
        }
    }
    static Node head = null;
    static void push(int data, int priority){
        Node newNode = new Node(data, priority);
        if (head == null){
            head  = newNode;
            return;
        }
        Node temp = head, parent = null;
        temp = head;
        while (temp != null && temp.priority >= priority){
            parent = temp;
            temp = temp.next;
        }
        if (parent == null){
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
        else if (temp == null){
            parent.next = newNode;
            newNode.prev = parent;
        }
        else {
            parent.next = newNode;
            newNode.next = temp;
            temp.prev = newNode;
            newNode.prev = parent;
        }
    }
    static int peek(){
        if (head != null){
            return head.data;
        }
        return -1;
    }
    static int pop(){
        if (head != null){
            int curr = head.data;
            head = head.next;
            if (head != null){
                head.prev = null;
            }
            return curr;
        }
        else {
            return -1;
        }
        
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            int data=sc.nextInt();
            int pri=sc.nextInt();
            push(data, pri);
        }
        sc.close();
        System.out.println(peek());
        System.out.println(pop());
        System.out.println(pop());
        System.out.println(peek());
    }


}


// Output 

// 5
// 3 4 
// 7 1
// 6 6 
// 4 9
// 3 1

// 4
// 4
// 6
// 3