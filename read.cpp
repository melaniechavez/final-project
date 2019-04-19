#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Renter.hpp"

using namespace std;

int read(int argc, char* argv[]) {
  string filename = argv[1];
  string response;
  string make;
  string year;
  string price;
  string color;
  string way;
  LCar l;

  ifstream source;
  source.open(filename);

  if(!source) {
    cout<<"Could not open file"<<endl;
  }
  else {
    while(getline(source, response)) {
      stringsteam s;
      s<<response;
      getline(s, make, ',');
      getline(s, year, ',');
      getline(s, color, ',');
      getline(s, way, ',');
      getline(s, price);
      l.insertCar(make, color, stoi(way), stof(price), stoi(year));
    }
  }
  return 0;
}
