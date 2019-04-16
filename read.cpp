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
  string model;
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
      getline(s, model, ',');
      getline(s, year, ',');
      getline(s, price, ',');
      getline(s, color, ',');
      getline(s, way, ',');
      l.addCar(make, model, stoi(year), stof(price), color, stoi(way))
    }
  }
  return 0;
}
