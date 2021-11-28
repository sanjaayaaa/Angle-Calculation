#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

class CalculateResult{
public:
	CalculateResult();
	~CalculateResult() = default;
public:
	float maxElement(std::vector<std::vector<float>>& data);
	float minElement(std::vector<std::vector<float>>& data);
	std::vector<std::vector<float>> offsetCorrection(std::vector<std::vector<float>>& data, float offset);
	std::vector<std::vector<float>> amplitudeNormalization(std::vector<std::vector<float>>& data, float amplitude);
	std::vector<std::vector<float>> angleOfSineWave(std::vector<std::vector<float>>& sineWave);
	std::vector<std::vector<float>> angleOfCosineWave(std::vector<std::vector<float>>& cosineWave);
};
