#include"trie_tree.h"

struct TrieTree::Node {
	char symbol;
	Node* child;
	Node* sibling;

	Node(const char& _symbol) : symbol(_symbol), child(nullptr), sibling(nullptr) {}
};

TrieTree::TrieTree() : root(nullptr) {}
TrieTree::~TrieTree() {}

void TrieTree::insert(Node* _root, std::string::const_iterator it) 
{
	if (*it != '\0')
	{
		if (_root->child == nullptr)
		{
			_root->child = new Node(*it);
			_root = _root->child;
			insert(_root, it++);
		}
		else
		{
			_root = _root->child;
			if (_root->symbol == *it)
				insert(_root, it++);
			else
			{
				while (_root->sibling != nullptr && _root->symbol != *it) {
					_root = _root->sibling;
				}
				if (_root->symbol == *it) 
				{
					insert(_root, it++);
				}
				else 
				{
					_root->sibling = new Node(*it);
					insert(_root->sibling, it++);
				}
			}
		}
	}
	else {
		Node* end = new Node('$');
		if (_root->child == nullptr)
		{
			_root->child = end;
		}
		else {
			while (_root->sibling != nullptr) {
				_root = _root->sibling;
			}
			_root->sibling = end;
		}
	}
}

void TrieTree::erase(Node*& root, std::string::const_iterator it) 
{

}

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

void TrieTree::print

void TrieTree::print()
{
	if(root != nullptr)
	{
		cout<<root->symbol<<"  ";
		print(root->child);
		print(root->sibling);
	}
}