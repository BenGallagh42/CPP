#include <iostream>
#include <string>

int main()
{
	std::string		str = "HI THIS IS BRAIN"; 	// Initialisation variable
	std::string*	stringPTR = &str;			// Pointeur vers str grace a &
	std::string&	stringREF = str;			// Reference a str(alias), pointe directement sur str

	// Affiche adresse memoire de str
	std::cout << "Address of str: " 			<< &str			<< std::endl;
	// Affiche stockee dans stringPTR (idem que &str)
	std::cout << "Address held by stringPTR: " 	<< stringPTR	<< std::endl;
	// Affiche adresse de stringREF (idem que &str car alias de str)
	std::cout << "Address held by stringREF: " 	<< &stringREF	<< std::endl;

	std::cout << std::endl;

	// Afficher la string str
	std::cout << "Value of str: "				<< str			<< std::endl;
	// Dereference le pointeur pour obtenir la valeur de str
	std::cout << "Value pointed by stringPTR: " << *stringPTR	<< std::endl;
	// Affiche idem que str car stringRef est un alias de str
	std::cout << "Value pointer by stringREF: " << stringREF	<< std::endl;

	return 0;
}