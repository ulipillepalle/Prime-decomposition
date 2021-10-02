
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class PrimFaktor 
{

public:

    PrimFaktor (unsigned long long zahl) {
		initVector(zahl);
	}
	
	~PrimFaktor () {
		a.clear();
	}
	
	void ladeDatei (const char*  datnam) {
		cout << "Status: Load File.." << endl;
		char str[20];
		ifstream fin(datnam);
		
		while (fin.good()) {
			fin.getline(str, 20);
			unsigned long long wert = atoll(str);
			if (wert < a.size()) a[wert] = true;
			else {
				cerr << "Fehler: Zahl zu groß! " << wert << " Z: " << str << endl;
				fin.close();
				return;
			}
		}
		fin.close();
	}

	void faktoren (unsigned long long G) {
		cout << "Status: Find factor.." << endl;
		unsigned long long g = G;
		unsigned long long s = a.size();
		while (g > 1) { // solange Teilen bis 1 ist
			for (unsigned long long i = 1; i < s; i++) {
				if (a[i] == false) continue; // das ist kein Primfaktor
				if (a[i] == true) {   // es ist ein primfaktor
					if (g % i == 0) {  // es ist teilbar
						// vermindere die Zahl um den gefunden Faktor
						g = g / i;
						cout << "Faktor gefunden: " << i << " Rest: " << g << endl;
						break;
					}
				}
			}
		}
	}

private:

	void initVector(unsigned long long zahl) {
		cout << "Status: Init Vector..." << endl;
		a.clear();
		a.resize(zahl);
		unsigned long long s = a.size();
		for (unsigned long long i = 0; i < s; i++) {
			a[i] = false;
		}
	}
	std::vector<bool> a;
}; // ende class


int main (int argc, char** argv) {
	
	if (argc < 2) {  // da fehlen die Argumente
		cerr << "Fehler: Bitte die Zahl eingeben!" << endl;
		return EXIT_FAILURE;
	}
	if (argv[1] == NULL) {
		cerr << "Fehler: ARG == NULL" << endl;
		return EXIT_FAILURE;
	}
	unsigned long long g = atoll(argv[1]);
	
	cout << "Status: Zahl: " << g << endl;
	
    unsigned long long ZAHL = 10000000000ULL;

    string datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/1000.dat";
    if (g < 1000ULL) {
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/1000.dat";
		ZAHL = 1000ULL;
	} else if (g < 100000ULL) { 
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/100000.dat";
		ZAHL = 100000ULL;
	} else if (g < 1000000ULL) {
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/1Million.dat";
		ZAHL = 1000000ULL;	
	} else if (g < 10000000ULL) {
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/10Millionen.dat";
		ZAHL = 10000000ULL;	
	} else if (g < 100000000ULL) {
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/100Millionen.dat";
		ZAHL = 100000000ULL;	
	} else if (g < 1000000000ULL) {
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/1Milliarden.dat";
		ZAHL = 1000000000ULL;	
	} else if (g < 10000000000ULL) {
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/10Milliarden.dat";
		ZAHL = 10000000000ULL;	
	} else if (g < 15000000000ULL) {
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/15Milliarden.dat";
		ZAHL = 15000000000ULL;	
	} else if (g < 20000000000ULL) {
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/20Milliarden.dat";
		ZAHL = 20000000000ULL;	
	} else if (g < 35000000000ULL) {
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/35Milliarden.dat";
		ZAHL = 35000000000ULL;	
	} else if (g < 50000000000ULL) {
		datnam = "/mnt/daten/work/cpp/Tools/primz_Eratosthenes/50Milliarden.dat";
		ZAHL = 50000000000ULL;	
        
	} else if (g > 50000000000ULL) {
        cerr << "Fehler: Zahl zu groß!" << endl;
    }
    cout << "Lade: " << datnam << endl;
	PrimFaktor p(ZAHL);

	p.ladeDatei (datnam.c_str());	
	
	p.faktoren(g);
	
	return EXIT_SUCCESS;
	
}
