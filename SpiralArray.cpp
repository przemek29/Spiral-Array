// SpiralArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

void initialConditions(int value)
{
	if (value <= 0)
  {
    cout << "The value should be greater than \"0\" " << endl;
    return;
  }

  if (value == 1)
  {
    cout << value << endl;
    return;
  }
}

int determineSize (int value)
{
	int size = 1,
		factor = 0;
	 
	while (size <= value)
  {
    factor++;
    size = (2 * factor + 1) * (2 * factor + 1);
  }
	return size;
}

int getFactor(int centerOfArray)
{
	return ((centerOfArray - 1) / 2);
}

void printArray (int row, int column, int centerOfArray, int tab[])
{
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
}


void makeSpiralArray (int lastValue)
{
  //initialConditions(lastValue);

   int size = determineSize(lastValue);
   int centerOfArray = sqrt((double) size);
   int factor = getFactor(centerOfArray);

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
  printArray(row,column,centerOfArray,tab);

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

