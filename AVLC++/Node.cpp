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
		:Value{ value }, Height{ 0 }, Balance{ 0 }
	{

	}

};