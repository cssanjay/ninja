//generic tree
int numLeafNodes(node<int>* root){
	int count = 0;
	if(root->children.size() == 0)
		count++;
	for(int i = 0; i < root->children.size(); i++)
		count += numLeafNodes(root -> children[i]);
	return count;
}