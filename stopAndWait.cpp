#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(0));
  string data = "steelseries";
  int timeout = 4;

  int dataSize = data.size();
  for (int i = 0; i < dataSize; i++)
  {
    cout << "\n\nSending "
         << data[dataSize - i - 1]
         << " from "
         << data.substr(0, dataSize - i - 1)
         << "[" << data[dataSize - i - 1]
         << "]" << data.substr(dataSize - i, dataSize);

    int randomAckTime = rand() % 6;
    if (randomAckTime < timeout)
    {
      cout << "\nReceived and acknowledged! ";
    }
    else
    {
      int randomLost = rand() % 2;
      if (randomLost == 1)
        cout << "\nAcknowledgement lost!";
      else
        cout << "\nDelayed acknowledgement! ";
      cout << "\nSending again...";
      i--;
    }
  }
  return 0;
}
