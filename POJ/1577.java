import java.util.LinkedList;
import java.util.Scanner;


public class Main {
	
	static class node{
		
		node leftKid;
		node rightKid;
		char letter;
		
		public node(char x){
			letter = x;
		}
		
	}

	static node root;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		while(in.hasNext()){
			LinkedList<String> list = new LinkedList<String>();
			while(true){
				String line = in.nextLine();
				if(line.equals("*") || line.equals("$")){
					break;
				}
				list.add(line);
			}
			root = new node(list.get(list.size()-1).charAt(0));
			for(int i=list.size()-2; i>=0; i--){
				String line = list.get(i);
				for(int j=0; j<line.length(); j++){
					node newNode = new node(line.charAt(j));
					insert(newNode);
				}
			}
			preorder(root);
			System.out.println();
		}
		
	}
	
	public static void preorder(node current){
		if(current==null){
			return;
		}
		System.out.print(current.letter);
		preorder(current.leftKid);
		preorder(current.rightKid);
	}
	
	public static void insert(node newNode){
		
		node current = root;
		node parent;
		while(true){
			parent = current;
			if(newNode.letter<current.letter){
				current = current.leftKid;
				if(current==null){
					parent.leftKid = newNode;
					return;
				}
			}else{
				current = current.rightKid;
				if(current==null){
					parent.rightKid = newNode;
					return;
				}
			}
		}
		
	}
	
}
