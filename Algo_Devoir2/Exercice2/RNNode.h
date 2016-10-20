#pragma once
template<typename T>
class RNNode
{
private:
	T data;
	bool red;
	RNNode<T>* leftchild;
	RNNode<T>* rightchild;
public:
	RNNode(T data, bool isRed, RNNode<T>* leftchild = NULL, RNNode<T>* rightchild = NULL) {
		this->data = data;
		this->red = isRed;
		this->leftchild = leftchild;
		this->rightchild = rightchild;
	}
	virtual ~RNNode() {};
	bool isRed() {
		return this->red;
	}
	bool isBlack() {
		return !this->red;
	}
	T getData() {
		return this->data;
	}
	void setLeftChild(RNNode<T>* node) {
		this->leftchild = node;
	}
	void setRightChild(RNNode<T>* node) {
		this->right = node;
	}
	RNNode<T>* getLeftChild() {
		return this->leftchild;
	}
	RNNode<T>* getRightChild() {
		return this->rightchild;
	}
};

