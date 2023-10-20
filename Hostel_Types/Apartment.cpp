#include "Apartment.h"

Apartment:: Apartment(const string &name, const string &location, double rentPerMonth, double distanceFromCollege,
              const string &flatType, int masterBedrooms, int maxStudentsAllowed)
       : Hostel(name, location, rentPerMonth, distanceFromCollege),
      flatType(flatType), masterBedrooms(masterBedrooms), maxStudentsAllowed(maxStudentsAllowed) {}


void Apartment::printTableHeadings()
{
    cout << "=====================================================================================================================================================\n";
    cout << "| " << left << setw(15) << "Apartment "
              << "| " << left << setw(20) << "Location"
              << "| " << left << setw(20) << "Flat Type"
              << "| " << left << setw(15) << "Master Bedrooms"
              << "| " << left << setw(16) << "Max Beds"
              << "| " << left << setw(16) << "Rent/Month"
              << "| " << left << setw(16) << "Distance (km)"
              << "| " << left << setw(16) << "Bookmark Status"
              << "| \n";
    cout << "=====================================================================================================================================================\n";
}


void Apartment::displayInfo()
{
    cout << "| " << left << setw(15) << name
              << "| " << left << setw(20) << location
              << "| " << left << setw(20) << flatType
              << "| " << left << setw(15) << masterBedrooms
              << "| " << left << setw(16) << maxStudentsAllowed
              << "| " << left << setw(16) << rentPerMonth
              << "| " << left << setw(16) << distanceFromCollege
              << "| " << left << setw(16) << (isBookmarked ? "Bookmarked" : "Not Bookmarked")
              << "| \n";
    
}

