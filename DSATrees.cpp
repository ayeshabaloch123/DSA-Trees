#include<iostream>
#include<fstream>
#include<conio.h>
#define SPACE 10
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//BST STARTS
class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class BST {
  public:
  	int countInsertionB;
  int countDeletionB ;
  int countSearchesB ;
    TreeNode * root;
  BST() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
     

  void insertNode(TreeNode * new_node) {
  	
    if (root == NULL) {
      root = new_node;
       countInsertionB++;
      cout << "Value Inserted as root node!" << endl;
    } else {

      TreeNode * temp = root;
          countInsertionB++;
      while (temp != NULL) {
        if (new_node -> value == temp -> value) {
          cout << "Value Already exist," <<
            "Insert another value!" << endl;
             countInsertionB++;
          return;
        } else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) {
          temp -> left = new_node;
           countInsertionB++;
          cout << "Value Inserted to the left!" << endl;

          break;
        } else if (new_node -> value < temp -> value) {
          temp = temp -> left;
           countInsertionB++;
        } else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) {
          temp -> right = new_node;
          cout << "Value Inserted to the right!" << endl;
 countInsertionB++;
          break;
        } else {
          temp = temp -> right;
           countInsertionB++;
        }
      }
    }
  }
  	TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)
	{
		 
               

		if(r==NULL)
		{

			r=new_node;
			cout <<"Insertion successful"<<endl;

			return r;
		}
		if(new_node->value < r->value)
		{    
			r->left = insertRecursive(r->left,new_node);
		}
		else if (new_node->value > r->value)  
		{
			r->right = insertRecursive(r->right,new_node);
		}
	   else
	   {
	     	cout << "No duplicate values allowed!" << endl;
	     	return r; 
		}
		return r;
	}
	
	int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      /* compute the height of each subtree */
      int lheight = height(r -> left);
      int rheight = height(r -> right);

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }

  void print2D(TreeNode * r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> value << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }
  
 
 

  TreeNode * iterativeSearch(int v) {
  	 fstream file;
      file.open("SearchBST.txt",ios::app | ios::out);
    if (root == NULL) {
      return root;
    } 

	else {
		               file<<"S  "<<v<<endl;

      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
        	countSearchesB++;
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
              		file.close();

      }
      return NULL;
    }
  }

 TreeNode * recursiveSearch(TreeNode * r, int val) {
  	
                   

    if (r == NULL || r -> value == val) {
      countSearchesB++;
      return r;
    }
    else if (val < r -> value)
      return recursiveSearch(r -> left, val);

    else

      return recursiveSearch(r -> right, val);

  }

  
  

  /* Print nodes at a given level */
  void printGivenLevel(TreeNode * r, int level) {
    if (r == NULL)
      return;
    else if (level == 0)
      cout << r -> value << " ";
    else // level > 0  
    {
      printGivenLevel(r -> left, level - 1);
      printGivenLevel(r -> right, level - 1);
    }
  }
  
  TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }

  TreeNode * deleteNode(TreeNode * r, int v) {
  	  fstream file2;
      file2.open("DeleteBST.txt",ios::app | ios::out); 
    // base case 
        	

    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 

    else if (v < r -> value) {

      r -> left = deleteNode(r -> left, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > r -> value) {
      r -> right = deleteNode(r -> right, v);

    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
    	file2<<"D  "<<v<<endl;
      // node with only one child or no child 
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
         countDeletionB++;

        return temp;
      } else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        countDeletionB++;

        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minValueNode(r -> right);
        // Copy the inorder successor's content to this node 
        r -> value = temp -> value;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp -> value);
        //deleteNode(r->right, temp->value); 
      }
    }
    return r;
                  file2.close();

  }

};
//BST ENDS
//AVL STARTS


class AVLTree {
  public:
   int countInsertionA ;
  int countDeletionA  ;
  int countSearchesA ;
    TreeNode * root;
  AVLTree() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
  // Get Height  
  int height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      /* compute the height of each subtree */
      int lheight = height(r -> left);
      int rheight = height(r -> right);

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }

  // Get Balance factor of node N  
  int getBalanceFactor(TreeNode * n) {
    if (n == NULL)
      return -1;
    return height(n -> left) - height(n -> right);
  }

  TreeNode * rightRotate(TreeNode * y) {
    TreeNode * x = y -> left;
    TreeNode * T2 = x -> right;

    // Perform rotation  
    x -> right = y;
    y -> left = T2;

    return x;
  }

  TreeNode * leftRotate(TreeNode * x) {
    TreeNode * y = x -> right;
    TreeNode * T2 = y -> left;

    // Perform rotation  
    y -> left = x;
    x -> right = T2;

    return y;
  }

  TreeNode * insert(TreeNode * r, TreeNode * new_node) {

      
           

    if (r == NULL) {

      r = new_node;
      cout << "Value inserted successfully" << endl;
            countInsertionA++;

      return r;

    }

    if (new_node -> value < r -> value) {
       

      r -> left = insert(r -> left, new_node);
    } else if (new_node -> value > r -> value) {
      r -> right = insert(r -> right, new_node);

    } else {
      cout << "No duplicate values allowed!" << endl;

      return r;

    }

    int bf = getBalanceFactor(r);
    // Left Left Case  
    if (bf > 1 && new_node -> value < r -> left -> value)
      return rightRotate(r);

    // Right Right Case  
    if (bf < -1 && new_node -> value > r -> right -> value)
      return leftRotate(r);

    // Left Right Case  
    if (bf > 1 && new_node -> value > r -> left -> value) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }

    // Right Left Case  
    if (bf < -1 && new_node -> value < r -> right -> value) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    /* return the (unchanged) node pointer */
    return r;
  }

  TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }

  

 
  void print2D(TreeNode * r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> value << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }
  void printPreorder(TreeNode * r) //(current node, Left, Right) 
  {
    if (r == NULL)
      return;
    /* first print data of node */
    cout << r -> value << " ";
    /* then recur on left sutree */
    printPreorder(r -> left);
    /* now recur on right subtree */
    printPreorder(r -> right);
  }

  void printInorder(TreeNode * r) //  (Left, current node, Right)
  {
    if (r == NULL)
      return;
    /* first recur on left child */
    printInorder(r -> left);
    /* then print the data of node */
    cout << r -> value << " ";
    /* now recur on right child */
    printInorder(r -> right);
  }
  void printPostorder(TreeNode * r) //(Left, Right, Root)
  {
    if (r == NULL)
      return;
    // first recur on left subtree 
    printPostorder(r -> left);
    // then recur on right subtree 
    printPostorder(r -> right);
    // now deal with the node 
    cout << r -> value << " ";
  }

  /* Print nodes at a given level */
  void printGivenLevel(TreeNode * r, int level) {
    if (r == NULL)
      return;
    else if (level == 0)
      cout << r -> value << " ";
    else // level > 0  
    {
      printGivenLevel(r -> left, level - 1);
      printGivenLevel(r -> right, level - 1);
    }
  }
  void printLevelOrderBFS(TreeNode * r) {
    int h = height(r);
    for (int i = 0; i <= h; i++)
      printGivenLevel(r, i);
  }

        
  
   TreeNode * iterativeSearch(int v) {
  	

    if (root == NULL) {
      return root;
    } 

	else {

      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
        	countSearchesA++;
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }

      }
      return NULL;
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

   TreeNode * recursiveSearch(TreeNode * r, int val) {
      
 fstream file2;
      file2.open("SearchAVL.txt",ios::app | ios::out);
      		               file2<<"S  "<<val<<endl;
    if (r == NULL || r -> value == val){
      countSearchesA++;
      return r;
              		file2.close();

	  }

       else if (val < r -> value)

      return recursiveSearch(r -> left, val);

    else
    

      return recursiveSearch(r -> right, val);
  }
  
    

  TreeNode * deleteNode(TreeNode * r, int v) {
    fstream file1;
      file1.open("DeleteAVL.txt",ios::app | ios::out);


    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    
    else if (v < r -> value) {
      r -> left = deleteNode(r -> left, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > r -> value) {
      r -> right = deleteNode(r -> right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
    	           file1<<"D "<<v<<endl;

      // node with only one child or no child 
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
         countDeletionA++;

        return temp;
      } else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
                file1.close();

       countDeletionA++;

        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minValueNode(r -> right);
        // Copy the inorder successor's content to this node 
        r -> value = temp -> value;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp -> value);
        //deleteNode(r->right, temp->value); 
      }
    }
 int bf = getBalanceFactor(r);
    // Left Left Imbalance/Case or Right rotation 
    if (bf == 2 && getBalanceFactor(r -> left) >= 0)
      return rightRotate(r);
    // Left Right Imbalance/Case or LR rotation 
    else if (bf == 2 && getBalanceFactor(r -> left) == -1) {
      r -> left = leftRotate(r -> left);
      return rightRotate(r);
    }
    // Right Right Imbalance/Case or Left rotation	
    else if (bf == -2 && getBalanceFactor(r -> right) <= -0)
      return leftRotate(r);
    // Right Left Imbalance/Case or RL rotation 
    else if (bf == -2 && getBalanceFactor(r -> right) == 1) {
      r -> right = rightRotate(r -> right);
      return leftRotate(r);
    }

    return r;
  }
};

//AVL ENDS
//SPLAY STARTS
  struct splay

    {

        int key;

        splay* lchild;

        splay* rchild;

    };

   class SplayTree

    {

        public:
            int countInsertionS ;
            int countDeletionS ;
            int countSearchesS ;
            SplayTree()

            {

            }

            // RR(Y rotates to the right)

            splay* RR_Rotate(splay* k2)

            {

                splay* k1 = k2->lchild;

                k2->lchild = k1->rchild;

                k1->rchild = k2;

                return k1;

            }

            // LL(Y rotates to the left)

            splay* LL_Rotate(splay* k2)

            {

                splay* k1 = k2->rchild;

                k2->rchild = k1->lchild;

                k1->lchild = k2;

                return k1;

            }

            // An implementation of top-down splay tree

            splay* Splay(int key, splay* root)

            {

                if (!root)

                    return NULL;

                splay header;

                /* header.rchild points to L tree;

                header.lchild points to R Tree */

                header.lchild = header.rchild = NULL;

                splay* LeftTreeMax = &header;

                splay* RightTreeMin = &header;

                while (1)

                {

                    if (key < root->key)

                    {

                        if (!root->lchild)

                            break;

                        if (key < root->lchild->key)

                        {

                            root = RR_Rotate(root);

                            // only zig-zig mode need to rotate once,

                            if (!root->lchild)

                                break;

                        }

                        /* Link to R Tree */

                        RightTreeMin->lchild = root;

                        RightTreeMin = RightTreeMin->lchild;

                        root = root->lchild;

                        RightTreeMin->lchild = NULL;

                    }

                    else if (key > root->key)

                    {

                        if (!root->rchild)

                            break;

                        if (key > root->rchild->key)

                        {

                            root = LL_Rotate(root);

                            // only zag-zag mode need to rotate once,

                            if (!root->rchild)

                                break;

                        }

                        /* Link to L Tree */

                        LeftTreeMax->rchild = root;

                        LeftTreeMax = LeftTreeMax->rchild;

                        root = root->rchild;

                        LeftTreeMax->rchild = NULL;

                    }

                    else

                        break;

                }

                /* assemble L Tree, Middle Tree and R tree */

                LeftTreeMax->rchild = root->lchild;

                RightTreeMin->lchild = root->rchild;

                root->lchild = header.rchild;

                root->rchild = header.lchild;

                return root;

            }

            splay* New_Node(int key)

            {

                splay* p_node = new splay;

                if (!p_node)

                {

                    fprintf(stderr, "Out of memory!\n");

                    exit(1);

                }

                p_node->key = key;

                p_node->lchild = p_node->rchild = NULL;

                return p_node;

            }

            splay* Insert(int key, splay* root)

            {
                 fstream file;
               file.open("InsertSplay.txt",ios::app | ios::out); 
                static splay* p_node = NULL;

                if (!p_node)

                    p_node = New_Node(key);

                else

                    p_node->key = key;

                if (!root)

                {

                    root = p_node;

                    p_node = NULL;
                    countInsertionS++;
                    return root;

                }

                root = Splay(key, root);
                                  file<<"I  "<<key<<endl;

                /* This is BST that, all keys <= root->key is in root->lchild, all keys >

                root->key is in root->rchild. */

                if (key < root->key)

                {

                    p_node->lchild = root->lchild;

                    p_node->rchild = root;

                    root->lchild = NULL;

                    root = p_node;

                }

                else if (key > root->key)

                {

                    p_node->rchild = root->rchild;

                    p_node->lchild = root;

                    root->rchild = NULL;

                    root = p_node;

                }

                else
                    countInsertionS++;
                    return root;

                p_node = NULL;
                return root;
               file.close();
            }

            splay* Delete(int key, splay* root)

            {
            	fstream file1;
                file1.open("DeleteSplay.txt",ios::app | ios::out); 
                file1<<"D  "<<key<<endl;

                splay* temp;

                if (!root)

                    return NULL;

                root = Splay(key, root);

                if (key != root->key){
                    countDeletionS++;
                    return root;}

                else

                {

                    if (!root->lchild)

                    {

                        temp = root;

                        root = root->rchild;

                    }

                    else

                    {

                        temp = root;

                        /*Note: Since key == root->key,

                        so after Splay(key, root->lchild),

                        the tree we get will have no right child tree.*/

                        root = Splay(key, root->lchild);

                        root->rchild = temp->rchild;

                    }

                    free(temp);
                    countDeletionS++;
                    return root;

                }
                file1.close();

            }

            splay* Search(int key, splay* root)

            {
            	fstream file2;
                file2.open("SearchSplay.txt",ios::app | ios::out); 
                file2<<"S  "<<key<<endl;
                countSearchesS++;
                return Splay(key, root);

            }

            void InOrder(splay* root)

            {

                if (root)

                {

                    InOrder(root->lchild);

                    cout<< "key: " <<root->key;

                    if(root->lchild)

                        cout<< " | left child: "<< root->lchild->key;

                    if(root->rchild)

                        cout << " | right child: " << root->rchild->key;

                    cout<< "\n";

                    InOrder(root->rchild);

                }

            }

    };

   

//SPLAY ENDS

print_method() {
 	cout<<"1. Binary Tree"<<endl;
	cout<<"2. Avl Tree"<<endl;
	cout<<"3. Splay Tree"<<endl;
	cout<<"4. Final table"<<endl;
	cout<<"0. exit"<<endl;
	
	int option;
	cout<<"In which tree do you want to perform operations? ";
	cin>>option;
	 BST obj;
	 AVLTree obj1;
	SplayTree  st;
      
	if(option==1){
		
  int option, val;

 do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST values" << endl;
    cout << "0.Back to Main" << endl;

    cin >> option;
    //Node n1;

    TreeNode * new_node = new TreeNode();
     fstream file1;
      file1.open("InsertBST.txt",ios::app | ios::out); 
    switch (option) {
    		

    case 0:
    	print_method();
      break;
    case 1:
      	cout <<"INSERT"<<endl;
      

	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->value = val;
                               file1<<"I  "<<val<<endl; 
                         
	      obj.root= obj.insertRecursive(obj.root,new_node);
	      //obj.insertNode(new_node);
	      		   

	      cout<<endl;
	            file1.close();

    		break;
       
    case 2:
      cout << "SEARCH" << endl;

      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;
     
      //new_node = obj.iterativeSearch(val);

      new_node = obj.recursiveSearch(obj.root, val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      new_node = obj.iterativeSearch(val);
      if (new_node != NULL) {
        obj.deleteNode(obj.root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      cout << "Height : " << obj.height(obj.root) << endl;

     
      break;
  
    
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

	}
	
	
	if(option==2){
		AVLTree obj1;
  int option, val;
  
  
  
  
  
  do {
  	cout << "****AVL TREE****" << endl;
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal AVL Tree values" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Back to Main" << endl;

    cin >> option;
    //Node n1;
    TreeNode * new_node = new TreeNode();
     fstream file;
               file.open("InsertAVL.txt",ios::app | ios::out); 
               
    switch (option) {
    case 0:
    	print_method();
      break;
    case 1:

      cout << "AVL INSERT" << endl;
      cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
      
      cin >> val;
                                                  file<<"I "<<val<<endl;

      new_node -> value = val;

      obj1.root = obj1.insert(obj1.root, new_node);
      cout << endl;
 file.close();
      break;
    case 2:
    	
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
     

      cin >> val;

      //new_node = obj.iterativeSearch(val);
      new_node = obj1.recursiveSearch(obj1.root, val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }             

      break;

    case 3:
    

      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
      cin >> val;

      new_node = obj1.recursiveSearch(obj1.root, val);
      if (new_node != NULL) {
        obj1.root = obj1.deleteNode(obj1.root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj1.print2D(obj1.root, 5);
      cout << endl;
      
      break;
    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj1.height(obj1.root) << endl;
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);
	}
	
	if(option==3){
		cout << "****SPLAY TREE****" << endl;
		 SplayTree st;

        int vector[10] = {9,8,7,6,5,4,3,2,1,0};

        splay *root;

        root = NULL;

        const int length = 10;

        int i;

        for(i = 0; i < length; i++)

            root = st.Insert(vector[i], root);

        cout<<"\nInOrder: \n";

        st.InOrder(root);

        int input, choice;

        while(1)

        {

            cout<<"\nSplay Tree Operations\n";

            cout<<"1. Insert "<<endl;

            cout<<"2. Delete"<<endl;

            cout<<"3. Search"<<endl;

            cout<<"4. Back to Main"<<endl;

            cout<<"Enter your choice: ";

            cin>>choice;

            switch(choice)

            {

            case 1:

                cout<<"Enter value to be inserted: ";

                cin>>input;

                root = st.Insert(input, root);

                cout<<"\nAfter Insert: "<<input<<endl;

                st.InOrder(root);

                break;

            case 2:

               cout<<"Enter value to be deleted: ";

                cin>>input;

                root = st.Delete(input, root);

                cout<<"\nAfter Delete: "<<input<<endl;

                st.InOrder(root);

                break;

            case 3:

                cout<<"Enter value to be searched: ";

                cin>>input;

                root = st.Search(input, root);

                cout<<"\nAfter Search "<<input<<endl;

                st.InOrder(root);

                break;

            case 4:

                print_method();
                return 0;

            default:

                cout<<"\nInvalid type! \n";

            }

        }
	}
	
if(option==4){
	cout<<"\t\tOperation Counts"<<endl;
  cout<<"\t\tBST \t AVL \t Splay"<<endl;
  cout<<"Search   \t"+to_string(obj.countSearchesB)+"\t"+to_string(obj1.countSearchesA)+"\t"+to_string(st.countSearchesS)<<endl;
  cout<<"Insert  \t"+to_string(obj.countInsertionB)+"\t"+to_string(obj1.countInsertionA)+"\t"+to_string(st.countInsertionS)<<endl;
  cout<<"Delete  \t"+to_string(obj.countDeletionB)+"\t"+to_string(obj1.countDeletionA)+"\t"+to_string(st.countDeletionS)<<endl;
  cout<<"\t\t------------------"<<endl;
  cout<<"Total  \t"<<endl;

}
	if(option==0){
	
	}
return 0;
	
}
	int main() {
      print_method();
	
return 0;
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


