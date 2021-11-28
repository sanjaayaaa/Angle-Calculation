#include "CSVReader.hpp"  
CSVReader::CSVReader()
{
}

std::vector<std::vector<float>> CSVReader::loadCSV(std::string fileName)
{
	std::vector<std::vector<float>> data;
	std::ifstream in(fileName.c_str());
	float value;
	std::string element, delimiters = ",\n\r";
	int row = 0;
	char ch;
	data.push_back(std::vector<float>());
	while(in.read((char*)&ch, 1)){
		if(delimiters.find_first_of(ch)== delimiters.npos){
			element += ch;
		} else {
			if(ch != '\r'){
				value = boost::lexical_cast<float>(element);
				data[row].push_back(value);
				element = "";
				if(ch =='\n'){
					data.push_back(std::vector<float>());
					row++;
				}
			}
		}
	}
	if(element.size() > 0){
	data[row].push_back(value);
	in.close();
	}
	return data;
}

void CSVReader::destroyContents(std::vector<std::vector<float>>& data)
{
	for(int i = 0; i < data.size(); i++){
		for(int j= 0; j<data[i].size(); j++){
			data[i].pop_back();
			data.pop_back();
		}
	}
}

float CSVReader::getItem(std::vector<std::vector<float>>& data, int x, int y)
{
	return data[x][y];
}

int CSVReader::numberOfColumns(std::vector<std::vector<float>>& data)
{
	if (data.size()>0){
		return data[0].size();
	} else {
		return 0;
	}
}

int CSVReader::numberOfRows(std::vector<std::vector<float>>& data)
{
	return data.size();
}
