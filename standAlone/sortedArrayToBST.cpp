int sortedArrayToBST(int arr[], int start, int end)

{
	if(start < end)
		return NULL;

	int mid = (start+end)/2;
	node * root  = newNode(arr[mid]);

	root->left = sortedArrayToBST(arr, start, mid);
	root->right = sortedArrayToBST(arr, mid+1, end);

	return root;
}