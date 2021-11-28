#include <vector>
#include <fstream>
#include <iostream>
#include <boost/lexical_cast.hpp>

class CSVReader{
public:
	CSVReader();
	~CSVReader() = default; 
public:
	std::vector<std::vector<float>> loadCSV(std::string fileName);
	void destroyContents(std::vector<std::vector<float>>& data);
	float getItem(std::vector<std::vector<float>>& data, int x, int y);
	int numberOfRows(std::vector<std::vector<float>>& data);
	int numberOfColumns(std::vector<std::vector<float>>& data);
};

