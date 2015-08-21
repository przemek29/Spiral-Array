// SpiralArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void makeSpiralArray (int lastValue)
{
  if (lastValue <= 0)
  {
    cout << "The value should be greater than \"0\" " << endl;
    return;
  }

  if (lastValue == 1)
  {
    cout << lastValue << endl;
    return;
  }

  int size = 1, 
      centerOfArray,
      factor = 0;

  while (size <= lastValue)
  {
    factor++;
    size = (2 * factor + 1) * (2 * factor + 1);
    centerOfArray = 2 * factor + 1;
  }

  int row, column,
      currentNumber = 1,
      currentCell = 0;

  int *tab = new int[size];

  for(row = 0; row < size; row++)
  {
    tab[row] = 0;
  }

  row = 0;
  column = 0;

  while (currentNumber <= lastValue)
  {
    tab[(row + factor) * centerOfArray + (column + factor)] = currentNumber;

    if( column == currentCell && row == -currentCell)
    {
      column++ ;
      currentCell++ ;
    }
    else
    {
      if(column == currentCell && row < currentCell)
      {
	row++ ;
      }
      else if (row == currentCell && column > -currentCell)
      {
	column--;
      }
      else if(column == -currentCell && row > -currentCell)
      {
	row-- ;
      }
      else if(row == -currentCell && row < currentCell)
      {
 	column++ ;
      }
    }
    currentNumber++ ;
  }

  for(row = 0; row < centerOfArray; row++)
  {
    for (column = 0; column < centerOfArray; column++)
    {
      if (tab[row * centerOfArray + column] != 0)
      {
        cout << setw(4) << tab[row * centerOfArray + column] << " " ;
      }
      else
      {
      cout << "     ";
      }
    }
    cout << endl;
  }
 delete [] tab;
}

int _tmain(int argc, _TCHAR* argv[])
{
  int lastValue;
  do
  {
    cout <<  "Input a last number of spiral array: " ;
    cin >> lastValue;
    makeSpiralArray(lastValue);
  } while (lastValue != 0);
}

