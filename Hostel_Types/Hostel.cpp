#include "Hostel.h"

Hostel:: Hostel(const string &name, const string &location, double rentPerMonth, double distanceFromCollege)
     : name(name), location(location), rentPerMonth(rentPerMonth),
      distanceFromCollege(distanceFromCollege), isBookmarked(false) {}

bool   Hostel::getBookmarkStatus() {    return isBookmarked; }

void   Hostel::toggleBookmark(){    isBookmarked = !isBookmarked;}

string Hostel::getName() {    return name;}

double Hostel::getRentPerMonth(){    return rentPerMonth;}

double Hostel::getDistanceFromCollege(){    return distanceFromCollege;}

string Hostel::getLocation(){    return location;}
    
