#include <string>
#include <vector>

using namespace std;

#ifndef PROJECTAED_G24_STUDENT_H
#define PROJECTAED_G24_STUDENT_H

class Student {

public:
    /**
    * Creates an object of the struct Student.
    * Complexity : O(1)
    * @param studentCode
    * @param name
    * @param vector<string> Class
    */
    Student(string studentCode, string name, vector<string> Class);

    /**
    * Returns the Student's name.
    * Complexity : O(1)
    * @return
    */
    string getName() const;

    /**
   * Returns the Student's code.
   * Complexity : O(1)
   * @return
   */
    string getStudentCode();

    /**
   * Returns the Student's classes vector.
   * Complexity : O(1)
   * @return
   */
    vector<vector<string>> getClasses() const;

    /**
    * Sets the Student's name.
    * Complexity : O(1)
    * @param name
    */
    void setName(string name);

    /**
    * Sets the Student's student code.
    * Complexity : O(1)
    * @param studentcode
    */
    void setStudentCode(string studentcode);

    /**
    * Adds a class to the array of student classes.
    * Complexity : O(1)
    * @param vector<string> Class
    */
    void addClass(vector<string> Class);

    /**
    * Compares if one attribute of a student is lower than the other.
    * Complexity : O(1)
    * @param Student &s1
    */
    bool operator<(const Student &s1) const;

    /**
    * Compares if one attribute of a student is higher than the other.
    * Complexity : O(1)
    * @param Student &s1
    */
    bool operator>(const Student &s1) const;

    /**
    * Does not allow duplicates.
    * Complexity : O(1)
    * @param Student &s1
    */
    bool operator==(const Student &s1) const;

private:
    string studentCode;
    string name;
    vector<vector<string>> classes = {};
};

#endif //PROJECTAED_G24_STUDENT_H