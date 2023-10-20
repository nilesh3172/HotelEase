#include "Hostel_Manager.h"

void HostelManager::addHostel(const string &collegeName, Hostel *hostel)
{
    hostelsByCollege[collegeName].push_back(hostel);
}

vector<Hostel *> &HostelManager::getColleges(const string &collegeName)
{
    return hostelsByCollege[collegeName];
}

void HostelManager::showAllHostels(const string &collegeName)
{
    vector<Hostel *> &hostels = getColleges(collegeName);

    showHostels(hostels);
}

void HostelManager::filterByRent(vector<Hostel *> &hostels)
{
    sort(hostels.begin(), hostels.end(), [](Hostel *a, Hostel *b)
         { return a->getRentPerMonth() < b->getRentPerMonth(); });
}

vector<Hostel *> HostelManager::filterByHostelType(vector<Hostel *> &hostels, const string &hostelType)
{
    vector<Hostel *> filteredHostels;
    cout << "in filtered by type" << endl;

    for (Hostel *h : hostels)
    {

        if (hostelType == "PG" && dynamic_cast<PG *>(h) != nullptr)
        {
            filteredHostels.push_back(h);
        }
        else if (hostelType == "Apartment" && dynamic_cast<Apartment *>(h) != nullptr)
        {
            filteredHostels.push_back(h);
        }
        else if (hostelType == "College" && dynamic_cast<CollegeHostel *>(h) != nullptr)
        {
            filteredHostels.push_back(h);
        }
    }
    return filteredHostels;
}

void HostelManager::filterByDistance(vector<Hostel *> &hostels)
{
    sort(hostels.begin(), hostels.end(), [](Hostel *a, Hostel *b)
         { return a->getDistanceFromCollege() < b->getDistanceFromCollege(); });
}

void HostelManager::showHostels(vector<Hostel *> &hostels)
{

    bool pgHeadingsPrinted = false;
    bool apartmentHeadingsPrinted = false;
    bool collegeHeadingsPrinted = false;

    for (auto hostel : hostels)
    {

        if (dynamic_cast<PG *>(hostel) != nullptr)
        {
            if (!pgHeadingsPrinted)
            {
                if (pgHeadingsPrinted || apartmentHeadingsPrinted || collegeHeadingsPrinted)
                {
                    cout << "\n\n\n";
                }
                PG *pgHostel = dynamic_cast<PG *>(hostel);
                pgHostel->printTableHeadings();
                pgHeadingsPrinted = true;
            }
            PG *pgHostel = dynamic_cast<PG *>(hostel);
            pgHostel->displayInfo();
        }
        else if (dynamic_cast<Apartment *>(hostel) != nullptr)
        {
            if (!apartmentHeadingsPrinted)
            {
                if (pgHeadingsPrinted || apartmentHeadingsPrinted || collegeHeadingsPrinted)
                {
                    cout << "\n\n\n";
                }
                Apartment *apartmentHostel = dynamic_cast<Apartment *>(hostel);
                apartmentHostel->printTableHeadings();
                apartmentHeadingsPrinted = true;
            }
            Apartment *apartmentHostel = dynamic_cast<Apartment *>(hostel);
            apartmentHostel->displayInfo();
        }
        else if (dynamic_cast<CollegeHostel *>(hostel) != nullptr)
        {
            if (!collegeHeadingsPrinted)
            {
                if (pgHeadingsPrinted || apartmentHeadingsPrinted || collegeHeadingsPrinted)
                {
                    cout << "\n\n\n";
                }
                CollegeHostel *collegeHostel = dynamic_cast<CollegeHostel *>(hostel);
                collegeHostel->printTableHeadings();
                collegeHeadingsPrinted = true;
            }
            CollegeHostel *collegeHostel = dynamic_cast<CollegeHostel *>(hostel);
            collegeHostel->displayInfo();
        }
    }

    cout << endl
         << endl
         << endl;
}

void HostelManager::showBookmarkedHostels(const string &collegeName)
{
    vector<Hostel *> &hostels = getColleges(collegeName);

    bool pgHeadingsPrinted = false;
    bool apartmentHeadingsPrinted = false;
    bool collegeHeadingsPrinted = false;

    for (auto hostel : hostels)
    {
        if (hostel->getBookmarkStatus())
        {
            if (dynamic_cast<PG *>(hostel) != nullptr)
            {
                if (!pgHeadingsPrinted)
                {
                    PG *pgHostel = dynamic_cast<PG *>(hostel);
                    pgHostel->printTableHeadings();
                    pgHeadingsPrinted = true;
                }
                PG *pgHostel = dynamic_cast<PG *>(hostel);
                pgHostel->displayInfo();
            }
            else if (dynamic_cast<Apartment *>(hostel) != nullptr)
            {
                if (!apartmentHeadingsPrinted)
                {
                    Apartment *apartmentHostel = dynamic_cast<Apartment *>(hostel);
                    apartmentHostel->printTableHeadings();
                    apartmentHeadingsPrinted = true;
                }
                Apartment *apartmentHostel = dynamic_cast<Apartment *>(hostel);
                apartmentHostel->displayInfo();
            }
            else if (dynamic_cast<CollegeHostel *>(hostel) != nullptr)
            {
                if (!collegeHeadingsPrinted)
                {
                    CollegeHostel *collegeHostel = dynamic_cast<CollegeHostel *>(hostel);
                    collegeHostel->printTableHeadings();
                    collegeHeadingsPrinted = true;
                }
                CollegeHostel *collegeHostel = dynamic_cast<CollegeHostel *>(hostel);
                collegeHostel->displayInfo();
            }
            cout << endl
                 << endl
                 << endl;
        }
    }

    
}


void HostelManager::bookHostel(const string &collegeName, const string &hostelName)
{
    vector<Hostel *> &hostels = getColleges(collegeName);

    for (Hostel *hostel : hostels)
    {
        if (hostel->getName() == hostelName)
        {
            cout << "Booking " << hostelName << " in " << collegeName << "...\n";
            cout << hostelName << " in " << collegeName << " has been booked!\n";
            return;
        }
    }

    cout << "Hostel " << hostelName << " was not found in " << collegeName << ".\n";
    cout << endl
         << endl
         << endl;
}