
#ifndef HOSTEL_H
#define HOSTEL_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <sstream>
using namespace std;


class Hostel
{
protected:
    string name;
    string location;
    double rentPerMonth;
    double distanceFromCollege;
    bool isBookmarked;

public:
     Hostel(const string &name, const string &location, double rentPerMonth, double distanceFromCollege);
    virtual void displayInfo() = 0;

    bool getBookmarkStatus();

    void toggleBookmark();

    string getName();

    double getRentPerMonth();

    double getDistanceFromCollege();

    string getLocation();

    virtual void printTableHeadings() = 0;
};


#endif