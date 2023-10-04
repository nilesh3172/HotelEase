
// Define and initialize hotel data
void Hotels_Data(std::map<std::string, std::vector<Hotel>> &hotelsByLocation)
{
    Hotel delhiHotel1("Modern Hotel", "Delhi");
    delhiHotel1.addRoom(Room(101, 100.0, 2));
    delhiHotel1.addRoom(Room(102, 120.0, 4));
    delhiHotel1.addRoom(Room(103, 150.0, 3));
    delhiHotel1.addRoom(Room(104, 120.0, 2));
    delhiHotel1.addRoom(Room(105, 100.0, 3));
    hotelsByLocation["Delhi"].push_back(delhiHotel1);

    Hotel delhiHotel2("New Hotel", "Delhi");
    delhiHotel2.addRoom(Room(201, 200.0, 2));
    delhiHotel2.addRoom(Room(202, 250.0, 4));
    delhiHotel2.addRoom(Room(203, 150.0, 3));
    delhiHotel2.addRoom(Room(204, 250.0, 2));
    delhiHotel2.addRoom(Room(205, 200.0, 4));
    hotelsByLocation["Delhi"].push_back(delhiHotel2);

    Hotel mumbaihotel1("New Hotel", "Mumbai");
    mumbaihotel1.addRoom(Room(201, 200.0, 2));
    mumbaihotel1.addRoom(Room(202, 250.0, 4));
    mumbaihotel1.addRoom(Room(203, 150.0, 3));
    mumbaihotel1.addRoom(Room(204, 250.0, 2));
    mumbaihotel1.addRoom(Room(205, 200.0, 4));
    hotelsByLocation["Mumbai"].push_back(mumbaihotel1);

    Hotel mumbaihotel2("Modern Hotel", "Mumbai");
    mumbaihotel2.addRoom(Room(101, 200.0, 2));
    mumbaihotel2.addRoom(Room(102, 250.0, 4));
    mumbaihotel2.addRoom(Room(103, 150.0, 3));
    mumbaihotel2.addRoom(Room(104, 250.0, 2));
    mumbaihotel2.addRoom(Room(105, 200.0, 4));
    hotelsByLocation["Mumbai"].push_back(mumbaihotel2);

    Hotel punehotel1("New Hotel", "Pune");
    punehotel1.addRoom(Room(201, 200.0, 2));
    punehotel1.addRoom(Room(202, 250.0, 4));
    punehotel1.addRoom(Room(203, 150.0, 3));
    punehotel1.addRoom(Room(204, 250.0, 2));
    punehotel1.addRoom(Room(205, 200.0, 4));
    hotelsByLocation["Pune"].push_back(punehotel1);

    Hotel punehotel2("Modern Hotel", "Pune");
    punehotel2.addRoom(Room(101, 200.0, 2));
    punehotel2.addRoom(Room(102, 250.0, 4));
    punehotel2.addRoom(Room(103, 150.0, 3));
    punehotel2.addRoom(Room(104, 250.0, 2));
    punehotel2.addRoom(Room(105, 200.0, 4));
    hotelsByLocation["Pune"].push_back(punehotel2);

}
