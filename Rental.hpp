#include <string>
#include <cstring>

using namespace std;

struct CarNode
{
  string make;
  string color;
  string two_way;
  float price;
  int year;
  float weight;
  struct CarNode* next;   // Pointer to the next node

  CarNode(){} // default constructor
};


class CarList
{
  private:
    CarNode* head;  // Pointer to the head.

  public:
    CarList();
    bool isEmpty();
    void insertCar(string make, string color, string two_way, float price, int year, float weight);

    void printList();

    void weighting_function();

    CarNode* getHead();
};

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

    void printQueue();

    //return: true if queue is full, false otherwise
    bool isFull();

    // return: true if queue is empty, false otherwise
    bool isEmpty();
    //
    CarNode dequeue();

    //CarNode* heapSort();

    CarNode* return_arr();

    int return_len();

    private:
    //Purpose: maintain heap properties by swapping node with parent if necessary
    void repairUpward(int nodeIndex);

    // Purpose: maintain heap properties by swapping node with child if necessary
    void repairDownward(int nodeIndex);

    // void heapSort(int arr1[], int len);

    CarNode* priorityQueue; //pointer to the array used to implement priority queue
    int currentQueueSize; //number of group currently in the priority queue
    int maxQueueSize; //maximum capacity of priority queue
};
