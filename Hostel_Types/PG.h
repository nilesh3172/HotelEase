#ifndef PG_H
#define PG_H
#include "Hostel.h"

class PG :  public Hostel
{
    public:
    int availableBeds;
    string timings;
    string ownerName;
    string contactNumber;

   PG(const string &name, const string &location, double rentPerMonth, double distanceFromCollege,
       int availableBeds, const string &timings, const string &ownerName, const string &contactNumber);
    
    void printTableHeadings();

    void displayInfo();
};
#endif