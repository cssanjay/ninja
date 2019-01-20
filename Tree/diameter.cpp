int diameter(node* root){
	if(root == NULL)
		return 0;

	int lH = height(node->left);
	int rH = height(node->right);

	int lD = diameter(node->left);
	int rD = diameter(node->right);

	return max(lH+rH+1, max(lD, rD));
}

int height(node* node){
	if(node == NULL)
		return 0;l
	else
		return 1+ max(height(node->left), height(node->right));
}

int diameterOpt(node* root, int* height){
	int lH=0, rH=0;
	int lD=0, rD=0;

	if(root==NULL){
		*height = 0;
		return 0;
	}

	lD = diameter(root->left, &lH);
	rD = diameter(root->right, &rH);

	*height = max(lH,Rh)+1;

	return 1+max(lH+rH+1, max(lD,rD));

}



int heightH(node* root, int& ans){
	if(root == NULL)
		return 0;
	int lH = heightH(root->left, ans);
	int rH = heightH(root->right, ans);

	ans = 1+max(ans, 1+lH+rH);

	return 1+max(lH, rH);
}
int diameterNew(node* root){
	if(root == NULL)
		return 0;
	int diameter = INT_MIN;
	int h = heightH(root, diameter);

	return diameter;
}