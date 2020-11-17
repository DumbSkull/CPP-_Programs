#include <bits/stdc++.h>
#include <ctime>
using namespace std;

int main()
{
  srand(time(0));
  string data = "1111010011";
  cout << "\nOriginal data to be sent: " << data;
  int numberOfOnes = 0;
  for (int i = 0; i < data.size(); i++)
  {
    if (data[i] == '1')
      numberOfOnes++;
  }
  string encryptedData = data + (numberOfOnes % 2 == 0 ? '0' : '1');
  cout << "\nAppending the parity bit with the data (data + parity bit): " << encryptedData;

  //make a random change in the encrypted data due to noise:
  cout << "\nSimulating a probable noise... ";
  int ifNoiseOccured = rand() % 2;
  if (ifNoiseOccured == 1)
  {
    int randomIndex = rand() % data.size();
    cout << "\nNoise occured at position " << randomIndex << "!";
    encryptedData[randomIndex] = encryptedData[randomIndex] == '1' ? '0' : '1';
  }
  else
  {
    cout << "\nNo noise occured!";
  }

  cout << "\nChecking the received message for an error...";
  numberOfOnes = 0;
  int parityBit = encryptedData[encryptedData.size() - 1] == '1' ? 1 : 0;
  for (int i = 0; i < encryptedData.size() - 1; i++)
  {
    if (encryptedData[i] == '1')
      numberOfOnes++;
  }
  if (numberOfOnes % 2 == parityBit)
    cout << "\nNo error was detected!";
  else
    cout << "\nAn error was detected!";
  return 0;
}