using namespace std;

#include <iostream>
#include <queue>
#include <vector>



class MaximizeCapital {

  struct capitalCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; }
  };

  struct profitCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return y.first > x.first; }
  };

 public:
  static int findMaximumCapital(const vector<int> &capital, const vector<int> &profits,
                                int numberOfProjects, int initialCapital) {
    // TODO: Write your code here
    // https://stackoverflow.com/questions/53587451/why-isnt-a-lambda-allowed-in-a-template-instantiation
    //auto capitalCompare =   [](const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; };
    //std::function<bool (const pair<int, int> &x, const pair<int, int> &y)> capitalCompare = [](const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; };
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,capitalCompare> minHeapCapitals;
    priority_queue<pair<int,int>,vector<pair<int,int>>,profitCompare> maxHeapProfits;
    
    int availableCapital = initialCapital;

    for(int i = 0; i < capital.size();++i)
    {
        minHeapCapitals.push(std::make_pair(capital[i],i));
    }

    while(numberOfProjects)
    {
        while(!minHeapCapitals.empty() && minHeapCapitals.top().first <= availableCapital )
        {
            maxHeapProfits.push(std::make_pair(profits[minHeapCapitals.top().second],minHeapCapitals.top().first));
            minHeapCapitals.pop();
        }
        //choose the product with max profit and increase capital in hand
        if(!maxHeapProfits.empty())
        {
            availableCapital += maxHeapProfits.top().first;
            maxHeapProfits.pop();
        }
        --numberOfProjects;
    }
    return availableCapital;
  }
};

int main(int argc, char *argv[]) {
  int result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2}, vector<int>{1, 2, 3}, 2, 1);
  cout << "Maximum capital: " << result << endl;
  result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2, 3}, vector<int>{1, 2, 3, 5}, 3, 0);
  cout << "Maximum capital: " << result << endl;
}
