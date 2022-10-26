#pragma once
#include<iostream>
using namespace std;
enum Colour
{
	RED,
	BLACK,
};
template<class K, class V>
struct RBtreeNode
{
	RBtreeNode(const pair<K,V> kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(RED)
	{}

	RBtreeNode<K, V>* _left;
	RBtreeNode<K, V>* _right;
	RBtreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col


};
template<class K,class V>
class RBtree
{
	typedef RBtreeNode Node;
public:
	RBtree()
		:_root(nullptr)
	{}
	
	~RBTree()
	{
		Destory(_root);
		_root = nullptr;
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}
	}
	pair<Node*, bool> Insert(const pair<K, V> kv)
	{
		Node* cur = _root,*parent=_root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return pair<cur, false>;
			}
		}
		Node* newnode = new Node(kv);
		newnode->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = newnode;
			newnode->_parent = parent;
		}
		else
		{
			parent->_left = newnode;
			newnode->_parent = parent;
		}
		cur = newnode;
		while (parent && parent->_col == RED)
		{
			// ������״��ڣ�����ɫΪ��ɫ����Ҫ����
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				// �ؼ��ǿ�����
				Node* uncle = grandfather->_right;
				// ���1��uncle������Ϊ��
				if (uncle&&uncle->_col == RED)
				{
					parent->_col = uncle->_col = RED;
					grandfather->_col = RED;
					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else// ���2+3��uncle������ uncle������Ϊ��
				{
					// ���2������
					if (cur == parent->_left)
					{
						rotateR(grandfather);

						parent->_kv = BLACK ;
						grandfather->_kv = RED;
					}
					// ���3��˫��
					else
					{
						RotateL(parent);
						RotateR(grandfather);

						cur->_kv = BLACK;
						grandfather->_kv = RED;
					}
				}
			}
			// ������״��ڣ�����ɫΪ��ɫ����Ҫ����
			else
			{
				// �ؼ��ǿ�����
				Node* uncle = grandfather->_left;
				// ���1��uncle������Ϊ��
				if (uncle && uncle->_kv == RED)
				{
					parent->_kv = uncle->_kv = RED;
					grandfather->_kv = RED;
					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else // ���2 + 3��uncle������ uncle������Ϊ��
				{
					// ���2������
					if (cur == parent->_right)
					{
						RotateL(grandfather);

						parent->_kv = BLACK;
						grandfather->_kv = RED;
					}
					// ���3��˫��
					else
					{
						RotateR(parent);
						RotateL(grandfather);

						cur->_kv = BLACK;
						grandfather->_kv = RED;
					}
				}
			}
		}
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}
private:
	void Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		Destory(root->_left);
		Destory(root->right);
		delete root;
	}
	Node* _root;

};