
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

std::string compare_basins(std::string date) {
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

  if (east_storage > west_storage) {
    return "East";
  } else if (east_storage < west_storage) {
    return "West";
  } else {
    return "Equal";
  }
}

int main() {
  std::cout << "The comparison of East and West basin storage on " << compare_basins("2018-01-01") << std::endl;
  std::cout << "The comparison of East and West basin storage on " << compare_basins("2018-02-01") << std::endl;
  std::cout << "The comparison of East and West basin storage on " << compare_basins("2018-03-01") << std::endl;
  std::cout << "The comparison of East and West basin storage on " << compare_basins("2018-04-01") << std::endl;
  std::cout << "The comparison of East and West basin storage on " << compare_basins("2018-05-01") << std::endl;
  std::cout << "The comparison of East and West basin storage on " << compare_basins("2018-06-01") << std::endl;
  std::cout << "The comparison of East and West basin storage on " << compare_basins("2018-07-01") << std::endl;
  std::cout << "The comparison of East and West basin storage on " << compare_basins("2018-08-01") << std::endl;
  std::cout << "The comparison of East and West basin storage on " << compare_basins("2018-09-01") << std::endl;
  std::cout << "The comparison of East and West basin storage on " << compare_basins("2018-10-01") << std::endl;

  return 0;
}
