

#include <iostream>
#include <string>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  //LAB A
  std::cout << "First Test: (08/27/2018)\n" << get_east_storage("08/27/2018") << " billion gallons" << std::endl;
  std::cout << "Second Test: (03/23/2018)\n" << get_east_storage("03/23/2018") << " billion gallons" << std::endl;
  std::cout << std::endl;

  //LAB B
  std::cout << "Minimum storage: " << get_min_east() << " billion gallons" << std::endl;
  std::cout << "Maximum storage: " << get_max_east() << " billion gallons" << std::endl;
  std::cout << std::endl;
  
  //LAB C
  std::cout << "First Test: (07/13/2018)\n" << compare_basins("07/13/2018") << std::endl;
  std::cout << "Second Test: (11/06/2018)\n" << compare_basins("11/06/2018") << std::endl;
 std:: cout << std::endl;

  //LAB D
  std::cout << "First Test: (04/09/2018 - 10/23/2018)\n";
  reverse_order("04/09/2018", "10/23/2018");
 std:: cout << "Second Test: (05/26/2018 - 06/02/2018)\n";
  reverse_order("05/26/2018", "09/16/2018");
  return 0;
}
