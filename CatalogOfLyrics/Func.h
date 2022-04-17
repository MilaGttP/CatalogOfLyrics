
#pragma once

#include "FuncWithEntering.h";

bool Empty();
int Getlenght();
Song* ElementAt(size_t index);

void Print(ostream& stream);

void Add(Song* p);
void AddRange(const Song sourceArr[], size_t size);

void Clear();
void DeleteAt(size_t index);