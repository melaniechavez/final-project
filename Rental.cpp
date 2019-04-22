#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Rental.hpp"

using namespace std;

// Constructor of the linked list
CarList::CarList()
{
  head = nullptr;
}

// checks if the list is empty
bool CarList::isEmpty()
{
  if(head == nullptr){
    return true;
  }
  else{
    return false;
  }
}

// inserts a car into the linked list by creating a CarNode out of the passed information
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

// returns the head of the linked list
CarNode* CarList::getHead(){
  return head;
}

// prints the linked list
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

// assigns a weight based on user prompts
void CarList::weighting_function(){

  // declare all necessary variables and set defaults as necessary
  // set state machine parameters
  int option = 0; // "option" determines whether the user is being prompted or not
  int state = 1; // "state" determines which question the user is being prompted by
  int redo = 0; // if the user needs to return to change a field, this variable will Challenger

  // important parameters to be used in calculating weights later
  string make_yn;
  string make_importance = "1";
  string make;
  string color_yn;
  string color_importance = "1";
  string color;
  string price_yn;
  string price_importance = "1";
  string price;
  string year_yn;
  string year_importance = "1";
  string year;
  string two_way_yn;
  string state_sel;

  // User Prompting Section, Beginning of State Machine
  while(option == 0){

    // Prompt the user for information about make and model
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(state == 1 && option == 0){
      cout << "Is a certain make desired? (Enter Y/N):" << endl;
      cout << "#> ";
      cin >> make_yn;
      while(make_yn != "Y" && make_yn != "N"){
        cout << "Is a certain make desired? Please enter Y or N as capital letters:" << endl;
        cout << "#> ";
        cin >> make_yn;
      }

      if(make_yn == "Y"){
        cout << "Enter the make and model: (E.g. Toyota Camry)" << endl;
        cout << "#> ";
        cin.ignore();
        getline(cin,make);
        cout << "Rank the importance of make from 0 to 5, with 5 being most important:" << endl;
        cout << "#> ";
        cin >> make_importance;
        while(make_importance != "0" && make_importance !="1" && make_importance !="2" && make_importance !="3" && make_importance !="4"&& make_importance !="5"){
          cout << "Please enter the importance as a number between 0 and 5:" << endl;
          cout << "#> ";
          cin >> make_importance;
        }
      }
      if(redo == 0){
        state = 2;
      }
      else{
        option = 1;
      }
    }

    // Prompt the user for information about the color
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(state == 2 && option == 0){
      cout << "Is a certain color desired? (Enter Y/N):" << endl;
      cout << "#> ";
      cin >> color_yn;
      while(color_yn != "Y" && color_yn != "N"){
        cout << "Is a certain color desired? Please enter Y or N as capital letters:" << endl;
        cout << "#> ";
        cin >> color_yn;
      }
      if(color_yn == "Y"){
        cout << "List the desired color of the car: (E.g. Green)" << endl;
        cout << "#> ";
        cin >> color;
        cout << "Rank the importance of color from 0 to 5, with 5 being most important:" << endl;
        cout << "#> ";
        cin >> color_importance;
        while(color_importance != "0" && color_importance !="1" && color_importance !="2" && color_importance !="3" && color_importance !="4"&& color_importance !="5"){
          cout << "Please enter the importance as a number between 0 and 5:" << endl;
          cout << "#> ";
          cin >> color_importance;
        }
      }
      if(redo == 0){
        state = 3;
      }
      else{
        option = 1;
      }
    }

    // Prompt the user for information about the price
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(state == 3 && option == 0){
      cout << "Is the price a determining factor? (Enter Y/N):" << endl;
      cout << "#> ";
      cin >> price_yn;
      while(price_yn != "Y" && price_yn != "N"){
        cout << "Is a certain color desired? Please enter Y or N as capital letters:" << endl;
        cout << "#> ";
        cin >> price_yn;
      }
      if(price_yn == "Y"){
        cout << "List the desired price of the car:" << endl;
        cout << "#> ";
        cin >> price;
        cout << "Rank the importance of price from 0 to 5, with 5 being most important:" << endl;
        cout << "#> ";
        cin >> price_importance;
        while(price_importance != "0" && price_importance !="1" && price_importance !="2" && price_importance !="3" && price_importance !="4"&& price_importance !="5"){
          cout << "Please enter the importance as a number between 0 and 5:" << endl;
          cout << "#> ";
          cin >> price_importance;
        }
      }
      if(redo == 0){
        state = 4;
      }
      else{
        option = 1;
      }
    }

    // Prompt the user for information about the year
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(state == 4 && option == 0){
      cout << "Is a certain year desired? (Enter Y/N):" << endl;
      cout << "#> ";
      cin >> year_yn;
      while(year_yn != "Y" && year_yn != "N"){
        cout << "Is a certain color desired? Please enter Y or N as capital letters:" << endl;
        cout << "#> ";
        cin >> year_yn;
      }
      if(year_yn == "Y"){
        cout << "List the desired year of the car:" << endl;
        cout << "#> ";
        cin >> year;
        cout << "Rank the importance of year from 0 to 5, with 5 being most important:" << endl;
        cout << "#> ";
        cin >> year_importance;
        while(year_importance != "0" && year_importance !="1" && year_importance !="2" && year_importance !="3" && year_importance !="4"&& year_importance !="5"){
          cout << "Please enter the importance as a number between 0 and 5:" << endl;
          cout << "#> ";
          cin >> year_importance;
        }
      }
      if(redo == 0){
        state = 5;
      }
      else{
        option = 1;
      }
    }

    // Prompt the user for information about the car's dropoff protocol
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(state == 5 && option == 0){
      cout << "Is it necessary for the rental to be two_way? (Enter Y/N):" << endl;
      cout << "#> ";
      cin >> two_way_yn;
      while(two_way_yn != "Y" && two_way_yn != "N"){
        cout << "Is a certain color desired? Please enter Y or N as capital letters:" << endl;
        cout << "#> ";
        cin >> two_way_yn;
      }
      option = 1;
    }


    // Make sure that the user is satisfied with their query
    cout << "You have selected: " << endl;
    if(make_yn == "Y"){
      cout << "Make and Model: " << make << endl;
    }
    else{
      cout << "Make and Model: No Selection" << endl;
    }
    if(color_yn == "Y"){
      cout << "Color: " << color << endl;
    }
    else{
      cout << "Color: No Selection" << endl;
    }
    if(price_yn == "Y"){
      cout << "Price: $" << price << endl;
    }
    else{
      cout << "Price: No Selection" << endl;
    }
    if(year_yn == "Y"){
      cout << "Year: " << year << endl;
    }
    else{
      cout << "Year: No Selection" << endl;
    }
    cout << "Two-Way Drop-off: " << two_way_yn << endl;

    cout << endl;
    cout << "Is this correct? (Y/N)" << endl;
    string final_yn;
    cout << "#> ";
    cin >> final_yn;
    while(final_yn != "Y" && final_yn != "N"){
      cout << "Please enter Y or N as capital letters:" << endl;//<< endl;
      cout << "#> ";
      cin >> final_yn;
    }

    // If the user is not satisfied with their query, return to the user prompting section by reassigning state machine variables
    if(final_yn == "N"){
      option = 0;
      redo = 1;
      cout << endl;
      cout << "Please select which item you'd like to change: " << endl;
      cout << "Make and Model (Enter: 1)" << endl;
      cout << "Color (Enter: 2)" << endl;
      cout << "Price (Enter: 3)" << endl;
      cout << "Year (Enter: 4)" << endl;
      cout << "Two-Way Dropoff (Enter: 5)" << endl;
      cout << "#> ";
      cin >> state_sel;
      while(state_sel != "1" && state_sel != "2" && state_sel != "3" && state_sel != "4" && state_sel != "5"){
        cout << "Please enter a number between 1 and 5:" << endl;//<< endl;
        cout << "#> ";
        cin >> state_sel;
      }
      state = stoi(state_sel);
    }
  }


  // Begin the mathematical weighting section
  int make_weight;
  int color_weight;
  int price_weight;
  int year_weight;

  // initialize arrays necessary for calculating the weights
  string yn[4] = {make_yn ,color_yn, price_yn, year_yn};
  int importance[4] = {stoi(make_importance), stoi(color_importance), stoi(price_importance), stoi(year_importance)};
  int weights[4] = {make_weight, color_weight, price_weight, year_weight};


  // iterate over the linked list and calculate a weight for each car based on user answers
  CarNode* tmp = head;

  while(tmp != nullptr){
    // if the car does not meet the two-way requirements, assign a weight of -1 for sorting purposes
    if(two_way_yn == "Y" && tmp->two_way == "one-way"){
      tmp->weight = -1;
    }
    else{

      // assign the fulfilled category to unity by default
      float fulfilled[4] = {1,1,1,1};

      // for make and model, if the user specifies a certain model and it is not fulfilled, assign fulfilled as 1.
      // Otherwise, assign fulfilled as 6
      if(tmp->make != make && make_yn == "Y"){
        fulfilled[0] = 1;
      }
      else{
        fulfilled[0] = 6;
      }

      // Same protocol for color
      if(tmp->color != color && color_yn == "Y"){
        fulfilled[1] = 1;
      }
      else{
        fulfilled[1] = 6;
      }

      // If price is not specified, assign fulfilled as 5.
      if(price_yn == "N"){
        fulfilled[2] = 5;
      }
      // If price is specified, assign fulfilled as inversely proportional to the difference between the specified price and the car's price.
      else if(tmp->price+15 < stof(price)){
        fulfilled[2] = 4/(0.1*(stof(price)-tmp->price)+1);
      }
      else if(tmp->price > stof(price)){
        fulfilled[2] = 4/(0.1*(tmp->price-stof(price))+1);
      }
      else{
        fulfilled[2] = 4*(0.1*(stof(price)-tmp->price)+1);
      }

      // follow the same inverse proportionality model for the year, except assign more weight to the difference as difference in years is smaller than
      // difference in price.
      if(year_yn == "N"){
        fulfilled[3] = 5;
      }
      else if(tmp->year > stoi(year)){
        fulfilled[3] = 5/(0.1*(tmp->year-stoi(year))+1);
      }
      else{
        fulfilled[3] = 5*(0.1*(stoi(year)-tmp->year)+1);
      }

      // calculate the weights for each criterion with an inner product (dot product) of the importance of that criterion and whether what is
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


// constructor for the priority queue
RentalCarQueue::RentalCarQueue(int maxQueueSize)
{
    currentQueueSize = 0;
    maxQueueSize = maxQueueSize;
    priorityQueue = new CarNode[maxQueueSize];
}

// deconstructor for the priority queue
RentalCarQueue::~RentalCarQueue()
{
    delete [] priorityQueue;
}

// is the priority queue empty?
bool RentalCarQueue::isEmpty(){
  if(currentQueueSize == 0)
    return true;
  else
    return false;
}

// is the priority queue full?
bool RentalCarQueue::isFull(){
  if(currentQueueSize == maxQueueSize)
    return true;
  else
    return false;
}

// return the CarNode at the top of the priority queue
CarNode RentalCarQueue::peek(){
  if(!isEmpty())
    return priorityQueue[0];
  else
    cout << "Heap empty, nothing to peek" << endl;
    return priorityQueue[0];
}

// useful functions for determining indices of nodes in the priority queue
int parent(int i) { return (i-1)/2; }
int left(int i) { return (2*i+1); }
int right(int i) { return (2*i + 2); }

// return the priority queue to ordered state after a node is added
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

// add a node to the priority queue
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

// return the queue to ordered state after removing the top of the queue
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

// remove the top of the queue and return the CarNode that was removed
CarNode RentalCarQueue::dequeue() // extractMin
{
    if(currentQueueSize <= 0){
      cout << "Heap empty, cannot dequeue" << endl;
    }
    if(currentQueueSize == 1){
      currentQueueSize--;
      return priorityQueue[0];
    }
    CarNode temp = priorityQueue[0];
    priorityQueue[0] = priorityQueue[currentQueueSize-1];
    currentQueueSize--;
    repairDownward(0);
    return temp;
}

// generic swap function
void swap(CarNode &x, CarNode &y)
{
    CarNode temp = x;
    x = y;
    y = temp;
}

// print the contents of the queue
void RentalCarQueue::printQueue() {
  cout << "Printing Queue" << endl;
  for(int i = 0; i<currentQueueSize; i++){
    cout << priorityQueue[i].make << ", " << priorityQueue[i].weight << ", " << priorityQueue[i].price << endl;
  }
}

// return the pointer to the array storing the nodes of the queue
CarNode* RentalCarQueue::return_arr(){
  return priorityQueue;
}

// return the number of items in the queue
int RentalCarQueue::return_len(){
  return currentQueueSize;
}
