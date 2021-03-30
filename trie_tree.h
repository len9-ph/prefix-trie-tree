#pragma once
#include<iostream>


class TrieTree {
	struct Node;
	Node* root;

	void insert(Node*, std::string::const_iterator);
	void erase(Node*&, std::string::const_iterator);
	bool find(Node*, std::string::const_iterator);
	void print(Node* _root);
public:
	TrieTree();
	~TrieTree();

	bool insert(const std::string&);
	bool erase(const  std::string&);
	bool find(const  std::string&);
	void print();

	void fromFile();

	friend std::istream& operator>>(std::istream&, TrieTree);
	friend std::ostream& operator<<(const std::ostream&, TrieTree);
};