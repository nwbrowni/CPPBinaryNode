#include "BinaryNode.h"
#include "BinaryNode.cpp"  // have to include because it utilizes templates... otherwise you get a linker error
#include "IntegerBinaryNodeApp.h"

int main()
{
	// some simple test code
	/*
    BinaryNode<int>* b = new BinaryNode<int>(100);
	b->insert(20);
	b->insert(120);
	b->insert(30);
	b->insert(10);
	b->insert(125);
	b->insert(130);
	b->insert(124);
	b->displayTree();
	std::cout << std::endl;
	b = b->remove(100);
	b = b->remove(125);
	b = b->remove(20);
	b->displayTree();
	std::cout << std::endl;
	*/

	IntegerBinaryNodeApp* app = new IntegerBinaryNodeApp(100);
	app->run();
}