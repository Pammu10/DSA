public class SegregateEvenOddLinkedList {

    static ListNode head, tail;

    static void printList(ListNode head){
        ListNode curr = head;
        for (; curr != null; curr = curr.next){
            System.out.print(curr.data + " --> ");
        }
        System.out.println("null");
    }

    static void InsertatLast(int data){
        ListNode newNode = new ListNode(data);
        if (head == null){
            head = tail = newNode;
            }
            else {
                tail = tail.next = newNode;
            }
        }

        
    static ListNode segregateOddEven(){
        ListNode oddHead = new ListNode(-1), oddTail = oddHead;
        ListNode evenHead = new ListNode(-1), evenTail = evenHead;
        ListNode curr = head, temp;
        while (curr != null){
            temp = curr;
            curr = curr.next;
            temp.next = null;

            if (temp.data % 2 == 0){
                evenTail = evenTail.next = temp;
            }
            else {
                oddTail = oddTail.next = temp;
            }
        }
        evenTail.next = oddHead.next;
        return evenHead.next;
    }


    public static void main(String[] args) {
        InsertatLast(1);
    InsertatLast(2);
    InsertatLast(3);
    InsertatLast(4);
    System.out.println("Intial LinkedList : ");
    printList(head);
    ListNode newHead = segregateOddEven();
    System.out.println("LinkedList After Segregration ");
    printList(newHead);
    }
}




class ListNode{
    
    int data;
    ListNode next;
        ListNode(int data){
            this.data = data;
            this.next = null;
        }
    }
        


// Output 

// Intial LinkedList : 
// 1 --> 2 --> 3 --> 4 --> null
// LinkedList After Segregration
// 2 --> 4 --> 1 --> 3 --> null