using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <deque>

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MinimumMeetingRooms {
 public:
  static int findRoomIfAvailable(deque<int>& roomsBusyUntil,int meetingStartTime)
  {
      if((roomsBusyUntil.size() > 0 ) && (roomsBusyUntil[0] <= meetingStartTime))
      {
          return true;

      }
      return false;
  }
  static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
     if(meetings.size() < 2)
         return meetings.size();
     int roomsRequired = 0;
     std::sort(meetings.begin(), meetings.end(),[](const Meeting& prev , const Meeting& next){return prev.start < next.start; });

     for(auto meeting:meetings)
     {
         cout << meeting.start << ":" << meeting.end << " ";
     }
     cout << endl;

     int i = 0,j=1;
     deque<int> roomsBusyUntil;
     while( i < meetings.size())
     {
         //find free room
         if(findRoomIfAvailable(roomsBusyUntil,meetings[i].start))
         {
             roomsBusyUntil.pop_front();
         }
         else
         {
             ++roomsRequired;
         }
         roomsBusyUntil.push_back(meetings[i].end);
         std::sort(roomsBusyUntil.begin(), roomsBusyUntil.end(),[](const int& prev , const int& next){return prev < next; });
         ++i;
     }
      
    return roomsRequired;
  }
};

int main(int argc, char *argv[]) {
  vector<Meeting> input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 5}, {7, 9}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{6, 7}, {2, 4}, {8, 12}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 3}, {3, 6}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;
}
