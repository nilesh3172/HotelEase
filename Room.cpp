#include "Room.h"

Room::Room(int roomNumber, double price, int capacity)
{
    this->roomNumber = roomNumber;
    this->price = price;
    this->capacity = capacity;
    this->isAvailable = true;
}

int Room::getRoomNumber()
{
    return roomNumber;
}

double Room::getPrice()
{
    return price;
}

int Room::getCapacity()
{
    return capacity;
}

bool Room::isRoomAvailable()
{
    return isAvailable;
}

void Room::bookRoom()
{
    isAvailable = false;
}

void Room::checkoutRoom()
{
    isAvailable = true;
}
