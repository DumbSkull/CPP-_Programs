#include <bits/stdc++.h>
using namespace std;

struct process
{
  int processID;
  int burstTime;
  int arrivalTime;
  int completionTime;
};

bool sortAccordingToArrivalTime(process a, process b)
{
  return a.arrivalTime < b.arrivalTime;
}

int sumBurstTimes(int sum, const process &b)
{
  return sum + b.burstTime;
}

int main()
{
  //process{process number, burstTime, arrivalTime}
  vector<process> processes{{1, 5, 5},
                            {2, 6, 4},
                            {3, 7, 3},
                            {4, 9, 1},
                            {5, 2, 2},
                            {6, 3, 6}};

  // vector<process> processes{{1, 5, 0},
  //                           {2, 3, 1},
  //                           {3, 1, 2},
  //                           {4, 2, 3},
  //                           {5, 3, 4}};

  vector<process> originalProcesses = processes;
  int n = processes.size();
  vector<int> completionTimes(n, -1);
  queue<int> readyQueueIndex;
  //int timeQuantum = 3;
  int timeQuantum = 3;
  vector<int> turnAroundTime;
  vector<int> waitingTime;

  sort(processes.begin(), processes.end(), sortAccordingToArrivalTime);
  int timeElapsed = processes[0].arrivalTime;
  processes = originalProcesses;
  vector<int> arrivedProcessIndex;

  for (int i = 0; i < n; i++)
  {
    if (processes[i].arrivalTime == timeElapsed)
    {
      readyQueueIndex.push(i);
      arrivedProcessIndex.push_back(i);
    }
  }

  int completedProcesses = 0;
  while (completedProcesses != n)
  {

    int indexOfCurrentProcess = readyQueueIndex.front();
    if (processes[indexOfCurrentProcess].burstTime <= timeQuantum)
    {
      timeElapsed += processes[indexOfCurrentProcess].burstTime;
      processes[indexOfCurrentProcess].burstTime = 0;
      processes[indexOfCurrentProcess].completionTime = timeElapsed;
      completedProcesses++;
    }
    else
    {
      timeElapsed += timeQuantum;
      processes[indexOfCurrentProcess].burstTime -= timeQuantum;
    }
    readyQueueIndex.pop();
    if (arrivedProcessIndex.size() != originalProcesses.size())
    {
      vector<process> sortedNewReadyProcesses;
      for (int i = 0; i < n; i++)
      {
        if (find(arrivedProcessIndex.begin(), arrivedProcessIndex.end(), i) == arrivedProcessIndex.end() && processes[i].arrivalTime <= timeElapsed)
        {
          arrivedProcessIndex.push_back(i);
          sortedNewReadyProcesses.push_back(processes[i]);
        }
      }
      sort(sortedNewReadyProcesses.begin(), sortedNewReadyProcesses.end(), sortAccordingToArrivalTime);
      for (auto p : sortedNewReadyProcesses)
        readyQueueIndex.push(p.processID - 1);

      if (readyQueueIndex.empty())
      {
        timeElapsed++;
        continue;
      }
    }
    if (processes[indexOfCurrentProcess].burstTime != 0)
      readyQueueIndex.push(indexOfCurrentProcess);
  }

  //turn around time = completion time (when not considering any specific arrival times)
  cout << "\nCompletion time: ";
  for (int i = 0; i < n; i++)
    cout << processes[i].completionTime << " ";

  for (int i = 0; i < n; i++)
    turnAroundTime.push_back(processes[i].completionTime - processes[i].arrivalTime);

  //computing waiting times:
  for (int i = 0; i < n; i++)
    waitingTime.push_back(turnAroundTime[i] - originalProcesses[i].burstTime);

  cout << "\nProccess No.\tBurst Time\tArrival Time\tTurn Around Time\tWaiting Time";
  for (int i = 0; i < n; i++)
    cout << "\nP" << (i + 1) << "\t\t"
         << originalProcesses[i].burstTime << "\t\t"
         << processes[i].arrivalTime << "\t\t"
         << turnAroundTime[i] << "\t\t\t"
         << waitingTime[i];
  cout << "\nAverage Turn Around Time = " << accumulate(turnAroundTime.begin(), turnAroundTime.end(), 0) / (float)n;
  cout << "\nAverage Waiting Time = " << accumulate(waitingTime.begin(), waitingTime.end(), 0) / (float)n;
  return 0;
}