#pragma once
#include <list>
using std::list;
template<typename T>
class TwoThreeFourNode
{
private :
	T data;
	list<int> keys;
	list<TwoThreeFourNode<T>*> children;
public:
	TwoThreeFourNode(T data) {
		this->data = data;
		this->keys = list<int>();
		this->children = list<TwoThreeFourNode<T>*>();
	};
	virtual ~TwoThreeFourNode() {};
	list<int> getKeys() {return this->keys};
	list<TwoThreeFourNode<T>*> getChildren() {return this->children};
};
