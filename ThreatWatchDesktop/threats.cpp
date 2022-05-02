#include "threats.h"

threats::threats()
{
}

// Add function
void threats::add(std::string name, double threatScore, std::string threatLvl)
{

	if (threatLvl.empty()) {
		throw(invalidThreatLvlException("Threat Level Invalid"));
	}
	else {
		threat temp;
		temp.name = name;
		temp.threatScore = threatScore;
		temp.threatLvl = threatLvl;
		threatList.emplace(name, temp);
	}
}

// Remove function
void threats::remove(std::string name)
{
	threatList.erase(name);
}
// Edit function with two parameters
void threats::edit(std::string name, double threatScore)
{
	threatList[name].threatScore = threatScore;

}
// Edit function with three parameters
void threats::edit(std::string name, double threatScore, std::string threatLvl)
{
	threatList[name].threatScore = threatScore;
	threatList[name].threatLvl = threatLvl;
}

// Search function
std::string threats::search(std::string name)
{
	std::string returnString;
	try {
		returnString = name + "\n" + std::to_string(threatList[name].threatScore) + "\n" + threatList[name].threatLvl;
	}
	catch (std::exception& e) {
		returnString = "non";
	}

	return returnString;
}

std::string threats::listByName()
{

	std::string outStr = "";

	for (auto i = threatList.begin(); i != threatList.end(); i++) {
		outStr += i->first + ", " + i->second.threatLvl + ", " + std::to_string(i->second.threatScore) + '\n';
	}


	return outStr;
}

std::string threats::listByLvl()
{
	return std::string();
}

std::string threats::listByScore()
{
	return std::string();
}

// Public sort function
void threats::sort()
{
	// Gets the size of the threat list
	int sizeOf = threatList.size();
	std::vector<threat> temp1;

	// Pushes back to a vector
	for (auto i = threatList.begin(); i != threatList.end(); i++) {
		temp1.push_back(i->second);
	}

	// Clears the map
	threatList.clear();
	// Sorts the vector
	temp1 = insertionSort(temp1, temp1.size());

	// Applies everything back to the map
	for (int i = 0; i < temp1.size(); i++) {
		threatList.emplace(temp1[i].name, temp1[i]);
	}
}

// Sort function that sorts from highets to lowest threat level
// Sort function could use a lot of work, ran out of time
std::vector<threat> threats::insertionSort(std::vector<threat> arr, int n)
{
	int i;
	std::vector<threat> arr2;

	for (i = 0; i < n; i++) {
		if (arr[i].threatLvl == "Critical") {
			arr2.push_back(arr[i]);
		}
	}
	for (i = 0; i < n; i++) {
		if (arr[i].threatLvl == "High") {
			arr2.push_back(arr[i]);
		}
	}
	for (i = 0; i < n; i++) {
		if (arr[i].threatLvl == "Medium") {
			arr2.push_back(arr[i]);
		}
	}
	for (i = 0; i < n; i++) {
		if (arr[i].threatLvl == "Low") {
			arr2.push_back(arr[i]);
		}
	}
	for (i = 0; i < n; i++) {
		if (arr[i].threatLvl == "None") {
			arr2.push_back(arr[i]);
		}
	}
	
	return arr2;
}
