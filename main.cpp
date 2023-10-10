#include "Hotel.h"
#include "Data.h"
int main()
{
    unordered_map<string, vector<Hotel>> hotelsByLocation;

    // Add some hotels and rooms with locations
    Hotels_Data(hotelsByLocation);

    while (true)
    {
        cout << "Enter a location to search for hotels (0 to exit): ";
        string searchLocation;
        getline(cin, searchLocation);

        if (searchLocation == "0")
        {
            break; // Exit the program
        }

        cout << "Hotels in " << searchLocation << ":" << endl;
        bool found = false;
        vector<Hotel> hotels;
        if (hotelsByLocation.find(searchLocation) != hotelsByLocation.end())
        {
            hotels = hotelsByLocation[searchLocation];
            for (size_t i = 0; i < hotels.size(); ++i)
            {
                cout << i + 1 << ". " << hotels[i].getName() << " in " << hotels[i].getLocation() << endl;
                found = true;
            }
        }

        if (!found)
        {
            cout << "No hotels found in " << searchLocation << endl;
            continue;
        }

        int hotelChoice;
        cout << "Enter the number of the hotel you want to book (0 to go back): ";
        cin >> hotelChoice;
        cin.ignore(); // Clear the input buffer

        if (hotelChoice == 0)
        {
            continue;
        }
        else if (hotelChoice >= 1 && hotelChoice <= hotels.size())
        {
            // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Hotel &selectedHotel = hotels[hotelChoice - 1];
            double totalBill = 0.0;

            while (true)
            {
                cout << "Sort by price:" << endl;
                cout << "1. Low to High" << endl;
                cout << "2. High to Low" << endl;
                cout << "3. Search by Capacity" << endl;
                cout << "0. Back to hotel selection" << endl;

                int sortChoice;
                cout << "Enter your choice: ";
                cin >> sortChoice;

                if (sortChoice == 0)
                {
                    break;
                }
                else if (sortChoice == 1)
                {
                    selectedHotel.displayAvailableRooms(true); // Sort by price low to high
                }
                else if (sortChoice == 2)
                {
                    selectedHotel.displayAvailableRooms(false); // Sort by price high to low
                }
                else if (sortChoice == 3)
                {
                    int capacity;
                    cout << "Enter the room capacity you want to search for: ";
                    cin >> capacity;
                    selectedHotel.displayRoomsByCapacity(capacity);
                }
                else
                {
                    cout << "Invalid choice. Please select a valid option." << endl;
                }

                int roomChoice;
                cout << "Enter the room numbers you want to book (space-separated, 0 when all rooms are selected): ";
                vector<int> roomsToBook;

                while (cin >> roomChoice && roomChoice != 0)
                {
                    roomsToBook.push_back(roomChoice);
                }

                if (roomsToBook.empty())
                {
                    continue;
                }

                selectedHotel.bookRooms(roomsToBook);

                // Calculate the total bill for the selected rooms
                vector<Room> &hotelRooms = selectedHotel.getRooms();
                for (int roomNumber : roomsToBook)
                {
                    for (Room &room : hotelRooms)
                    {
                        if (room.getRoomNumber() == roomNumber)
                        {
                            totalBill += room.getPrice();
                        }
                    }
                }
                // Allow the user to choose whether to book more rooms or view the final bill
                cout << "Do you want to book more rooms (1 for Yes, 0 for Final Bill)? ";
                int bookMoreRoomsChoice;
                cin >> bookMoreRoomsChoice;

                if (bookMoreRoomsChoice == 0)
                {
                    // cout << "Your Final Bill (with 12% tax): $" << totalBill << endl;
                    break;
                }
            }
            // Calculate the tax (12%) on the total bill
            double tax = 0.12 * totalBill;
            totalBill += tax;

            cout << "Your Final Bill (with 12% tax): $" << totalBill << endl;
        }
        else
        {
            cout << "Invalid choice. Please select a valid hotel." << endl;
        }
        // Clear the input buffer
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
