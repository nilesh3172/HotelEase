
#include "Hostel_Manager.h"


int main()
{
    HostelManager hostelManager;
    string collegeName, choice, hostelType;

    PG pg1("PG Hostel 1", "Location 1", 500, 2.5, 10, "9:00 AM - 9:00 PM", "John Doe", "123-456-7890");
    PG pg2("PG Hostel 2", "Location 2", 600, 3.0, 8, "8:00 AM - 10:00 PM", "Alice Smith", "987-654-3210");
    PG pg3("PG Hostel 3", "Location 2", 400, 3.8, 8, "8:00 AM - 10:00 PM", "Alice Smith", "987-654-3210");
    PG pg4("PG Hostel 4", "Location 2", 800, 3.5, 8, "8:00 AM - 10:00 PM", "Alice Smith", "987-654-3210");
    PG pg5("PG Hostel 5", "Location 2", 300, 3.0, 8, "8:00 AM - 10:00 PM", "Alice Smith", "987-654-3210");

    Apartment apartment1("Apartment 1", "Location 3", 700, 2.0, "2BHK", 2, 4);
    Apartment apartment2("Apartment 2", "Location 4", 800, 3.5, "3BHK", 3, 5);
    Apartment apartment3("Apartment 3", "Location 4", 500, 3.5, "3BHK", 3, 5);
    Apartment apartment4("Apartment 4", "Location 4", 400, 3.5, "3BHK", 3, 5);

    // Sample data for College Hostel
    CollegeHostel collegeA("College Hostel 1", "College", 5000, 1.0, 20, 2, "9:30 AM - 6:30 PM", "Alice", "9876543212");
    CollegeHostel collegeB("College Hostel 2", "College", 4500, 1.5, 15, 3, "9:00 AM - 7:00 PM", "Bob", "9876543213");

    hostelManager.addHostel("College A", &pg1);
    hostelManager.addHostel("College A", &pg2);
    hostelManager.addHostel("College A", &pg3);
    hostelManager.addHostel("College A", &pg4);
    hostelManager.addHostel("College A", &pg5);

    hostelManager.addHostel("College A", &apartment2);
    hostelManager.addHostel("College A", &apartment1);
    hostelManager.addHostel("College A", &apartment4);

    hostelManager.addHostel("College B", &pg1);
    hostelManager.addHostel("College B", &pg3);
    hostelManager.addHostel("College B", &pg4);
    hostelManager.addHostel("College B", &apartment4);
    hostelManager.addHostel("College B", &apartment3);

    // Add the Co.ege Hostel to a specific college
    hostelManager.addHostel("College A", &collegeA);
    hostelManager.addHostel("College B", &collegeB);

    while (true)
    {

        cout << "Enter the college name (or 'exit' to quit): ";
        getline(cin, collegeName);

        if (collegeName == "exit")
        {
            break; // Exit the loop
        }

        while (true)
        {
            cout << "1] Show all hostels\n2] Show bookmarked hostels\n3] Book Hostel\n4] Back to the main menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == "1")
            {
                hostelManager.showAllHostels(collegeName);

                char filterRequired;
                cout << "Do you want to apply any filter(y/n)?" << endl;
                cin >> filterRequired;

                if (filterRequired == 'y')
                {
                    vector<Hostel *> &hostels = hostelManager.getColleges(collegeName);
                    cout << "size" << hostels.size() << endl;
                    while (true)
                    {

                        int filterChoice;
                        cout << "Select the filter:\n";
                        cout << "1] Rent (Low to High)\n";
                        cout << "2] Hostel Type\n";
                        cout << "3] Distance (Low to High)\n";
                        cout << "Enter your choice: ";
                        cin >> filterChoice;

                        if (filterChoice == 1)
                        {
                            cout << "Filtered by Rent (Low to High):\n";

                            vector<Hostel *> t1 = hostelManager.filterByHostelType(hostels, "PG");
                            hostelManager.filterByRent(t1);
                            hostelManager.showHostels(t1);

                            vector<Hostel *> t2 = hostelManager.filterByHostelType(hostels, "Apartment");
                            hostelManager.filterByRent(t2);
                            hostelManager.showHostels(t2);

                            vector<Hostel *> t3 = hostelManager.filterByHostelType(hostels, "College");
                            hostelManager.filterByRent(t3);
                            hostelManager.showHostels(t3);
                        }
                        else if (filterChoice == 2)
                        {
                            cout << "Enter the type of hostel (e.g., PG, Apartment, College): ";
                            cin >> hostelType;
                            vector<Hostel *> filteredHostels = hostelManager.filterByHostelType(hostels, hostelType);
                            hostelManager.showHostels(filteredHostels);
                            cout << "Filtered by Hostel Type: " << hostelType << "\n";
                        }
                        else if (filterChoice == 3)
                        {

                            cout << "Filtered by Distance (Low to High):\n";
                            vector<Hostel *> t1 = hostelManager.filterByHostelType(hostels, "PG");
                            hostelManager.filterByDistance(t1);
                            hostelManager.showHostels(t1);

                            vector<Hostel *> t2 = hostelManager.filterByHostelType(hostels, "Apartment");
                            hostelManager.filterByDistance(t2);
                            hostelManager.showHostels(t2);

                            vector<Hostel *> t3 = hostelManager.filterByHostelType(hostels, "College");
                            hostelManager.filterByDistance(t3);
                            hostelManager.showHostels(t3);
                        }
                        cout << "Do you want to apply another filter(y/n)?" << endl;
                        cin >> filterRequired;
                        if (filterRequired == 'n')
                            break;
                    }
                }

                char bookmarkOption;
                cout << "Do you want to bookmark any hostel(y/n)?" << endl;
                cin >> bookmarkOption;

                if (bookmarkOption == 'y')
                {

                    while (true)
                    {
                        vector<Hostel *> &hostels = hostelManager.getColleges(collegeName);
                        cout << "Enter the name of the hostel you want to bookmark: ";
                        string hostelName;
                        cin.ignore();
                        getline(cin, hostelName);

                        for (Hostel *hostel : hostels)
                        {
                            if (hostel->getName() == hostelName)
                            {
                                hostel->toggleBookmark();
                                cout << "Hostel " << hostelName << " has been bookmarked!" << endl;
                            }
                        }
                        cout << "Do you want to bookmar another Hostel(y/n)?" << endl;
                        cin >> bookmarkOption;
                        if (bookmarkOption == 'n')
                            break;
                    }
                }
            }
            else if (choice == "2")
            {
                hostelManager.showBookmarkedHostels(collegeName);
            }
            else if (choice == "3")
            {
                int bookopction = 0;
                while (true)
                {
                    cout << "Select the Booking Opction:\n";
                    cout << "1] Book From All Hostels\n";
                    cout << "2] Book From Bookmarked Hostels\n";
                    cout << "3] Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> bookopction;

                    if (bookopction == 1)
                    {
                        hostelManager.showAllHostels(collegeName);
                        cout << "Enter the name of the hostel you want to book: ";
                        string hostelName;
                        cin.ignore();
                        getline(cin, hostelName);
                        hostelManager.bookHostel(collegeName, hostelName);
                    }
                    else if (bookopction == 2)
                    {
                        hostelManager.showBookmarkedHostels(collegeName);
                        cout << "Enter the name of the hostel you want to book: ";
                        string hostelName;
                        cin.ignore();
                        getline(cin, hostelName);
                        hostelManager.bookHostel(collegeName, hostelName);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (choice == "4")
            {
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    return 0;
}
