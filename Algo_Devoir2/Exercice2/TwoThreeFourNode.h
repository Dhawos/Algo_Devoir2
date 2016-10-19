#pragma once
#include <vector>
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
	};
	virtual ~TwoThreeFourNode() {};
	vector<T> getKeys() { return this->keys; };
	vector<TwoThreeFourNode<T>*> getChildren() { return this->children; };
	void addChild(TwoThreeFourNode<T>* child) { 
		this->children.push_back(child);
		child->parent = this;
	}
	TwoThreeFourNode<T>* getParent() {
		return this->parent;
	}
	bool isRoot() {
		return this->parent == NULL;
	}
	bool isLeaf() {
		return this->children.size() == 0;
	}
	bool is2Node() {
		return this->children.size() == 2;
	}
	bool is3Node() {
		return this->children.size() == 3;
	}
	bool is4Node() {
		return this->children.size() == 4;
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
};
