#include <limits>
#include <vector>

bool min_expand(const std::vector<int> & base_values, int value, std::vector<int> & coefficients) {
  if (value == 0) {
    return false;
  }

  std::vector<int> value_min_coefficients_count(value + 1, 0);

  // Create 'value -> min_coefficients_count' mapping
  for (int curr_value = 1; curr_value <= value; ++curr_value) {
    int min_coefficients_count = std::numeric_limits<int>::max();

    for (int curr_base_value : base_values) {
      if (curr_value < curr_base_value) {
        // Take next base value
        continue;
      }

      int prev_value = curr_value - curr_base_value;

      if (0 < prev_value && value_min_coefficients_count[prev_value] == 0) {
        // Take next base value
        continue;
      }

      int coefficients_count = value_min_coefficients_count[prev_value] + 1;

      if (coefficients_count < min_coefficients_count) {
        min_coefficients_count = coefficients_count;
        value_min_coefficients_count[curr_value] = min_coefficients_count;
      }
    }
  }

  if (value_min_coefficients_count[value] == 0) {
    return false;
  }

  std::vector<int> coeffs(base_values.size());

  // Trace back coefficients
  for (int curr_value = value; 0 < curr_value; ) {
    int min_coefficients_count = std::numeric_limits<int>::max();
    int min_coefficient_index = -1;

    for (int curr_base_value_index = 0; curr_base_value_index < base_values.size(); ++curr_base_value_index) {
      int curr_base_value = base_values[curr_base_value_index];

      if (curr_value < curr_base_value) {
        // Take next base value
        continue;
      }

      int prev_value = curr_value - curr_base_value;

      if (0 < prev_value && value_min_coefficients_count[prev_value] == 0) {
        // Take next base value
        continue;
      }

      int coefficients_count = value_min_coefficients_count[prev_value] + 1;

      if (coefficients_count < min_coefficients_count) {
        min_coefficients_count = coefficients_count;
        min_coefficient_index = curr_base_value_index;
      }
    }

    if (min_coefficient_index != -1) {
      curr_value = curr_value - base_values[min_coefficient_index];
      ++coeffs[min_coefficient_index];
    } else {
      --curr_value;
    }
  }

  coefficients.swap(coeffs);

  return true;
}
