#ifndef PROJECTAED_G24_CLASS_H
#define PROJECTAED_G24_CLASS_H

#include <string>
using namespace std;

enum CLASS_TYPE {
    T, TP, PL
};

class UniClass {

public:
    /**
    * Creates an object of the struct UniClass.
    * Complexity : O(1)
    * @param classCode
    * @param ucCode
    * @param weekDay
    * @param startHour
    * @param duration
    * @param classType
    */
    UniClass(string classCode, string ucCode, int weekDay, double startHour, double duration, string classType);

    /**
    * Returns the UniClass's class code.
    * Complexity : O(1)
    * @return
    */
    string getClassCode() const;

    /**
    * Returns the UniClass's uc code.
    * Complexity : O(1)
    * @return
    */
    string getUcCode() const;

    /**
    * Returns the UniClass's week day.
    * Complexity : O(1)
    * @return
    */
    int getWeekDay() const;

    /**
    * Returns the UniClass's start hour.
    * Complexity : O(1)
    * @return
    */
    double getStartHour() const;

    /**
    * Returns the UniClass's duration.
    * Complexity : O(1)
    * @return
    */
    double getDuration() const;

    /**
    * Returns the UniClass's class type.
    * Complexity : O(1)
    * @return
    */
    CLASS_TYPE getClassType() const;

    /**
     * Sets the UniClass's class code.
     * Complexity : O(1)
     * @param classCode
     */
    void setClassCode(string classCode);

    /**
     * Sets the UniClass's uc code.
     * Complexity : O(1)
     * @param ucCode
     */
    void setUcCode(string ucCode);

    /**
     * Sets the UniClass's week day.
     * Complexity : O(1)
     * @param weekDay
     */
    void setWeekDay(int weekDay);

    /**
     * Sets the UniClass's start hour.
     * Complexity : O(1)
     * @param startHour
     */
    void setStartHour(double startHour);

    /**
     * Sets the UniClass's duration.
     * Complexity : O(1)
     * @param duration
     */
    void setDuration(double duration);

    /**
     * Sets the UniClass's class type.
     * Complexity : O(1)
     * @param classType
     */
    void setClassType(CLASS_TYPE classType);

private:
    string CLASSCODE;
    string UCCODE;
    int WEEKDAY;
    float STARTHOUR;
    float DURATION;
    CLASS_TYPE CLASSTYPE;
};

#endif //PROJECTAED_G24_CLASS_H