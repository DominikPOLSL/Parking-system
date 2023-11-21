#pragma once
#include <vector>
#include <iostream>
#include <string>
class Plik
{
public:
	void read(std::vector<std::string> &list,std::string doc);
	void save(std::vector<std::string> &list,std::string doc);
	void show(std::vector<std::string>list);
	void change(std::vector<std::string>& list, std::vector<std::string>& list2, int id);
};

