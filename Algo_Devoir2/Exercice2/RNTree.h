#pragma once
#include "TwoThreeFourTree.h"
#include "RNNode.h"
template<typename T>
class RNTree
{
private:
	RNNode<T>* root;
public:
	RNTree(TwoThreeFourTree<T> otherTree)
	{
		this->root = otherTree.getRoot()->getEquivalentRNNode();
	}
	virtual ~RNTree()
	{

	}
	RNNode<T>* getRoot() {
		return this->root;
	}
	template <typename U> friend std::ostream& operator<<(std::ostream& stream, const RNTree<U> tree) {
		stream << *(tree.root);
		return stream;
	}
};

