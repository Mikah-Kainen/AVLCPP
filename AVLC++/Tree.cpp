#include "Node.cpp"


template <typename T>
class Tree
{
//private:
public:
	std::shared_ptr<Node<T>> head;


	std::shared_ptr<Node<T>> Rotateleft(std::shared_ptr<Node<T>> oldHead)
	{
		std::shared_ptr<Node<T>> newHead;

		if (oldHead->RightChild->Balance < 0)
		{
			newHead = oldHead->RightChild->LeftChild;
			std::shared_ptr<Node<T>> oldLeftChild = newHead->LeftChild;
			std::shared_ptr<Node<T>> oldRightChild = newHead->RightChild;

			newHead->LeftChild = oldHead;
			newHead->RightChild = oldHead->RightChild;

			newHead->LeftChild->RightChild = oldLeftChild;
			newHead->RightChild->LeftChild = oldRightChild;
		}
		else
		{

		}

		return newHead;
	}



	std::shared_ptr<Node<T>> RotateRight(std::shared_ptr<Node<T>> oldHead)
	{
		std::shared_ptr<Node<T>> newHead;

		if (oldHead->RightChild->Balance > 0)
		{
			//double rotation logic 
		}
		else
		{
			//single rotation logic
		}

		return newHead;
	}


	//std::shared_ptr<Node<T>> RotateLeft(std::shared_ptr<Node<T>> parentNode)
	//{
	//	if (parentNode->RightChild->RightChild == nullptr)
	//	{
	//		std::shared_ptr<Node<T>> temp = parentNode->RightChild->LeftChild;
	//		parentNode->RightChild->LeftChild = nullptr;
	//		temp->RightChild = parentNode->RightChild;
	//		parentNode->RightChild = temp;
	//	}

	//	std::shared_ptr<Node<T>> newParent = parentNode->RightChild;
	//	std::shared_ptr<Node<T>> temp2 = newParent->LeftChild;
	//	newParent->LeftChild = parentNode;
	//	parentNode->RightChild = temp2;

	//	return newParent;
	//}

	//std::shared_ptr<Node<T>> RotateRight(std::shared_ptr<Node<T>> parentNode)
	//{
	//	if (parentNode->LeftChild->LeftChild == nullptr)
	//	{
	//		std::shared_ptr<Node<T>> temp = parentNode->LeftChild->RightChild;
	//		parentNode->LeftChild->RightChild = nullptr;
	//		temp->LeftChild = parentNode->LeftChild;
	//		parentNode->LeftChild = temp;
	//	}

	//	std::shared_ptr<Node<T>> newParent = parentNode->LeftChild;
	//	std::shared_ptr<Node<T>> temp2 = newParent->RightChild;
	//	newParent->RightChild = parentNode;
	//	parentNode->LeftChild = temp2;

	//	return newParent;
	//}

//public:

	Tree()
		: head{nullptr}
	{

	}


	void Add(T value)
	{
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
		if (value == 15)
		{
			newNode->Balance = -1;
		}
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		std::shared_ptr<Node<T>> currentNode = head;
		while (true)
		{
			if (value < currentNode->Value)
			{
				if (currentNode->LeftChild == nullptr)
				{
					currentNode->LeftChild = newNode;
					return;
				}
				else
				{
					currentNode = currentNode->LeftChild;
				}
			}
			else
			{
				if (currentNode->RightChild == nullptr)
				{
					currentNode->RightChild = newNode;
					return;
				}
				else
				{
					currentNode = currentNode->RightChild;
				}
			}
		}
	}


	bool Remove()
	{

	}

};
