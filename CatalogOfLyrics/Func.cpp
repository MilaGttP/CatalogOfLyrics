
#include "Includes.h";
#include "Func.h";
#include "Entering.h";
#include "Run.h"

using namespace std;

static Song** arr = nullptr;
static size_t lenght = 0;

bool Empty()
{
	return arr == nullptr;
}


int Getlenght()
{
	return lenght;
}


Song* ElementAt(size_t index) 
{
	return arr[index];
}



void Add(Song* p)
{
	if (Empty())
	{
		arr = new Song * [1];
		arr[0] = p;
	}

	else
	{
		Song** newArr = new Song * [lenght + 1];

		for (size_t i = 0; i < lenght; i++)
			newArr[i] = arr[i];

		newArr[lenght] = p;
		delete[] arr;
		arr = newArr;
	}

	lenght++;
}


void AddRange(const Song sourceArr[], size_t size)
{
	size_t newSize = lenght + size;
	Song** newArr = new Song * [newSize];

	for (size_t i = 0; i < lenght; i++)
		newArr[i] = arr[i];

	for (size_t i = lenght, j = 0; i < newSize; i++, j++)
	{
		newArr[i] = new Song();
		*newArr[i] = sourceArr[j];
	}

	delete[] arr;
	arr = newArr;
	lenght = newSize;
}


void Print(ostream& stream) 
{
	stream << setprecision(12);

	for (size_t i = 0; i < lenght; i++) 
		Print(stream, arr[i]);
	
}


void Clear()
{
	for (size_t i = 0; i < lenght; i++)
		delete arr[i];

	delete[] arr;
	arr = nullptr;
	lenght = 0;
}


void DeleteAt(size_t index)
{
	Song** newArr = new Song * [lenght - 1];

	for (size_t i = 0; i < index; i++)
		newArr[i] = arr[i];

	delete arr[index];

	for (size_t i = index + 1; i < lenght; i++)
		newArr[i - 1] = arr[i];

	delete[] arr;
	arr = newArr;
	lenght--;
}