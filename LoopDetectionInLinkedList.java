public class LoopDetectionInLinkedList {
    static class Node {
        public int data;
        public Node next;

        public Node(int data) {
            this.data = data;
        }

        public void addNode(int data) {

        }

    }

    public static boolean detecytCycle(Node head) {
        Node slow = head;
        Node fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            System.out.print("slow: " + slow.data);
            System.out.println(" fast : " + fast.data);
            if (slow.data == fast.data) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Node head = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);
        Node fourth = new Node(4);
        Node fifth = new Node(5);

        head.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = fifth;
        // Create a loop
        fifth.next = third;

        if (detecytCycle(head)) {
            System.out.println("Cycle detected");
        } else {
            System.out.println("Cycle undetected");
        }
    }

}

// Output

// slow: 2 fast : 3
// slow: 3 fast : 5
// slow: 4 fast : 4
// Cycle detected
