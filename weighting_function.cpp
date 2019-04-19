// Weighting function

// Takes in a linked list and assigns a weight to each node.
// finds the length of the linked list
// instantiates a linked list
// Then pushes each weighted node to a priority queue

void CarList::weighting_function(CarNode* root){

  cout << "Is a certain make desired? (Enter Y/N):" << endl;//<< endl;
  string make_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,make_yn);

  if(make_yn == "Y"){
    cout << "Enter the make: (E.g. Toyota)" << endl;//<< endl;
    string make;
    cout << "#> ";
    cin.ignore();
    getline(cin,make);
    cout << "Rank the importance of make from 0 to 5, with 5 being most important:" << endl;//<< endl;
    int make_importance;
    cout << "#> ";
    cin.ignore();
    getline(cin,make_importance);
  }


  cout << "Is a certain color desired? (Enter Y/N):" << endl;//<< endl;
  int color_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,color_yn);

  if(color_yn == "Y"){
    cout << "List the desired color of the car: (E.g. Green)" << endl;//<< endl;
    int color;
    cout << "#> ";
    cin.ignore();
    getline(cin,color);
    cout << "Rank the importance of color from 0 to 5, with 5 being most important:" << endl;//<< endl;
    int color_importance;
    cout << "#> ";
    cin.ignore();
    getline(cin,color_importance);
  }

  cout << "Is the price a determining factor? (Enter Y/N):" << endl;//<< endl;
  int price_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,price_yn);

  if(price_yn == "Y"){
    cout << "List the desired price of the car:" << endl;//<< endl;
    float price;
    cout << "#> ";
    cin.ignore();
    getline(cin,price);
    cout << "Rank the importance of price from 0 to 5, with 5 being most important:" << endl;//<< endl;
    int price_importance;
    cout << "#> ";
    cin.ignore();
    getline(cin,price_importance);
  }

  cout << "Is a certain year desired? (Enter Y/N):" << endl;//<< endl;
  string year_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,year_yn);

  if(year_yn == "Y"){
    cout << "List the desired year of the car:" << endl;//<< endl;
    int year;
    cout << "#> ";
    cin.ignore();
    getline(cin,year);
    cout << "Rank the importance of year from 0 to 5, with 5 being most important:" << endl;//<< endl;
    int year_importance;
    cout << "#> ";
    cin.ignore();
    getline(cin,year_importance);
  }


  cout << "Is it necessary for the rental to be two_way? (Enter Y/N):" << endl;//<< endl;
  int two_way_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,two_way_yn);

  
  int make_weight;
  int color_weight;
  int price_weight;
  int year_weight;


  string yn[4] = {make_yn ,color_yn, price_yn, year_yn};
  int importance[4] = {make_importance, color_importance, price_importance, year_importance};
  int weights[4] = {make_weight, color_weight, price_weight, year_weight};


  Car* tmp = head;

  while(tmp != nullptr){
    if(two_way_yn == "Y" && tmp->two_way == "Y"){

      int fulfilled[4] = {1,1,1,1};

      if(tmp->make == make && make_yn != "N"){
        fulfilled[0] = 5;
      }
      if(tmp->color == color && color_yn != "N"){
        fulfilled[1] = 5;
      }
      if(tmp->price < (price+10) && price_yn != "N"){
        fulfilled[2] = 5;
      }
      if(tmp->year == year && year_yn != "N"){
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

    else{
      tmp->weight = -1;
    }
    tmp = tmp -> next;
  }
}
