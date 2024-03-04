import java.util.Scanner;

public class SumLists {
    class Node {
        int val;
        Node next;

        public Node(int val){
            this.val = val;
        }
    }

    void printList(Node head){
        while (head != null){
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    Node head1, head2, result;
    int carry;

    void push(int val, int list){
        Node newNode = new Node(val);
        if (list == 1){
            newNode.next = head1;
            head1 = newNode;
        }
        else if(list == 2){
            newNode.next = head2;
            head2 = newNode;
        }
        else {
            newNode.next = result;
            result = newNode;
        }
    }
    void addsamesize(Node n, Node m) 
    {
        if (n == null)
            return;
 
        addsamesize(n.next, m.next);
 
        int sum = n.val + m.val + carry;
        carry = sum / 10;
        sum = sum % 10;
 
        push(sum, 3);
 
    }
 
    Node cur;
    void propogatecarry(Node head1) 
    {
        if (head1 != cur) 
        {
            propogatecarry(head1.next);
            int sum = carry + head1.val;
            carry = sum / 10;
            sum %= 10;
 
            push(sum, 3);
        }
    }
 
    int getsize(Node head) 
    {
        int count = 0;
        while (head != null) 
        {
            count++;
            head = head.next;
        }
        return count;
    }
 
    
    void addlists() 
    {
        if (head1 == null) 
        {
            result = head2;
            return;
        }
 
        if (head2 == null) 
        {
            result = head1;
            return;
        }
 
        int size1 = getsize(head1);
        int size2 = getsize(head2);
 
        // Add same size lists
        if (size1 == size2) 
        {
            addsamesize(head1, head2);
        } 
        else
        {
            if (size1 < size2) 
            {
                Node temp = head1;
                head1 = head2;
                head2 = temp;
            }
            int diff = Math.abs(size1 - size2);
 
            Node temp = head1;
            while (diff-- >= 0) 
            {
                cur = temp;
                temp = temp.next;
            }
 
            addsamesize(cur, head2);
 
            propogatecarry(head1);
        }
            if (carry > 0)
                push(carry, 3);
         
    }

    

}
