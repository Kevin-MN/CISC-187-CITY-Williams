/**Date:7/27/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Binary Trees, Chapter 21
 * 
 * This file contains the class specification for the binary tree data structure, the default 
 * constructor is provided and the prototypes for the methods specified in the assignment.
 * */
#ifndef INTBINARYTREE_H //.h file is the specification file and is used for 
#define INTBINARYTREE_H  // class decleration
#include <string>
using namespace std;

class IntBinaryTree{
    private:
        struct TreeNode{ // struct for binary tree
          int value;
          TreeNode *left;
          TreeNode *right;
        };
        
        TreeNode *root;
        
        //These are the private helper methods that carry out the recursion
        void insert(TreeNode *&, TreeNode *&);
        void recurDisplayInOrder(TreeNode *) const;
        int recurLeafCount(TreeNode *);
        int recurTreeHeight(TreeNode *);
        int recurTreeWidth(TreeNode *);
        int recurLevelWidth(TreeNode *,int);
        
    public:
        IntBinaryTree(){
            root = nullptr;
        }
        
        ~IntBinaryTree();
        void insertNode(int);
        
        //These inline function are basically outer shells to call the recursive 
        //methods and pass the root as the starting node
        void displayInOrder() const {
            recurDisplayInOrder(root);
        }
        
        int leafCount(){
            return recurLeafCount(root);
        }
        
        int treeHeight(){
            return recurTreeHeight(root);
        }
        
        int treeWidth(){
            return recurTreeWidth(root);
        }
};
#endif