#include "College_Hostel.h"

CollegeHostel:: CollegeHostel(const string &name, const string &location, double rentPerMonth, double distanceFromCollege,
                  int availableRooms, int personsInEachRoom, const string &timings, const string &ownerName, const string &contactNumber)
          : Hostel(name, location, rentPerMonth, distanceFromCollege), availableRooms(availableRooms),
          personsInEachRoom(personsInEachRoom), timings(timings), ownerName(ownerName), contactNumber(contactNumber) {}

void CollegeHostel::printTableHeadings()
{
    cout << "=====================================================================================================================================================\n";
    cout << "| " << left << setw(15) << "College Hostel"
              << "| " << left << setw(20) << "Location"
              << "| " << left << setw(20) << "Rent/Month"
              << "| " << left << setw(20) << "Open Time"
              << "| " << left << setw(16) << "Owner Name"
              << "| " << left << setw(16) << "Contact no"
              << "| " << left << setw(16) << "Distance (km)"
              << "| " << left << setw(16) << "Bookmark Status"
              << "| \n";
    cout << "=====================================================================================================================================================\n";
}

void CollegeHostel::displayInfo()
{
    cout << "| " << left << setw(15) << name
              << "| " << left << setw(20) << location
              << "| " << left << setw(20) << rentPerMonth
              << "| " << left << setw(20) << timings
              << "| " << left << setw(16) << ownerName
              << "| " << left << setw(16) << contactNumber
              << "| " << left << setw(16) << distanceFromCollege
              << "| " << left << setw(16) << (isBookmarked ? "Bookmarked" : "Not Bookmarked")
              << "| \n";
}