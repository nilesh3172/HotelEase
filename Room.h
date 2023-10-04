#include <bits/stdc++.h>
using namespace std;

class Room
{
private:
    int roomNumber;
    double price;
    int capacity;
    bool isAvailable;

public:
    Room(int roomNumber, double price, int capacity);
    int getRoomNumber();
    double getPrice();
    int getCapacity();
    bool isRoomAvailable();
    void bookRoom();
    void checkoutRoom();
};