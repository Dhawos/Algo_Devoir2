#pragma once
#include <list>
using std::list;

template <typename T>
class Node
{
private:
	T data;
	list<T*> children;
	T* father;
public:
	

	Node(T data, T* father)
	{
		this->data = data;
		this->father = father;
		this->children = new list();
	}

	virtual ~Node()
	{

	}

	void setData(T data) {
		this->data = data;
	}

	T getData() {
		return this->data;
	}

	void setFather(T* father) {
		this->father = father;
	}

	T* getFather() {
		return this->father
	}

	void addChild(T* child) {
		this->children.push_back(child);
	}

	void removeChild(T* child) {
		this->children.remove(child);
	}

	list<T*> getChildren() {
		return this->children;
	}
};

