#include "Node.cpp"


template <typename T>
class Tree
{
private:
	std::shared_ptr<Node<T>> head;

	void RotateLeft(std::shared_ptr<Node<T>> parentNode)
	{
		//might need to make another check if parent->right->left != null
		if (parentNode->RightChild->RightChild == nullptr)
		{
			//do a double rotation
		}
	}

	void RotateRight(std::shared_ptr<Node<T>> parentNode)
	{
		//might need to make another check if parent->left->right != null
		if (parentNode->LeftChild->LeftChild == nullptr)
		{
			//do a double rotation
		}
	}

public:


	Tree()
		: head{nullptr}
	{

	}


	void Add()
	{

	}


	bool Remove()
	{

	}

};
