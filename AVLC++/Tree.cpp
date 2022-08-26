#include "Node.cpp"
#include <deque>
#include <iostream>


template <typename T>
class Tree
{
private:


	std::shared_ptr<Node<T>> rotateLeft(std::shared_ptr<Node<T>> oldHead)
	{
		std::shared_ptr<Node<T>> newHead;

		if (oldHead->RightChild->GetBalance() < 0)
		{
			newHead = oldHead->RightChild->LeftChild;
			std::shared_ptr<Node<T>> oldLeftChild = newHead->LeftChild;
			std::shared_ptr<Node<T>> oldRightChild = newHead->RightChild;

			newHead->LeftChild = oldHead;
			newHead->RightChild = oldHead->RightChild;

			newHead->LeftChild->RightChild = oldLeftChild;
			newHead->RightChild->LeftChild = oldRightChild;

			newHead->RightChild->UpdateHeight();
		}
		else
		{
			newHead = oldHead->RightChild;
			std::shared_ptr<Node<T>> oldLeftChild = newHead->LeftChild;
			newHead->LeftChild = oldHead;
			oldHead->RightChild = oldLeftChild;
		}

		oldHead->UpdateHeight();
		newHead->UpdateHeight();

		return newHead;
	}



	std::shared_ptr<Node<T>> rotateRight(std::shared_ptr<Node<T>> oldHead)
	{
		std::shared_ptr<Node<T>> newHead;

		if (oldHead->LeftChild->GetBalance() > 0)
		{
			newHead = oldHead->LeftChild->RightChild;
			std::shared_ptr<Node<T>> oldLeftChild = newHead->LeftChild;
			std::shared_ptr<Node<T>> oldRightChild = newHead->RightChild;

			newHead->RightChild = oldHead;
			newHead->LeftChild = oldHead->LeftChild;

			newHead->LeftChild->RightChild = oldLeftChild;
			newHead->RightChild->LeftChild = oldRightChild;

			newHead->LeftChild->UpdateHeight();
		}
		else
		{
			newHead = oldHead->LeftChild;
			std::shared_ptr<Node<T>> oldRightChild = newHead->RightChild;
			newHead->RightChild = oldHead;
			oldHead->LeftChild = oldRightChild;
		}

		oldHead->UpdateHeight();
		newHead->UpdateHeight();

		return newHead;
	}


	std::shared_ptr<Node<T>> updateTree(std::deque<std::shared_ptr<Node<T>>>& nodesToUpdate)
	{
		std::shared_ptr<Node<T>> current;
		while (nodesToUpdate.size() > 1)
		{
			current = nodesToUpdate.back();
			nodesToUpdate.pop_back();
			bool isRightChild;
			if (current->Value < nodesToUpdate.back()->Value)
			{
				isRightChild = false;
				nodesToUpdate.back()->LeftChild = current;
			}
			else
			{
				isRightChild = true;
				nodesToUpdate.back()->RightChild = current;
			}
			if (current->GetBalance() > 1)
			{
				if (!isRightChild)
				{
					nodesToUpdate.back()->LeftChild = rotateLeft(current);
				}
				else
				{
					nodesToUpdate.back()->RightChild = rotateLeft(current);
				}
			}
			else if (current->GetBalance() < -1)
			{
				if (!isRightChild)
				{
					nodesToUpdate.back()->LeftChild = rotateRight(current);
				}
				else
				{
					nodesToUpdate.back()->RightChild = rotateRight(current);
				}
			}
			nodesToUpdate.back()->UpdateHeight();
		}

		current = nodesToUpdate.back();
		if (current->GetBalance() > 1)
		{
			current = rotateLeft(current);
		}
		else if (current->GetBalance() < -1)
		{
			current = rotateRight(current);
		}
		current->UpdateHeight();
		return current;
	}


	void destroy(std::shared_ptr<Node<T>> targetNode)
	{
		if (!targetNode)
		{
			return;
		}
		destroy(targetNode->LeftChild);
		destroy(targetNode->RightChild);
		targetNode->LeftChild = nullptr;
		targetNode->RightChild = nullptr;
	}

	std::shared_ptr<Node<T>> create(std::shared_ptr<Node<T>> targetNode)
	{
		create(targetNode->LeftChild);
		create(targetNode->RightChild);
	}


public:

	int Count;
	std::shared_ptr<Node<T>> head;

	Tree()
		: head{ nullptr }, Count{ 0 }
	{

	}


	Tree(Tree<T>& copyTree)
	{
		std::deque<std::shared_ptr<Node<T>>> backingDeque = std::deque<std::shared_ptr<Node<T>>>();
		backingDeque.push_back(copyTree.head);
		std::shared_ptr<Node<T>> current = head;
		while (backingDeque.size() > 0)
		{
			current = backingDeque.front();
			backingDeque.pop_front();
			if (current)
			{
				backingDeque.push_back(current->LeftChild);
				backingDeque.push_back(current->RightChild);
				Add(current->Value);
			}
		}
	}


	~Tree()
	{
		destroy(head);
		head = nullptr;
		Count = 0;
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
		parents.back()->UpdateHeight();

		head = updateTree(parents);
	}


	bool Remove(T value)
	{
		if (head == nullptr)
		{
			return false;
		}

		bool isHead = head->Value == value;
		std::shared_ptr<Node<T>> current = head;
		std::deque<std::shared_ptr<Node<T>>> parents = std::deque<std::shared_ptr<Node<T>>>();

		while (current->Value != value)
		{
			parents.push_back(current);
			if (value < current->Value)
			{
				current = current->LeftChild;
			}
			else
			{
				current = current->RightChild;
			}
			if (!current)
			{
				return false;
			}
		}


		if (!current->LeftChild)
		{
			if (isHead)
			{
				head = head->LeftChild;
			}
			else if (current->Value < parents.back()->Value)
			{
				parents.back()->LeftChild = current->RightChild;
			}
			else
			{
				parents.back()->RightChild = current->RightChild;
			}
		}
		else if (!current->RightChild)
		{
			if (isHead)
			{
				head = head->RightChild;
			}
			else if (current->Value < parents.back()->Value)
			{
				parents.back()->LeftChild = current->LeftChild;
			}
			else
			{
				parents.back()->RightChild = current->LeftChild;
			}
		}
		else
		{
			//current = targetNode
			std::deque<std::shared_ptr<Node<T>>> deepParents = std::deque<std::shared_ptr<Node<T>>>();
			current = current->LeftChild;
			while (current->RightChild)
			{
				deepParents.push_back(current);
				current = current->RightChild;
			}

			if (deepParents.size() > 0)
			{
				deepParents.back()->RightChild = current->LeftChild;
				//target has been replaced
				current->LeftChild = updateTree(deepParents);
			}
			if (isHead)
			{
				current->RightChild = head->RightChild;
			}
			else if (current->Value < parents.back()->Value)
			{
				current->RightChild = parents.back()->LeftChild->RightChild;
				parents.back()->LeftChild = current;
			}
			else
			{
				current->RightChild = parents.back()->RightChild->RightChild;
				parents.back()->RightChild = current;
			}

			parents.push_back(current);
		}

		head = updateTree(parents);
		Count--;
		return true;
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
};
