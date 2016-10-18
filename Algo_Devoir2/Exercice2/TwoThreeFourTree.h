#pragma once
template<typename T>
class TwoThreeFourTree
{
private:
	int nbNodes;
public:
	Arbre();
	Arbre(constArbre& source);
	~Arbre();
	bool isEmpty() const;
	Node addNode(const T &);
	const T & max() const;
	const T & min() const;
	int getNbNodes() const;
	bool search(const T &) const;
	const T& parent(const T &) const;
	T successor(const T &) const;
	void list(std::vector<T> &) const;
}

