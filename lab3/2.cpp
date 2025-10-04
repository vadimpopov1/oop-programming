#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Airport {
    protected:
        string place;
        int countOfFlights;
        string status;

    public:
        Airport(string _place, int _countOfFlights, string _status) {
            place = _place;
            countOfFlights = _countOfFlights;
            status = _status;
        }

        Airport() {
            place = "Толмачево";
            countOfFlights = 0;
            status = "Междугородний";
        }

        string getPlace() {
            return place;
        }
        
        void setPlace(string _place) {
            place = _place;
        }

        int getCountOfFlights() {
            return countOfFlights;
        }

        void setCountOfFlights(int _countOfFlights) {
            countOfFlights = _countOfFlights;
        }

        string getStatus() {
            return status;
        }
        
        void setStatus(string _status) {
            status = _status;
        } 

        void getAirportInfo() {
            cout << "Аэропорт: " << getPlace() << endl
                 << "Количество полётов: " << getCountOfFlights() << endl
                 << "Статус: " << getStatus() << endl;
        }
};

class Flight : public Airport {
    private:
        int numOfFlight;
        int countOfSeats;

    public:
        int getNumOfFlight() {
            return numOfFlight;
        }

        void setNumOfFlight(int _numOfFlight) {
            numOfFlight = _numOfFlight;
        }

        int getCountOfSeats() {
            return countOfSeats;
        }

        void setCountOfSeats(int _countOfSeats) {
            countOfSeats = _countOfSeats;
        } 

        void getFlightInfo() {
            cout << "Рейс номер: " << getNumOfFlight() << endl
                 << "Вместимость: " << getCountOfSeats() << endl;
        }
};

int main() {
    Airport* airports[500];
    int i = 0;

    ifstream in("APOpt.txt");
    if (in.is_open()) {
        string place, _countOfFlights, status;
        while (getline(in, place) && 
               getline(in, _countOfFlights) && 
               getline(in, status)) {
                int countOfFlights = stoi(_countOfFlights);
            airports[i] = new Airport(place, countOfFlights, status);
            i++;
        }
    }
    in.close();

    int N;
    cout << "Информацию о скольки аэропортах хотите вывести? ";
    cin >> N;
    if (N > 56) {
        cout << "Превышает файл!" << endl;
    } else {
        cout << endl;

        ofstream out("info_airports.txt");
        for (int j = 0; j < N; j++) {
            airports[j]->getAirportInfo();
            cout << endl;
            
            out << airports[j]->getPlace() << endl
                << airports[j]->getCountOfFlights() << endl
                << airports[j]->getStatus() << endl;
        }
        out.close();
    }
} 
