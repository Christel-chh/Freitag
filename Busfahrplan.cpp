#include <iostream>
#include <string>

using namespace std;

 class Person {
        protected:
        string name;
        string geburtsdatum;
        public:
        Person(string nam, string geb) : name(nam), geburtsdatum(geb) {}
        void anzeigen()
        {
            cout << "Name: " << name << endl;
            cout << "Geburtsdatum: " << geburtsdatum << endl;
        }
    };

class Fahrer :public Person {
        private: 
        string fueherscheinNr;
        public:
        Fahrer(string nam, string geb, string fNr) : Person(nam, geb), fueherscheinNr(fNr) {}   
        void fahrerInfo()
        {
            cout << "Führerscheinnummer: " << fueherscheinNr << endl;
            cout << "Name: " << name << endl;
            cout << "Geburtsdatum: " << geburtsdatum << endl;
        }

    };

class Fahrzeug {
protected:
                string kennzeichen;
                string fahrgestellNr;

public:
        void fahren() const {
                cout << "Das Fahrzeug fährt." << endl;
        }
        void bremsen() const {
                cout << "Das Fahrzeug bremst." << endl;
        }
    
};

class Bus : public Fahrzeug {
    private:
        int busNr;
        string start;
        string ziel;
        int fahrgaeste;
        Fahrer* fahrer; // Bus besitzt einen Fahrer
    public:
        Bus(int nr, string str, string zl, Fahrer* f)
        : busNr(nr), start(str), ziel(zl), fahrgaeste(0), fahrer(f) {}
        
        void halten() const {
            cout << "Der Bus hält an der nächsten Haltestelle." << endl;
        }
        void einsteigen(int anzahl) {
            fahrgaeste += anzahl;
            cout << anzahl << " Fahrgäste steigen ein." << endl;
        }
        void aussteigen(int anzahl) {
            fahrgaeste -= anzahl;
            cout << anzahl << " Fahrgäste steigen aus." << endl;
        }
        void businfo() const {
            cout << "Busnummer: " << busNr << endl;
            cout << "Start: " << start << endl;
            cout << "Ziel: " << ziel << endl;
            cout << "Anzahl der Fahrgäste: " << fahrgaeste << endl;

    
        };

    

   
};
int main ()
{
    Fahrer fahrer1(
    "Horst Berwald",
    "25.07.1644",
    "0.123456789");

    Bus bus1(
         1,
        "Hauptbahnhof",
        "Audi Forum",
        &fahrer1);

        bus1.einsteigen(20);
        bus1.businfo();
        bus1.fahren();
        bus1.halten();
        bus1.aussteigen(5);
        bus1.businfo();
}
