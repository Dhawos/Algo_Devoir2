#pragma once
#include <vector>
using std::vector;
template<typename T>
class TwoThreeFourNode
{
private :
	T data;
	vector<int> keys;
	vector<TwoThreeFourNode<T>*> children;
public:
	TwoThreeFourNode(T data) {
		this->data = data;
		this->keys = vector<int>();
		this->children = vector<TwoThreeFourNode<T>*>();
	};
	virtual ~TwoThreeFourNode() {};
	vector<int> getKeys() {return this->keys};
	vector<TwoThreeFourNode<T>*> getChildren() {return this->children};
};
