#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> readyQueue{98, 183, 37, 122, 14, 124, 65, 67};
  int currentPointer = 53;
  int totalSeekTime = currentPointer;
  int firstIndex;
  sort(readyQueue.begin(), readyQueue.end());
  //goes left first, then right
  for (int i = 0; i < readyQueue.size(); i++)
  {
    if (readyQueue[i] > currentPointer)
    {
      firstIndex = i - 1;
      break;
    }
  }
  cout << "\nSchedule: ";
  cout << currentPointer << " ";
  int i = firstIndex;
  if (i > 0)
  {
    while (i >= 0)
    {
      cout << readyQueue[i] << " ";
      currentPointer = readyQueue[i];
      i--;
    }
  }
  if (readyQueue[0] != 0)
    cout << 0 << " ";
  currentPointer = 0;
  i = firstIndex + 1;
  while (i < readyQueue.size())
  {
    cout << readyQueue[i] << " ";
    currentPointer = readyQueue[i++];
  }
  totalSeekTime += readyQueue[readyQueue.size() - 1];
  cout << "\nTotal seek time: " << totalSeekTime;
  return 0;
}
