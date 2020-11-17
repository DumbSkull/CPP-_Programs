#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> requestQueue{98, 183, 37, 122, 14, 124, 65, 67};
  int startingPosition;
  startingPosition = 53;
  //inputting values:
  //int sizeOfQueue;
  // cout << "\nEnter the queue size: ";
  // cin >> sizeOfQueue;
  //vector<int> requestQueue;
  // for(int i=0; i<sizeOfQueue; i++){
  //   int position;
  //   cin>>position;
  //   requestQueue.push_back(position);
  // }
  // cout<<"\nEnter the head: ";
  // cin>>startingPosition;
  int totalSeekTime = requestQueue[0] - startingPosition;
  for (int i = 1; i < requestQueue.size(); i++)
    totalSeekTime += abs(requestQueue[i] - requestQueue[i - 1]);
  cout << "\nSeek time: " << totalSeekTime;
  return 0;
}
