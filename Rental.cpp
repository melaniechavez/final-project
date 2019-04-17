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
void RentalCar::repairUpward(int nodeIndex)
{
  int i = nodeIndex;
  int p = (i-1)/2; // Parent equation

  int max = nodeIndex;
  if (priorityQueue[nodeIndex].weight < priorityQueue[p].weight){
    max = p;
    // Calulating these based on the weight.
  }
  if (priorityQueue[nodeIndex].weight == priorityQueue[p].weight){
    /* If the weights are equal, we then check for the price, or whatever
        they prioritize after.
    */
    if (priorityQueue[nodeIndex].price < priorityQueue[p].price)
      max = p;
    }
  }
  if (max != nodeIndex){
    swap(priorityQueue[max], priorityQueue[nodeIndex]);
    repairUpward(max);
  }
}

void RentalCar::repairDownward(int nodeIndex)
{
  int i = nodeIndex;
  int l = (2*i)+1; // Left child equation
  int r = (2*i)+2; // Right child equation

  /* I'm comparing these values prioritizing the weight and after that the _price
      of the rental.
  */

  if (l < currentQueueSize && priorityQueue[l].weight < priorityQueue[nodeIndex].weight)  {
    if(l < currentQueueSize && r < currentQueueSize && priorityQueue[l].weight == priorityQueue[r].weight){
      if(priorityQueue[r].price < priorityQueue[l].price){
        nodeIndex = r;
      }
      else{
        nodeIndex = l;
      }
    }
    else{
      nodeIndex = l;
    }
  }
  else if (r < currentQueueSize && priorityQueue[r].weight < priorityQueue[i].weight) {
    if (r < currentQueueSize && l < currentQueueSize && priorityQueue[l].weight == priorityQueue[r].weight){
      if (priorityQueue[l].price < priorityQueue[r].price){
        nodeIndex = l;
      }
      else{
        nodeIndex = r;
      }
    }
    else {
      nodeIndex = r;
    }
  }
  else if (l < currentQueueSize && priorityQueue[l].weight == priorityQueue[i].weight && priorityQueue[l].price < priorityQueue[i].price){
  nodeIndex=l;
  }
  else if (r < currentQueueSize && priorityQueue[r].weight == priorityQueue[i].weight && priorityQueue[r].price < priorityQueue[i].price){
    nodeIndex = r;
  }
  if (i != nodeIndex){
    swap(priorityQueue[i],priorityQueue[nodeIndex]);
    repairDownward(i);
  }
}

