#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

void reverse_order(std::string date1, std::string date2) {
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

  double west_storage = 0.0;
  while (fin >> date) {
    fin >> west_storage;
  }

  while (fin >> date) {
    if (date.compare(date2) > 0) {
      std::cout << date << " " << west_storage << std::endl;
    } else {
      break;
    }
  }

  while (fin >> date) {
    if (date.compare(date1) > 0) {
      std::cout << date << " " << west_storage << std::endl;
    } else {
      break;
    }
  }
}
