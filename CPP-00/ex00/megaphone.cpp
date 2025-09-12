#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i = 1;

    if (argc > 1)
	{
        while (i < argc)
		{
            int j = 0;
            while (argv[i][j])
			{
                char letter = argv[i][j];
                std::cout << static_cast<char>(std::toupper(letter));
                j++;
            }
            i++;
            if (i < argc)
                std::cout << " ";
        }
        std::cout << std::endl;
    } 
	else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
