#ifndef PROJECTAED_G24_APPLICATION_H
#define PROJECTAED_G24_APPLICATION_H

#include "Student.h"
#include "UniClass.h"
#include "bst.h"
#include <map>
#include <set>


struct studentAndClass {
    string studentCode;
    string name;
    string classCode;
    string ucCode;
    int weekDay;
    CLASS_TYPE classType;
    double startHour;
    double duration;

    friend bool operator<(studentAndClass a, studentAndClass b) {
        if (b.weekDay == a.weekDay) {
            if (b.startHour == a.startHour) {
                if (b.studentCode == a.studentCode) {
                    if (b.name == a.name) {
                        if (b.classCode == a.classCode) {
                            if (b.ucCode == a.ucCode) {
                                if (b.classType == a.classType) {
                                    return b.duration < a.duration;

                                } else {
                                    return b.classType < a.classType;
                                }
                            } else {
                                return b.ucCode < a.ucCode;
                            }
                        } else {
                            return b.classCode < a.classCode;
                        }
                    } else {
                        return b.name < a.name;
                    }
                } else {
                    return b.studentCode < a.studentCode;
                }
            } else {
                return b.startHour > a.startHour;
            }
        } else {
            return b.weekDay > a.weekDay;
        }
    }
};

struct schedule {
    string classCode;
    string ucCode;

    friend bool operator<(schedule a, schedule b) {
        if (b.ucCode == a.ucCode) {
            if (b.classCode == a.classCode) {
            } else {
                return b.classCode < a.classCode;
            }
        } else {
            return b.ucCode < a.ucCode;
        }
        return false;
    }
};

struct StudentUcs {
    string name;
    string studentCode;
    string count;

    friend bool operator<(StudentUcs a, StudentUcs b) {
        if (b.name == a.name) {
            if (b.studentCode == a.studentCode) {
                if (b.count == a.count) {
                } else {
                    return b.count < a.count;
                }
            } else {
                return b.studentCode < a.studentCode;
            }
        } else {
            return b.name > a.name;
        }
        return false;
    }
};

struct ClassSchelude {
    string ucCode;
    int weekDay;
    CLASS_TYPE classType;
    double startHour;
    double duration;

    friend bool operator<(ClassSchelude a, ClassSchelude b) {
        if (b.weekDay == a.weekDay) {
            if (b.startHour == a.startHour) {
                if (b.ucCode == a.ucCode) {
                    if (b.classType == a.classType) {
                        return b.duration < a.duration;
                    } else {
                        return b.classType < a.classType;
                    }
                } else {
                    return b.ucCode < a.ucCode;
                }
            } else {
                return b.startHour > a.startHour;
            }
        } else {
            return b.weekDay > a.weekDay;
        }
    }
};

struct Ficheiro {
    string studentCode;
    string name;
    string ucCode;
    string classCode;

    friend bool operator<(Ficheiro a, Ficheiro b) {
        if (b.studentCode == a.studentCode) {
            if (b.name == a.name) {
                if (b.ucCode == a.ucCode) {
                    return b.classCode > a.classCode;
                } else {
                    return b.ucCode > a.ucCode;
                }
            } else {
                return b.name > a.name;
            }
        } else {
            return b.studentCode > a.studentCode;
        }
    }
};

enum REQUEST_TYPE {
    ADD, CHANGE, REMOVE
};

struct Request {
    REQUEST_TYPE type;
    string studentCode;
    string ucCode;
    string classCode;
    int cap;
};

class Application {

public:

    map<string, string> UcsMap = {{"L.EIC001", "ALGA"},
                                  {"L.EIC002", "AM I"},
                                  {"L.EIC003", "FP"},
                                  {"L.EIC004", "FSC"},
                                  {"L.EIC005", "MD"},
                                  {"L.EIC006", "AC"},
                                  {"L.EIC007", "AM II"},
                                  {"L.EIC008", "F I"},
                                  {"L.EIC009", "P"},
                                  {"L.EIC010", "TC"},
                                  {"L.EIC011", "AED"},
                                  {"L.EIC012", "BD"},
                                  {"L.EIC013", "F II"},
                                  {"L.EIC014", "LDTS"},
                                  {"L.EIC015", "SO"},
                                  {"L.EIC016", "DA"},
                                  {"L.EIC017", "ES"},
                                  {"L.EIC018", "LC"},
                                  {"L.EIC019", "LTW"},
                                  {"L.EIC020", "ME"},
                                  {"L.EIC021", "FSI"},
                                  {"L.EIC022", "IPC"},
                                  {"L.EIC023", "LBAW"},
                                  {"L.EIC024", "PFL"},
                                  {"L.EIC025", "RC"}};

    /**
    * Reads the file classes.csv and stores it in a set, using the UniClass constructor.
    * Complexity : O(1)
    * @return set<UniClass*>
    */
    set<UniClass *> readUniclasses();

    /**
    * Reads the file students_classes.csv and stores it in a set, using the Student constructor.
    * Complexity : O(n)
    * @return set<UniClass*>
    */
    set<Student *> readStudents();

    /**
    * Reads the file classes_per_uc.csv and stores it in a set, using the schedule struct.
    * Complexity : O(n)
    * @return set<UniClass*>
    */
    set<schedule> readClassesPerUC();

    /**
    * Joins the sets from the functions readUniclasses and readStudents into a single set, to join all the information about schedules and students.
    * Complexity : O(n^3)
    * @return set<studentAndClass>
    */
    set<studentAndClass> StudentClass();

    /**
    * Puts the time in the correct format (hh:mm).
    * Complexity : O(1)
    * @param hour
    * @return hourStart
    */
    string FormatDate(float hour);

    /**
    * Goes through the set of the function StudentClass and adds to a new set (without duplicates) the student's classes that the user entered.
    * Complexity : O(n)
    * @param studentCode
    * @return set<UniClass*>
    */
    set<studentAndClass> StudentSchedule(string studentCode);

    /**
    * Creates a set with all the lessons in a class, entered by the use.
    * Complexity : O(n^2)
    * @param classCode
    * @return set<studentAndClass>
    */
    set<ClassSchelude> ClassesSchedule(string classCode);

    /**
    * Create a bst with all students and their number of Ucs
    * Complexity : O(n^2)
    * @return BST<StudentUcs>
    */
    BST<StudentUcs> StudentUC();

    /**
    * Creates a bst with all students of a certain year (1, 2 or 3).
    * Complexity : O(n^2)
    * @param ano
    * @return  BST<pair<string, string>>
    */
    BST<pair<string, string>> StudentNumbYear(int ano);

    /**
    * Creates a bst with all students enrolled in a given Uc.
    * Complexity : O(n^2)
    * @param uccode
    * @return BST<pair<string, string>>
    */
    BST<pair<string, string>> StudentNumbUc(string uccode);

    /**
    * Creates a bst with all students enrolled in a specific Uc in a specific class.
    * Complexity : O(n^2)
    * @param uccode
    * @param turmaFinal
    * @return set<UniClass*>
    */
    BST<pair<string, string>> StudentClassUc(string uccode, string turmaFinal);

    /**
    * Removes a class from a student.
    * Complexity : O(n)
    * @param studentCode
    * @param uccode
    */
    void RemoveClass(string studentCode, string ucCode);

    /**
    * Gets a name from student using their code.
    * Complexity : O(n)
    * @param studentCode
    * @return name
    */
    string StudentName(string studentCode);

    /**
    * checks for overlapping lessons .
    * Complexity : O(n)
    * @param weekday
    * @param startHour
    * @param duration
    * @param classType
    * @return bool
    */
    bool Overlapping(int weekday, double startHour, double duration, CLASS_TYPE classType);

    /**
    * Add a class to a student.
    * Complexity : O(n)
    * @param studentCode
    * @param ucCode
    * @param classCode
    * @param ocupation
    * @param Cap
    * @return bool
    */
    bool AddClass(string studentCode, string ucCode, string classCode, int ocupation, int Cap);

    /**
    * Executes all requests from the queue and adds the ones that cannot be executed to an array.
    * Complexity : O(n)
    * @param studentCode
    * @param uccode
    */
    void ResolveRequests();

    /**
    * Adds a request to add a class to the queue.
    * Complexity : O(1)
    * @param studentCode
    * @param ucCode
    * @param classCode
    * @param cap
    */
    void AddAddRequest(string studentCode, string ucCode, string classCode, int cap);

    /**
    * Adds a request to change a class to the queue.
    * Complexity : O(1)
    * @param studentCode
    * @param ucCode
    * @param classCode
    * @param cap
    */
    void AddChangeRequest(string studentCode, string ucCode, string classCode, int cap);

    /**
    * Adds a request to remove a class to the queue.
    * Complexity : O(1)
    * @param studentCode
    * @param ucCode
    */
    void AddRemoveRequest(string studentCode, string ucCode);

    /**
    * Calculates the occupation of a class.
    * Complexity : O(n)
    * @param ucCode
    * @param classCode
    * @return ocupation
    */
    int OcupationPerUcClass(string ucCode, string classCode);

    /**
    * Saves all changes to a file.
    * Complexity : O(n)
    */
    void saveStudents();

private:
    set<studentAndClass> studentsClassSet = {};
    set<UniClass *> uniClassSet = {};
    set<Student *> studentSet = {};
    set<schedule> classesPerUcSet = {};
    set<studentAndClass> studentSchedule = {};
    set<ClassSchelude> classSchedule = {};
    queue<Request> requests = {};
    vector<Request> requestDenied = {};
};

#endif //PROJECTAED_G24_APPLICATION_H