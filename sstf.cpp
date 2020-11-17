#include <bits/stdc++.h>
using namespace std;

int findNearest(vector<int> readyQueue, int currentPointer, map<int, bool> isCompleted)
{
  int shortest = INT_MAX;
  for (int i = 0; i < readyQueue.size(); i++)
  {
    if (abs(readyQueue[i] - currentPointer) < abs(shortest - currentPointer) && isCompleted.count(readyQueue[i]) == 0)
      shortest = readyQueue[i];
  }
  return shortest;
}

int main()
{
  vector<int> readyQueue{98, 183, 37, 122, 14, 124, 65, 67};
  map<int, bool> isCompleted;
  int currentPointer = 53;
  int totalSeekTime = 0;
  cout << "\nSchedule: ";
  for (auto point : readyQueue)
  {
    int nearest = findNearest(readyQueue, currentPointer, isCompleted);
    cout << nearest << " ";
    isCompleted[nearest] = true;
    totalSeekTime += abs(currentPointer - nearest);
    currentPointer = nearest;
  }
  cout << "\nTotal seek time: " << totalSeekTime;
  return 0;
}
