
#include "Includes.h"
#include "Input.h"

using namespace std;

char* InputString(istream& stream) 
{
	static char buff[USHRT_MAX];
	stream.getline(buff, sizeof buff);
	return buff;
}


bool InputAndPasrseString(istream& stream, char*& pStr) 
{
	pStr = InputString(stream);
	pStr = strchr(pStr, ':');

	if (pStr == nullptr)
		return false;

	pStr += 2;
	return true;
}


bool InputAndPasrseValue(istream& stream, const char* format, void* ptr) 
{
	char* sValue;

	if (InputAndPasrseString(stream, sValue)) 
	{
		sscanf(sValue, format, ptr);
		return true;
	}

	return false;
}


bool InputAndParseMultilineText(istream& stream, char*& pStr) 
{
	if (!InputAndPasrseString(stream, pStr))
		return false;
	
	static char buff[USHRT_MAX];
	strcpy(buff, pStr);

	while (true) 
	{
		char* pTmp = InputString(stream);

		if (pTmp[0] == '\0')
			break;
		
		strcat(buff, "\n");
		strcat(buff, pTmp);
	}

	pStr = buff;
	return true;
}


void InputMultilineText(istream& stream, char*& pStr) 
{
	static char buff[USHRT_MAX];

	while (true) 
	{
		char* pTmp = InputString(stream);

		if (pTmp[0] == '\0') 
			break;
		
		strcat(buff, "\n");
		strcat(buff, pTmp);
	}

	pStr = buff;
}