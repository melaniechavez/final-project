#include <iostream>
#include <vector>
#include "Rental.hpp"

using namespace std;

void Lcar::insertCar(LLRentalCar* previous, std::string Nmake, std::string color, std::string dropoff, float price, int year)
{
  LLRentalCar* newCar = new LLRentalCar;
  newcar-> make = Nmake;
  if (previous == NULL){
    newCar->next = head;
    head = newCar;
    cout <<"adding: " << Nmake << " (HEAD)" <<endl;
  }
  else {
    newCar->next = previous -> next;
    previous->next = newCar;
    cout <<"adding: "<< Nmake << " (prev: " <<previous -> make << ")" << endl;
  }
}

LLRentalCar Lcar::* searchCar(std::string Nmake)
{
  LLRentalCar *head = head;
  while(temp != NULL && temp->make != Nmake){
    temp = temp->next;
  }
  if (head != NULL && head->make == Nmake)
    temp = head;
    return temp;
}

RentalCar::RentalCar(int queueSize)
{
  this->maxQueueSize = queueSize;
  this->currentQueueSize = 0;
  priorityQueue= new LLRentalCar[maxQueueSize];
}

RentalCar::~RentalCar()
{
  maxQueueSize = 0;
  currentQueueSize = 0;
  delete [] priorityQueue;
}

void RentalCar::enqueue(std::string _make, int _year, ::string _dropoff, ::string _color, float _price)
{
  LLRentalCar temp;
  temp.make = _make;
  temp.year = _year;
  temp.dropoff = _dropoff;
  temp.color = _color;
  temp.price = _price;

  if (isFull()){
    cout<<"Heap is full, cannot add more cars"<< endll;
  }
  else{
    priorityQueue[currentQueueSize] = temp;
    repairUpward(currentQueueSize);
    currentQueueSize++;
  }
}

void RentalCar::dequeue()
{
  if (isEmpty()){
    cout<<"Heap empty, cannot dequeue"<< endl;
  }
  else if (currentQueueSize == 1){
    currentQueueSize --;
  }
  else{
    priorityQueue[0] = priorityQueue[currentQueueSize -1];
    currentQueueSize --;
    repairDownward(0);
  }
}

bool RentalCar::isEmpty()
{
  if(currentQueueSize == 0){
    return true;
  }
  return false;
}

bool RentalCar::isFull()
{
  if (currentQueueSize == maxQueueSize){
    return true;
  }
  return false;
}

LLRentalCar RentalCar::peek()
{
  if (isEmpty()){
    cout <<"Nothing to peek, queue is empty"<< endl;
  }
  return priorityQueue[0];
}
