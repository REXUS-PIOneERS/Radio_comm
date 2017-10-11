#include <iostream>
#include <ctime>
#include <cstdio>
#include "../src/radiocom.h"

using namespace std;
using namespace rfcom;

int main(int argc, char** argv)
{
  //To test CRC encode;
  int length = 16;
  byte1_t* crc_test = (byte1_t*)malloc(length * sizeof(byte1_t));
  srand((unsigned)time(NULL));
  for(int count = 0; count < length; ++count)
    {
      crc_test[count] = (byte1_t)rand() % 0x100;
      //hex can only work with int type. Can not work with char type.
      cout << hex << (int)crc_test[count] << " ";
    }
  cout << endl;
  
  cout << hex << Protocol::crc16Gen(crc_test, length, 0x8005) << endl;
}
