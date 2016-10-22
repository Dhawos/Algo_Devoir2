#pragma once
template <class T>
class TwoThreeFourNode;
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
	TwoThreeFourNode<T>* getEquivalentTwoThreeFourNode() {
		TwoThreeFourNode<T>* newNode;
		if (this->isLeaf()) {
			newNode = new TwoThreeFourNode<T>();
			newNode->pushKey(this->data);
			return newNode;
		}
		else if (this->rightchild == NULL || this->leftchild == NULL) {
			return NULL;
		}
		else if (this->leftchild->isBlack() && this->rightchild->isBlack()) {
			newNode = new TwoThreeFourNode<T>();
			TwoThreeFourNode<T>* newLeftNode = NULL;
			TwoThreeFourNode<T>* newRightNode = NULL;
			if (this->leftchild != NULL) {
				newLeftNode = this->leftchild->getEquivalentTwoThreeFourNode();
			}
			if (this->rightchild != NULL) {
				newRightNode = this->rightchild->getEquivalentTwoThreeFourNode();
			}
			if (newLeftNode == NULL && this->leftchild != NULL) {
				if (this->leftchild->leftchild != NULL) {
					newLeftNode = new TwoThreeFourNode<T>();
					newLeftNode->pushKey(this->leftchild->leftchild->data);
				}
				else if (this->leftchild->rightchild != NULL) {
					newLeftNode = new TwoThreeFourNode<T>();
					newLeftNode->pushKey(this->leftchild->rightchild->data);
				}
			}
			if (newRightNode == NULL && this->rightchild != NULL) {
				if (this->rightchild->leftchild != NULL) {
					newRightNode = new TwoThreeFourNode<T>();
					newRightNode->pushKey(this->rightchild->leftchild->data);
				}
				else if (this->rightchild->rightchild != NULL) {
					newRightNode = new TwoThreeFourNode<T>();
					newRightNode->pushKey(this->rightchild->rightchild->data);
				}
			}
			newNode->pushKey(this->data);
			if (newLeftNode != NULL && newRightNode != NULL) {
				newNode->addChild(newLeftNode);
				newNode->addChild(newRightNode);
			}
			return newNode;

		}
		else if (this->leftchild->isRed() && this->rightchild->isRed()) {
			newNode = new TwoThreeFourNode<T>();
			TwoThreeFourNode<T>* newFirstNode = NULL;
			TwoThreeFourNode<T>* newSecondNode = NULL;
			TwoThreeFourNode<T>* newThirdNode = NULL;
			TwoThreeFourNode<T>* newFourthNode = NULL;
			if (this->leftchild->leftchild != NULL){
				 newFirstNode = this->leftchild->leftchild->getEquivalentTwoThreeFourNode();
			}
			if (this->leftchild->rightchild != NULL) {
				newSecondNode = this->leftchild->rightchild->getEquivalentTwoThreeFourNode();
			}
			if (this->rightchild->leftchild != NULL) {
				newThirdNode = this->rightchild->leftchild->getEquivalentTwoThreeFourNode();
			}
			if (this->rightchild->rightchild != NULL) {
				newFourthNode = this->rightchild->rightchild->getEquivalentTwoThreeFourNode();
			}
			if (newFirstNode == NULL && this->leftchild->leftchild != NULL) {
				newFirstNode = new TwoThreeFourNode<T>();
				newFirstNode->pushKey(this->leftchild->leftchild->data);
				newFirstNode->pushKey(this->leftchild->data);
			}
			if (newSecondNode == NULL && this->leftchild->rightchild != NULL) {
				newSecondNode = new TwoThreeFourNode<T>();
				newSecondNode->pushKey(this->leftchild->data);
				newSecondNode->pushKey(this->leftchild->rightchild->data);
			}
			if (newThirdNode == NULL && this->rightchild->leftchild != NULL) {
				newThirdNode = new TwoThreeFourNode<T>();
				newThirdNode->pushKey(this->rightchild->leftchild->data);
				newThirdNode->pushKey(this->rightchild->data);
			}
			if (newFourthNode == NULL && this->rightchild->rightchild != NULL) {
				newFourthNode = new TwoThreeFourNode<T>();
				newFourthNode->pushKey(this->rightchild->data);
				newFourthNode->pushKey(this->rightchild->rightchild->data);
			}
			newNode->pushKey(this->data);
			newNode->pushKey(this->leftchild->data);
			newNode->pushKey(this->rightchild->data);
			if (newFirstNode != NULL && newSecondNode != NULL && newThirdNode != NULL && newFourthNode != NULL) {
				newNode->addChild(newFirstNode);
				newNode->addChild(newSecondNode);
				newNode->addChild(newThirdNode);
				newNode->addChild(newFourthNode);
			}
			return newNode;
		}
		else if (this->leftchild->isRed() && this->rightchild->isBlack()) {
			newNode = new TwoThreeFourNode<T>();
			TwoThreeFourNode<T>* newFirstNode = NULL;
			TwoThreeFourNode<T>* newSecondNode = NULL;
			TwoThreeFourNode<T>* newThirdNode = NULL;
			if (this->leftchild->leftchild != NULL) {
				newFirstNode = this->leftchild->leftchild->getEquivalentTwoThreeFourNode();
			}
			if (this->leftchild->rightchild != NULL) {
				newSecondNode = this->leftchild->rightchild->getEquivalentTwoThreeFourNode();
			}
			newThirdNode = this->rightchild->getEquivalentTwoThreeFourNode();
			if (newThirdNode == NULL) {
				newThirdNode = new TwoThreeFourNode<T>();
				if (this->rightchild->leftchild == NULL) {
					newThirdNode->pushKey(this->rightchild->data);
					newThirdNode->pushKey(this->rightchild->leftchild->data);
				}
				else if (this->rightchild->rightchild == NULL) {
					newThirdNode->pushKey(this->rightchild->leftchild->data);
					newThirdNode->pushKey(this->rightchild->data);
				}
			}
			newNode->pushKey(this->leftchild->getData());
			newNode->pushKey(this->data);
			newNode->addChild(newFirstNode);
			newNode->addChild(newSecondNode);
			newNode->addChild(newThirdNode);
			return newNode;
		}
		else if (this->leftchild->isBlack() && this->rightchild->isRed()) {
			newNode = new TwoThreeFourNode<T>();
			TwoThreeFourNode<T>* newFirstNode = this->leftchild->getEquivalentTwoThreeFourNode();
			TwoThreeFourNode<T>* newSecondNode = this->rightchild->leftchild->getEquivalentTwoThreeFourNode();
			TwoThreeFourNode<T>* newThirdNode = this->rightchild->rightchild->getEquivalentTwoThreeFourNode();
			if (newFirstNode == NULL) {
				newFirstNode = new TwoThreeFourNode<T>();
				if (this->leftchild->leftchild == NULL) {
					newThirdNode->pushKey(this->rightchild->data);
					newThirdNode->pushKey(this->rightchild->leftchild->data);
				}
				else if (this->leftchild->rightchild == NULL) {
					newThirdNode->pushKey(this->rightchild->leftchild->data);
					newThirdNode->pushKey(this->rightchild->data);
				}
			}
			newNode->pushKey(this->data);
			newNode->pushKey(this->rightchild->data);
			newNode->addChild(newFirstNode);
			newNode->addChild(newSecondNode);
			newNode->addChild(newThirdNode);
			return newNode;
		}
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

