#pragma once
#include "TwoThreeFourNode.h"
template<typename T>
class RNNode
{
private:
	T data;
	bool red;
	RNNode<T>* leftchild;
	RNNode<T>* rightchild;
public:
	RNNode() {
		this->red = false;
		this->leftchild = NULL;
		this->rightchild = NULL;
	}
	RNNode(T data, bool isRed, RNNode<T>* leftchild = NULL, RNNode<T>* rightchild = NULL) {
		this->data = data;
		this->red = isRed;
		this->leftchild = leftchild;
		this->rightchild = rightchild;
	}
	virtual ~RNNode() {};
	TwoThreeFourNode<T>* getEquivalent234Node(){
		TwoThreeFourNode<T>* newNode;
		if (this->isLeaf()) {
			newNode = new TwoThreeFourNode<T>();
			newNode->pushKey(this->data);
			return newNode;
		}
		else if (this->rightchild == NULL) {
			newNode = new TwoThreeFourNode<T>();
			TwoThreeFourNode<T>* newLeftNode = this->leftchild->getEquivalentTwoThreeFourNode();
			newNode->pushKey(this->data);
			newNode->addChild(newLeftNode);
			return newNode;
		}
		else if (this->leftchild == NULL) {
			newNode = new TwoThreeFourNode<T>();
			TwoThreeFourNode<T>* newRightNode = this->rightchild->getEquivalentTwoThreeFourNode();
			newNode->pushKey(this->data);
			newNode->addChild(newRightNode);
			return newNode;
		}
		else if (this->leftchild->isBlack() && this->rightchild->isBlack()) {
			newNode = new TwoThreeFourNode<T>();
			TwoThreeFourNode<T>* newLeftNode = this->leftchild->getEquivalentTwoThreeFourNode();
			TwoThreeFourNode<T>* newRightNode = this->rightchild->getEquivalentTwoThreeFourNode();
			newNode->pushKey(this->data);
			newNode->addChild(newLeftNode);
			newNode->addChild(newRightNode);
			return newNode;

		}
		else if (this->leftchild->isRed() && this->rightchild->isRed()) {
			newNode = new TwoThreeFourNode<T>();
			TwoThreeFourNode<T>* newFirstNode = this->leftchild->leftchild->getEquivalentTwoThreeFourNode();
			TwoThreeFourNode<T>* newSecondNode = this->leftchild->rightchild->getEquivalentTwoThreeFourNode();
			TwoThreeFourNode<T>* newThirdNode = this->rightchild->leftchild->getEquivalentTwoThreeFourNode();
			TwoThreeFourNode<T>* newFourthNode = this->rightchild->rightchild->getEquivalentTwoThreeFourNode();
			newNode->pushKey(this->data);
			newNode->pushKey(this->leftChild->data);
			newNode->pushKey(this->rightChild->data);
			newNode->addChild(newFirstNode);
			newNode->addChild(newSecondNode);
			newNode->addChild(newThirdNode);
			newNode->addChild(newFourthNode);
			return newNode;
		}
		else if (this->leftchild->isRed() && this->rightchild->isBlack()) {
			newNode = new TwoThreeFourNode<T>();
			TwoThreeFourNode<T>* newFirstNode = this->leftchild->leftchild->getEquivalentTwoThreeFourNode();
			TwoThreeFourNode<T>* newSecondNode = this->leftchild->rightchild->getEquivalentTwoThreeFourNode();
			TwoThreeFourNode<T>* newThirdNode = this->rightchild->getEquivalentTwoThreeFourNode();
			newNode->pushKey(this->leftChild->data);
			newNode->pushKey(this->data);
			newNode->addChild(newFirstNode);
			newNode->addChild(newSecondNode);
			newNode->addChild(newThirdNode);
			return newNode;
		}
		else if (this->leftchild->isBlack() && this->rightchild->isRed()) {
			newNode = new TwoThreeFourNode<T>();
			TwoThreeFourNode<T>* newFirstNode = this->leftchild->dgetEquivalentTwoThreeFourNode();
			TwoThreeFourNode<T>* newSecondNode = this->rightchild->leftchild->getEquivalentTwoThreeFourNode();
			TwoThreeFourNode<T>* newThirdNode = this->rightchild->rightchild->getEquivalentTwoThreeFourNode();
			newNode->pushKey(this->data);
			newNode->pushKey(this->rightchild->data);
			newNode->addChild(newFirstNode);
			newNode->addChild(newSecondNode);
			newNode->addChild(newThirdNode);
			return newNode;
		}
	}
	bool isRed() {
		return this->red;
	}
	bool isBlack() {
		return !this->red;
	}
	bool isLeaf() {
		return (this->leftchild == NULL && this->rightchild == NULL);
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
	template <typename U> friend std::ostream& operator<<(std::ostream& stream, const RNNode<U> node) {
		if (node.leftchild != NULL) {
			stream << *node.leftchild;
		}
		stream << node.data;
		if (node.rightchild != NULL) {
			stream << *node.rightchild;
		}
		return stream;
	}
};

