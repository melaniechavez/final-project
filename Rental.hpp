#include <string>
#include <cstring>

using namespace std;


// Create struct for nodes containing information about rental cars
struct CarNode
{
  // make and model of the car
  string make;
  // color of the car
  string color;
  // can the car be dropped off as a two way or one way rental?
  string two_way;
  // price of the rental
  float price;
  // year of the car
  int year;
  // a weighting parameter to be used when sorting the rental options
  float weight;
  // pointer to the next CarNode in the linked lsit
  struct CarNode* next;
  // constructor
  CarNode(){}
};


// Create a linked list data structure to store CarNodes
class CarList
{
  private:
    // pointer to the head of the linked list
    CarNode* head;

  public:
    // constructor
    CarList();
    // is the list empty?
    bool isEmpty();
    // insert a CarNode to the linked list based on its parameters
    void insertCar(string make, string color, string two_way, float price, int year, float weight);
    // print the linked list
    void printList();
    // assigns a weight to each CarNode based on user prompted priorities
    void weighting_function();
    // returns the head of the linked list
    CarNode* getHead();
};


// Create Priority Queue implemented as a Binary Heap
class RentalCarQueue
{
    public:

    //Purpose: perform all operations necessary to instantiate a class object
    RentalCarQueue(int queueSize);

    // Purpose: free all resources that the object has acquired
    ~RentalCarQueue();

    // Purpose: enqueue new group into priority queue; call other
    void enqueue(CarNode node);

    // return: groupID of the group at the front of the priority queue
    CarNode peek();

    // print the contents of the queue
    void printQueue();

    //return: true if queue is full, false otherwise
    bool isFull();

    // return: true if queue is empty, false otherwise
    bool isEmpty();

    // remove, or pop, the item off the top of the queue
    CarNode dequeue();

    // return the pointer to the priority queue array
    CarNode* return_arr();

    // return the current quantity of items in the priority queue
    int return_len();

    private:
    //Purpose: maintain heap properties by swapping node with parent if necessary
    void repairUpward(int nodeIndex);

    // Purpose: maintain heap properties by swapping node with child if necessary
    void repairDownward(int nodeIndex);

    CarNode* priorityQueue; //pointer to the array used to implement priority queue
    int currentQueueSize; //number of group currently in the priority queue
    int maxQueueSize; //maximum capacity of priority queue
};
