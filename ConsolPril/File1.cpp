#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <Project1.h>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	setlocale (LC_ALL, ".866");

	int length=60;
	wchar_t *a=new wchar_t[length];

	wcout << MyName(a,length) << endl;
	wcout <<L"РИ-" << MyGroup() << endl;

	system("pause");
	return 0;
}

