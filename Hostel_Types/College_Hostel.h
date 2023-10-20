#ifndef COLLEGE_HOSTEL_H
#define COLLEGE_HOSTEL_H

#include "Hostel.h"

class CollegeHostel : public Hostel
{
    public:
    int availableRooms;
    int personsInEachRoom;
    string timings;
    string ownerName;
    string contactNumber;

     CollegeHostel(const string &name, const string &location, double rentPerMonth, double distanceFromCollege,
                  int availableRooms, int personsInEachRoom, const string &timings, const string &ownerName, const string &contactNumber);
    void printTableHeadings();

    void displayInfo();
};
#endif