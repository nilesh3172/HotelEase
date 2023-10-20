#ifndef APARTMENT_H
#define APARTMENT_H
#include "Hostel.h"

class Apartment :  public Hostel
{
    public:
    string flatType;
    int masterBedrooms;
    int maxStudentsAllowed;

     Apartment(const string &name, const string &location, double rentPerMonth, double distanceFromCollege,
              const string &flatType, int masterBedrooms, int maxStudentsAllowed);
       
    void printTableHeadings();

    void displayInfo();
    
};
#endif