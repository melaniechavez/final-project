#include "Rental.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

  string filename = argv[1];


  CarList l;

  // open the text file
  ifstream myFile;
  myFile.open(argv[1]);
  string make;
  string year_;
  string color;
  string dropoff;
  string price_;
  string line;

  if(myFile.is_open()){

    while(getline(myFile, line)){
      istringstream ss(line);

      getline(ss, make, ',');
      getline(ss, year_, ',');
      getline(ss, color, ',');
      getline(ss, dropoff, ',');
      getline(ss, price_, ',');


      int year = stoi(year_);
      float price = stof(price_);

      l.insertCar(make,color,dropoff,price,year,0);
    }
  }
  else{
    cout << "Failed to open the file." << endl;
    exit(0);
  }
  // close inStream when the file is read, or if it failed to open
  myFile.close();

  l.printList();

  int length = 0;
  CarNode* temp = l.getHead();
  while(temp != nullptr){
    length++;
    temp = temp->next;
  }
  cout << "length of list: " << length << endl;

  l.weighting_function();

  l.printList();

  CarList lreject;
  int reject_count = 0;
  temp = l.getHead();
  while(temp != nullptr){
    if(temp->weight == -1){
      lreject.insertCar(temp->make,temp->color,temp->two_way,temp->price,temp->year,0);
      reject_count++;
    }
    temp = temp->next;
  }

  temp = l.getHead();
  RentalCarQueue cq(length);
  while(temp != nullptr){
    if(temp->weight != -1){
      cq.enqueue(*temp);
    }
    temp = temp->next;
  }

  cq.printQueue();

  //cq.writeCSV();

  return 0;
}
