#include <iostream>
#include <string>

using namespace std;

bool find_element(int arr[], int size, int el)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == el)
            return true;
    return false;
}

void calculate_waiting_time(int burst_time[], int waiting_time[])
{
    int n = 4;
    int min_index;
    int checked_burst_times[n];
    int size_of_checked_burst_times = 0;
    int wait_time_acc = 0;
    for (int i = 0; i < n; i++)
    {
        min_index = INT_MAX;
        for (int j = i; j < n - 1; j++)
        {
            if (burst_time[j] < burst_time[min_index] && !find_element(checked_burst_times, size_of_checked_burst_times, j))
                min_index = j;
        }
        waiting_time[min_index] = wait_time_acc;
        wait_time_acc += burst_time[min_index];
        checked_burst_times[size_of_checked_burst_times++] = min_index;
    }
}

int main()
{
    int burst_time[4] = {21, 3, 6, 2};
    string processes[4] = {"P1", "P2", "P3", "P4"};
    int waiting_time[4] = {0};
    calculate_waiting_time(burst_time, waiting_time);
    cout << "\nWaiting time : ";
    for (int i = 0; i < 4; i++)
    {
        cout << waiting_time[i] << " ";
    }
    return 0;
}