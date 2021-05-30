 #pragma once
#include "stdio.h"
#include "string"
#include <iostream>
#include <vector>


template <class T>
class Node {
public:
	T key;
	Node<T>* right;
	Node<T>* left;
	Node<T>* parent;

	Node() {
		key = data;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	Node(T key1) {
		key = key1;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	Node(const Node& temp) {
		key = temp.key;
		left = temp.left;
		right = temp.right;
		parent = temp.parent;
	}
	
};

template<class T>
class Tree  {
protected:
	size_t size;
public:
	Node<T>* root;

	Tree() {
		root = NULL;
		size = 0;
	}

	Tree(T key) {
		root = new Node<T>(key);
		size = 1;
	}

	Tree(const Tree& tree_) 
	{
		root = tree_.root;
		size = tree_.size;
	}

	~Tree() {
		delete root;
	}

	void insert(T key, Node<T>* root) {
		Node<T>* temp = find(key, root); //если такой элемент уже есть, то выбрасываем исключение
		if (temp != NULL && temp->key == key)
			throw "There is already such element in the tree";

		temp = root;
		Node<T>* temp2 = root; //если нет корня, то делаем его корнем
		if (temp == NULL) {
			temp = new Node<T>(key);
			return;
		}
		while (temp != NULL) { //пока не дойдем до нулевого элемента, идем по дереву
			if (key < temp->key) {
				temp2 = temp;
				temp = temp->left;
			}
			else if (key > temp->key) {
				temp2 = temp;
				temp = temp->right;
			}
		}
		if (key < temp2->key) { //запоминаем элемент
			temp = new Node<T>(key);
			temp2->left = temp;
		}
		else if (key > temp2->key) {
			temp = new Node<T>(key);
			temp2->right = temp;
		}
		temp->parent = temp2;
		size++; // увеличиваем количество
		return;
	}
	
	void erase(T key, Node<T>* root) {
		/*if (temp == NULL)
			throw "Nothing to delete";
		Node<T>* temp1;
		if (key > temp->key)
			erase(key, temp->right);
		else if (key < temp->key)
			erase(key, temp->left);
		else {
			if (temp->left == NULL) {
				temp1 = temp->right;
				delete temp;
				return;
			}
			else if (temp->right == NULL) {
				temp1 = temp->left;
				delete temp;
				return;
			}
		}*/

		Node<T>* temp = find(key, root);
		if (temp == NULL)
			throw "Nothing to delete";

		Node<T>* temp1;

		if ((temp->left == NULL) && (temp->right == NULL)) {//если нет потомков, тообнуляем указатель
			if (temp->key > temp->parent->key) //правый или левый, в зависимости от элемента 
				temp->parent->right = NULL;
			else 
				temp->parent->left = NULL;
			return;
		}

		if ((temp->left != NULL) || (temp->right != NULL)) {
			if(temp->right != NULL)
				temp1 = findmin(temp->right); // ищем наименьший в правом поддереве
			if (temp->left != NULL)
				temp1 = findmax(temp->left); //ищем наибольший в левом поддереве

			if (temp->key > temp->parent->key)
				temp->parent->right = temp1;
			else
				temp->parent->left = temp1;
			return;

		}
		delete temp;
		delete temp1;
		size--;
	}

	Node<T>* find(T key, Node<T>* root) {
		Node<T>* temp = root;
		while (temp != NULL) { //идем по дереву, пока не дойдем до конца
			if (key == temp->key)
				return temp; //если находим элемент, возвращаем его

			if (key < temp->key) {
				temp = temp->left;
				continue;
			}

			if (key > temp->key) {
				temp = temp->right;
				continue;
			}
		}

		if (temp == NULL || key != temp->key) //если не находим элемент, то возвращает NULL
			return NULL;
	}

	Node<T>* findmin(Node<T>* Root)
	{
		if (Root == NULL)
			throw "empty tree";
		while (Root->left != NULL)
			Root = Root->left;
		return Root;
	};

	Node<T>* findmax(Node<T>* Root)
	{
		if (Root == NULL)
			throw "empty tree";
		while (Root->right != NULL)
			Root = Root->right;
		return Root;
	};

	size_t getSize()
	{
		return size;
	}

	bool empty()
	{
		return (size == 0);
	}
};
