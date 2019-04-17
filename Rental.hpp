#include <string>
#include <cstring>

struct LLRentalCar
{
  std::string make;
  std::string color;
  std::string dropoff;
  float price;
  int year;
  float weight;
  struct LLRentalCar* next;   // Pointer to the next node

  LLRentalCar(){} // default constructor

  // Parametrized constructor
  LLRentalCar(std::string m, std::string c, ::string dropoff d, float p, int y, float w) : make(r), color(c),
      dropoff(d), price(p), year(y), weight(w), next(NULL) {}
};
class LCar
{
  private:
    LLRentalCar* head;  // Pointer to the head.

  public:
    void insertCar(std::string make, std::string color, std::string dropoff, float price, int year);

    LLRentalCar* searchCar(std::string make);
    // Searches for the car if it's in the linked list.

    weighting_function(LLRentalCar* node);
    // Calculates weight of the car.
};
class RentalCar
{
    public:

    //Purpose: perform all operations necessary to instantiate a class object
    RentalCar(int queueSize);

    // Purpose: free all resources that the object has acquired
    ~RentalCar();

    // Purpose: enqueue new group into priority queue; call other
    void enqueue (std::string _make, int _year, ::string _model, float _price);

    //Purpose: remove the group (allocate the table) at the front of the priority queue from
    void dequeue();

    // return: groupID of the group at the front of the priority queue
    LLRentalCar peek();

    void printL();

    //return: true if queue is full, false otherwise
    bool isFull();

    // return: true if queue is empty, false otherwise
    bool isEmpty();

    private:
    //Purpose: maintain heap properties by swapping node with parent if necessary
    void repairUpward(int nodeIndex);

    // Purpose: maintain heap properties by swapping node with child if necessary
    void repairDownward(int nodeIndex);

    void heapSort(int arr1[], int arr2[]);

    // Sorts the array at a given list

    LLRentalCar* priorityQueue; //pointer to the array used to implement priority queue
    int currentQueueSize; //number of group currently in the priority queue
    int maxQueueSize; //maximum capacity of priority queue
};
