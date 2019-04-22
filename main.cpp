#include "Rental.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Heapsort function to sort the items of the priority queue.
// Will be used to sort the queue based on weight and price.
CarNode* heapSort(int len, CarNode arr[]){
  RentalCarQueue hp(len);
  for(int i=0; i<len; i++){
    hp.enqueue(arr[i]);
  }
  for(int i=0; i<len; i++){
    arr[i] = hp.dequeue();
  }
  return arr;
}

// MAIN function that executes a rental ranking
int main(int argc, char* argv[]) {

  string filename = argv[1];

  // declare a linked list of CarNodes
  CarList l;

  // open the input rental car text file
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

      // insert a CarNode to the linked list with values from the input file
      l.insertCar(make,color,dropoff,price,year,0);
    }
  }
  else{
    cout << "Failed to open the file." << endl;
    exit(0);
  }
  // close inStream when the file is read, or if it failed to open
  myFile.close();


  // find the length of the linked list for testing purposes.
  // This portion of the code does not have any significance in regards to the objective
  int length = 0;
  CarNode* temp = l.getHead();
  while(temp != nullptr){
    length++;
    temp = temp->next;
  }


  // call the weighting function to sort the options into relative rankings
  l.weighting_function();

  // if the user specifies that they desire a two-way rental, all one-ways will be put in a "non-viable" list
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

  // Begin the process of adding the CarNodes into a priority queue based on weight and price.
  // Enqueue the cars that will work based on the two-way or one-way specification
  temp = l.getHead();
  RentalCarQueue cq(length-reject_count);
  while(temp != nullptr){
    if(temp->weight != -1){
      cq.enqueue(*temp);
    }
    temp = temp->next;
  }

  // sort the priority queue using a heapsort
  int list_length = cq.return_len();
  CarNode* arr = cq.return_arr();
  arr = heapSort(list_length,arr);

  // print the sorted list to the terminal
  cout << "Sorted List: " << endl;
  for(int i=0; i<list_length; i++){
    cout<< i+1 << ". " << arr[i].make << ", "<< arr[i].color  << ", "<< arr[i].year <<", $"<< arr[i].price<<endl;
  }
  cout << endl;
  cout << "Rental Options That Will Not Work Based on Two-Way Specification: " << endl;
  temp = lreject.getHead();
  while(temp != NULL){
    cout << temp->make << ", " << temp->color << ", " << temp->year << ", "<< temp->price << ", "<< endl;
    temp = temp->next;
  }

  // write the results of the sorting process to an output .txt file
  ofstream outFile;
  outFile.open ("Results.txt");
  outFile << "Ranked Results: ";
  outFile << endl;
  outFile << "Top 5 Options: "<< endl;
  for(int i=0; i<5; i++){
    outFile << i+1 << ". " << arr[i].make << ", "<< arr[i].color << ", "<< arr[i].year <<", $"<< arr[i].price<<endl;
  }
  outFile << endl;
  outFile << "Other Ranked Options: " << endl;
  for(int i=5; i<list_length; i++){
    outFile << i+1 << ". " << arr[i].make << ", "<< arr[i].color << ", "<< arr[i].year <<", $"<< arr[i].price<<endl;
  }
  outFile << endl;
  outFile << "Rental Options That Will Not Work Based on Two-Way Specification: " << endl;
  temp = lreject.getHead();
  while(temp != NULL){
    outFile << temp->make << ", " << temp->color << ", " << temp->year << ", "<< temp->price << ", "<< endl;
    temp = temp->next;
  }


  outFile.close();

  return 0;
}
