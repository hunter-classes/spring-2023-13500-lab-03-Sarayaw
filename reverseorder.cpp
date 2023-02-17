#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

int main() {
  std::string date1 = "2018-01-01";
  std::string date2 = "2018-05-01";
  reverse_order(date1, date2);

  return 0;
}
 {
  // Open the file in read-only mode.
  std::ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    std::cerr << "File cannot be read." << std::endl;
    exit(1); 
  }

  // Get the dates of the first and last days in the interval.
  std::string date1_line = fin.read_line();
  std::string date2_line = fin.read_line();
  std::string date1 = date1_line.substr(date1_line.find('-') + 1);
  std::string date2 = date2_line.substr(date2_line.find('-') + 1);

  // Get the West basin elevations for all days in the interval.
  std::string line;
  while(std::getline(fin, line, '\n')) {

    std::string date = line.substr(0, line.find('-'));
    if (date == date1 || date == date2) {
      std::cout << line << std::endl;
    }
  }
}
