#include <iostream>
using namespace std;

// Function to find the square root of a number using binary search
int findsqrt(int n) {
  int target = n; // Store the target number to find the square root of
  int s = 0;      // Initialize the starting index of the search range
  int e = n;      // Initialize the ending index of the search range
  int mid = s + (e - s) / 2; // Calculate the middle index of the search range
  int ans = -1; // Initialize the variable to store the square root (if found)

  // Binary search algorithm to find the square root
  while (s <= e) {
    if (mid * mid == target) {
      return mid; // Return the square root if found
    } else if (mid * mid > target) {
      e = mid - 1; // Update the ending index for the next iteration
    } else {
      ans = mid;   // Update the potential square root
      s = mid + 1; // Update the starting index for the next iteration
    }
    mid = s + (e - s) / 2; // Calculate the new middle index
  }
  return ans; // Return the potential square root (if not found, -1)
}

int main() {
  int n;
  cout << "Enter the number to be square rooted: ";
  cin >> n;
  int precision;
  cout << "Enter the precision of the square root: ";
  cin >> precision;

  // Call the findsqrt function to calculate the square root
  int sqrt = findsqrt(n);

   // Calculate the square root with a specified precision
  double step = 0.1; // Initialize the step size for iterating over decimal places
  double finalAns = sqrt; // Initialize the final answer with the initial approximation
  // Iterative refinement to achieve the desired precision
  for (int i = 0; i < precision; i++) { // Loop for refining the answer to the specified precision
    for (double j = finalAns; j * j <= n; j = j + step) { // Iterate over decimal places to find the closest value within the target range
      finalAns = j; // Update the final answer with the closest value found within the target range
    }
    step = step / 10; // Reduce the step size for refining the answer to a higher precision in the next iteration
  }

  cout << "Final ans is. " << finalAns << endl;
  cout<< "Thank you" << endl;
  return 0;
}
