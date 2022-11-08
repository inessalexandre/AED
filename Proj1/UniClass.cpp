#include "UniClass.h"
#include <string>
using namespace std;

UniClass::UniClass(string classCode, string ucCode, int weekDay, double startHour, double duration, std::string classType) : CLASSCODE(classCode), UCCODE(ucCode), WEEKDAY(weekDay), STARTHOUR(startHour), DURATION(duration) {
    if (classType=="TP"){
        CLASSTYPE = TP;
    }
    else if(classType=="T"){
        CLASSTYPE = T;
    }
    else {
        CLASSTYPE = PL;
    }
}

string UniClass::getClassCode() const{
    return CLASSCODE;
}

string UniClass::getUcCode() const{
    return UCCODE;
}

int UniClass::getWeekDay() const {
    return WEEKDAY;
}

double UniClass::getStartHour() const {
    return STARTHOUR;
}

double UniClass::getDuration() const {
    return DURATION;
}

CLASS_TYPE UniClass::getClassType() const {
    return CLASSTYPE;
}

void UniClass::setClassCode(string classCode) {
    this -> CLASSCODE = classCode;
}

void UniClass::setUcCode(string ucCode) {
    this -> UCCODE = ucCode;
}

void UniClass::setWeekDay(int weekDay) {
    this -> WEEKDAY = weekDay;
}

void UniClass::setStartHour(double startHour) {
    this-> STARTHOUR = startHour;
}

void UniClass::setDuration(double duration) {
    this -> DURATION = duration;
}

void UniClass::setClassType(CLASS_TYPE classType) {
    this -> CLASSTYPE = classType;
}

