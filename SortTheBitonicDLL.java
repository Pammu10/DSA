public class SortTheBitonicDLL {
    static class Node {
        int data;
        Node next;
        Node prev;

        public Node(int data) {
            this.data = data;
        }

    }

    Node head, tail = null;

    public void addNode(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = tail = newNode;
            head.prev = null;
            tail.next = null;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
            tail.next = null;
        }
    }

    public void sortList() {
        Node current = null;
        Node index = null;
        int temp;
        if (head == null) {
            return;
        } else {
            for (current = head; current.next != null; current = current.next) {
                for (index = current.next; index != null; index = index.next) {
                    if (current.data > index.data) {
                        temp = current.data;
                        current.data = index.data;
                        index.data = temp;
                    }
                }
            }
        }
    }

    public void display() {
        Node temp = head;
        if (temp.next == null || temp == null) {
            System.out.println("List is empty or too short");  

            return;
        } else {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
            while (temp.next != null) {
                System.out.print(temp.data + " -> ");
                temp = temp.next;
            }
            System.out.println(temp.data);

        }

    }

    public static void main(String[] args) {
        SortTheBitonicDLL listToSort = new SortTheBitonicDLL();
        listToSort.addNode(7);  
        listToSort.addNode(1);  
        listToSort.addNode(4);  
        listToSort.addNode(5);  
        listToSort.addNode(2); 

        System.out.println("Original list: ");  
        listToSort.display();  
           
        listToSort.sortList();  
           
        System.out.println("Sorted list: ");  
        listToSort.display();  

    }
}