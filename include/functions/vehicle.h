#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace vehicle {
	enum VehicleType {
		CAR,
		TRUCK,
		MOTOCYCLE
	};
	enum Model {
		FORD,
		BMW,
		HONDA,
		TOYOTA
	};
	class Vehicle {
	private:
		VehicleType _type;
		Model _model;
		float _volume_of_engine;
		float _tonnage;
	public:
		Vehicle(); //DEFAULT
		Vehicle(VehicleType type, Model model, float volume_of_engine, float tonnage);
		float transport_tax(float s);

		//sets and gets
		void set_type(VehicleType _type);
		void set_model(Model _model);
		void set_volume_of_engine(float _volume_of_engine);
		void set_tonnage(float _tonnage);

		VehicleType get_type();
		Model get_model();
		float get_volume_of_engine();
		float get_tonnage();
	};
	class VehicleList {
	public:
		static const int CAPACITY = 10;
	private:
		Vehicle _vehicle[CAPACITY];
		int _size;
	public:
		VehicleList();
		VehicleList(Vehicle _vehicle[], int _size);
		void insert(int index, Vehicle f);
		void remove(int index);
		int size() const;
		Vehicle& operator[](int index);
		Model highest_transport_tax(VehicleList& t, float s); 
	};
}