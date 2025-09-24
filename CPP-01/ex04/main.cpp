#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	// Check arguments
	if (argc != 4)
	{
		std::cout << "Error: Use command: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Check s1
	if (s1.empty())
	{
		std::cout << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}

	// Ouverture fichier source
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cout << "Error: Cannot open file " << filename << std::endl;
		return 1;
	}

	// Creation et check fichier output
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cout << "Error: Cannot create file " << outputFilename << std::endl;
		inputFile.close();
		return 1;
	}

	// Lecture et remplacement
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}

	// Fermeture fichiers
	inputFile.close();
	outputFile.close();

	return 0;
}
