#include <stdio.h>
#include <string.h>
int main()
{
  int i = 0, count = 0;
  //Input the data bits:
  char data[] = "A-ESC-FLAG-B-FLAG-B-E";
  //Print the original data bits:
  printf("Data before bit stuffing: %s", data);
  printf("\nData after bit stuffing: ");
  printf("FLAG-");
  for (i = 0; i < strlen(data); i++)
  {
    if (data[i] == 'E' && data[i + 1] == 'S' && data[i + 2] == 'C')
    {
      printf("ESC-ESC");
      i = i + 2;
    }
    else if (data[i] == 'F' && data[i + 1] == 'L' && data[i + 2] == 'A' && data[i + 3] == 'G')
    {
      printf("ESC-FLAG");
      i = i + 3;
    }
    else if (data[i] != '-')
    {
      printf("%c", data[i]);
    }
    if (data[i] != '-')
      printf("-");
  }
  printf("FLAG");
  return 0;
}
