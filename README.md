# Flight Management System :airplane:
## Overview
The Flight Management System is a terminal-based program designed to manage seating arrangements and passenger information for a flight. 
## How to Run
1. Compile the program using the command `g++ -Wall -o main airline.cpp flight.cpp main.cpp seat.cpp passenger.cpp` in an integrated terminal within the program directory.
2. Execute the generated executable file `main.exe`.
3. Use the program!
## Key Features
The program reads flight and passenger information from the file `flight_info.txt`, which has the Flight ID, number of rows and columns of seats, and all passengers' information, to properly populate the flight.  
When the program is run, you will see an interactive menu where you can input the numbers 1 to 6 to use certain functions of the program.  
### 1. Display Flight Seat Map:  
Displays the flight seat map in a grid format, with already assigned seats marked with an ‘x’.    
### 2. Display Passengers Information:  
Shows all passengers’ details, including first name, last name, phone number, row, seat letter, and passenger ID.    
### 3. Add a New Passenger:  
Allows the user to add a new passenger by entering their passenger ID, first name, last name, phone number, row number, and seat letter.    
### 4. Remove an Existing Passenger:  
Enables the removal of an existing passenger using their passenger ID.    
### 5. Save Data:  
Saves the current passenger data back into the flight_info.txt file.    
### 6. Quit:  
Exits the program.  
