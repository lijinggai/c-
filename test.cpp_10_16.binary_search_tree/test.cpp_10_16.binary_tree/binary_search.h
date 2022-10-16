#pragma once
#include <iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}

	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key > key)
		{
			parent->_left = cur;
			return true;
		}
		else
		{
			parent->_right = cur;
			return true;
		}
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while(cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	bool Erase(const K& key)//ɾ��
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			//��key
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//�ҵ�key,���ֻ��һ���ӽڵ�
				if (cur->_left == nullptr)
				{
					if (cur=_root)
					{
						//û��������cur����ͷ�ڵ�
						_root = cur->_right;
						delete cur;
					} 
					else
					{
						//cur��parent�������Ҳ���ȷ
						if (parent->_left == cur) {
							parent->_left = cur->_right;
						}
						else {
							parent->_right = cur->_right;
						}
						delete cur;
					}
				}
				else if (cur->_right == nullptr)
				{
					//û��������cur����ͷ�ڵ�
					if (cur = _root)
					{
						_root = cur->_left;
						delete cur;
					}
					else
					{
						if (parent->_left == cur) {
							parent->_left = cur->_left;
						}
						else {
							parent->_right = cur->_left;
						}
						delete cur;
					}
				}
				//else ///2�����Ҷ���Ϊ�գ��滻��ɾ��
				//{
				//	Node* minRight = cur->_right;
				//	while (minRight->_left)
				//	{
				//		minRight = minRight->_left;
				//	}
				//	K min = minRight->_key;

				//	// �ݹ�����Լ�ȥɾ���滻�ڵ㣬һ�����ߵ���Ϊ�յ��������
				//	this->Erase(min);

				//	cur->_key = min;
				//}
				else
				{
					parent = cur;
					Node* curparent = cur;
					cur = cur->_right;
					//��������С�������������
					while (cur->_left != nullptr)
					{
						curparent = cur;
						cur = cur->_left;
					}
					parent->_key = cur->_key;// ��������С�滻
					if (cur->_left == nullptr)
					{
						//cur��parent�������Ҳ���ȷ
						if (curparent->_left == cur) {
							curparent->_left = cur->_right;
						}
						else {
							curparent->_right = cur->_right;
						}
					}
					else if (cur->_right == nullptr)
					{
						if (curparent->_left == cur) {
							curparent->_left = cur->_left;
						}
						else {
							curparent->_right = cur->_left;
						}
					}
					delete cur;
				}
				return true;
			}
		}
		return false;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout<<endl;
	}
private:
	Node* _root;
};