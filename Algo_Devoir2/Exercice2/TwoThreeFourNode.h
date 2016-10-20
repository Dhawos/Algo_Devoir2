#pragma once
#include <vector>
#include <iostream>
using std::vector;
template<typename T>
class TwoThreeFourNode
{
private :
	vector<T> keys;
	vector<TwoThreeFourNode<T>*> children;
	TwoThreeFourNode<T>* parent;
public:
	TwoThreeFourNode() {
		this->parent = NULL;
		this->keys = vector<T>();
		this->children = vector<TwoThreeFourNode<T>*>();
	}
	virtual ~TwoThreeFourNode() {};
	vector<T>& getKeys() { return this->keys; }
	vector<TwoThreeFourNode<T>*>& getChildren() { return this->children; }
	void pushKey(T key) {
		int index;
		if (this->keys.size() == 0) {
			index = 0;
		}
		else if (key < this->keys[0]) {
			index = 0;
		}
		else if(key > this->keys[this->keys.size() - 1]){
			index = this->keys.size();
		}
		else if(key > this->keys[0] && this->keys.size() > 1 && key < this->keys[1]) {
			index = 1;
		}
		vector<T>::iterator it = this->keys.begin();
		for (int i = 0; i < index; i++) {
			++it;
		}
		this->keys.insert(it, key);
		
	}
	void addChild(TwoThreeFourNode<T>* child) { 
		this->children.push_back(child);
		child->parent = this;
	}
	void removeChild(TwoThreeFourNode<T>* child) {
		vector<TwoThreeFourNode<T>*>::iterator it;
		for (it = this->children.begin();it != this->children.end(); ++it) {
			if (*it == child) {
				break;
			}
		}
		this->children.erase(it);
		delete child;
		child = NULL;
	}
	TwoThreeFourNode<T>* getParent() {
		return this->parent;
	}
	void setParent(TwoThreeFourNode<T>* parent) {
		this->parent = parent;
	}
	bool isRoot() {
		return this->parent == NULL;
	}
	bool isLeaf() {
		return this->children.size() == 0;
	}
	bool is2Node() {
		return this->keys.size() == 1;
	}
	bool is3Node() {
		return this->keys.size() == 2;
	}
	bool is4Node() {
		return this->keys.size() == 3;
	}
	bool operator==(const TwoThreeFourNode<T>& other)
	{
		for (int i = 0; i < this->keys.size(); i++) {
			if (this->keys[i] != other.keys[i]) {
				return false
			}
		}
		return true;
	}

	template <typename U> friend std::ostream& operator<<(std::ostream& stream, const TwoThreeFourNode<U> node) {
		if (!node.children.size() == 0) {
			//Case of a 2 node
			if (node.keys.size() == 1) {
				stream << *node.children[0];
				stream << node.keys[0];
				stream << *node.children[1];
			}
			//Case of a 3 node
			else if(node.keys.size() == 2){
				stream << *node.children[0];
				stream << node.keys[0];
				stream << *node.children[1];
				stream << node.keys[1];
				stream << *node.children[2];
			}
			//Case of a 4 node
			else if (node.keys.size() == 2) {
				stream << *node.children[0];
				stream << node.keys[0];
				stream << *node.children[1];
				stream << node.keys[1];
				stream << *node.children[2];
				stream << node.keys[2];
				stream << *node.children[3];
			}
		}
		else {
			for (U element : node.keys) {
				stream << element;
			}
		}
		return stream;
	}
};
