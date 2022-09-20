#ifndef BINARYNODE_CPP
#define BINARYNODE_CPP

#include "BinaryNode.h"

template<typename T> BinaryNode<T>::BinaryNode() {
	data = T();
	left = nullptr;
	right = nullptr;
}

template<typename T> BinaryNode<T>::BinaryNode(T val) {
	data = val;
}

template<typename T> void BinaryNode<T>::insert(T val) {
	if (data != 0) {
		if (val < data) {
			if (left == nullptr) {
				left = new BinaryNode(val);
			}
			else {
				left->insert(val);
			}
		}
		else if (val > data) {
			if (right == nullptr) {
				right = new BinaryNode(val);
			}
			else {
				right->insert(val);
			}
		}
	}
	else {
		data = val;
	}
}

template<typename T> bool BinaryNode<T>::search(T val) {
	bool res = false;
	std::cout << "node data: " << data << "\tLooking for: " << val << std::endl;
	if (val == data) {
		std::cout << "found " << val << "." << std::endl;
		res = true;
	}
	else if (res == false && val < data && left != nullptr) {
		res = left->search(val);
	}
	else if (res == false && val > data && right != nullptr) {
		res = right->search(val);
	}

	return res;
}

template<typename T> void BinaryNode<T>::displayTree() {
	if (left != nullptr) {
		left->displayTree();
	}
	std::cout << data << std::endl;
	if (right != nullptr) {
		right->displayTree();
	}
}

template<typename T> BinaryNode<T>* BinaryNode<T>::remove(BinaryNode<T>* root, T val) {
	if (!root->search(val)) {
		std::cout << "Provided: " << val << ". That value is not a part of the binary tree." << std::endl;
		return this;
	}
	
	if (root == NULL) return root;

	if (val < root->data) {
		root->left = remove(root->left, val);
	}
	else if (val > root->data) {
		root->right = remove(root->right, val);
	}
	else {
		if (root->left == NULL) {
			BinaryNode<T>* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			BinaryNode<T>* temp = root->left;
			free(root);
			return temp;
		}

		BinaryNode<T>* temp = findMin(root->right);
		root->data = temp->data;
		root->right = remove(root->right, temp->data);
	}

	return root;
}

template<typename T> BinaryNode<T>* BinaryNode<T>::remove(T val) {
	if (!search(val)) {
		std::cout << "Provided: " << val << ". That value is not a part of the binary tree." << std::endl;
		return this;
	}
	
	if (val < data) {
		left = left->remove(val);
	}
	else if (val > data) {
		right = right->remove(val);
		//right = right->remove(left, val)
	}
	else {
		if (left == NULL) {
			BinaryNode<T>* temp = right;
			free(this);
			return temp;
		}
		else if (right == NULL) {
			BinaryNode<T>* temp = left;
			free(this);
			return temp;
		}

		BinaryNode<T>* temp = findMin(right);
		data = temp->data;
		right = right->remove(temp->data);
	}

	return this;
}

template<typename T> BinaryNode<T>* BinaryNode<T>::findMin(BinaryNode<T>* node) {
	BinaryNode<T>* current = node;
	while (current != nullptr & current->left != nullptr) {
		current = current->left;
	}
	return current;
}

#endif