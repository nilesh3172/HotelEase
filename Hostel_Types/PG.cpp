#include "PG.h"

PG::PG(const string &name, const string &location, double rentPerMonth, double distanceFromCollege,
       int availableBeds, const string &timings, const string &ownerName, const string &contactNumber)
     : Hostel(name, location, rentPerMonth, distanceFromCollege), availableBeds(availableBeds),
      timings(timings), ownerName(ownerName), contactNumber(contactNumber) {}

void PG::printTableHeadings()
{
    cout<<"here"<<endl;
    cout << "======================================================================================================================================================\n";
    cout << "| " << left << setw(15) << "PG Hostel"
              << "| " << left << setw(20) << "Location"
              << "| " << left << setw(15) << "Rent/Month"
              << "| " << left << setw(20) << "Open Time"
              << "| " << left << setw(16) << "Owner Name"
              << "| " << left << setw(16) << "Contact no"
              << "| " << left << setw(16) << "Distance (km)"
              << "| " << left << setw(16) << "Bookmark Status"
              << "| \n";
    cout << "======================================================================================================================================================\n";
}
void PG::displayInfo()
{
    cout << "| " << left << setw(15) << name
              << "| " << left << setw(20) << location
              << "| " << left << setw(15) << rentPerMonth
              << "| " << left << setw(20) << timings
              << "| " << left << setw(16) << ownerName
              << "| " << left << setw(16) << contactNumber
              << "| " << left << setw(16) << distanceFromCollege
              << "| " << left << setw(16) << (isBookmarked ? "Bookmarked" : "Not Bookmarked")
              << "| \n";
}

