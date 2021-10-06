using namespace std;

#include <iostream>
#include <unordered_map>

// PROBLEM: Any number will be called a happy number if, after repeatedly replacing it with a number equal to the sum of the square 
// of all of its digits, leads us to number ‘1’. All other (not-happy) numbers will never reach ‘1’. Instead, they will be stuck 
// in a cycle of numbers which does not include ‘1’.

// EXAMPLE: Input: 23   
//          Output: true (23 is a happy number)  
//          Explanations: Here are the steps to find out that 23 is a happy number:

class HappyNumber {
 public:
  static bool find(int num) {
    int slow = getSum(num);
    int fast = getSum(getSum(num));

    while (fast != 1 && slow != fast) {
      slow = getSum(slow);
      fast = getSum(getSum(fast));
    }

    return fast == 1;
  }

private:
  static int getSum(int num) {
    int sum = 0, digit;
    while (num > 0) {
      int digit = num % 10;
      sum += digit * digit;

      num = num / 10;
    }

    return sum;
  }

  // Time: O(log N) to process digits in a number and same for very large
  //       numbers since they get reduced to 3 digits in a few steps
  
  // Space: O(1) additional space
};