node* lcaBST(node* root, int x, int y){
	if(root == NULL)
		return NULL;
	if(root->data>x && root->data>y)
		return lcaBST(root->left, x, y);
	if(root->data<x && root->data<y)
		return lcaBST(root->right, x, y);
	return root;
}


// iterative

node* lcaBST(node* root, int x, int y){
	while(root){
		if(root->data>x && root->data>y)
			root= root->left;
		else if(root->data < x && root->data < y)
			root= root->right;
		else break;
	}
	return root;
}

// doesn't solve the case when not present
node* lcaBT(node* root, int x, int y){
	if(root == NULL)
		return NULL;

	if(root->key == x || root->key == y)
		return root;

	node* left_lca = lcaBT(root->left, x, y);
	node* right_lca= lcaBT(root->right, x, y);

	if(left_lca && right_lca)
		return root;
	return (left_lca)? left_lca : right_lca;
}