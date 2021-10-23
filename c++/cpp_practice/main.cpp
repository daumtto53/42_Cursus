#include <iostream>
#include <string>
#include <cstring>


int main()
{
	char str[100];
	char str2[] = "123";

	{
		std::cin >> str;
		std::cout << str;
		std::cout << std::endl;
	}

	getchar();

	{
		std::cin.getline(str, 100);
		std::cout << str << std::endl;
	}

	getchar();

	{
		std::cin.get(str, 100);
		std::cout << str;
	}
}
