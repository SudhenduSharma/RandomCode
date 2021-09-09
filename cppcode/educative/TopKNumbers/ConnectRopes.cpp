using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ConnectRopes {
 public:
  static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
    int result = 0;
    priority_queue<int,vector<int>, std::greater<int> > costOfRopes;
    for(auto ropeLen : ropeLengths)
    {
        costOfRopes.push(ropeLen);
    }
    while(!costOfRopes.empty())
    {
        int cost1 = costOfRopes.top();
        costOfRopes.pop();
        int cost2 = 0;
        if(!costOfRopes.empty())
        {
            cost2 = costOfRopes.top();
            costOfRopes.pop();
            costOfRopes.push(cost1+cost2);
            result += (cost1 + cost2);
            //cout << cost1 << " + " << cost2 << endl;
            //cout << result  << endl;
        }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  int result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{3, 4, 5, 6});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
  cout << "Minimum cost to connect ropes: " << result << endl;
}
