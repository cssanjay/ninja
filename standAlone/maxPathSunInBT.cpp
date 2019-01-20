int maxPathSunInBT(node * root, int * res)
{
	if(root == NULL)
		return 0;

	int l = maxPathSunInBT(root->left, res);
	int r = maxPathSunInBT(root->right, res);

	int max_single = max(max(l,r) + root->data);
	int max_top = ma(max(max_single, l+r+root->data), root->data);

	res = max(res, max_top);

	return max_single;
}

int findMaxSum(node* root)
{
	int res = INT_MIN;

	result = maxPathSunInBT(root, res);
	return res;
}