#include <bits/stdc++.h>
using namespace std;

int main()
{
  string data = "steelseries";
  int windowSize = 4;

  string dataReceived;
  int dataSize = data.size();

  cout << "\nData to be sent: " << data;
  for (int i = 0; i < dataSize; i++)
  {
    string dataSent = data.substr(dataSize - i - 1, dataSize);
    cout << "\n\nData sent: " << dataSent;
    if (i > (windowSize - 1))
    {
      cout << "\nSliding window representation: " << data.substr(0, dataSize - i - 1) + "[" + dataSent.substr(0, windowSize) + "]" + data.substr(dataSize - i + windowSize - 1, dataSize);
      cout << "\nData received and acknowledged: " << data.substr(dataSize - i + (windowSize - 1), dataSize);
    }
    else
    {
      cout << "\nSliding window representation: " << data.substr(0, dataSize - i - 1) + "[" + data.substr(dataSize - i - 1, dataSize) + "]";
    }
  }

  for (int i = 0; i < windowSize; i++)
  {
    cout << "\n\nSliding window representation: "
         << "[" + data.substr(0, windowSize - i) + "]" + data.substr(windowSize - i, dataSize);
    cout << "\nData received and acknowledged: " << data.substr(windowSize - i - 1, dataSize);
  }

  return 0;
}