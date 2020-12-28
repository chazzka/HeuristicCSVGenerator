#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>

#include "SOMA.cpp"


using namespace std;

#define BOUNDARY 100


void makeCSVfile(string filename, std::vector<std::vector<result>> result)
{
	ofstream file;
	file.open(filename + ".csv");
	std::vector<string> tempRes;

	for (unsigned int i = 0; i < result.size(); i++)
	{
		for (unsigned int p = 0; p < result.at(i).size(); p++)
		{

			if (i == 0)
			{
				tempRes.push_back(to_string(static_cast<int>(result.at(i).at(p).fez)) + ";" + to_string(result.at(i).at(p).cost));
			}
			else
			{
				tempRes.at(p) = tempRes.at(p) + ";" + to_string(result.at(i).at(p).cost);
			}
		}
	}
	for (int i = 0; i < tempRes.size(); i++)
	{
		file << tempRes.at(i) + "\n";
	}
	file.close();
}


int dimensionSize = 10;
const int runs = 30;


//TODO: paralelismus funguje nanic
int main()
{
	srand((unsigned)time(0));

	std::vector<string> names = { "BendCigar", "RotatedSchwefel", "Lunacek", "Rosenbrock", "HybridOne", "HybridOneTwo", "HybridOneThree", "CompositionOne", "CompositionTwo", "CompositionThree" };
	for (int funkce = 1; funkce <= 10; funkce++) {
		std::vector<std::vector<result>> csv;
		for (int j = 0; j < runs; j++) {
			csv.push_back(run(dimensionSize, funkce, BOUNDARY));
		}
		makeCSVfile(names[funkce-1], csv);
	}

	return 0;
}


