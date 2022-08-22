#include <memory>

template <typename T>
class Node
{
private:

public:
	std::shared_ptr<Node<T>> RightChild;
	std::shared_ptr<Node<T>> LeftChild;
	int Height;
	T Value;


	Node(T value)
		:Value{ value }, Height{ 1 }
	{

	}


	int GetBalance()
	{
		return RightHeight() - LeftHeight();
	}

	void UpdateHeight()
	{
		if (RightHeight() > LeftHeight())
		{
			Height = RightHeight() + 1;
		}
		else
		{
			Height = LeftHeight() + 1;
		}
	}


	int RightHeight()
	{
		if (RightChild)
		{
			return RightChild->Height;
		}
		else
		{
			return 0;
		}
	}

	int LeftHeight()
	{
		if (LeftChild)
		{
			return LeftChild->Height;
		}
		else
		{
			return 0;
		}
	}
};