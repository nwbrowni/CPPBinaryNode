#ifndef BINARYNODE
#define BINARYNODE

#include <iostream>
#include <string>

template<typename T> class BinaryNode {
public:
	T data;
	BinaryNode* left = nullptr;
	BinaryNode* right = nullptr;

	BinaryNode();
	BinaryNode(T val);
	void insert(T val);
	bool search(T val);
	BinaryNode<T>* remove(BinaryNode<T>* root, T val);
	BinaryNode<T>* remove(T val);
	void displayTree();
	BinaryNode* findMin(BinaryNode<T>* right);
};

#endif