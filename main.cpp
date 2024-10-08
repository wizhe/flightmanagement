// main.cpp

// ---to compile---
// g++ -Wall -o main airline.cpp flight.cpp main.cpp seat.cpp passenger.cpp

// then run main.exe 


#include "main.h"
#include "airline.h"




string formatReading(const string& line) {
    string result = line;

    // removes trailing spaces
    int spaceI = result.rfind(' ');
    while (result[spaceI] == ' ' && spaceI == (int) result.length()-1) {
        result.erase(spaceI, 1);
        spaceI = result.rfind(' ');
    }

    // replaces double or more spaces with an underscore
    for (size_t i = 0; i < result.length(); ++i) {
        if (result[i] == ' ' && i + 1 < result.length() && result[i + 1] == ' ') {
            while (i + 1 < result.length() && result[i + 1] == ' ') {
                result.erase(i + 1, 1);
            }
            result[i] = '_';
        }
    }

    // finds spaces from the end that weren't caught by the loop above, if found and if it's after the phone number, it'll replace it with an underscore
    // this is to properly format the passenger's information if there is only a single space between the seat and passenger id.
    while (spaceI != (int) string::npos && spaceI > (int) result.length()-10){
        result[spaceI] = '_';
        spaceI = result.rfind(' ');
    }
    return result;
}


void display_header() {
    cout<< "\nFlight Management System\n"
        << "Version: 1.0\n";
}


int getSelection() {
    int input;
    cout<< "\n\nPlease select one of the following options:\n"
        << "1. Display Flight Seat Map\n"
        << "2. Display Passengers Information\n"
        << "3. Add a New Passenger\n"
        << "4. Remove an Existing Passenger\n"
        << "5. Save Data\n"
        << "6. Quit\n";

    cout<< "\n\nEnter your choice: (1, 2, 3, 4, 5, or 6)  ";
    
    do {
        cin.clear();
        cin >> input;
        if (input < 1 || input > 6) {
            cout << "\nInvalid input, please try again.\n";
            cout<< "\nPlease select one of the following options:\n"
            << "1. Display Flight Sea Map\n"
            << "2. Display Passengers Information\n"
            << "3. Add a New Passenger\n"
            << "4. Remove an Existing Passenger\n"
            << "5. Save Data\n"
            << "6. Quit\n";
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (input < 1 || input > 6);

    return input;
}


void returnToContinue() {
    char input;

    cout << "\n\n\n<<< Press Return to Continue >>>\n";

    do {
        cin.clear();
        input = cin.get();
    } while (input != '\n');

}


void showSeatMap(const vector<vector<Seat>>& seating) {
    cout << "\n\n----= Displaying Seat Map =----\n";
    int rows = seating.size();
    int cols = seating[0].size();
    
    // printing col indexes
    cout << endl << right << "   ";
    for (char c = 'A'; c < 'A' + (cols); ++c) {
        cout << setw(4) << c;
    }
    cout << "\n";

    // printing rows
    for (int i = 0; i < rows; ++i) {
        // prints top cell border
        cout << "    +";
        for (int j = 0; j < cols; ++j) {
            cout << "---+";
        }
        cout << "\n";

        // prints row index
        cout << setw(3) << i+1 << " |";

        // print cell values and borders
        for (int j = 0; j < cols; ++j) {
            char seatAvailability = seating[i][j].getAvailability() == false ? 'X' : ' ';
            cout << " " << seatAvailability << " |";
        }
        cout << "\n";
    }

    // prints bottom border
    cout << "    +";
    for (int j = 0; j < cols; ++j) {
        cout << "---+";
    }
    cout << "\n";
}


void displayPassInfo(Flight& flight) {

    int numOfPass = flight.getPass().size();
    vector<Passenger> allPass = flight.getPass();
    cout<< "\n\n----= Displaying Passenger Information =----\n\n";
    cout<< setw(20) << left << "First Name"
    << setw(20) << left << "Last Name"
    << setw(20) << left << "Phone Number"
    << setw(8) << left << "Row"
    << setw(8) << left << "Seat"
    << setw(8) << left << "ID";
    

    for (int i = 0; i < numOfPass; ++i) {
        cout<< "\n------------------------------------------------------------------------------------\n";
        allPass[i].print_info();
    }

}


bool menu(Flight& currentFlight) {
    int selection = getSelection();
    if (selection == 1) {
        showSeatMap(currentFlight.getSeating());
        returnToContinue();
        return true;
    }

    else if (selection == 2) {
        displayPassInfo(currentFlight);
        returnToContinue();
        return true;
    }

    else if (selection == 3) {
        currentFlight.menuCreatePass();
        return true;
    }

    else if (selection == 4) {
        currentFlight.menuDeletePass();
        return true;
    }

    else if (selection == 5) {
        currentFlight.saveData();
        return true;
    }

    else if (selection == 6) {
        cout << "\nProgram Terminating...";
        cout << "\nGoodbye!\n\n";
        return false;
    }

    return false;
}




int main() {
    // airline usage:
    Airline thisairline;
    vector <Flight> flightlist;
    thisairline.setFlight(&flightlist);
    Flight thisflight;


    //populate thisflight
    thisflight.populate_flight_from_file("flight_info.txt");
    //adding thisflight to thisairline
    thisairline.addFlight(thisflight);

    // cout<< "AIRLINE CHECK" << thisairline.getFlights()->at(0).getID()<<endl; //airline check

    display_header();

    while(menu(thisflight)) {}

    return 0;
}

