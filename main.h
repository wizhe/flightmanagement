// main.h

#include "flight.h"
#include "seat.h"
#include <string>
#include <vector>
using namespace std;


#ifndef MAIN_H
#define MAIN_H


string formatReading(const string& line);


void display_header();


int getSelection();


void returnToContinue();


void showSeatMap(const vector<vector<Seat>>& seating);


void displayPassInfo(Flight& flight);


bool menu(Flight& currentFlight);

#endif

