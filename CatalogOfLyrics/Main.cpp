
#include "Includes.h";
#include "Run.h";
#include "FileIO.h";
#include "Func.h";

using namespace std;

BOOL CtrlHandler(DWORD fdwCtrlType);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
	{
		cerr << "\nError! Failed to install control!";
		_getch();
		return 1;
	}

	Run();
	return 0;
}


BOOL CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
	case CTRL_CLOSE_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_SHUTDOWN_EVENT:
	{
		int res = (MessageBoxA(nullptr, "Save data?", "Close solution", MB_YESNO | MB_DEFBUTTON1 | MB_ICONQUESTION));

		switch (res)
		{
		case IDYES:
			Save();
		case IDNO:
			for(size_t i = 0; i < Getlenght(); i++)
				delete[] ElementAt(i);
			break;
		}

		return (TRUE);
	}

	default:
		return FALSE;
	}
}