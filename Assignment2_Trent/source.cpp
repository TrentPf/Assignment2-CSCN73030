#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct STUDENT_DATA // Define student info for one student, containing first name string and last name string
{
    std::string firstName;
    std::string lastName;
};

int main()
{
	std::vector<STUDENT_DATA> students; // Vector to hold all student data read from the file

    std::ifstream inputFile("StudentData.txt");

	if (!inputFile.is_open())   // Check if the file was opened successfully
    {
        std::cerr << "Error: Could not open StudentData.txt" << std::endl;
        return 1;
    }

    std::string line;

	while (std::getline(inputFile, line))   // Read each line from the file
    {
        std::stringstream ss(line);

        STUDENT_DATA student;

		std::getline(ss, student.firstName, ',');   // Read first name until the comma, then read last name until the end of the line
        std::getline(ss, student.lastName);

		students.push_back(student);    // Add the student data to the vector
    }

    inputFile.close();

    return 0;
}