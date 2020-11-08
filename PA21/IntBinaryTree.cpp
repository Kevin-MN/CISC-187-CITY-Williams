/**Date:7/27/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Binary Trees, Chapter 21
 * 
 * This file contains the implementation for the binary tree with added methdos specified by the assignemt,
 * the majority of the methods are implemented recursively
 * */
#include "IntBinaryTree.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//This method is used to insert a new node, the new node os initialized then recursively placed into tree
void IntBinaryTree::insertNode(int num){
    // initialize node
    TreeNode *newNode = nullptr;
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;
    
    insert(root,newNode); // place node recursively
}

//this is the private helper method that recursively traverses the binary tree to place the new node
//we pass a reference to the pointer so that we can work with the actual argument instead of a copy
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode){
    if(nodePtr == nullptr){ // either tree is empty or we have reached the end of a path, set new node, base case
        nodePtr = newNode;
    }
    else if(newNode->value < nodePtr->value){
        insert(nodePtr->left,newNode); // take left path is lesss than
    }
    else{
        insert(nodePtr->right,newNode); //right path if more than or equal 
    }
}

//this method is used ot display the tree recursively 
void IntBinaryTree::recurDisplayInOrder(TreeNode *nodePtr) const{
    if(nodePtr){
        recurDisplayInOrder(nodePtr->left); // traverse until at the left end 
        cout << nodePtr->value << " "; //print
        recurDisplayInOrder(nodePtr->right); // after printing the left node and unwinding take right node 
    }
    // the base case is implicit because if ther if statement does not execute then nothing happens, I guess unwinding occurs
}

//this method is used to count the number of leaf nodes
int IntBinaryTree::recurLeafCount(TreeNode *nodePtr){
    if(nodePtr == nullptr){ // return 0 if at end of path, base case
        return 0;
    }
    //return 1 if leaf node by definition
    if(nodePtr->left == nullptr && nodePtr->left == nullptr){ //base case
        return 1;
    }
    else{
        //this basically traverses the entire list and either reach a leaf and return 1 or reach a node with 1 child and return 0
        return recurLeafCount(nodePtr->left) + recurLeafCount(nodePtr->right);
    }
}

//this method is used to count the height of the tree
int IntBinaryTree::recurTreeHeight(TreeNode *nodePtr){
    if(nodePtr == nullptr){ //base case, either tree is empty or we have reached the end of a path
        return -1;
    }
    
    int hleft = recurTreeHeight(nodePtr->left);
    int hright = recurTreeHeight(nodePtr->right);
    //this statement here does the bulk of the work, it will keep traversing until end of subtree and then it will unwind 
    // until the left and right subtree from the root node are evaluated, each time the recursive call unwinds the 
    //left or right subtree is incremented until the final evaluation is made between the left and right subtees from root node,
    //that value is then returned as the height
    return hleft > hright ? hleft + 1 : hright + 1;
    
}

//this method is used to go count the largest width in the tree
int IntBinaryTree::recurTreeWidth(TreeNode *nodePtr){
   int maxWidth = 0;
   int width;
   int height = recurTreeHeight(root); // use recursive helper method to get height
   
   for(int i = 0;i <= height;i++){ // for every level we will find the number of nodes in that level and reassign max if necessary
       width = recurLevelWidth(nodePtr,i);
       if(width > maxWidth){
           maxWidth = width;
       }
   }
   return maxWidth;
}

//this is the helper method that is used to recursively count the number of nodes at a given level
int IntBinaryTree::recurLevelWidth(TreeNode *nodePtr, int stage){
   if(nodePtr == nullptr){ // base case a null node was passed return 0
       return 0;
   }
   
   if(stage == 0){ // base case, a valid node was passed and we at the n'th stage because the recursion will decrement until the stage is reached
       return 1;
   }
   else if(stage > 0){
       //This is the part where we traverse until we reach the specified stage and then base cases are hit.
       return recurLevelWidth(nodePtr->left,stage-1) + recurLevelWidth(nodePtr->right, stage-1);
   }
}

//empty destructor...
IntBinaryTree::~IntBinaryTree(){
    
}