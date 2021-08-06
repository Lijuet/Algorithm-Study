#include <iostream>

using namespace std;

class BST {
    int data;
    BST *left, *right;

public:
    // Constructor
    BST(); 
    BST(int);   

    // Operation
    BST* Search(BST*, int);
    BST* Insert(BST*, int);
    BST* Delete(BST*, int);
    BST* AdvancedDelete(BST*, int);
    void Inorder(BST*);
};

// Constructor
BST::BST() : data(0), left(NULL), right(NULL) {}

BST::BST(int key) : data(key), left(NULL), right(NULL) {}

// Operation
BST* BST::Search(BST* root, int key){
    if(root == NULL || root->data == key) return root;

    if(key > root->data) return Search(root->right, key);
    else return Search(root->left, key);
}

BST* BST::Insert(BST* root, int key){
    if(root == NULL) root = new BST(key); // If root is null, Insert the new node
    else if(key > root->data) root->right = Insert(root->right, key);
    else root->left = Insert(root->left, key);

    return root;
}

BST* BST::Delete(BST* root, int key){
    // Find the node with the key
    if(key > root->data) {
        root->right = Delete(root->right, key);
    } else if(key < root->data) {
        root->left = Delete(root->left, key);
    } else {
        BST* deletedNode = root;
        // CASE 1 : If the root is leaf node
        if(!root->left && !root->right) {
            root = NULL;
            delete deletedNode;
        }
        // CASE 2 : If the root has only one child
        else if(!root->left || !root->right){
            root = root->left ? root->left : root->right;
            delete deletedNode;
        }
        // CASE 3 : If the root has two children
        else if(root->left && root->right){
            // Find inorder successor
            BST* succ = root->right;
            while(succ->left != NULL) {
                succ = succ->left;
            }
            // Copy data
            root->data = succ->data;

            // Will delete successor memory
            root->right = Delete(root->right, succ->data);
        }
    }
    return root;    
}

BST* BST::AdvancedDelete(BST* root, int key){
    // Find the node with the key
    if(key > root->data) {
        root->right = Delete(root->right, key);
    } else if(key < root->data) {
        root->left = Delete(root->left, key);
    } else{
        BST* deletedNode = root;
        // CASE 1 : If the root is leaf node
        if(!root->left && !root->right) root = NULL;
        // CASE 2 : If the root has only one child
        else if(!root->left || !root->right)
            root = root->left ? root->left : root->right;
        // CASE 3 : If the root has two children
        else if(root->left && root->right){
            // Find inorder successor
            BST* succParent = root;
            BST* succ = root->right;
            while(succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }
            
            // Successor is the left child of some parent node
            if(succParent != root) succParent->left = succ->right;
            // Successor is some parent node which only has right node
            else succParent->right = succ->right;

            // Copy data
            root->data = succ->data;

            // Will delete successor memory
            deletedNode = succ;
        }

        delete deletedNode;
    }
    return root;
}

void BST::Inorder(BST* root){
    if(!root) return;

    Inorder(root->left);        // Left Recursion
    cout << root->data << " ";  // Do sth
    Inorder(root->right);       // Right Recursion
}

//*******************PROBLEM SOLVING*******************
// Sol for Lowest Common Ancestor
// https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

void LCA(BST* root, int a, int b){
    int bigger = a > b? a : b;
    int smaller = a < b? a : b;

    while(root != NULL){
        if(bigger < root->data) root = root->left;
        else if(smaller > root->data) root = root->right;
        else break;
    }

    return root;  
}

int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);
 
    cout << "***************Inorder Test***************" << endl;
    b.Inorder(root);
    cout << endl;

    cout << "***************Exist Test***************" << endl;
    if(b.Search(root, 30)) cout << "Exist 30" << endl;
    else cout << "No Exist 30" << endl;
    if(b.Search(root, 10)) cout << "Exist 10" << endl;
    else cout << "No Exist 10" << endl;
    
    cout << "***************Delete Test***************" << endl;
 
    printf("Inorder traversal of the given tree \n");
    b.Inorder(root);
    cout << endl;
 
    printf("\nDelete 20\n");
    b.AdvancedDelete(root, 20);
    printf("Inorder traversal of the modified tree \n");
    b.Inorder(root);
    cout << endl;
 
    printf("\nDelete 30\n");
    b.AdvancedDelete(root, 30);
    printf("Inorder traversal of the modified tree \n");
    b.Inorder(root);
    cout << endl;
 
    printf("\nDelete 50\n");
    b.AdvancedDelete(root, 50);
    printf("Inorder traversal of the modified tree \n");
    b.Inorder(root);
    cout << endl;
    return 0;
}