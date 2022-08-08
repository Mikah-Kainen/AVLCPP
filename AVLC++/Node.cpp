#include <memory>

template <typename T>
class Node
{
private:
	


public:
	std::shared_ptr<Node<T>> RightChild;
	std::shared_ptr<Node<T>> LeftChild;
	int Height;
	int Balance;

	Node()
	{

	}

};