#include"trie_tree.h"

struct TrieTree::Node {
	char symbol;
	Node* child;
	Node* sibling;

	Node(const char& _symbol) : symbol(_symbol), child(nullptr), sibling(nullptr) {}
};

TrieTree::TrieTree() : root(nullptr) {}
TrieTree::~TrieTree() {}

bool TrieTree::find(const  std::string& str) 
{
	find(root, str.begin());
}


bool TrieTree::insert(const std::string& str) 
{
    if(find(str))
    {
        insert(root, str.begin());
        return true;
    }   
    else 
        return false; //Такой эл-т уже есть
	
}

bool TrieTree::erase(const  std::string& str) 
{
    if(find(str))
    {
        erase(root, str.begin());
        return true;
    }   
    else 
        return false; //Эл-та не существует - удалять нечего
}

void TrieTree::fromFile() 
{

}


void TrieTree::insert(Node* root, std::string::const_iterator it) {
	if (*it != '\0')
	{
		if (root->child == nullptr)
		{
			root->child = new Node(*it);
			/*insert(root->child, it++);*/
			root = root->child;
			insert(root, it++);
		}
		else
		{
			root = root->child;
			if (root->symbol == *it)
				insert(root, it++);
			else
			{
				while (root->sibling != nullptr && root->symbol != *it) {
					root = root->sibling;
				}
				if (root->symbol == *it) {
					/*insert(root->child, it++);*/
					//root = root->child;
					insert(root, it++);
				}
				else {
					root->sibling = new Node(*it);
					/*insert(root->sibling, it++);*/
					//root = root->sibling;
					insert(root->sibling, it++);
				}
			}
		}
		//insert(root, it++);
	}
	else {
		Node* end = new Node('$');
		if (root->child == nullptr)
		{
			root->child = end;
		}
		else {
			while (root->sibling != nullptr) {
				root = root->sibling;
			}
			root->sibling = end;
		}
	}
}

void TrieTree::erase(Node*& root, std::string::const_iterator it) 
{

}

//bool trietree::find(node* root, std::string::const_iterator it) {
//	if (root->child == nullptr) 
//		return false;
//	root = root->child;
//	char _symbol;
//	if (*it == '\0') 
//		_symbol = '$'; 
//	else 
//		_symbol = *it;
//	while (root->sibling != nullptr && root->child->symbol != _symbol) 
//	{
//		root = root->sibling;
//	}
//	if (root->symbol == _symbol) 
//	{
//		if (_symbol == '$') 
//			return true; 
//		else 
//			find(root, it++);
//	}
//	else 
//		return false;
//}

bool TrieTree::find(Node* _root, std::string::const_iterator it)
{
	if (_root->child == nullptr)
		return false;
	_root = _root->child;
	char _symbol;
	if (*it == '\0')
		_symbol = '$';
	else
		_symbol = *it;
	if (_root->symbol == _symbol && _root->symbol != '&')
		find(_root, it++);
	else 
	{
		while (_root->sibling != nullptr && _root->symbol != _symbol)
			_root = _root->sibling;
		if (_root->symbol == _symbol)
		{
			if (_symbol == '&')
				return true;
			else
				find(_root, it++);
		}
		return false;
	}
}

