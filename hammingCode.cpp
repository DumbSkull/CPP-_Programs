#include <bits/stdc++.h>
#include <ctime>
using namespace std;

string xorValues(string st, vector<int> positions)
{
  int n = positions.size();
  int sizeOfSt = st.size();
  //0,1,3,7;
  int xorValue = st[sizeOfSt - positions[0]] - '0';
  for (int i = 1; i < n; i++)
  {
    xorValue = xorValue ^ (st[sizeOfSt - positions[i]] - '0');
  }
  return to_string(xorValue);
}

string dataToHammingCode(string data)
{
  data = data + '-' + '-';
  data = data.substr(0, data.size() - 3) + '-' + data.substr(data.size() - 3, data.size());
  data = data.substr(0, data.size() - 7) + '-' + data.substr(data.size() - 7, data.size());
  int size = data.size();
  vector<int> positions{3, 5, 7, 9, 11};
  data = data.substr(0, size - 1) + xorValues(data, positions);
  positions.clear();
  positions = {3, 6, 7, 10, 11};
  data = data.substr(0, size - 2) + xorValues(data, positions) + data.substr(size - 1);
  positions.clear();
  positions = {5, 6, 7};
  data = data.substr(0, size - 4) + xorValues(data, positions) + data.substr(size - 3);
  positions.clear();
  positions = {9, 10, 11};
  data = data.substr(0, size - 8) + xorValues(data, positions) + data.substr(size - 7);
  return data;
}

string checkError(string data)
{
  vector<int> positions{3, 5, 7, 9, 11};
  string errorPosition = xorValues(data, positions);
  positions.clear();
  positions = {3, 6, 7, 10, 11};
  errorPosition = errorPosition + xorValues(data, positions);
  positions.clear();
  positions = {5, 6, 7};
  errorPosition = errorPosition + xorValues(data, positions);
  positions.clear();
  positions = {9, 10, 11};
  errorPosition = errorPosition + xorValues(data, positions);
  return errorPosition;
}

int main()
{
  srand(time(0));
  string data = "1011001";
  cout << "\nOriginal data to be sent: " << data;
  int numberOfOnes = 0;
  for (int i = 0; i < data.size(); i++)
  {
    if (data[i] == '1')
      numberOfOnes++;
  }
  string encryptedData = dataToHammingCode(data);
  cout << "\nAfter adding the parity bits (using Hamming Code's method): " << encryptedData;
  //make a random change in the encrypted data due to noise:
  cout << "\nSimulating a probable noise... ";
  int randomIndex = rand() % encryptedData.size();
  encryptedData[randomIndex] = encryptedData[randomIndex] == '1' ? '0' : '1';
  cout << "\nChecking the received message for the error...";
  string errorPosition = checkError(encryptedData);
  int integerPosition = stoi(errorPosition, 0, 2);
  cout << "\nThe error is at position: " << integerPosition;
  return 0;
}