using namespace std;

#include <iostream>
#include <vector>

class FirstSmallestMissingPositive {
 public:
  static int findNumber(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      cout<< " nums[nums.at(i)]"  << nums[nums.at(i) - 1];
      if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums.at(i) - 1]) {
        swap(nums, i, nums[i] - 1);
      } else {
        i++;
      }
    }

    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    return nums.size() + 1;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {-3, 1, 5, 4, 2};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, -2, 0, 1, 2};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, 2, 5, 1};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;
  v1 = {13, 12, 15, 11};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;
  for(auto c : v1)
     cout << " " << c << " ";

}
