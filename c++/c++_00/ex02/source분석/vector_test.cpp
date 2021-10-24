#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

class A
{
	public :
		A(int initial_deposit)
		{
			std::cout << "123" << std::endl;
		}

		~A()
		{
			std::cout << "destroying" << std::endl;
		}
};

int		main()
{
	int		amount[] = {1, 2, 3, 4, 5, 6};
	int		amount_size = (sizeof(amount) / sizeof(int));
	std::vector <A>		atest(amount, amount_size + amount);
	return (0);
}
