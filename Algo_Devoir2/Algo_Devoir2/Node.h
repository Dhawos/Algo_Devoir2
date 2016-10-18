#pragma once
#include <list>
using std::list;
template <typename T>
class Node
{
private:
	T data;
	Node<T>* father;
	Node<T>* mother;
public:
	
	Node(T data, T* father = NULL, T* mother = NULL)
	{
		this->data = data;
		this->father = father;
		this->mother = mother;
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

	void setFather(Node<T>* father) {
		this->father = father;
	}

	Node<T>* getFather() {
		return this->father;
	}

	void setMother(Node<T>* mother) {
		this->mother = mother;
	}

	Node<T>* getMother() {
		return this->mother;
	}
};

