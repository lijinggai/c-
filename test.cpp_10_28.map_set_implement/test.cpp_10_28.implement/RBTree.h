#pragma once
#pragma once
#include<iostream>
using namespace std;
enum Colour
{
	RED,
	BLACK,
};
template<class T>
struct RBtreeNode
{
	RBtreeNode(const T data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}

	RBtreeNode<T>* _left;
	RBtreeNode<T>* _right;
	RBtreeNode<T>* _parent;
	T _data;
	Colour _col;

};
template<class T, class Ref, class Ptr>
struct _TreeIterator
{
	typedef RBtreeNode<T> Node;
	typedef _TreeIterator<T, Ref, Ptr> Self;

	Node* _node;

	_TreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator != (const Self& s) const
	{
		return _node != s._node;
	}

	// �ѵ�
	Self operator++()
	{
		if (_node->_right)
		{
			// ��һ�����ʾ��������У�����ĵ�һ���ڵ�
			Node* left = _node->_right;
			while (left->_left)
			{
				left = left->_left;
			}

			_node = left;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	//operator--();
};
template<class K, class T,class dataofT>
class RBtree
{
	typedef RBtreeNode<T> Node;
public:
	typedef _TreeIterator < T, T&, T* > iterator;

	iterator begin()
	{
		Node* left = _root;
		while (left && left->_left)
		{
			left = left->_left;
		}

		return iterator(left);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	RBtree()
		:_root(nullptr)
	{}

	~RBtree()
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
	pair<Node*, bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(_root, true);
		}
		Node* cur = _root, * parent = _root;
		dataofT dot;
		while (cur)
		{
			if (dot(cur->_data) < dot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (dot(cur->_data) > dot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(cur, false);
			}
		}
		Node* newnode = new Node(data);
		newnode->_col = RED;
		if (dot(parent->_data) < dot(data))
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
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
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
						RotateR(grandfather);

						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					// ���3��˫��
					else
					{
						RotateL(parent);
						RotateR(grandfather);

						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					//������Ľڵ��Ѿ�����ˣ����ü���
					break;
				}
			}
			// ������״��ڣ�����ɫΪ��ɫ����Ҫ����
			else
			{
				// �ؼ��ǿ�����
				Node* uncle = grandfather->_left;
				// ���1��uncle������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
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

						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					// ���3��˫��
					else
					{
						RotateR(parent);
						RotateL(grandfather);

						cur->_col = BLACK;
						grandfather->_col = RED;
					}
				}
				break;
			}
		}
		_root->_col = BLACK;
		return make_pair(newnode, true);
	}
	Node* Find(const K& key)
	{
		dataofT dot;
		Node* cur = _root;
		while (cur)
		{
			if (dot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else if (dot(cur->_data) < key)
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
	bool _CheckBalance(Node* root, int LeftNum, int count)
	{
		if (root == nullptr)
		{
			if (count != LeftNum)
			{
				return false;
			}
			return true;
		}
		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "���������ĺ�ɫ�ڵ�" << endl;
			return false;
		}
		if (root->_col == BLACK)
		{
			count++;
		}
		return _CheckBalance(root->_left, LeftNum, count) &&
			_CheckBalance(root->_right, LeftNum, count);
	}
	bool CheckBalance()
	{
		if (_root == nullptr)
		{
			return true;
		}
		else if (_root->_col == RED)
		{
			cout << "���ڵ��Ǻ�ɫ��" << endl;
			return false;
		}
		else
		{
			int LeftNum = 0;
			Node* left = _root;
			// ������·������ɫ�ڵ������ο�ֵ
			while (left)
			{
				if (left->_col == BLACK)
				{
					LeftNum++;
				}
				left = left->_left;
			}
			int count = 0;
			return _CheckBalance(_root, LeftNum, count);
		}
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	void Destory(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		Destory(root->_left);
		Destory(root->_right);
		delete root;
	}
	Node* _root;

};