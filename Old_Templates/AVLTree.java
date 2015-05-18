
/*
 * 		Binary Search Tree Template Code
 * 
 * 			Comments by Jim Gao
 */

public class AVLTree <T extends Comparable<T>>{

    public AVLTree(){
        this(null);
    }
	
	/*
	 * 		data: 		The pointer of the current object
	 * 		parent: 	The parent node of the current BST
	 * 		leftChild:	The left child of the current BST
	 * 		rightChild:	The right child of the current BST
	 * 		height: 	The number of levels / height of the current BST
	 */

    /*
     * 		Constructor
     */
    public AVLTree(T t){
        data=t;
        parent=null;
        leftChild=null;
        rightChild=null;
        height=t==null?-1:0;
    }

    public int getHeight(){
        return updateHeight();
    }

    public AVLTree<T> getRoot(){
        if(data==null)
            return null;
        AVLTree<T>root=this;
        while(root.parent!=null)
            root=root.parent;
        return root;
    }

    public AVLTree<T>getLeftChild(){
        return leftChild;
    }

    public AVLTree<T>getRightChild(){
        return rightChild;
    }

    public AVLTree<T>getParent(){
        return parent;
    }

    public boolean isEmpty(){
        return data==null;
    }

    /*
     * 		IMPORTANT:
     * 			The code to insert another node under
     * 			the current BST node.
     */
    public AVLTree<T> insert(T t){
        if(t==null)
            return this;

        if(data==null){
            data=t;
            updateHeight();
            return this;
        }
        AVLTree<T>root=getRoot();//���ڵ�
        return root.rootInsert(t);
    }


    public AVLTree<T> delete(T t){
        AVLTree<T>root=getRoot();
        return root.rootDelete(t);
    }

    public AVLTree<T> find(T t){
        AVLTree<T>root=getRoot();
        return root.rootFind(t);
    }

    /*
     * 		Prints a user-friendly chart of the current BST
     */
    public void display(){

        if(data==null||(parent!=null&&leftChild==null&&rightChild==null))
            return;
        System.out.println(String.format("H=%2d, %s->(%s,%s)",
                height,
                data.toString(),
                leftChild==null?null:leftChild.data.toString(),
                rightChild==null?null:rightChild.data.toString()));
        if(leftChild!=null)
            leftChild.display();
        if(rightChild!=null)
            rightChild.display();
    }


    /*
     * 		Check if the current BST is balanced
     */
    public boolean checkBalance(){
        int left=getLeftHeight(),
                right=getRightHeight();
        if(left-right>1||right-left>1)
            return false;
        if(leftChild!=null&&!leftChild.checkBalance())
            return false;
        if(rightChild!=null&&!rightChild.checkBalance())
            return false;
        return true;
    }

    /*
     * 		The encapsulated data of the current BST
     *
     * 		For detailed information, go to the constructor at the start.
     */
    protected T data;
    protected AVLTree<T> parent;
    protected AVLTree<T> leftChild;
    protected AVLTree<T> rightChild;
    protected int height;

    /*
     * 		Get the height of the left kid of the current BST
     */
    private int getLeftHeight(){
        return leftChild==null?-1:leftChild.height;
    }

    /*
     * 		Get the height of the right kid of the current BST (duh...)
     */
    private int getRightHeight(){
        return rightChild==null?-1:rightChild.height;
    }


    /*
     * 		Get the node under current BST that has the greatest weight
     */
    private AVLTree<T>getMax(){
        if(isEmpty())
            return null;
        if(rightChild!=null)
            return rightChild.getMax();
        return this;
    }


    /*
     * 		Get the node under current BST that as the minimum weight
     */
    private AVLTree<T>getMin(){
        if(isEmpty())
            return null;
        if(leftChild!=null)
            return leftChild.getMin();
        return this;
    }

    /*
     * 		Get the depth / height of the current BST
     */
    private int depth(AVLTree<T>node){
        int dep=0;
        while(node!=null&&this!=node){
            dep++;
            node=node.parent;
        }
        return node!=null?dep:-1;
    }


    /*
     * 		Look for the node 't' under the root of
     * 		the current BST
     */
    private AVLTree<T>rootFind(T t){
        if(t!=null&&data!=null){
            int cp=t.compareTo(data);
            if(cp==0)
                return this;
            if(cp>0)
                return rightChild==null?null:rightChild.rootFind(t);
            return leftChild==null?null:leftChild.rootFind(t);
        }
        return null;
    }

    /*
     * 		Delete the node 't' under the current BST
     */
    private AVLTree<T>rootDelete(T t){

        AVLTree<T>del=rootFind(t);
        if(del==null)
            return this;

        del.data=null;
        AVLTree<T>maxL=null,minR=null,updatePos=del;
        int dL,dR;

        maxL=del.leftChild==null?null:del.leftChild.getMax();

        minR=del.rightChild==null?null:del.rightChild.getMin();

        dL=del.depth(maxL);
        dR=del.depth(minR);
		
		/*
		 * 		The 3 cases we talked about in class.
		 * 
		 * 		Case 1: The node has no child.
		 * 		Case 2: The node has one child (can be smaller or larger)
		 * 		Case 3: The node has 2 children. 
		 */
        if(minR==null&&maxL==null){
            updatePos=del.divFromParent();
            del.parent=null;
        }

        else if(dL>dR||(dL==dR&&del.getLeftHeight()>del.getRightHeight())){
            del.data=maxL.data;
            updatePos=maxL.divFromParent();
            if(maxL.leftChild!=null){
                if(dL==1)
                    updatePos.leftChild=maxL.leftChild;
                else
                    updatePos.rightChild=maxL.leftChild;
                maxL.leftChild.parent=updatePos;
            }
        }else{
            del.data=minR.data;
            updatePos=minR.divFromParent();
            if(minR.rightChild!=null){
                if(dR==1)
                    updatePos.rightChild=minR.rightChild;
                else
                    updatePos.leftChild=minR.rightChild;
                minR.rightChild.parent=updatePos;
            }
        }
        if(updatePos!=null){
            return updatePos.update();
        }
        return this;
    }

    private AVLTree<T>divFromParent(){
        AVLTree<T>p=parent;
        if(parent!=null){
            if(parent.leftChild==this)
                parent.leftChild=null;
            else
                parent.rightChild=null;
            parent.updateHeight();
            parent=null;
        }
        return p;
    }

    private AVLTree<T>update(){
        if(data==null)
            return this;

        AVLTree<T>root=rootUpdate();
        while(root.parent!=null){

            root=root.parent.rootUpdate();
        }
        return root;
    }

    private AVLTree<T>rootUpdate(){

        int Rh=getRightHeight(),
                Lh=getLeftHeight();
        AVLTree<T>root=this;

        if(Lh-Rh==2){
            if(leftChild.getLeftHeight()>=leftChild.getRightHeight()){
                root=rotateLeft(this);
            }else{
                rotateRight(leftChild);
                root=rotateLeft(this);
            }
        }else if(Rh-Lh==2){
            if(rightChild.getLeftHeight()<=rightChild.getRightHeight()){
                root=rotateRight(this);
            }else{
                rotateLeft(rightChild);
                root=rotateRight(this);
            }
        }

        root.updateHeight();
        return root;
    }

    /*
     * 		Recalculate the height of current BST
     */
    private int updateHeight(){
        if(data==null){
            height=-1;
            return height;
        }
        int right=getRightHeight(),left=getLeftHeight();
        height=left>right?(1+left):(1+right);
        return height;
    }

    /*
     * 		Insert a node 't' into the current BST
     */
    private AVLTree<T>rootInsert(T t){
        int cp=t.compareTo(data);

        if(cp==0){
            data=t;
            return this;
        }

        if(cp<0){
            if(leftChild==null){
                leftChild=new AVLTree<T>(t);
                leftChild.parent=this;
            }else{
                leftChild.rootInsert(t);
            }
        }else{
            if(rightChild==null){
                rightChild=new AVLTree<T>(t);
                rightChild.parent=this;
            }else{
                rightChild.rootInsert(t);
            }
        }

        return rootUpdate();
    }


    private static <T extends Comparable<T>> AVLTree<T> rotateLeft(
            AVLTree<T> tree) {
        if(tree==null||tree.leftChild==null)
            return tree;
        AVLTree<T>root=tree.leftChild;
        tree.leftChild=root.rightChild;
        if(tree.leftChild!=null)
            tree.leftChild.parent=tree;
        root.rightChild=tree;
        root.parent=tree.parent;
        tree.parent=root;
        if(root.parent!=null){
            if(root.parent.leftChild==tree)
                root.parent.leftChild=root;
            else
                root.parent.rightChild=root;
        }
        tree.updateHeight();
        root.updateHeight();
        return root;
    }

    private static <T extends Comparable<T>> AVLTree<T> rotateRight(
            AVLTree<T> tree) {
        if(tree==null||tree.rightChild==null)
            return tree;
        AVLTree<T>root=tree.rightChild;
        tree.rightChild=root.leftChild;
        if(tree.rightChild!=null)
            tree.rightChild.parent=tree;
        root.leftChild=tree;
        root.parent=tree.parent;
        tree.parent=root;

        if(root.parent!=null){
            if(root.parent.leftChild==tree)
                root.parent.leftChild=root;
            else
                root.parent.rightChild=root;
        }

        tree.updateHeight();
        root.updateHeight();
        return root;
    }
}
