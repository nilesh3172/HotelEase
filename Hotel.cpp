#include "Hotel.h"

Hotel::Hotel(string name, string location)
{
    this->name = name;
    this->location = location;
}
void Hotel::addRoom(Room room)
{
    rooms.push_back(room);
}
vector<Room> &Hotel::getRooms()
{
    return rooms;
}
string Hotel::getName()
{
    return name;
}
string Hotel::getLocation()
{
    return location;
}
void Hotel::displayAvailableRooms(bool sortByPriceLowToHigh)
{
    cout << "Available rooms at " << name << " in " << location << ":" << endl;
    vector<Room> availableRooms;
    for (Room &room : rooms)
    {
        if (room.isRoomAvailable())
        {
            availableRooms.push_back(room);
        }
    }
    if (sortByPriceLowToHigh)
    {
        sort(availableRooms.begin(), availableRooms.end(),
             [](Room &a, Room &b)
             {
                 return a.getPrice() < b.getPrice();
             });
    }
    else
    {
        sort(availableRooms.begin(), availableRooms.end(),
             [](Room &a, Room &b)
             {
                 return a.getPrice() > b.getPrice();
             });
    }
    for (Room &room : availableRooms)
    {
        cout << "Room " << room.getRoomNumber() << " - $" << room.getPrice()
             << " per night (Capacity: " << room.getCapacity() << " persons)" << endl;
    }
    cout << endl;
}
void Hotel::displayRoomsByCapacity(int capacity)
{
    cout << "Available rooms at " << name << " in " << location << " with capacity for "
         << capacity << " persons:" << endl;
    for (Room &room : rooms)
    {
        if (room.isRoomAvailable() && room.getCapacity() >= capacity)
        {
            cout << "Room " << room.getRoomNumber() << " - $" << room.getPrice()
                 << " per night (Capacity: " << room.getCapacity() << " persons)" << endl;
        }
    }
    cout << endl;
}
bool Hotel::bookRoom(int roomNumber)
{
    for (Room &room : rooms)
    {
        if (room.getRoomNumber() == roomNumber && room.isRoomAvailable())
        {
            room.bookRoom();
            return true;
        }
    }
    return false;
}
void Hotel::checkoutRooms(vector<int> &roomNumbers)
{
    for (int roomNumber : roomNumbers)
    {
        for (Room &room : rooms)
        {
            if (room.getRoomNumber() == roomNumber && !room.isRoomAvailable())
            {
                room.checkoutRoom();
                // Remove the room from the booked rooms list
                bookedRooms.erase(remove(bookedRooms.begin(), bookedRooms.end(), roomNumber), bookedRooms.end());
            }
        }
    }
}
double Hotel::getStartingPrice()
{
    double minPrice = numeric_limits<double>::max();
    for (Room &room : rooms)
    {
        if (room.getPrice() < minPrice)
        {
            minPrice = room.getPrice();
        }
    }
    return minPrice;
}
double Hotel::getEndingPrice()
{
    double maxPrice = numeric_limits<double>::min();
    for (Room &room : rooms)
    {
        if (room.getPrice() > maxPrice)
        {
            maxPrice = room.getPrice();
        }
    }
    return maxPrice;
}
void Hotel::bookRooms(vector<int> &roomNumbers)
{
    for (int roomNumber : roomNumbers)
    {
        for (Room &room : rooms)
        {
            if (room.getRoomNumber() == roomNumber && room.isRoomAvailable())
            {
                room.bookRoom();
                bookedRooms.push_back(roomNumber);
            }
        }
    }
}
void Hotel::displayBookedRooms()
{
    cout << "Booked rooms at " << name << " in " << location << ":" << endl;
    for (int roomNumber : bookedRooms)
    {
        cout << "Room " << roomNumber << " is booked." << endl;
    }
}