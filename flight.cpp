// flight.cpp

#include "flight.h"
#include "main.h"


Flight::Flight() : 
    flightID(""), rows(0), cols(0), passengers(new vector <Passenger>), seating(new vector <vector <Seat>>) {}


Flight::Flight(const string& fID, const int& ro, const int& co, const vector <Passenger>& pas) : 
    flightID(fID), rows(ro), cols(co), passengers(new vector <Passenger> (pas)), seating(new vector <vector <Seat>>) {
        setSeats();
    }


Flight::Flight(const Flight& f) :
    flightID(f.flightID), rows(f.rows), cols(f.cols), passengers(new vector <Passenger> (*f.passengers)) {
        seating = new vector <vector <Seat>>(rows, vector <Seat>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                (*seating)[i][j] = (*f.seating)[i][j];
            }
        }
}


Flight::~Flight() {
    delete passengers;
    delete seating;
}


void Flight::setFlightID(string val) {
    flightID = val;
}


void Flight::setRows(int val) {
    rows = val;
    setSeats();
}


void Flight::setCols(int val) {
    cols = val;
    setSeats();
}


void Flight::addPass(Passenger val) {
    passengers->push_back(val);
}


void Flight::delPass(int val) {
    for (auto it = passengers->begin(); it != passengers->end(); ++it) {
        if (it->getID() == val) {
            getSeat(it->getSeatRow(), it->getSeatCol()).setAvailability(true);
            passengers->erase(it);
            cout << "Passenger with ID \'"<< val <<"\' was successfully deleted.\n";
            return;
        }
    }
    cout << "Error, passenger with ID \'"<< val <<"\' not found.\n";
}


void Flight::menuCreatePass() {
    char add = 'x';
    Passenger newPass;
    int newID;
    string newFname, newLname, newPhone;
    int newRow = 0;
    char newCol = '0';
    
    cout << "\nPlease enter the Passenger ID of the new passenger: ";
    while(!(cin >> newID)){
        cout << "Error, invalid input. Please enter a number for the Passenger ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nPlease enter the First Name of the new passenger: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newFname);

    cout << "\nPlease enter the Last Name of the new passenger: ";
    cin.clear();
    
    getline(cin, newLname);

    cout << "\nPlease enter the Phone Number of the new passenger: ";
    cin.clear();
    
    getline(cin, newPhone);

    cout << "\nPlease enter the Seat Row Number of the new passenger: ";
    while(!(cin >> newRow)){
        cout << "Error, invalid input. Please enter the Seat Row Number for the new passenger: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nPlease enter the Seat Column Letter (A-Z) of the new passenger: ";
    while(!(cin >> newCol) || !isalpha(newCol)){
        cout << "Error, invalid input. Please enter the Seat Column Letter (A-Z) for the new passenger: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    newCol = toupper(newCol);
    int intNewCol = newCol-'A';


    cout<< "\nConfirm addition of this passenger?" 
        << "\n   Passenger ID: " << newID
        << "\n   First Name: " << newFname 
        << "\n   Last Name: " << newLname 
        << "\n   Phone Number: " << newPhone
        << "\n   Seat: " << newRow << newCol ;
    cout<< "\nEnter Y to confirm, N to cancel: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> add;
    if (add !='Y' && add !='y' && add !='N' && add !='n') {
        cout << "\nError, could not get confirmation.\n";
        //continue
    }
    if (add == 'Y' || add == 'y') {
        for (const auto& passenger : *passengers) {
            if (passenger.getID() == newID) {
                cout << "Error, a passenger with this ID already exists.\n";
                return;
            }
        }

        if (newRow < 0 || newRow - 1 > (int) seating->size() || intNewCol < 0 || intNewCol > (int) (*seating)[0].size()) {
            cout << "Error, this seat does not exist.\n";
            return;
        }

        if (((*seating)[newRow - 1][intNewCol].getAvailability() == false)) {
            cout << "Error, this seat is already occupied.\n";
            return;
        }

        

        newPass.setID(newID);
        newPass.setFname(newFname);
        newPass.setLname(newLname);
        newPass.setPhone(newPhone);
        newPass.setSeat(newRow, newCol- 'A'+1);
        addPass(newPass);
        setPassSeat(newID, newRow, newCol);
        cout << "\nPassenger \'" << newFname << " " << newLname << "\' added.\n";
    }
    if (add == 'N' || add == 'n') {
        cout << "\nPassenger addition canceled.\n";
        //continue;
    }
}


void Flight::menuDeletePass() {
    int delID;
    
    cout << "\nPlease enter the Passenger ID of the passenger to delete: ";
    cin >> delID;

    for (auto iter = passengers->begin(); iter != passengers->end(); ++iter) {
        if (iter->getID() == delID) {
            getSeat(iter->getSeatRow(), iter->getSeatCol()).setAvailability(true);
            passengers->erase(iter);
            cout << "Passenger with ID \'"<<delID<<"\' was successfully deleted.\n";
            return;
        }
    }
}


void Flight::setSeats() {
    seating->resize(rows);

    for (int i = 0; i < rows; ++i) {
        (*seating)[i].resize(cols);
        for (int j = 0; j < cols; ++j) {
            (*seating)[i][j] = Seat(i+1, j+1, true);
        }
    }
}


void Flight::setPassSeat(int id, int row, char col) {
    int colInt = toupper(col) -'A';
    Passenger* findPass = nullptr;
    for (auto& passenger : *passengers) {
        if (passenger.getID() == id) {
            findPass = &passenger;
            break;
        }
    }

    if (findPass != nullptr) {  
        if (row > 0 && row <= (int) seating->size() &&
            colInt >= 0 && colInt <= (int) (*seating)[0].size()) {
                findPass->setSeat(row, colInt + 1);
                (*seating)[row-1][colInt].setAvailability(false);
        } else {
            cout << "\n Error, Row/Column not within limits. \n";
        }
    } else {
        cout << "\n Error, Passenger not found. \n";
    }
}


void Flight::populate_flight_from_file(const string& file_name) {
    ifstream file(file_name);

    if (!file.is_open()) {
        cout << "Unable to open file: " << file_name << endl;
        return;
    }

    string line;
    string a, b, c;
    if (getline(file, line)) {
        string fID, numrow, numcol;
        string flightinfo = formatReading(line);
        stringstream stringstr(flightinfo);

        getline(stringstr, fID, '_');
        getline(stringstr, numrow, '_');
        getline(stringstr, numcol, '_');
        stringstr.clear();

        flightID = fID;
        rows = stoi(numrow);
        cols = stoi(numcol);
        setSeats();
    }

    while (getline(file, line)) {
        string passengerinfo = formatReading(line);
        stringstream stringstr(passengerinfo);
        string fname, lname, phone, seat, id;
        
        getline(stringstr, fname, '_');
        getline(stringstr, lname, '_');
        getline(stringstr, phone, '_');
        getline(stringstr, seat, '_');
        getline(stringstr, id, '_');
        int intID = stoi(id);
        
        Passenger newPass;
        newPass.setID(intID);
        newPass.setFname(fname);
        newPass.setLname(lname);
        newPass.setPhone(phone);
        

        int row = stoi(seat.substr(0, seat.length() - 1));
        int col = seat.back() - 'A' + 1;

        newPass.setSeat(row, col);

        addPass(newPass);
        setPassSeat(intID, row, seat.back());

        
        stringstr.clear();
    }

    file.close();
}


void Flight::saveData() {
    string save_file_name;
    cout<< "\nPlease enter the name of the file you wish to save this flight's information as: ";
    cin >> save_file_name;
    while (save_file_name.compare(save_file_name.length() - 4, 4, ".txt") != 0) {
        cout<< "\nError, invalid Save File Name (must end in \'.txt\')";
        cout<< "\nPlease enter the name of the file you wish to save this flight's information as: ";
        cin >> save_file_name;
    }
    ofstream file(save_file_name);
    if (!file.is_open()) {
        cout << "Unable to open file: " << save_file_name << endl;
        return;
    }

    file << left << setw(10) << flightID << setw(5) << rows << setw(5) << cols << "\n";

    for (const auto& passenger : *passengers) {
        file << left << setw(20) << passenger.getFname()
             << setw(20) << passenger.getLname()
             << setw(20) << passenger.getPhone()
             << setw(5) << to_string(passenger.getSeatRow()) + static_cast<char>('A' + passenger.getSeatCol() - 1)
             << setw(10) << passenger.getID() << "\n";
    }

    file.close();
    cout << "\n Sucessfully saved to file \'" << save_file_name << "\'.\n";
}

