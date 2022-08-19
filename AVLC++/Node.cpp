#include <memory>

template <typename T>
class Node
{
private:
	


public:
	std::shared_ptr<Node<T>> RightChild;
	std::shared_ptr<Node<T>> LeftChild;
	T Value;
	int Height;
	int Balance;


	Node(T value)
		:Value{ value }, Height{ 1 }, Balance{ 0 }
	{

	}

	int RightBalance()
	{
		if (RightChild)
		{
			return RightChild->Balance;
		}
		else
		{
			return 0;
		}
	}

	int LeftBalance()
	{
		if (LeftChild)
		{
			return LeftChild->Balance;
		}
		else
		{
			return 0;
		}
	}
};