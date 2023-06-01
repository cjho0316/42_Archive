#include "MutantStack.hpp"

int main()
{
	std::cout << "MutantStack" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "------------------------------\n";
	std::cout << "Default list" << std::endl;
	{
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
			std::list<int> s(list);
	}
	std::cout << "------------------------------\n";
	std::cout << "Default deque" << std::endl;
	{
		std::deque<int> deque;
		deque.push_back(5);
		deque.push_back(17);
		std::cout << deque.back() << std::endl;
		deque.pop_back();
		std::cout << deque.size() << std::endl;
		deque.push_back(3);
		deque.push_back(5);
		deque.push_back(737);
		deque.push_back(0);
		std::deque<int>::iterator it = deque.begin();
		std::deque<int>::iterator ite = deque.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
			std::deque<int> s(deque);
	}


	return 0;
}
