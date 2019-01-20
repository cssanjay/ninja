int isBSTHelper(node* root, int min, int max){
	if(root == NULL)
		return 1;

	if(root->data < min || root->data > max)
		return 0;

	return isBSTHelper(root->left, min, root->data-1) && 
	isBST(root->right, node->data+1, max);
}

int isBST(node* root){
	return isBSTHelper(root, INT_MIN, INT_MAX);
}

bool isBSTNew(node* root, node* l= NULL, node* r = NULL){
	if(root == NULL)
		return true;

	if(l!=NULL && root->data < l->data)
		return false;
	if(r!=NULL && root->data > r->data)
		return false;

	return isBSTNew(root->left, l, root) &&
		isBSTNew(root->right, root, r);
}