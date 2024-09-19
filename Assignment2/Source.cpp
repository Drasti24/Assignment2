// DRASTI PATEL
// ASSIGNMENT 2 - PROJECT 5 - CSCN73030

// The header files
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

// Structure to hold student's first name, last name, and email
struct StudentData
{
    std::string FirstName;
    std::string LastName;
    std::string Email; // Make sure this matches the usage in the code
};

int main()
{
    // The vector to hold multiple student data
    std::vector<StudentData> students;

    // Open the text file (StudentData.txt) to read the data from it
    std::ifstream inputFile("StudentData.txt");

    // If the file failed to open, show an error message
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open StudentData text file." << std::endl;
        return 1;
    }

    // Each line from the file will be stored in this variable
    std::string line;

    // Read the file line by line
    while (std::getline(inputFile, line))
    {
        // Create a string stream from the line to parse the last and first names
        std::stringstream ss(line);
        std::string LastName;
        std::string FirstName;

        // Extract the last name first and then the first name (since the file format is LastName,FirstName)
        if (std::getline(ss, LastName, ',') && std::getline(ss, FirstName))
        {
            // Create a student object and populate it with the first and last names
            StudentData student;
            student.FirstName = FirstName;
            student.LastName = LastName;

            // Add the student object to the students vector
            students.push_back(student);
        }
    }

    // Close the input file after reading it completely
    inputFile.close();

    // Determine which mode we are in - 'DEBUG' or 'RELEASE'
#ifdef _DEBUG

#ifdef PRE_RELEASE
    std::cout << "Running in prerelease mode.\n" << std::endl;

    // Read and assign the emails to respective students
    std::ifstream emailFile("StudentData_Emails.txt");
    if (!emailFile.is_open())
    {
        //print an error if file could not be opened
        std::cerr << "Error: Could not open the StudentData_Emails text file." << std::endl;
        return 1;
    }

    std::string emailLine; // Variable to hold emails
    int i = 0;        // To track the student vector index

    //to loop through each line in email file
    while (std::getline(emailFile, emailLine))
    {
        //creating a stringstream to extract current line of email text file.
        std::stringstream emailSS(emailLine);

        //variables to hold the extracted lines
        std::string emailLastName, emailFirstName, email;

        //extract firstname, lastname and emails from the line
        if (std::getline(emailSS, emailLastName, ',') &&
            std::getline(emailSS, emailFirstName, ',') &&
            std::getline(emailSS, email))
        {
            //to check if there is corresponding student in the vector.
            if (i < students.size() &&
                students[i].LastName == emailLastName &&
                students[i].FirstName == emailFirstName)
            {
                //assign extracted email to corresponding student
                students[i].Email = email;
                //move to next student
                i++;
            }
        }
    }

    emailFile.close();

    // Print the names and emails
    for (const auto& student : students)
    {
        //std::cout << "" << student.FirstName
        //    << ", " << student.LastName
        //    << ", " << student.Email << std::endl;
        std::cout << "" << student.FirstName;
        std::cout << ", " << student.LastName;
        std::cout << ", " << student.Email << std::endl;
        std::cout << "\n";
    }

#else
    std::cout << "Running in Standard Mode. \n" << std::endl;

    // Print student names only (without email)
    for (const auto& student : students)
    {
        std::cout << "" << student.FirstName;
        std::cout << ", " << student.LastName << std::endl;
        std::cout << "\n";
    }
#endif
#else
#ifdef PRE_RELEASE
    std::cout << "Running in Pre-Release Mode.\n" << std::endl;

    // Read and print student emails
    std::ifstream emailFile("StudentData_Emails.txt");
    if (!emailFile.is_open())
    {
        //print an error if file couldn't be opened.
        std::cerr << "Error: Could not open email file." << std::endl;
        return 1;
    }

    //declare a variable to hold each lime of email file
    std::string emailLine;
    //loop through each line
    while (std::getline(emailFile, emailLine))
    {
        //create a stringstream object to parse current line of email file.
        std::stringstream emailSS(emailLine);

        //variables to hold extracted part of line
        std::string emailLastName, emailFirstName, email;

        //extract lastname, firstname and email from lines
        if (std::getline(emailSS, emailLastName, ',') &&
            std::getline(emailSS, emailFirstName, ',') &&
            std::getline(emailSS, email))
        {
            //print emails
            std::cout << email << std::endl;

        }
    }

    emailFile.close();
#else
    std::cout << "Running in standard mode\n" << std::endl;
#endif

#endif

    return 0;
}