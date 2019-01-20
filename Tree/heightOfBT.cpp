int maxDepth(node* node){
	if(node == NULL)
		return 0;
	else{
		int lH = maxDepth(node->left);
		int rH = maxDepth(node->right);

		if(lH > rH)
			return lH+1;
		else return rH+1;
	}
}
