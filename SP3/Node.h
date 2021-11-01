class NodeT{
	public:
		NodeT(registroNode data);
		NodeT(registroNode data, NodeT *left, NodeT *right);
		registroNode getData();
		NodeT* getLeft();
		NodeT* getRight();
		void setData(registroNode data);
		void setLeft(NodeT *left);
		void setRight(NodeT *right);
	private:
		registroNode data;
		NodeT *left;
		NodeT *right;
};

NodeT::NodeT(registroNode data){
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

NodeT::NodeT(registroNode data, NodeT *left, NodeT *right){
	this->data = data;
	this->left = left;
	this->right = right;
}

registroNode NodeT::getData(){
	return data;
}

NodeT* NodeT::getLeft(){
	return left;
}

NodeT* NodeT::getRight(){
	return right;
}

void NodeT::setData(registroNode data){
	this->data = data;
}

void NodeT::setLeft(NodeT *left){
	this->left = left;
}

void NodeT::setRight(NodeT *right){
	this->right = right;
}







