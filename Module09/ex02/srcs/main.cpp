/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:15:01 by shmoreno          #+#    #+#             */
/*   Updated: 2025/04/29 18:40:14 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.tpp"

// Main test that comes from the subject
/*int main()
{
	std::list<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}*/

int main(void)
{
    std::cout << "===== Test MutantStack =====" << std::endl;

    {
        std::cout << "\n--- Test 1: push(), top(), pop() ---" << std::endl;
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top: " << mstack.top() << std::endl; // 17
        mstack.pop();
        std::cout << "Size after pop: " << mstack.size() << std::endl; // 1
    }

    {
        std::cout << "\n--- Test 2: Iteration ---" << std::endl;
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(42);
        std::cout << "Elements (bottom to top): ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl; // "5 17 3 42"
    }

    {
        std::cout << "\n--- Test 3: Comparaison with std::list ---" << std::endl;
        MutantStack<int> mstack;
        std::list<int> list;

        list.push_back(5);
        list.push_back(17);
        list.push_back(3);
        list.push_back(42);

        mstack.push(5);
        mstack.push(17);
        mstack.push(3);
        mstack.push(42);
        MutantStack<int>::iterator mstack_it = mstack.begin();
        std::list<int>::iterator list_it = list.begin();

        bool are_equal = true;
        while (mstack_it != mstack.end() && list_it != list.end()) {
            if (*mstack_it != *list_it) {
                are_equal = false;
                break;
            }
            ++mstack_it;
            ++list_it;
        }

        std::cout << "MutantStack and list have the same elements: " 
                  << (are_equal ? "YES" : "NO") << std::endl; // YES
    }

    {
        std::cout << "\n--- Test 4: Large Stack (10,000 elements) ---" << std::endl;
        MutantStack<int> mstack;

        for (int i = 0; i < 10000; ++i) {
            mstack.push(i);
        }

        std::cout << "Size: " << mstack.size() << std::endl; // 10000
        std::cout << "First element: " << *mstack.begin() << std::endl; // 0
        std::cout << "Last element: " << *(mstack.end() - 1) << std::endl; // 9999
	}
    return (0);
}