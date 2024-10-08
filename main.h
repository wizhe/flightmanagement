// main.h


#include "flight.h"
#include "seat.h"

#ifndef STRING_L
#define STRING_L
#include <string>
using namespace std;
#endif

#ifndef VECTOR_L
#define VECTOR_L
#include <vector>
using namespace std;
#endif




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

