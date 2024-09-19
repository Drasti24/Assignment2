//DRASTI PATEL
//ASSIGNMENT 2 - PROJECT 5 - CSCN73030


//The header files
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

//structure to hold student's first name and last name
struct StudentData
{
    std::string FirstName;
    std::string LastName;
};


int main()
{
    //the vector to hold multiple student data in it.
    std::vector<StudentData> Students;

    //To open the text file (StudentData.txt) to read the data from it.
    std::ifstream inputFile("StudentData.txt");

    //if the file failed to open - show an error message.s
    if (!inputFile.is_open())
    {
        //if the file is unable to open, an error message should be printed.
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }


    //each line from the file would be stored in a variable.
    std::string line;

    //while to read the file line by line
    while (std::getline(inputFile, line))
    {
        //creating a string stream from the line to parse the first and last names.
        std::stringstream ss(line);
        std::string LastName;
        std::string FirstName;

        //extract the first and last names
        if (std::getline(ss, LastName, ',') && std::getline(ss, FirstName))
        {
            //create a student object and populate it with the first and last names.
            StudentData student;
            student.FirstName = FirstName;
            student.LastName = LastName;

            //add the student object to the student vector
            Students.push_back(student);
        }
    }


    //to close the input file after reading it completely
    inputFile.close();

    ////loop through the students vector and print their names
    for (const auto& student : Students)
    {
        std::cout << "" << student.FirstName;
        std::cout << ", " << student.LastName << std::endl;
    }

    return 1;
}
