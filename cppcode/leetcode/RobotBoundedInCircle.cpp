#include<iostream>
class Solution {
    public:
        bool isRobotBounded(std::string instructions) 
        {
            //Intial position
            int x = 0;
            int y = 0;
            //use dirX/dirY  to move forward by one unit
            int dirX = 0, dirY = 1;
            for(int i =0; i< 4;i++)
            {
                for(auto c : instructions)
                {
                    if(c == 'G')
                    {
                        //move forward in current direction
                        x += dirX;
                        y += dirY;
                    }
                    else if( c == 'L')
                    {
                        //rotate left 
                        int tmp = dirX;
                        dirX = -dirY;
                        dirY = tmp;
                    }   
                    else if( c == 'R')
                    {
                        int tmp = dirX;
                        dirX = dirY;
                        dirY = - tmp;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return ((x == 0 && y ==0)?true:false) ;

        }
};
int main()
{
    std::cout << Solution().isRobotBounded("GL");

}
