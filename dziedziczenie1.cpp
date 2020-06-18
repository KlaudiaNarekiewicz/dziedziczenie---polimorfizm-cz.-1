#include <iostream>
#include <fstream>
using namespace std;

class gra
{
	public:
		string nazwa, rok, producent;
		ifstream plik1;
		ofstream plik2;
		void wczytaj();
		void zapisz();
};

void gra::wczytaj()
{
	plik1.open("1.txt");
	getline(plik1,nazwa);
	getline(plik1,rok);
	getline(plik1,producent);	
}

void gra::zapisz()
{
	plik2.open("2.txt");
	plik2<<"[";
	plik2<<"{\"nazwa\":\""<<nazwa<<"\",\"rok\":\""<<rok<<"\",\"producent\":\""<<producent<<"\",";
}

class graFPS:public gra
{
	public:
		string tryby_gry;
		
		void wczytaj();
		void zapisz();
};

void graFPS::wczytaj()
{
	gra::wczytaj();
	getline(plik1,tryby_gry);
	plik1.close();
}

void graFPS::zapisz()
{
	gra::zapisz();
	plik2<<"\"tryby_gry\":\""<<tryby_gry<<"\"}";
	plik2<<"]";
	plik2.close();
}
int main(int argc, char** argv) 
{
	graFPS g;
	g.wczytaj();
	g.zapisz();
	return 0;
}
