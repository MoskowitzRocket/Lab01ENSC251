/**
 * @file lab1.cpp
 * @author Kale Moskowitz
 * @Date   9/16/2024
 * @version 1.0
 * @section DESCRIPTION 
 */
// I declare that this assignment is my own work and that I have correctly
// acknowledged the work of others.  I acknowledged that I have read and
// following the Academic Honesty and Integrity related policies as
// outlined in the syllabus.
//
// _____ (Kale Moskowitz) ____      _____(9/16/2024)______________
//
// ____ (301588993) ______

#include <iostream>
#include <vector>
#include <format>
#include <rapidcsv.h>
#include <string>
#include <fstream>


int main(){
	std::ofstream outputFile;
	outputFile.open ("example.csv");
	outputFile << "firstname, lastname, exam1grade, exam2grade, exam3grade, average\n";

	rapidcsv::Document grades_input{"grades.csv"}; //loads grades.csv
	std::vector<std::string> firstnames{grades_input.GetColumn<std::string>("firstname")};
	std::vector<std::string> lastnames{grades_input.GetColumn<std::string>("lastname")};
	std::vector<int> exam1grades{grades_input.GetColumn<int>("exam1grade")};
	std::vector<int> exam2grades{grades_input.GetColumn<int>("exam2grade")};
	std::vector<int> exam3grades{grades_input.GetColumn<int>("exam3grade")};

	std::cout << std::format("{:<20} {:<6} {:<6} {:<6} {:<5}\n",
			"Name","Exam1", "Exam2", "Exam3", "Avg");
	std::cout << "-----------------------------------------------\n";
	for (size_t i{0}; i <  firstnames.size(); ++i){
		float sumGrades = (exam1grades.at(i) + exam2grades.at(i) + exam3grades.at(i));
		std::cout << std::format("{:<20} {:<6} {:<6} {:<6} {:<5.2f}\n",firstnames.at(i) + " " + lastnames.at(i),
				exam1grades.at(i), exam2grades.at(i), exam3grades.at(i),sumGrades/3);
		outputFile <<  std::format("{},{},{},{},{},{:.2f}\n",firstnames.at(i),lastnames.at(i),
				exam1grades.at(i), exam2grades.at(i), exam3grades.at(i),sumGrades/3);

	}
	outputFile.close();

	return 0;
}

