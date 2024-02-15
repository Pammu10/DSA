public class MergeSortDll {
    static void addNode(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = tail = newNode;
        } else {
            tail = tail.next = new Node(data);
        }
    }

    static void displayList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " --> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    static Node split(Node head) {
        Node fast = head, slow = head;
        while (fast.next != null && fast.next.next != null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        Node temp = slow.next;
        slow.next = null;
        return temp;

    }

    static Node mergeSort(Node node) {
        if (node == null || node.next == null) {
            return node;
        }
        Node splitNode = split(node);
        node = mergeSort(node);
        splitNode = mergeSort(splitNode);

        return merge(node, splitNode);
    }

    static Node merge(Node first, Node second) {
        if (first == null) {
            return second;
        }
        if (second == null) {
            return first;
        }
        if (first.data < second.data) {
            first.next = merge(first.next, second);
            first.next.prev = first;
            first.prev = null;
            return first;
        } else {
            second.next = merge(first, second.next);
            second.next.prev = second;
            second.prev = null;
            return second;
        }
    }

    static Node head, tail;

    public static void main(String[] args) {
        addNode(10);
        addNode(30);
        addNode(3);
        addNode(4);
        addNode(20);
        addNode(5);
        displayList(head);
        Node SortedList = null;
        SortedList = mergeSort(head);
        displayList(SortedList);
    }
}

class Node {
    int data;
    Node next, prev;

    Node(int data) {
        this.data = data;
        this.next = this.prev = null;
    }
}

// Output 

// 10 --> 30 --> 3 --> 4 --> 20 --> 5 --> null
// 3 --> 4 --> 5 --> 10 --> 20 --> 30 --> null