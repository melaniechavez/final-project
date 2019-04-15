// Weighting function

// Takes in a linked list and assigns a weight to each node.
// finds the length of the linked list
// instantiates a linked list
// Then pushes each weighted node to a priority queue

void weighting_function(Car* list_root){

  string yn[6];
  cout << "Is a certain type of car desired? (Enter Y/N):" << endl;//<< endl;
  string type_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,type_yn);
  yn[0] = type_yn;


  if(type_yn == "Y"){
    cout << endl;
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Sedan " << endl;
    cout << " 2. SUV " << endl;
    cout << " 3. Station Wagon " << endl;
    cout << " 4. Truck " << endl;
    cout << " 5. Hatchback " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
    int type;
    cout << "#> ";
    cin.ignore();
    getline(cin,type);
    cout << "Rank the importance of type from 0 to 5, with 5 being most important:" << endl;//<< endl;
    int type_importance;
    cout << "#> ";
    cin.ignore();
    getline(cin,type_importance);
  }

  cout << "Is a certain make desired? (Enter Y/N):" << endl;//<< endl;
  string make_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,make_yn);
  yn[1] = make_yn;

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

  cout << "Is a certain model desired? (Enter Y/N):" << endl;//<< endl;
  string model_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,model_yn);
  yn[2] = model_yn;

  if(model_yn == "Y"){
    cout << "Enter the model: (E.g. Camry)" << endl;//<< endl;
    string model;
    cout << "#> ";
    cin.ignore();
    getline(cin,model);
    cout << "Rank the importance of model from 0 to 5, with 5 being most important:" << endl;//<< endl;
    int model_importance;
    cout << "#> ";
    cin.ignore();
    getline(cin,model_importance);
  }

  cout << "Is a certain year desired? (Enter Y/N):" << endl;//<< endl;
  string year_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,year_yn);
  yn[3] = year_yn;

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

  cout << "Is a certain color desired? (Enter Y/N):" << endl;//<< endl;
  int color_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,color_yn);
  yn[4] = color_yn;

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

  cout << "Is it necessary for the rental to be two_way? (Enter Y/N):" << endl;//<< endl;
  int two_way_yn;
  cout << "#> ";
  cin.ignore();
  getline(cin,two_way_yn);
  yn[5] = two_way_yn;

  cout << "Rank the importance of price from 0 to 5, with 5 being most important:" << endl;//<< endl;
  int price_importance;
  cout << "#> ";
  cin.ignore();
  getline(cin,price_importance);

  int color_weight;
  int year_weight;
  int make_weight;
  int model_weight;
  int type_weight;


  int importance[5] = {color_importance,year_importance,make_importance,model_importance,type_importance};
  int weights[5] = {color_weight,year_weight,make_weight,model_weight,type_weight};

  PriorityQueue p;

  Car* tmp = head;

  while(tmp != nullptr){
    int fulfilled[5] = {1,1,1,1,1};

    if(tmp->color == color && color_yn != "N"){
      fulfilled[0] = 5;
    }

    if(tmp->year == year && year_yn != "N"){
      fulfilled[1] = 5;
    }

    if(tmp->make == make && make_yn != "N"){
      fulfilled[2] = 5;
    }

    if(tmp->model == model && model_yn != "N"){
      fulfilled[3] = 5;
    }

    if(tmp->type == type && type_yn != "N"){
      fulfilled[4] = 5;
    }

    // calculate the weights for each criterion with an inner product of the importance of that criterion and whether what is
    // desired is fulfilled
    for(int i=0; i<5; i++){
      weights[i] = importance[i]*fulfilled[i];
    }

    // calculate the overall weight of the car and add to priority queue
    for(int i=0; i<6; i++){
      if(yn[i] == "Y"){
        tmp->weight = tmp->weight + weights[i];
      }
    }
    p.enqueue(tmp*);
    tmp = tmp -> next;
  }
}
