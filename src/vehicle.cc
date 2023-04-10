#include <functions/vehicle.h>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
using namespace vehicle;

 Vehicle::Vehicle(VehicleType type, Model model, float volume_of_engine, float tonnage)
{
	this->_type = type;
	this->_model = model;
	this->_volume_of_engine = volume_of_engine;
	this->_tonnage = tonnage;
}

Vehicle::Vehicle() {
	_type = CAR;
	_model = BMW;
	_volume_of_engine = 0.0;
	_tonnage = 0.0;
}

float Vehicle::transport_tax(float s) {
	switch (_type) {
	case CAR:
		return _volume_of_engine * s;
	case TRUCK:
		return _volume_of_engine * s * ((_tonnage / 2) + 1);
	case MOTOCYCLE:
		return 0.3 * s * _volume_of_engine;
	default: 
	    throw runtime_error("error2");
	}
}

Model VehicleList::highest_transport_tax(VehicleList& t, float s) {
	const int n = t.size();
	int max = 0;
	int index = 0;
	for (int i = 0; i < n; ++i) {
		if (max < t[i].transport_tax(s)) {
			max = t[i].transport_tax(s);
			index = i;
		}
	}
	return t[index].get_model();
}

int VehicleList::size() const {
	return _size;
}

VehicleType Vehicle::get_type() {
	return _type;
}

Model Vehicle::get_model() {
	return _model;
}

float Vehicle::get_volume_of_engine() {
	return _volume_of_engine;
}

float Vehicle::get_tonnage() {
	return _tonnage;
}

void Vehicle::set_type(VehicleType _type) {
	this->_type = _type;
}

void Vehicle::set_model(Model _model) {
	this->_model = _model;
}

void Vehicle::set_volume_of_engine(float _volume_of_engine) {
	this->_volume_of_engine = _volume_of_engine;
}

void Vehicle::set_tonnage(float _tonnage) {
	this->_tonnage = _tonnage;
}

VehicleList::VehicleList()
{
	this->_size = 9;
	for (int i = 0; i < 9; i++) {
		this->_vehicle[i] = Vehicle();
	}
}

VehicleList::VehicleList(Vehicle _vehicle[], int _size) {
	this->_size = _size;
	for (int i = 0; i <= _size; i++) {
		this->_vehicle[i].set_model(_vehicle[i].get_model());
		this->_vehicle[i].set_type(_vehicle[i].get_type());
		this->_vehicle[i].set_volume_of_engine(_vehicle[i].get_volume_of_engine());
		this->_vehicle[i].set_tonnage(_vehicle[i].get_tonnage());
	}
}

void VehicleList::insert(int index, Vehicle f) {
	if (index >= CAPACITY || index < 0) {
		throw runtime_error("error1");
	}
	for (int i = _size - 1; i >= index; --i) {
		_vehicle[i] = _vehicle[i - 1];

	} ++_size;
	_vehicle[index] = f;
}

void VehicleList::remove(int index) {
	if (index >= CAPACITY || index < 0) {
		throw runtime_error("error1");
	}
	for (int i = index; i < _size - 1; ++i) {
		_vehicle[i] = _vehicle[i + 1];
	}  --_size;
}

Vehicle& VehicleList::operator[](int index) {
	if (index >= CAPACITY || index < 0) {
		throw runtime_error("error1");
	}
	return _vehicle[index];
}