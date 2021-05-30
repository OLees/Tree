#include "stdio.h"
#include "Tree.h"
#include "iostream"
#include <string>
#include <vector>

#include <gtest.h>


TEST(Tree, can_create_empty_class) {
	ASSERT_NO_THROW(Tree<int> tree);
}

TEST(Tree, can_create_not_empty_class) {
	ASSERT_NO_THROW(Tree<int> tree(10));
}

TEST(Tree, can_insert_1) {
	Tree<int> tree;
	ASSERT_NO_THROW(tree.insert(2, tree.root));
}

TEST(Tree, can_insert_2) {
	Tree<int> tree(3);
	ASSERT_NO_THROW(tree.insert(2, tree.root));
}

TEST(Tree, cant_insert_1) {
	Tree<int> tree(2);
	ASSERT_ANY_THROW(tree.insert(2, tree.root));
}



TEST(Tree, can_delete) {
	Tree<int> tree(3);
	tree.insert(4, tree.root);
	tree.insert(5, tree.root);
	tree.insert(9, tree.root);
	tree.insert(7, tree.root);
	tree.insert(1, tree.root);
	tree.insert(2, tree.root);
	tree.erase(5, tree.root);
	
	if (!tree.find(5, tree.root))
		std::cout << "Everything is ok" << std::endl;
	else
		std::cout << "Something is not ok" << std::endl;
}