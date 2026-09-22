#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct STUDENT_DATA // Define student info for one student, containing first name string and last name string
{
    std::string firstName;
    std::string lastName;

#ifdef PRE_RELEASE  // If PRE_RELEASE is defined, include an email string in the student struct
    std::string email;
#endif
};

int main()
{
#ifdef PRE_RELEASE  // If PRE_RELEASE is defined, print a message indicating that the pre-release version is running
    std::cout << "Running Pre-Release Version" << std::endl;
#else   // If PRE_RELEASE is not defined, print a message indicating that the release version is running
	std::cout << "Running Release Version" << std::endl;
#endif

	std::vector<STUDENT_DATA> students; // Vector to hold all student data read from the file

#ifdef PRE_RELEASE  // If PRE_RELEASE is defined, read from StudentData_Emails.txt
	std::ifstream inputFile("StudentData_Emails.txt");
#else   // If PRE_RELEASE is not defined, read from StudentData.txt
    std::ifstream inputFile("StudentData.txt");
#endif

	if (!inputFile.is_open())   // Check if the file was opened successfully
    {
        std::cerr << "Error: Could not open student data file" << std::endl;
        return 1;
    }

    std::string line;

	while (std::getline(inputFile, line))   // Read each line from the file
    {
        std::stringstream ss(line);

        STUDENT_DATA student;

		std::getline(ss, student.firstName, ',');   // Read first name until the comma, then read last name until the end of the line

#ifdef PRE_RELEASE  // If PRE_RELEASE is defined, read the email as well
        std::getline(ss, student.lastName);
        std::getline(ss, student.email);
#else   //  If PRE_RELEASE is not defined, read the last name only
		std::getline(ss, student.lastName);
#endif

		students.push_back(student);    // Add the student data to the vector
    }

    inputFile.close();

#ifdef _DEBUG   // If _DEBUG is defined, print the student data to the console for debugging purposes

    std::cout << "Student Data:" << std::endl;
    for (const auto& student : students)   // Loop through the vector and print each
    {
        std::cout << student.firstName
            << " "
            << student.lastName;
#ifdef PRE_RELEASE  // If PRE_RELEASE is defined, print the email as well
            std::cout << " " << student.email;
#endif
            std::cout << std::endl;
    }

#endif

    return 0;
}