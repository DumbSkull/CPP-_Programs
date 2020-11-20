#include <bits/stdc++.h>
using namespace std;

bool isProcessPossible(vector<vector<int>> maximum, vector<vector<int>> allocation, vector<int> currentAvailable, int index)
{
  for (int i = 0; i < maximum[index].size(); i++)
    if ((maximum[index][i] - allocation[index][i]) > currentAvailable[i])
      return false;
  return true;
}

vector<string> findSafeSequence(vector<vector<int>> allocation, vector<vector<int>> maximum, vector<string> processIds, vector<int> available, int startIndex)
{

  vector<string> safeSequence;
  vector<int> totalAllocation(allocation[0].size(), 0); //setting total initial allocation to 0

  for (auto process : allocation)
    for (int i = 0; i < process.size(); i++)
      totalAllocation[i] += process[i];

  vector<int> currentAvailable; //setting the current available to available-totalAllocation
  for (int i = 0; i < available.size(); i++)
    currentAvailable.push_back(available[i] - totalAllocation[i]);

  map<int, bool> isCompleted;
  int currentIndex = startIndex;
  int loopCount = 0;
  while (isCompleted.size() != allocation.size())
  {
    for (int i = currentIndex; i < allocation.size(); i++)
    {
      if (isProcessPossible(maximum, allocation, currentAvailable, i) && isCompleted.count(i) == 0)
      {
        safeSequence.push_back(processIds[i]);
        for (int j = 0; j < allocation[j].size(); j++)
          currentAvailable[j] += allocation[i][j];
        isCompleted[i] = true;
      }
    }
    currentIndex = 0;
    loopCount++;
    if (loopCount >= allocation.size())
      break;
  }
  return safeSequence;
}

void bankersAlgorithm(vector<vector<int>> allocation, vector<vector<int>> maximum, vector<string> processIds, vector<int> available, int startIndex)
{
  vector<string> safeSequence = findSafeSequence(allocation, maximum, processIds, available, startIndex);
  if (allocation.size() != safeSequence.size())
  {
    cout << "\nThere is no safe sequence. Hence, deadlock can occur.";
    return;
  }
  if (safeSequence[0] != processIds[startIndex])
  {
    cout << "\nNo sequence can be found that begins with " << processIds[startIndex] << ".";
  }
  cout << "\nThe possible sequence is: ";
  for (auto process : safeSequence)
  {
    cout << process << ((process != safeSequence.back()) ? " -> " : "");
  }
}

int main()
{
  vector<char> resources{'A', 'B', 'C'};
  vector<int> available{10, 5, 7};
  vector<string> processIds{"P1", "P2", "P3", "P4", "P5"};
  string startingProcess = "P2";
  int startingProcessIndex = 0;
  for (int i = 0; i < processIds.size(); i++)
  {
    if (processIds[i] == startingProcess)
    {
      startingProcessIndex = i;
      break;
    }
  }
  vector<vector<int>> allocation{
      {0, 1, 0},
      {2, 0, 0},
      {3, 0, 2},
      {2, 1, 1},
      {0, 0, 2}};
  vector<vector<int>> maximum{
      {7, 5, 3},
      {3, 2, 2},
      {9, 0, 2},
      {2, 2, 2},
      {4, 3, 3}};
  bankersAlgorithm(allocation, maximum, processIds, available, startingProcessIndex);
}