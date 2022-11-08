#ifndef PROJECT_AED_MENU_CPP
#define PROJECT_AED_MENU_CPP

#include "Menu.h"
#include "Application.h"
#include <iostream>

using namespace std;
Application app;

Menu::Menu() {
    mainMenu();
}

void Menu::mainMenu() {
    int option;
    cout << "===============MAIN MENU===============" << endl;
    cout << "1 - Student Schedule" << endl;
    cout << "2 - Class Menu" << endl;
    cout << "3 - Students with more than n Ucs" << endl;
    cout << "4 - Request for schedule change" << endl;
    cout << "5 - Execute queue requests" << endl;
    cout << "6 - Exit" << endl;
    cout << "=======================================" << endl;
    cout << "Option:";
    cin >> option;

    while (option < 1 || option > 6) {
        cout << "This option is not valid, try again!" << endl;
        cout << "Option:";
        cin >> option;
    }

    switch (option) {
        case 1:
            SchedulePerStudent();
            break;
        case 2:
            ClassMenu();
            break;
        case 3:
            UcNumbers();
            break;
        case 4:
            ChangeRequest();
            break;
        case 5:
            app.ResolveRequests();
            mainMenu();
            break;
        case 6:
            app.saveStudents();
            exit(-1);
    }
}

void Menu::SchedulePerStudent() {
    string option;
    cout << "Enter your student code:";
    cin >> option;
    string nome;
    set<studentAndClass> studentAndClass = app.StudentSchedule(option);
    for (auto studentAndClassSet: studentAndClass) {
        if (studentAndClassSet.studentCode == option) {
            nome = studentAndClassSet.name;
            break;
        }
    }
    vector<string> weekdayNames = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    vector<string> classTypeNames = {"T", "TP", "PL"};
    if (studentAndClass.size() != 0) {
        cout << "Horario de " << nome << ", up" << option << endl;
        for (auto studentAndClassSet: studentAndClass) {
            float startHour = studentAndClassSet.startHour;
            float endHour = (studentAndClassSet.startHour + studentAndClassSet.duration);
            cout << weekdayNames[studentAndClassSet.weekDay] << " -> " << studentAndClassSet.ucCode << ": "
                 << app.UcsMap[studentAndClassSet.ucCode] << " | " << studentAndClassSet.classCode << " | [ClassType] "
                 << classTypeNames[studentAndClassSet.classType] << " | " << app.FormatDate(startHour) << "-"
                 << app.FormatDate(endHour) << endl;
        }
        string conti;
        cout << "Do you want to see any other schedule? (y/n)" << endl;
        cin >> conti;
        if (conti == "n" || conti == "N") {
            mainMenu();
        } else if (conti == "Y" || conti == "y") {
            SchedulePerStudent();
        } else {
            cout << "This option is not valid, please enter it again: (y/n):" << endl;
            cin >> conti;
        }
    } else {
        cout << "This option is not valid, try again!" << endl;
        SchedulePerStudent();
    }
}

void Menu::ChangeRequest() {
    int option;
    cout << "==============CHANGE MENU==============" << endl;
    cout << "1 - Remove class" << endl;
    cout << "2 - Add class" << endl;
    cout << "3 - Change class" << endl;
    cout << "4 - Back to the main menu" << endl;
    cout << "======================================" << endl;
    cout << "Option:";
    cin >> option;
    switch (option) {
        case 1:
            RemoveClass();
            break;
        case 2:
            AddClass();
            break;
        case 3:
            ChangeClass();
            break;
        case 4:
            mainMenu();
            break;
    }
}

void Menu::RemoveClass() {
    string studentCode;
    cout << "Enter the Student code:";
    cin >> studentCode;
    string ucCode;
    cout << "Enter the Uc code (format: L.EIC0XX):";
    cin >> ucCode;
    app.AddRemoveRequest(studentCode,ucCode);
    mainMenu();
}

void Menu::AddClass() {
    int cap;
    cout << "Enter the capacity of a class:";
    cin >> cap;
    string studentCode;
    cout << "Enter the Student code:";
    cin >> studentCode;
    string classCode;
    cout << "Enter the ClassCode (format: XLEICXX):";
    cin >> classCode;
    string ucCode;
    cout << "Enter the Uc code (format: L.EIC0XX):";
    cin >> ucCode;
    app.AddAddRequest(studentCode, ucCode, classCode, cap);
    mainMenu();
}

void Menu::ChangeClass() {
    int cap;
    cout << "Enter the capacity of a class:";
    cin >> cap;
    string studentCode;
    cout << "Enter the Student code:";
    cin >> studentCode;
    string classCode;
    cout << "Enter the ClassCode (format: XLEICXX):";
    cin >> classCode;
    string ucCode;
    cout << "Enter the Uc code (format: L.EIC0XX):";
    cin >> ucCode;
    app.AddChangeRequest(studentCode, ucCode, classCode, cap);
    mainMenu();
}


void Menu::ClassMenu() {
    int option;
    cout << "==============CLASS MENU==============" << endl;
    cout << "1 - Class Schedule" << endl;
    cout << "2 - Enrolled in a UC" << endl;
    cout << "3 - Enrolled in a year" << endl;
    cout << "4 - Occupancy of a class" << endl;
    cout << "5 - Back to the main menu" << endl;
    cout << "======================================" << endl;
    cout << "Option:";
    cin >> option;
    switch (option) {
        case 1:
            SchedulePerClass();
            break;
        case 2:
            StudentNUcs();
            break;
        case 3:
            StudentYears();
            break;
        case 4:
            OcupationPerClass();
            break;
        case 5:
            mainMenu();
            break;
    }
}

string Menu::ConstruirATurma() {
    int ano;
    int turma;

    cout << "Enter the year (1 a 3):" << endl;
    cin >> ano;
    while (ano < 1 || ano > 3) {
        cout << "The year entered is invalid! Please enter it again:" << endl;
        cin >> ano;
    }
    cout << "Enter the class number (1 a 16):" << endl;
    cin >> turma;
    while (turma < 1 || turma > 16) {
        cout << "The class entered is invalid! Please enter it again:" << endl;
        cin >> turma;
    }
    string turmaFinal;
    if (turma > 0 && turma < 9) {
        turmaFinal = to_string(ano) + "LEIC0" + to_string(turma);
    } else {
        turmaFinal = to_string(ano) + "LEIC" + to_string(turma);
    }
    return turmaFinal;
}

void Menu::SchedulePerClass() {
    string turmaFinal = ConstruirATurma();
    set<ClassSchelude> classesSchedule = app.ClassesSchedule(turmaFinal);
    cout << "The " << turmaFinal << " class has the following schedule:" << endl;
    vector<string> weekdayNames = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    vector<string> classTypeNames = {"T", "TP", "PL"};
    for (auto x: classesSchedule) {
        float startHour = x.startHour;
        float endHour = (x.startHour + x.duration);
        cout << weekdayNames[x.weekDay] << " -> " << x.ucCode << ": " << app.UcsMap[x.ucCode] << " | [ClassType] "
             << classTypeNames[x.classType] << " | " << app.FormatDate(startHour) << "-" << app.FormatDate(endHour)
             << endl;
    }

    string conti;
    cout << "Do you want to see any more schedules? (y/n)" <<
         endl;
    cin >>
        conti;
    if (conti == "n" || conti == "N") {
        ClassMenu();
    } else if (conti == "Y" || conti == "y") {
        SchedulePerClass();
    } else {
        cout << "This option is not valid, Please enter it again:" << endl;
        cin >> conti;
    }
}

void Menu::OcupationPerClass() {
    string turmaFinal = ConstruirATurma();
    string uccode;
    cout << "Enter the Uc code (format: L.EIC0XX):";
    cin >> uccode;
    BST<pair<string, string>> studentUc = app.StudentClassUc(uccode, turmaFinal);
    int count = 0;
    for (auto i = studentUc.begin(); i != studentUc.end(); i++) {
        cout << (*i).first << " [" << (*i).second << "]" << endl;
        count++;
    }
    cout << "There are " << count << " students enrolled in " << app.UcsMap[uccode] << " in class " << turmaFinal << endl;
    string conti;
    cout << "Wish to see any more classes? (y/n)" << endl;
    cin >> conti;
    if (conti == "n" || conti == "N") {
        ClassMenu();
    } else if (conti == "Y" || conti == "y") {
        OcupationPerClass();
    } else {
        cout << "This option is not valid, Please enter it again:" << endl;
        cin >> conti;
    }
}

void Menu::UcNumbers() {
    int n;
    cout << "Introduce the number of Ucs:";
    cin >> n;
    int count = 0;
    BST<StudentUcs> studentUc = app.StudentUC();

    for (auto i = studentUc.begin(); i != studentUc.end(); i++) {
        if (stoi((*i).count) > n) {
            cout << (*i).name << " [" << (*i).studentCode << "]" << endl;
            count++;
        }
    }
    if (count != 0) {
        cout << "There are " << count << " students with more than " << n << " UCs." << endl;
    } else {
        cout << "There are no students with more than " << n << " UCs." << endl;
    }

    string conti;
    cout << "Do you want to see any more numbers of UCs? (y/n)" << endl;
    cin >> conti;
    if (conti == "n" || conti == "N") {
        ClassMenu();
    } else if (conti == "Y" || conti == "y") {
        UcNumbers();
    } else {
        cout << "This option is not valid, Please enter it again:" << endl;
        cin >> conti;
    }
}

void Menu::StudentYears() {
    int ano;
    cout << "Enter the year (de 1 a 3):";
    cin >> ano;
    while (ano < 1 || ano > 3) {
        cout << "The year entered is invalid! Please enter it again:" << endl;
        cin >> ano;
    }
    int count = 0;
    BST<pair<string, string>> studentYear = app.StudentNumbYear(ano);
    for (auto i = studentYear.begin(); i != studentYear.end(); i++) {
        cout << (*i).first << " [" << (*i).second << "]" << endl;
        count++;
    }
    cout << "Ther are " << count << " students enrolled in " << ano << " year." << endl;
    string conti;
    cout << "Do you want to see another year? (y/n)" << endl;
    cin >> conti;
    if (conti == "n" || conti == "N") {
        ClassMenu();
    } else if (conti == "Y" || conti == "y") {
        StudentYears();
    } else {
        cout << "This option is not valid, Please enter it again:" << endl;
        cin >> conti;
    }
}

void Menu::StudentNUcs() {
    string uccode;
    cout << "Enter de Uc code (format: L.EIC0XX):";
    cin >> uccode;
    BST<pair<string, string>> studentUc = app.StudentNumbUc(uccode);
    int count = 0;
    for (auto i = studentUc.begin(); i != studentUc.end(); i++) {
        cout << (*i).first << " [" << (*i).second << "]" << endl;
        count++;
    }
    cout << "The are " << count << " students enrolled in " << app.UcsMap[uccode] << endl;
    string conti;
    cout << "Do you want to see another UC? (y/n)" << endl;
    cin >> conti;
    if (conti == "n" || conti == "N") {
        ClassMenu();
    } else if (conti == "Y" || conti == "y") {
        StudentNUcs();
    } else {
        cout << "This option is not valid, Please enter it again:" << endl;
        cin >> conti;
    }
}

#endif // PROJECT_AED_MENU_CPP