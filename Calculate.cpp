#include "Calculate.hpp"

CalculateResult::CalculateResult()
{
}

float CalculateResult::maxElement(std::vector<std::vector<float>>& data)
{
	float maxElement = 0.00;
	for(int i = 0; i < data.size(); i++){
		for(int j= 0; j<data[i].size(); j++){
			if (data[i][j] > maxElement){
				maxElement = data[i][j];
			}
		}
	}
	return maxElement;
}

float CalculateResult::minElement(std::vector<std::vector<float>>& data)
{
	float minElement = 1000.12;
	for(int i = 0; i < data.size(); i++){
		for(int j= 0; j<data[i].size(); j++){
			if (data[i][j] < minElement){
				minElement = data[i][j];
			}
		}
	}
	return minElement;
}

std::vector<std::vector<float>> CalculateResult::offsetCorrection(std::vector<std::vector<float>>& data, float offset)
{
	for(int i = 0; i < data.size(); i++){
		for(int j= 0; j<data[i].size(); j++){
			data[i][j] -= offset;
		}
	}
	return data;
}

std::vector<std::vector<float>> CalculateResult::amplitudeNormalization(
	std::vector<std::vector<float>>& data, 
	float amplitude)
{
	for(int i = 0; i < data.size(); i++){
		for(int j= 0; j<data[i].size(); j++){
			data[i][j] / amplitude;
		}
	}
	return data;
}

std::vector<std::vector<float>> CalculateResult::angleOfSineWave(std::vector<std::vector<float>>& sineWave)
{
	for(int i = 0; i < sineWave.size(); i++){
		for(int j= 0; j<sineWave[i].size(); j++){
			sineWave[i][j] = (asin(sineWave[i][j])*180.0/3.14);
		}
	}
	return sineWave;
}

std::vector<std::vector<float>> CalculateResult::angleOfCosineWave(std::vector<std::vector<float>>& cosineWave)
{
	for(int i = 0; i < cosineWave.size(); i++){
		for(int j= 0; j<cosineWave[i].size(); j++){
			cosineWave[i][j] = (acos(cosineWave[i][j])*180.0/3.14);
		}
	}
	return cosineWave;
}
