
#include "Includes.h";
#include "Entering.h";
#include "FuncWithEntering.h";
#include "Func.h";
#include "Input.h";
#include "Commands.h";

using namespace std;

void OutText(Song* pObj)
{
	cout << "\n\tText: \n" << pObj->Text;
}


void OutObject(Song* pObj, size_t num)
{
	cout << left << setw(2) << num << " "
		<< setw(35) << pObj->Name
		<< setw(25) << pObj->Author
		<< setw(5) << pObj->Year << endl;

	cout << setfill('-') << setw(75) << '-' << setfill(' ') << endl;
}


Song* AddSongFromConsole()
{
	system("cls");
	Out();

	Song* p = new Song();

	cout << "\n\tEnter song data: \n";

	cout << "\tName: ";
	cin.getline(p->Name, NAME_SIZE);

	cout << "\tText: \n";
	char* sValue;
	InputMultilineText(cin, sValue);
	strncpy(p->Text, sValue, TEXT_SIZE);

	cout << "\tAuthor: ";
	cin.getline(p->Author, AUTHOR_NAME_SIZE);

	cout << "\tYear: ";
	cin >> p->Year;

	cin.ignore();
	return p;
}


void Edit(Song* pObj)
{
	system("cls");
	char buff[512];
	char* sValue;
	cout << "\n\tEditing song: \n";

	cout << "\tText (" << pObj->Text << "): ";
	InputMultilineText(cin, sValue);
	if (*buff != '\0')
		strncpy(pObj->Text, sValue, TEXT_SIZE);

	cout << "\n\n" << endl;
}


void Filter(Select select)
{
	for (size_t i = 0; i < Getlenght(); i++)
	{
		if (select(ElementAt(i)))
			OutObject(ElementAt(i), i + 1);
	}
}


void Print(ostream& stream, Song* pObj, int wide)
{
	stream << setw(wide) << "Name" << ": " << pObj->Name << "\n"
		<< setw(wide) << "Author" << ": " << pObj->Author << "\n"
		<< setw(wide) << "Year" << ": " << pObj->Year << "\n"
		<< setw(wide) << "Text" << ": " << pObj->Text << "\n";
}


bool Input(istream& stream, Song* pObj) 
{
	char* sValue;

	if (!InputAndPasrseString(stream, sValue))
		return false;

	strncpy(pObj->Name, sValue, NAME_SIZE);
	if (!InputAndPasrseString(stream, sValue))
		return false;

	strncpy(pObj->Author, sValue, AUTHOR_NAME_SIZE);

	InputAndPasrseValue(stream, "%d", &(pObj->Year));

	InputAndParseMultilineText(stream, sValue);
	strncpy(pObj->Text, sValue, TEXT_SIZE);

	return true;
}