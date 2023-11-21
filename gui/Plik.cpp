#include "Plik.h"
#include <fstream>
#include <vector>
#include <string>
void Plik::read(std::vector<std::string>&list,std::string doc)
{
	std::string text;
	std::fstream file;
	file.open(doc, std::ios::in);
	while (!file.eof())
	{
		std::getline(file, text);
		list.push_back(text);
	}
	file.close();
}

void Plik::save(std::vector<std::string>& list, std::string doc)
{
	std::fstream file;
	file.open(doc, std::ios::out);

	for (auto x : list)
		file << x << std::endl;
	file.close();
}

void Plik::show(std::vector<std::string>list)
{
	for(auto x : list)
		std::cout << x << "\n";
}

void Plik::change(std::vector<std::string>& list, std::vector<std::string>& list2,int id)
{
	list[0] = list2[id];

	std::cout << id << "\n\n\n";
	if (id < 2)
		list[1] = "data = load(\"routePlan.mat\");";
	else 
		list[1] = "data = load(\"routePlan1.mat\");";


}
