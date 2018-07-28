// BinaryTreeUse.cpp
#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

using namespace std;

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

BinaryTreeNode<int>* takeInput(){
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	if(rootData == -1)
		return NULL;

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();

	root->left = leftChild;
	root->right = rightChild;
	return root;
}

int numNodes(BinaryTreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	return 1 + numNodes(root->left) + numNodes(root->right);
}

void inorder(BinaryTreeNode<int>* root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data <<" ";
	inorder(root->right);
}

int height(BinaryTreeNode<int>* root){
	if(root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

int diameterRookieWay(BinaryTreeNode<int>* root){
	if(root == NULL)
		return 0;

	int option1 = height(root->left) + height(root->right);
	int option2 = diameterRookieWay(root->left);
	int option3 = diameterRookieWay(root->right);

	return max(option1, max(option3, option2));
}

pair<int, int>heightDiameter(BinaryTreeNode<int>* root){
	pair<int, int>p;
	if(root == NULL){
		p.first = 0;
		p.second = 0;
		return p;
	}
	pair<int, int> leftAns = heightDiameter(root->left);
	pair<int, int> rightAns= heightDiameter(root->right);
	int lh = leftAns.first;
	int rh = rightAns.first;
	int ld = leftAns.second;
	int rd = rightAns.second;

	int height = 1 + max(lh,rh);
	int diameter = max(lh+rh, max(ld, rd));

	p.first = height;
	p.second = diameter;

	return p;

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
	
	//	BinaryTreeNode<int>* root = takeInputLevelWise();

	// printTree(root);
	// printLevelWise(root);
	
	/*
	cout << "Number of nodes::" << numNodes(root);
	delete root;
	*/

	// pair<int, int> p = heightDiameter(root);
	// cout << "height::"<<p.first << "::DIAMETER::"<<p.second;

	BST b;
	b.insert(10);
	b.insert(5);
	b.insert(20);
	b.insert(7);
	b.insert(3);
	b.insert(15);
	b.printTree();
}