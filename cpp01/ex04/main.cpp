#include <iostream>
#include <fstream>
#include <string>

std::string replaceString(std::string content, const std::string& s1, const std::string& s2)
{
	if (s1.empty())
	return content;

	std::string result = "";
	size_t pos;
	size_t from;

	pos = 0;
	from = 0;
	while ((pos = content.find(s1, from)) != std::string::npos)
	{
		result = result + content.substr(from, pos - from);
		result = result + s2;
		from = pos + s1.length();
	}
	result = result + content.substr(from);
	return (result);
}

int main(int argc, char*argv[])
{
	if (argc != 4)
	{
		std::cerr << "Error: Usage: ./replace <filenama> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream ifs(filename.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error: Could not open file: " << filename << std::endl;
		return (1);
	}
	std::ofstream ofs((filename + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Error: Could not creare replace file." << std::endl;
		ifs.close();
		return (1);
	}
	std::string line;
	std::string fullContent = "";
	while (std::getline(ifs, line))
	{
		fullContent = fullContent + line;
		if (!ifs.eof()) fullContent = fullContent + "\n";
	}
	ofs << replaceString(fullContent, s1, s2);

	ifs.close();
	ofs.close();
	return (0);
}

