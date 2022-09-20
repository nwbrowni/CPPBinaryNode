#ifndef BINARYNODEAPP
#define BINARYNODEAPP

#include <string>
#include <iostream>
#include "BinaryNode.h"
#include "BinaryNode.cpp"

class IntegerBinaryNodeApp {
public:
	BinaryNode<int>* root;

	IntegerBinaryNodeApp(int val) {
		root = new BinaryNode<int>(val);
	}

	std::string printMenu() {
		std::string response;
		std::cout << std::endl;
		std::cout << "Binary Node App Menu:" << std::endl;
		std::cout << "1) print tree" << std::endl;
		std::cout << "2) insert" << std::endl;
		std::cout << "3) remove" << std::endl;
		std::cout << "4) exit" << std::endl;
		std::cout << ">> ";
		std::cin >> response;
		return response;
	}

	bool handleMenuInput(std::string response) {
		if (response == "1") {
			root->displayTree();
			return true;
		}
		else if (response == "2") {
			std::string sval;
			std::cout << "value to insert: ";
			std::cin >> sval;
			int val = 0;
			if (convertStringToInteger(&sval, &val)) {
				root->insert(val);
			}
			return true;
		}
		else if (response == "3") {
			std::string sval;
			std::cout << "value to remove: ";
			std::cin >> sval;
			int val = 0;
			if (convertStringToInteger(&sval, &val)) {
				root->remove(val);
			}
			return true;
		}
		else if (response == "4") {
			return false;
		}
		else {
			std::cout << "That was an invalid input. Valid inputs are 1, 2, 3, 4." << std::endl;
			return true;
		}
	}

	void run() {
		while (handleMenuInput(printMenu()));
	}

	bool convertStringToInteger(std::string* sval, int* val) {
		for (int i = 0; i < sval->length(); i++) {
			if (!(sval->at(i) >= '0' && sval->at(i) <= '9')) {
				return false;
			}

			int digit = sval->at(i) - '0';
			for (int j = i; j < sval->length() - 1; j++) {
				digit = digit * 10;
			}

			*val = *val + digit;
			//*val = *val + ((sval->at(i) - '0') * 10 * (sval->length() - i));
		}

		return true;
	}
};

#endif