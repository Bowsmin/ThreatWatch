/***************************************************************
* Name        : Threats
* Author      : Josiah Anderson
* Created     : 4/4/2022
***************************************************************/

/*
* 
* This program was meant to look better and do a lot more. I ran out of time so this is what came out as fast as I could get it done.
* There is a ton of functionality missing. This is the program in it's simplest form. Will probably continue working on what I have in mind after school.
* 
*/

#pragma once

#include <unordered_map>
#include "threatController.h"
#include "duplicateException.h"
#include "invalidThreatLvlException.h"
#include "invalidThreatScException.h"

class threats
{
private:
	// Vector size of 5 with threat level
	std::vector<std::string> threatLvl = { "None", "Low", "Medium", "High", "Critical" };
	// Sorting
	std::vector<threat> insertionSort(std::vector<threat> arr, int n);

public:

	std::unordered_map<std::string, threat> threatList; // The unordered map
	threats(); // Default constructor
	void add(std::string name, double threatScore, std::string threatLvl); // Add function
	void remove(std::string name); // Remove function
	void edit(std::string name, double threatScore); // Edit function with two parameters
	void edit(std::string name, double threatScore, std::string threatLvl); // Edit function with three parameters
	std::string search(std::string name); // Search Function
	// Unused list by function as of right now
	std::string listByName();
	std::string listByLvl();
	std::string listByScore();
	void sort(); // Sort function


};

