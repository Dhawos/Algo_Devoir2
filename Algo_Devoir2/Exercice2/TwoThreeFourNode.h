#pragma once
template<typename T>
class TwoThreeFourNode
{
private :
	T data;
	int keys[2];
	TwoThreeFourNode<T> children[3];
public:
	TwoThreeFourNode();
	virtual ~TwoThreeFourNode();
};

