#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
public:
    char vehicleID[20];
    char vehicleType[10]; // "Car", "Bike", or "Jeep"
    
    Vehicle();
    // Abdullah: Function to manually set data without <string>
    void setData(const char* id, const char* type);
};

#endif