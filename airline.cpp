// airline.cpp

#include "airline.h"


Airline::Airline() : 
    name(""), numOfFlights(0), flights(new vector <Flight>) {}


Airline::Airline(const Airline& rhs) : 
    name(rhs.name), numOfFlights(rhs.numOfFlights), flights(new vector <Flight> (*rhs.flights)) {}


Airline::~Airline() {
    delete flights;
}


string Airline::getName() const {
    return name;
}


int Airline::getNumOfFlights() const {
    return numOfFlights;
}


vector<Flight>* Airline::getFlights() const {
    return flights;
}


void Airline::setName(string val) {
    name = val;
}


void Airline::setNumOfFlights(int val) {
    numOfFlights = val;
}


void Airline::setFlight(vector<Flight>* val) {
    flights = val;
}


void Airline::addFlight(Flight val) {
    flights->push_back(val);
    ++numOfFlights;
}

