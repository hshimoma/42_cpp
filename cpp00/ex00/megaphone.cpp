#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int i;
		int j;

		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
				j++;
			}
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}