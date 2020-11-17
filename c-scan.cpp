#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> readyQueue{82, 170, 43, 140, 24, 16, 190};
  int lastPoint = 199;
  int currentPointer = 50;
  int totalSeekTime = currentPointer;
  sort(readyQueue.begin(), readyQueue.end());
  //goes left first, then right
  int i;
  for (i = 0; i < readyQueue.size(); i++)
  {
    if (readyQueue[i] > currentPointer)
      break;
  }
  int firstIndex = i - 1;
  i = i - 1;
  cout << "\nSchedule: ";
  cout << currentPointer << " ";
  if (i > 0)
  {
    while (i >= 0)
    {
      cout << readyQueue[i] << " ";
      currentPointer = readyQueue[i--];
    }
  }
  if (readyQueue[0] != 0)
  {
    cout << 0 << " ";
  }
  totalSeekTime += lastPoint;
  cout << lastPoint << " ";
  i = readyQueue.size() - 1;
  while (i > firstIndex)
  {
    cout << readyQueue[i] << " ";
    currentPointer = readyQueue[i];
    i--;
  }
  totalSeekTime += abs(lastPoint - readyQueue[firstIndex + 1]);
  cout
      << "\nTotal seek time: " << totalSeekTime;
  return 0;
}
