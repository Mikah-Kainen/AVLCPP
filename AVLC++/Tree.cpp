#include "Node.cpp"
#include <deque>
#include <iostream>


template <typename T>
class Tree
{
private:
//public:
	std::shared_ptr<Node<T>> head;


	std::shared_ptr<Node<T>> rotateLeft(std::shared_ptr<Node<T>> oldHead)
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
			newHead = oldHead->RightChild;
			std::shared_ptr<Node<T>> oldLeftChild = newHead->LeftChild;
			newHead->LeftChild = oldHead;
			oldHead->RightChild = oldLeftChild;
		}

		return newHead;
	}



	std::shared_ptr<Node<T>> rotateRight(std::shared_ptr<Node<T>> oldHead)
	{
		std::shared_ptr<Node<T>> newHead;

		if (oldHead->LeftChild->Balance > 0)
		{
			newHead = oldHead->LeftChild->RightChild;
			std::shared_ptr<Node<T>> oldLeftChild = newHead->LeftChild;
			std::shared_ptr<Node<T>> oldRightChild = newHead->RightChild;

			newHead->RightChild = oldHead;
			newHead->LeftChild = oldHead->LeftChild;

			newHead->LeftChild->RightChild = oldLeftChild;
			newHead->RightChild->LeftChild = oldRightChild;
		}
		else
		{
			newHead = oldHead->LeftChild;
			std::shared_ptr<Node<T>> oldRightChild = newHead->RightChild;
			newHead->RightChild = oldHead;
			oldHead->LeftChild = oldRightChild;
		}

		return newHead;
	}



public:

	int Count;

	Tree()
		: head{ nullptr }, Count{ 0 }
	{

	}


	void Add(T value)
	{
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(value);
		Count++;
		if (head == nullptr)
		{
			head = newNode;
			return;
		}

		std::shared_ptr<Node<T>> current = head;
		std::deque<std::shared_ptr<Node<T>>> parents;
		bool isRightChild = false;
		while (current)
		{
			parents.push_back(current);
			if (newNode->Value < current->Value)
			{
				isRightChild = false;
				current = current->LeftChild;
			}
			else
			{
				isRightChild = true;
				current = current->RightChild;
			}
		}

		if (isRightChild)
		{
			parents.back()->RightChild = newNode;
		}
		else
		{
			parents.back()->LeftChild = newNode;
		}

		while (parents.size() > 1)
		{
			current = parents.back();
			parents.pop_back();
			bool isRightChild;
			if (current->Value < parents.back()->Value)
			{
				isRightChild = false;
			}
			else
			{
				isRightChild = true;
			}
			current->Balance = current->RightBalance() + current->LeftBalance();
			if (current->Balance > 1)
			{
				if (!isRightChild)
				{
					parents.back()->LeftChild = rotateLeft(current);
				}
				else
				{
					parents.back()->RightChild = rotateLeft(current);
				}
			}
			else if (current->Balance < -1)
			{
				if (!isRightChild)
				{
					parents.back()->LeftChild = rotateRight(current);
				}
				else
				{
					parents.back()->RightChild = rotateRight(current);
				}
			}
		}
		std::cout << "step 1" << std::endl;
		
		current = parents.back();
		current->Balance = current->RightBalance() + current->LeftBalance();
		if (current->Balance > 1)
		{
			head = rotateLeft(current);
		}
		else if (current->Balance < -1)
		{
			head = rotateRight(current);
		}
	}

	void FakeAdd(T value)
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
