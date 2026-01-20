#include "Zone.h"

Zone::Zone() {
    zoneID = 0;
    areaCount = 3; // Each building has 3 floors
    areas = new ParkingArea[areaCount];
}

Zone::~Zone() {
    delete[] areas;
}