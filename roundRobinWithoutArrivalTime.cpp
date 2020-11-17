#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> burstTimes{4, 1, 8, 1};
  vector<int> originalBurstTimes = burstTimes;
  int n = burstTimes.size();
  vector<int> completionTimes(n, -1);
  queue<int> readyQueueIndex;
  int timeQuantum = 1;
  vector<int> turnAroundTime;
  vector<int> waitingTime;

  int totalTime = accumulate(burstTimes.begin(), burstTimes.end(), 0);
  int timeElapsed = 0;

  //filling the ready queue:
  for (int i = 0; i < n; i++)
    readyQueueIndex.push(i);

  while (timeElapsed < totalTime)
  {
    int indexOfCurrentProcess = readyQueueIndex.front();
    if (burstTimes[indexOfCurrentProcess] <= timeQuantum)
    {
      timeElapsed += burstTimes[indexOfCurrentProcess];
      burstTimes[indexOfCurrentProcess] = 0;
      completionTimes[indexOfCurrentProcess] = timeElapsed;
    }
    else
    {
      timeElapsed += timeQuantum;
      burstTimes[indexOfCurrentProcess] -= timeQuantum;
      readyQueueIndex.push(indexOfCurrentProcess);
    }
    readyQueueIndex.pop();
  }

  //turn around time = completion time (when not considering any specific arrival times)
  turnAroundTime = completionTimes;

  //computing waiting times:
  for (int i = 0; i < n; i++)
    waitingTime.push_back(completionTimes[i] - originalBurstTimes[i]);

  cout << "\nProccess No. \t\tBurst Time\t\tTurn Around Time\t\tWaiting Time";
  for (int i = 0; i < n; i++)
    cout << "\nP" << (i + 1) << "\t\t\t"
         << originalBurstTimes[i] << "\t\t\t"
         << turnAroundTime[i] << "\t\t\t\t"
         << waitingTime[i];
  cout << "\nAverage Turn Around Time = " << accumulate(turnAroundTime.begin(), turnAroundTime.end(), 0) / (float)n;
  cout << "\nAverage Waiting Time = " << accumulate(waitingTime.begin(), waitingTime.end(), 0) / (float)n;
  return 0;
}