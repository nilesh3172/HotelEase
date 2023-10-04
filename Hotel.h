#include "Room.h"
using namespace std;

class Hotel
{
private:
    string name;
    string location;
    vector<Room> rooms;
    vector<int> bookedRooms;

public:
    Hotel(string name, string location);
    void addRoom(Room room);
    vector<Room> &getRooms();
    string getName();
    string getLocation();
    void displayAvailableRooms(bool sortByPriceLowToHigh);
    void displayRoomsByCapacity(int capacity);
    bool bookRoom(int roomNumber);
    void checkoutRooms(vector<int> &roomNumbers);
    double getStartingPrice();
    double getEndingPrice();
    void bookRooms(vector<int> &roomNumbers);
    void displayBookedRooms();
};
