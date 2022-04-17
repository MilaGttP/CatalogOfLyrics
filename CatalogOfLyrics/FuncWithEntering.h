
#pragma once

#include <iostream>

using std::ostream;
using std::istream;

enum { NAME_SIZE = 60 };
enum { AUTHOR_NAME_SIZE = 40 };
enum { TEXT_SIZE = 1024 };

struct Song
{
	char Name[NAME_SIZE];
	char Author[AUTHOR_NAME_SIZE];
	int Year;
	char Text[TEXT_SIZE] = "";
};

void OutText(Song* pObj);
void OutObject(Song* pObj, size_t num);
Song* AddSongFromConsole();

void Print(ostream& stream, Song* pObj, int wide = 10);
bool Input(istream& stream, Song* pObj);

void Edit(Song* pObj);

typedef bool (Select)(Song* pObj);
void Filter(Select select);