#include <iostream>
#include <queue>
#include "NodeTree.h"
using namespace std;

TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout << "Enter root data" << endl;
	cin>>rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	while(pendingNodes.size()!=0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "enter numberes of children of " <<front->data;
		int numChild;
		cin>>numChild;
		for(int i = 0; i<numChild;i++){
			int childData;
			cout << "Enter "<< i<< "th child of "<<front->data;
			cin>>childData;
			// allocate dynamically not statically so that can use it in next iteration
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}



TreeNode<int>* takeInput(){
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	cout << "Enter number of cildren of " << rootData << endl;
	cin >> n;
	for(int i = 0;i<n; i++){
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root){
	if(root == NULL)
		return;
	cout << root->data << ":";
	for(int i = 0; i < root->children.size(); i++)
		cout << root->children[i]->data <<",";
	cout << endl;

	for(int i = 0; i < root->children.size(); i++)
		printTree(root->children[i]);
}

void printLevelWise(TreeNode<int>* root){
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size()!=0){
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << endl<<front->data <<":";

		for(int i = 0; i < front->children.size(); i++){
			pendingNodes.push(front->children[i]);
			cout<< front->children[i]->data;
			if(i<front->children.size()-1) cout<<",";
		}
	}
}

int height(TreeNode<int>* root){
	int ans = 0;
	for(int i =0; i<root->children.size(); i++){
		int childHeight = height(root->children[i]);
		if(childHeight>ans)
			ans = childHeight;
	}
	return ans+1;
}
int sumOfNodes(TreeNode<int>*root){
	int sum = root->data;
	for(int i = 0; i<root->children.size(); i++){
		sum += sumOfNodes(root->children[i]);
	}
	return sum;
}

int numNodes(TreeNode<int>* root){
	if(root == NULL)
		return 0;
	int ans = 1;
	for(int i = 0; i<root->children.size(); i++){
		ans += numNodes(root->children[i]);
	}
	return ans;
}

void printAtLevelK(TreeNode<int>*root, int k){
	if(root == NULL)
		return;
	if(k==0){
		cout << root->data <<endl;
		return;
	}

	for(int i = 0; i< root->children.size(); i++){
		printAtLevelK(root->children[i], k-1);
	}
}

void preorder(TreeNode<int>* root){
	if(root == NULL){
		return;
	}

	cout << root->data;
	for(int i = 0; i< root->children.size(); i++){
		preorder(root->children[i]);
	}
}

void postOrder(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output in specified format.
     */
  if(root == NULL)
    return;
  for(int i =0; i<root->children.size(); i++){
    postOrder(root->children[i]);
  }
  cout<<root->data<<" ";
}

void deleteTree(TreeNode<int>* root){
	for(int i = 0; i<root->children.size(); i++){
		deleteTree(root->children[i]);
	}
	delete root;
}

int main(){
	/*
	TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);

	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	
	// TreeNode<int>* root = takeInput();
	TreeNode<int>* root = takeInputLevelWise();

	// printTree(root);
	// printLevelWise(root);
	cout <<sumOfNodes(root);
	printAtLevelK(root,2);

	//TODO delete the tree
	deleteTree(root);
	return 0;
}