# include<bits/stdc++.h>
using namespace std;
class Room {
public:
    Room(int roomNumber, double price, int capacity, bool isAvailable = true)
        : roomNumber(roomNumber), price(price), capacity(capacity), isAvailable(isAvailable) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    double getPrice() const {
        return price;
    }

    int getCapacity() const {
        return capacity;
    }

    bool isRoomAvailable() const {
        return isAvailable;
    }

    void bookRoom() {
        isAvailable = false;
    }

    void checkoutRoom() {
        isAvailable = true;
    }

private:
    int roomNumber;
    double price;
    int capacity;
    bool isAvailable;
};

class Hotel {
public:
    Hotel(const string& name, const string& location)
        : name(name), location(location) {}

    void addRoom(const Room& room) {
        rooms.push_back(room);
    }

    const string& getName() const {
        return name;
    }

    const string& getLocation() const {
        return location;
    }

    void displayAvailableRooms(bool sortByPriceLowToHigh) const {
        cout << "Available rooms at " << name << " in " << location << ":" << endl;

        vector<Room> availableRooms;
        for (const Room& room : rooms) {
            if (room.isRoomAvailable()) {
                availableRooms.push_back(room);
            }
        }

        if (sortByPriceLowToHigh) {
            sort(availableRooms.begin(), availableRooms.end(),
                [](const Room& a, const Room& b) {
                    return a.getPrice() < b.getPrice();
                });
        } else {
            sort(availableRooms.begin(), availableRooms.end(),
                [](const Room& a, const Room& b) {
                    return a.getPrice() > b.getPrice();
                });
        }

        for (const Room& room : availableRooms) {
            cout << "Room " << room.getRoomNumber() << " - $" << room.getPrice()
                << " per night (Capacity: " << room.getCapacity() << " persons)" << endl;
        }

        cout << endl;
    }

    void displayRoomsByCapacity(int capacity) const {
        cout << "Available rooms at " << name << " in " << location << " with capacity for "
            << capacity << " persons:" << endl;

        for (const Room& room : rooms) {
            if (room.isRoomAvailable() && room.getCapacity() >= capacity) {
                cout << "Room " << room.getRoomNumber() << " - $" << room.getPrice()
                    << " per night (Capacity: " << room.getCapacity() << " persons)" << endl;
            }
        }

        cout << endl;
    }

    bool bookRoom(int roomNumber) {
        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber && room.isRoomAvailable()) {
                room.bookRoom();
                return true;
            }
        }
        return false;
    }

    bool checkoutRoom(int roomNumber) {
        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber && !room.isRoomAvailable()) {
                room.checkoutRoom();
                return true;
            }
        }
        return false;
    }

    double getStartingPrice() const {
        double minPrice = numeric_limits<double>::max();
        for (const Room& room : rooms) {
            if (room.getPrice() < minPrice) {
                minPrice = room.getPrice();
            }
        }
        return minPrice;
    }

    double getEndingPrice() const {
        double maxPrice = numeric_limits<double>::min();
        for (const Room& room : rooms) {
            if (room.getPrice() > maxPrice) {
                maxPrice = room.getPrice();
            }
        }
        return maxPrice;
    }

private:
    string name;
    string location;
    vector<Room> rooms;
};

int main() {
    vector<Hotel> hotels;

    // Add some hotels and rooms with locations
    hotels.push_back(Hotel("Cozy Inn", "New York"));
    hotels[0].addRoom(Room(101, 100.0, 2));
    hotels[0].addRoom(Room(102, 120.0, 4));
    hotels[0].addRoom(Room(103, 150.0, 3));

    hotels.push_back(Hotel("Luxury Suites", "Los Angeles"));
    hotels[1].addRoom(Room(201, 200.0, 2));
    hotels[1].addRoom(Room(202, 250.0, 4));

    while (true) {
        cout << "Enter a location to search for hotels (0 to exit): ";
        string searchLocation;
        
        
        getline(cin, searchLocation);

        if (searchLocation == "0") {
            break; // Exit the program
        }

        cout << "Hotels in " << searchLocation << ":" << endl;
        bool found = false;

        for (size_t i = 0; i < hotels.size(); ++i) {
            if (hotels[i].getLocation() == searchLocation) {
                cout << i + 1 << ". " << hotels[i].getName() << " in " << hotels[i].getLocation() << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No hotels found in " << searchLocation << endl;
            continue;
        }

        int hotelChoice;
        cout << "Enter the number of the hotel you want to book (0 to go back): ";
        cin >> hotelChoice;

        if (hotelChoice == 0) {
            continue;
        } else if (hotelChoice >= 1 && hotelChoice <= hotels.size()) {
            Hotel& selectedHotel = hotels[hotelChoice - 1];

            while (true) {
                cout << "Sort by price:" << endl;
                cout << "1. Low to High" << endl;
                cout << "2. High to Low" << endl;
                cout << "3. Search by Capacity" << endl;
                cout << "0. Back to hotel selection" << endl;

                int sortChoice;
                cout << "Enter your choice: ";
                cin >> sortChoice;

                if (sortChoice == 0) {
                    break;
                } else if (sortChoice == 1) {
                    selectedHotel.displayAvailableRooms(true); // Sort by price low to high
                } else if (sortChoice == 2) {
                    selectedHotel.displayAvailableRooms(false); // Sort by price high to low
                } else if (sortChoice == 3) {
                    int capacity;
                    cout << "Enter the room capacity you want to search for: ";
                    cin >> capacity;
                    selectedHotel.displayRoomsByCapacity(capacity);
                } else {
                    cout << "Invalid choice. Please select a valid option." << endl;
                }

                int roomChoice;
                cout << "Enter the number of the room you want to book (0 to go back): ";
                cin >> roomChoice;

                if (roomChoice == 0) {
                    continue;
                }

                if (selectedHotel.bookRoom(roomChoice)) {
                    cout << "Room " << roomChoice << " has been booked." << endl;
                } else {
                    cout << "Room " << roomChoice << " is not available." << endl;
                }
            }
        } else {
            cout << "Invalid choice. Please select a valid hotel." << endl;
        }
    }

    return 0;
}
