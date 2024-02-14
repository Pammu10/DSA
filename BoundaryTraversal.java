import java.util.Scanner;

public class BoundaryTraversal {
    static Node root;
	static void printLeaves(Node node)
	{
		if (node == null)
			return;

		printLeaves(node.left);
		if (node.left == null && node.right == null)
			System.out.print(node.data + " ");
		printLeaves(node.right);
	}
    static void printBoundaryLeft(Node node)
	{
		if (node == null)
			return;

		if (node.left != null) {
			System.out.print(node.data + " ");
			printBoundaryLeft(node.left);
		}
		else if (node.right != null) {
			System.out.print(node.data + " ");
			printBoundaryLeft(node.right);
		}
	}
    static void printBoundaryRight(Node node)
	{
		if (node == null)
			return;

		if (node.right != null) {
			printBoundaryRight(node.right);
			System.out.print(node.data + " ");
		}
		else if (node.left != null) {
			printBoundaryRight(node.left);
			System.out.print(node.data + " ");
		}
	}
    static void printBoundary(Node node)
	{
		if (node == null)
			return;
		System.out.print(node.data + " ");
		printBoundaryLeft(node.left);
		printLeaves(node.left);
		printLeaves(node.right);
		printBoundaryRight(node.right);
	}
static Node insert(Node root, int data) {

		if (root == null)
			root = new Node(data);
else if (root.data < data)
			root.right = insert(root.right, data);
		else
			root.left = insert(root.left, data);
		return root;
	}
	public static void main(String args[]) {
	    Scanner sc = new Scanner(System.in);
	    int input = sc.nextInt();
      	    while(input >= 0)   {
                    root = insert(root, input);
                    input = sc.nextInt();      
	   }
	 printBoundary(root);
    }	
} 



class Node {
	int data;
	Node left, right;

	Node(int item)
	{
		data = item;
		left = right = null;
	}
 }

