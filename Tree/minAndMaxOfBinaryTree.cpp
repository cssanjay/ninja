#include <iostream>
#include <queue>

using namespace std;

template <typename T>

class BinaryTreeNode{
public:
  T data;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(T data){
    this->data = data;
    left = NULL;
    right = NULL;
  }

  ~BinaryTreeNode(){
    delete left;
    delete right;
  }
};
 // PairAns class -
 class PairAns {
    public :
        int min;
        int max;
 };
 

#include <climits>


 BinaryTreeNode<int>* takeInputLevelWise(){
  int rootData;
  cout << "Enter root data:" << endl;
  cin >>rootData;
  if(rootData == -1)
    return NULL;

  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);

  while(pendingNodes.size() != 0){
    BinaryTreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    
    cout <<"Enter left child of "<< front->data << endl;
    int leftChildData;
    cin >> leftChildData;
    if(leftChildData != -1){
      BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
      front->left = child;
      pendingNodes.push(child);
    }

    cout <<"Enter right child of "<< front->data << endl;
    int rightChildData;
    cin >> rightChildData;
    if(rightChildData != -1){
      BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
      front->right = child;
      pendingNodes.push(child);
    }
  }
  return root;
}


void printTree(BinaryTreeNode<int>* root){
  if(root == NULL)
    return;
  cout << root->data <<":";

  if(root->left)
    cout << "L:"<<root->left->data;
  if(root->right)
    cout << "R:" << root->right->data;

  cout<<endl;
  printTree(root->left);
  printTree(root->right);
}

void printLevelWise(BinaryTreeNode<int>* root){
  if(root == NULL)
    return;
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);

  while(pendingNodes.size() != 0){

    BinaryTreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    cout <<front->data <<":";
    if(front->left){
      cout << "L:"<<front->left->data<<",";
      pendingNodes.push(front->left);
    }
    else
      cout << "L:"<<"-1"<<",";
    if(front->right){
      cout << "R:"<<front->right->data;
      pendingNodes.push(front->right);
    }   
    else
      cout << "R:"<<"-1";
    cout << endl;
  }
}


void helperfunc(BinaryTreeNode<int>* root, PairAns* p){
  if(root == NULL)
    return ;
  cout << endl<<"ROOT:"<<root->data << "MIN::"<<p->min<< "MAX::"<<p->max<<endl;
  if(root->data < p->min){
    cout << "first:" <<root->data<<endl;
    p->min = root->data;
  }
  if(root->data > p->max){
    p->max = root->data;
        cout << "second:"<<root->data <<endl;

  }
  
  helperfunc(root->left, p);
  helperfunc(root->right, p);
  
  return;
}

//minimum and maximum of a binary tree
PairAns minMax(BinaryTreeNode<int> *root) {
  PairAns p;
  p.min = INT_MAX;
  p.max = INT_MIN;
  
  helperfunc(root, &p);
  return p;

}

void printBetweenK1K2(BinaryTreeNode<int>* root, int k1, int k2){
  if(root == NULL){
    return;
  }

  if(root->data >= k1 && root->data < k2)
    cout << root->data;

  if(root->data > k1)
    printBetweenK1K2(root->left, k1, k2);

  if(root->data <= k2)
    printBetweenK1K2(root->right, k1, k2);
}

bool isBST(BinaryTreeNode<int>* root, int min= INT_MIN, int max = INT_MAX){
  if(root == NULL)
    return true;

  if(root->data >max || root->data < min)
    return false;

  return isBST(root->left, min, root->data-1) && isBST(root->right, root->data+1, max);

}

int main(){
  /*
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
  BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
  BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

  root->left = node1;
  root->right= node2;
  */
  // BinaryTreeNode<int>* root = takeInput();
    BinaryTreeNode<int>* root = takeInputLevelWise();

  // printTree(root);
  printLevelWise(root);
  
  /*
  cout << "Number of nodes::" << numNodes(root);
  delete root;
  */

  PairAns p = minMax(root);
  cout << "MIN::"<<p.min<< "MAX::"<<p.max;
}