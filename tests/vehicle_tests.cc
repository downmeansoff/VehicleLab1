#include <gtest/gtest.h>

#include <functions/vehicle.h>
#define CAPACITY 10
using namespace vehicle;
using namespace std;

TEST(FunctionsTests, transport_tax_CAR_Test1) {
    // Arrange
    Vehicle vehicle(VehicleType::CAR, Model::BMW, 3.5, 0);
    
    // Act
    float r = vehicle.transport_tax(1.5);
    
    // Assert
    EXPECT_EQ(r, 5.25);
}
TEST(FunctionsTests, transport_tax_TRUCK_Test2) {
    Vehicle vehicle(VehicleType::TRUCK, Model::FORD, 3.5, 3.0);

    float r = vehicle.transport_tax(2.0);

    EXPECT_EQ(r, 17.5);
}
TEST(FunctionsTests, transport_tax_MOTOCYCLE_Test3) {
    Vehicle vehicle(VehicleType::MOTOCYCLE, Model::HONDA, 2.5, 0);

    float r = vehicle.transport_tax(4.0);
    
    EXPECT_EQ(r, 3.0);
}
TEST(FunctionsTests, ForGetModel) {
    Vehicle vehicle(VehicleType::CAR, Model::FORD, 2.5, 0);

    int r = vehicle.get_model();

    EXPECT_EQ(r, FORD);
}
TEST(FunctionsTests, ForGetType) {
    Vehicle vehicle(VehicleType::TRUCK, Model::FORD, 2.5, 0);

    int r = vehicle.get_type();
 
    EXPECT_EQ(r, TRUCK);
}
TEST(FunctionsTests, ForGetVolumeOfEngine) {
    Vehicle vehicle(VehicleType::CAR, Model::FORD, 3.0, 0);

    float r = vehicle.get_volume_of_engine();

    EXPECT_EQ(r, 3.0);
}
TEST(FunctionsTests, ForGetTonnage) {
    Vehicle vehicle(VehicleType::TRUCK, Model::TOYOTA, 3.0, 9.5);
    
    float r = vehicle.get_tonnage();

    EXPECT_EQ(r, 9.5);
}
TEST(FunctionsTests, SetType) {
    Vehicle vehicle;

    vehicle.set_type(CAR);

    EXPECT_EQ(vehicle.get_type(), CAR);
}
TEST(FunctionsTests, SetModel) {
    Vehicle vehicle;

    vehicle.set_model(FORD);

    EXPECT_EQ(vehicle.get_model(), FORD);
}
TEST(FunctionsTests, SetTonnage) {
    Vehicle vehicle;

    vehicle.set_tonnage(2.0);

    EXPECT_EQ(vehicle.get_tonnage(), 2.0);
}
TEST(FunctionsTests, SetVolumeOfEngine) {
    Vehicle vehicle;

    vehicle.set_volume_of_engine(3.0);

    EXPECT_EQ(vehicle.get_volume_of_engine(), 3.0);
}
TEST(VehicleTests, Size) {
    // Arrange
    const int size = 5;
    Vehicle vehicle[CAPACITY];
    vehicle[0] = Vehicle(CAR, HONDA, 2.0, 0);
    vehicle[1] = Vehicle(CAR, HONDA, 2.0, 0);
    vehicle[2] = Vehicle(CAR, FORD, 2.0, 0);
    vehicle[3] = Vehicle(CAR, FORD, 2.0, 0);
    vehicle[4] = Vehicle(CAR, FORD, 2.0, 0);
    vehicle[5] = Vehicle(CAR, FORD, 2.0, 0);
    vehicle[6] = Vehicle(CAR, FORD, 2.0, 0);
    vehicle[7] = Vehicle(CAR, FORD, 2.0, 0);
    vehicle[8] = Vehicle(CAR, FORD, 2.0, 0);
    VehicleList ll = VehicleList(vehicle, size);

    // Assert
    EXPECT_EQ(ll.size(), 5);
}
TEST(VehicleTests, Index) {
    VehicleList ll = VehicleList();
    EXPECT_THROW(ll.remove(-1), std::runtime_error);
}