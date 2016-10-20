#pragma once
#include "TwoThreeFourTree.h"
#include "RNNode.h"
template<typename T>
class RNTree
{
private:
	RNNode<T> root;
public:
	RNTree(TwoThreeFourTree<T> otherTree)
	{
		this->root = otherTree.getRoot()->getEquivalentRNNode();
	}

	virtual ~RNTree()
	{

	}
};

