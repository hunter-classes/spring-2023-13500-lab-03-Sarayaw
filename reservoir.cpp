
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>



double get_east_storage(std::string date){
  string fileDate;
  double eastSt;
  double eastEl;
  double westSt;
  double westEl;

 
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    std::cerr << "File cannot be read." << std::endl;
    exit(1); 
  }


  std::string junk;       
  getline(fin, junk); 

 
  while(fin >> fileDate >> eastSt >> eastEl >> westSt >> westEl) {

   fin.ignore(INT_MAX, '\n');
   if (fileDate == date){
      return eastSt;
    }

  }
  fin.close();
  return 0.0;
 }

double get_min_east() {
  std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); 
    }

  std::string trash;
  getline(fin, trash);

  std::string user_date;
  std::cout << "Enter date in 2018: ";
  std::cin >> user_date;

  std::string date;
  double east_storage = 0.0;

  do {
    fin >> date;
  }
  while (date.compare(user_date) != 0);

  fin >> east_storage;

  double min_east = east_storage;
  while (fin >> date) {
    fin >> east_storage;
    if (east_storage < min_east) {
      min_east = east_storage;
    }
  }

  return min_east;
}

double get_max_east() {
  std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); 
    }

  std::string trash;
  getline(fin, trash);

  std::string user_date;
  std::cout << "Enter date in 2018: ";
  std::cin >> user_date;

  std::string date;
  double east_storage = 0.0;

  do {
    fin >> date;
  }
  while (date.compare(user_date) != 0);

  fin >> east_storage;

  double max_east = east_storage;
  while (fin >> date) {
    fin >> east_storage;
    if (east_storage > max_east) {
      max_east = east_storage;
    }
  }

  return max_east;
}
