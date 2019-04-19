#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Rental.hpp"

using namespace std;


CarList::CarList()
{
  head = nullptr;
}

bool CarList::isEmpty()
{
  if(head == nullptr){
    return true;
  }
  else{
    return false;
  }
}

void CarList::insertCar(string make, string color, string two_way, float price, int year, float weight)
{
  CarNode* temp = new CarNode;
  temp->make = make;
  temp->color = color;
  temp->two_way = two_way;
  temp->price = price;
  temp->year = year;
  temp->weight = weight;
  temp->next = head;
  head = temp;
}

CarNode* CarList::getHead(){
  return head;
}

void CarList::printList()
{
  CarNode *current = head;
  cout << "== CURRENT LIST ==" << endl;

  if(head == nullptr){
    cout << "nothing in path" << endl;
    cout << "===" << endl;
  }
  else{
    while(current != NULL){
      cout << current->make << ", " << current->color << ", " << current->year << ", "<< current->price << ", "<< current->two_way << ", "<< current->weight << endl;
      current = current->next;
    }
    cout << "===" << endl;
  }
}


void CarList::weighting_function(){

  cout << "Is a certain make desired? (Enter Y/N):" << endl;//<< endl;
  string make_yn;
  cout << "#> ";
  getline(cin,make_yn);
  cout << "make_yn: " << make_yn << endl;

  string make_importance = "1";
  string make;
  if(make_yn == "Y"){
    cout << "Enter the make: (E.g. Toyota)" << endl;//<< endl;
    cout << "#> ";
    getline(cin,make);
    cout << "make: "  << make << endl;
    cout << "Rank the importance of make from 0 to 5, with 5 being most important:" << endl;//<< endl;
    cout << "#> ";
    getline(cin,make_importance);
    cout << "make_importance: " << make_importance << endl;
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  cout << "Is a certain color desired? (Enter Y/N):" << endl;//<< endl;
  string color_yn;
  cout << "#> ";
  //cin.ignore();
  getline(cin,color_yn);
  cout << "color_yn: " << color_yn << endl;
  string color_importance = "1";
  string color;
  if(color_yn == "Y"){
    cout << "List the desired color of the car: (E.g. Green)" << endl;//<< endl;
    cout << "#> ";
    getline(cin,color);
    cout << "color: " << color << endl;
    cout << "Rank the importance of color from 0 to 5, with 5 being most important:" << endl;//<< endl;
    cout << "#> ";
    getline(cin,color_importance);
    cout << "color_importance: " << color_importance << endl;
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  cout << "Is the price a determining factor? (Enter Y/N):" << endl;//<< endl;
  string price_yn;
  cout << "#> ";
  getline(cin,price_yn);
  cout << "price_yn: " << price_yn << endl;

  string price_importance = "1";
  string price;
  if(price_yn == "Y"){
    cout << "List the desired price of the car:" << endl;//<< endl;
    cout << "#> ";
    getline(cin,price);
    cout << "price: " << price << endl;
    cout << "Rank the importance of price from 0 to 5, with 5 being most important:" << endl;//<< endl;
    cout << "#> ";
    getline(cin,price_importance);
    cout << "price_importance: " << price_importance << endl;
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  cout << "Is a certain year desired? (Enter Y/N):" << endl;//<< endl;
  string year_yn;
  cout << "#> ";
  getline(cin,year_yn);
  cout << "year_yn: " << year_yn << endl;

  string year_importance = "1";
  string year;
  if(year_yn == "Y"){
    cout << "List the desired year of the car:" << endl;//<< endl;
    cout << "#> ";
    getline(cin,year);
    cout << "year: " << year << endl;
    cout << "Rank the importance of year from 0 to 5, with 5 being most important:" << endl;//<< endl;
    cout << "#> ";
    getline(cin,year_importance);
    cout << "year_importance: " << year_importance << endl;
  }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  cout << "Is it necessary for the rental to be two_way? (Enter Y/N):" << endl;//<< endl;
  string two_way_yn;
  cout << "#> ";
  getline(cin,two_way_yn);
  cout << "two_way_yn: " << two_way_yn << endl;


  int make_weight;
  int color_weight;
  int price_weight;
  int year_weight;

  string yn[4] = {make_yn ,color_yn, price_yn, year_yn};
  int importance[4] = {stoi(make_importance), stoi(color_importance), stoi(price_importance), stoi(year_importance)};
  int weights[4] = {make_weight, color_weight, price_weight, year_weight};


  CarNode* tmp = head;

  while(tmp != nullptr){
    if(two_way_yn == "Y" && tmp->two_way == "one-way"){
      tmp->weight = -1;
    }
    else{

      int fulfilled[4] = {1,1,1,1};

      if(tmp->make != make && make_yn == "Y"){
        fulfilled[0] = 1;
      }
      else{
        fulfilled[0] = 5;
      }
      if(tmp->color != color && color_yn == "Y"){
        fulfilled[1] = 1;
      }
      else{
        fulfilled[1] = 5;
      }
      if(price_yn == "N"){
        fulfilled[2] = 5;
      }
      else if(tmp->price > (stof(price)+5)){
        fulfilled[2] = 1;
      }
      else{
        fulfilled[2] = 5;
      }
      if(year_yn == "N"){
        fulfilled[3] = 5;
      }
      else if(tmp->year < stoi(year)){
        fulfilled[3] = 1;
      }
      else{
        fulfilled[3] = 5;
      }

      // calculate the weights for each criterion with an inner product of the importance of that criterion and whether what is
      // desired is fulfilled
      for(int i=0; i<4; i++){
        weights[i] = importance[i]*fulfilled[i];
      }

      // calculate the overall weight of the car and add to priority queue
      for(int i=0; i<4; i++){
        if(yn[i] == "Y"){
          tmp->weight = tmp->weight + weights[i];
        }
      }
    }
    tmp = tmp -> next;
  }
}


RentalCarQueue::RentalCarQueue(int maxQueueSize)
{
    currentQueueSize = 0;
    maxQueueSize = maxQueueSize;
    priorityQueue = new CarNode[maxQueueSize];
}


RentalCarQueue::~RentalCarQueue()
{
    delete [] priorityQueue;
}

bool RentalCarQueue::isEmpty(){
  if(currentQueueSize == 0)
    return true;
  else
    return false;
}

bool RentalCarQueue::isFull(){
  if(currentQueueSize == maxQueueSize)
    return true;
  else
    return false;
}

CarNode RentalCarQueue::peek(){
  if(!isEmpty())
    return priorityQueue[0];
  else
    cout << "Heap empty, nothing to peek" << endl;
    return priorityQueue[0];
}


int parent(int i) { return (i-1)/2; }
int left(int i) { return (2*i+1); }
int right(int i) { return (2*i + 2); }


void RentalCarQueue::repairUpward(int i){
  if(priorityQueue[i].weight == priorityQueue[parent(i)].weight){
    if(priorityQueue[i].price < priorityQueue[parent(i)].price){
      swap(priorityQueue[i], priorityQueue[parent(i)]);
      repairUpward(parent(i));
    }
  }
  else if(priorityQueue[i].weight > priorityQueue[parent(i)].weight){
    swap(priorityQueue[i], priorityQueue[parent(i)]);
    repairUpward(parent(i));
  }
}


void RentalCarQueue::enqueue(CarNode node)
{
  if(currentQueueSize == maxQueueSize){
    cout << "Heap full, cannot enqueue" << endl;
  }
  else{
    currentQueueSize++;
    int i = currentQueueSize-1;
    priorityQueue[i] = node;
    repairUpward(i);
  }
}

void RentalCarQueue::repairDownward(int i)
{
  int leftChild = left(i);
  int rightChild = right(i);
  int largest = i;

  if(leftChild < currentQueueSize){
    if(priorityQueue[leftChild].weight == priorityQueue[i].weight){
      if(priorityQueue[leftChild].price < priorityQueue[i].price){
        largest = leftChild;
      }
    }
    if(priorityQueue[leftChild].weight > priorityQueue[i].weight){
      largest = leftChild;
    }
  }
  if(rightChild < currentQueueSize){
    if(priorityQueue[rightChild].weight == priorityQueue[largest].weight){
      if(priorityQueue[rightChild].price < priorityQueue[largest].price){
        largest = rightChild;
      }
    }
    if(priorityQueue[rightChild].weight > priorityQueue[largest].weight){
      largest = rightChild;
    }
  }
  if(largest != i){
    swap(priorityQueue[i], priorityQueue[largest]);
    repairDownward(largest);
  }
}

void RentalCarQueue::dequeue() // extractMin
{
    if(currentQueueSize <= 0){
      cout << "Heap empty, cannot dequeue" << endl;
    }
    if(currentQueueSize == 1){
      currentQueueSize--;
    }
    else{
      priorityQueue[0] = priorityQueue[currentQueueSize-1];
      currentQueueSize--;
      repairDownward(0);
    }
}

void swap(CarNode &x, CarNode &y)
{
    CarNode temp = x;
    x = y;
    y = temp;
}

void RentalCarQueue::printQueue() {
  for(int i = 0; i<maxQueueSize; i++){
    cout << priorityQueue[i].make << ", " << priorityQueue[i].weight << endl;
  }
}

// float* RentalCarQueue::heapSort(CarNode arr[]){
//   CarNode arr[currentQueueSize];
//   RentalCarQueue hp(currentQueueSize);
//   for(int i=0; i<currentQueueSize; i++){
//     hp.enqueue(arr[i]);
//   }
//   for(int i=0; i<currentQueueSize; i++){
//     arr[i] = hp.dequeue();
//   }
//   return arr;
// }
