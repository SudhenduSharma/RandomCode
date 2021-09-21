#include<iostream>
#include<vector>
using namespace std;
class Solution
{

    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            if(nums1.size()>nums2.size())
            {
                return findMedianSortedArrays(nums2,nums1);
            }
            else
            {
                int x = nums1.size();
                int y = nums2.size();
                int medianIndex = (x+y+1)/2;
                cout<< "medianIndex " << medianIndex << endl;
                int low = 0;
                int high = x;
                //binary search in x such that
                //partitionX + partionY = medianIndex
                while(low <= high)
                {
                    int partitionX = (low+high)/2;
                    int partitionY = medianIndex - partitionX;
                    int maxLeftX = (partitionX == 0)?INT_MIN:nums1[partitionX-1];
                    int minRightX = (partitionX == x) ?INT_MAX:nums1[partitionX];
                    int maxLeftY = (partitionY == 0)?INT_MIN:nums2[partitionY-1];
                    int minRightY = (partitionY == y) ?INT_MAX:nums2[partitionY];
                    if(maxLeftX <= minRightY && maxLeftY <= minRightX)
                    {
                        //found 
                        cout<< "partitionX " << partitionX << " partitionY " << partitionY << endl;
                        cout<< "maxLeftX " << maxLeftX << " maxLeftY " << maxLeftY << endl;
                        cout << "minRightX " << minRightX << " minRightY " << minRightY << endl; 
                        if((x+y)%2 == 0)
                        {
                            double median =  max({ maxLeftX,maxLeftY }) + min({minRightX,minRightY});
                            cout << "median " << median <<endl;
                            return median/2;
                        }
                        else
                        {
                            return max({ maxLeftX,maxLeftY });
                        }
                    }
                    else if( maxLeftX > minRightY )
                    {
                        high = partitionX-1;
                    }
                    else
                    {
                        low = partitionX+1;
                    }
                }
                //INVALID input
                return -1;
            }
        }

};

int main()
{
    vector<int> arr1 = { 2,4,6};
    vector<int> arr2 = { 1,3,5};
    cout << Solution().findMedianSortedArrays(arr1,arr2);
    return 0;
}
