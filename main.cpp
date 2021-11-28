#include "Calculate.hpp"
#include "CSVReader.hpp"

static constexpr int rowSize = 13;
void printData(std::vector<std::vector<float>>& data);

int main(int argc, char *argv[])
{
	CalculateResult cal;
	CSVReader input;

	// TODO: This Path Needs to be checked
	auto sineData = input.loadCSV("/home/sanjay/Tut/myApp/Data/Sine.csv");
	auto cosineData = input.loadCSV("/home/sanjay/Tut/myApp/Data/Cosine.csv");

	float amplitudeOfSine = (cal.maxElement(sineData) - cal.minElement(sineData))/2.00;
	std::cout<< "Vmax Of Sine Wave : "<< cal.maxElement(sineData) <<std::endl;
	float amplitudeofCosine = (cal.maxElement(cosineData) - cal.minElement(cosineData))/2.00;
	std::cout<< "Vmax Of Cosine Wave : "<< cal.maxElement(cosineData)  <<std::endl;

	float offsetValueOfSine = (cal.maxElement(sineData) + cal.minElement(sineData))/2.00;
	float offsetValueOfCosine = (cal.maxElement(cosineData) + cal.minElement(cosineData))/2.00;

	auto offsetCorrectedSineWave = cal.offsetCorrection(sineData, offsetValueOfSine);
	float amplitudeOfCorrectedSine = (cal.maxElement(offsetCorrectedSineWave) - cal.minElement(offsetCorrectedSineWave))/2.00;
	std::cout<< "Vmax Of Corrected Sine Wave : "<< cal.maxElement(offsetCorrectedSineWave) <<std::endl;
	auto offsetCorrectedCosineWave = cal.offsetCorrection(cosineData, offsetValueOfCosine);
	float amplitudeOfCorrectedCosine = (cal.maxElement(offsetCorrectedSineWave) - cal.minElement(offsetCorrectedSineWave))/2.00;
	std::cout<< "Vmax Of Corrected Cosine Wave : "<< cal.maxElement(offsetCorrectedCosineWave) <<std::endl;

	auto normalizedSineWave = cal.amplitudeNormalization(offsetCorrectedSineWave, amplitudeOfSine);
	auto normalizedCosineWave = cal.amplitudeNormalization(offsetCorrectedCosineWave, amplitudeofCosine);

	auto angleSine = cal.angleOfSineWave(normalizedSineWave);
	auto angleCosine = cal.angleOfSineWave(normalizedCosineWave);

	std::cout<< "############################# Sine Wave ###############################"<< std::endl;
	printData(angleSine);
	std::cout<< "############################# Cosine Wave ###############################"<< std::endl;
	printData(angleCosine);
	return 0;
}

void printData(std::vector<std::vector<float>>& data)
{
	int p = 0;
	for(int i = 0; i < data.size(); i++){
		for(int j= 0; j<data[i].size(); j++){
		 std::cout << std::fixed;
		 std::cout << std::setprecision(1);
			std::cout << data[i][j] << " ";
			p++;
			if (p == rowSize){
				std::cout << std::endl;
				p = 0;
			}
		}
	}
	std::cout<< std::endl;
}

