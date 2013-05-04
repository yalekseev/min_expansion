#include <cassert>
#include <vector>

#include "min_expand.h"

int main(int argc, char *argv[]) {
  std::vector<int> base_values = { 2, 3, 7, 10 };
  std::vector<int> expected_coefficients = { 1, 0, 0, 2 };

  std::vector<int> coefficients;
  assert(true == min_expand(base_values, 22, coefficients));
  assert(expected_coefficients == coefficients);

  return 0;
}
