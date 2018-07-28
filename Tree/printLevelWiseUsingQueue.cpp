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