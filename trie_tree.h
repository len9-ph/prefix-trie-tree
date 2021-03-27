#pragma once
#include<iostream>


class TrieTree {
	struct Node;
	Node* root;

	void insert(Node*, std::string::const_iterator);
	void erase(Node*&, std::string::const_iterator);
	bool find(Node*, std::string::const_iterator);
public:
	TrieTree();
	~TrieTree();

	void insert(const std::string&);
	void erase(const  std::string&);
	bool find(const  std::string&);

	void fromFile();

	friend std::istream& operator>>(std::istream&, TrieTree);
	friend std::ostream& operator<<(const std::ostream&, TrieTree);
};