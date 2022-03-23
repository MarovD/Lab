//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
     HINSTANCE MyDLL =LoadLibraryW(L"Project1.dll");
	if(MyDLL==NULL)
	{
	   return 0;
	}
	PMyGroup MyGroup;
	PMyName MyName;
	MyGroup =(PMyGroup)GetProcAddress(MyDLL,"MyGroup");
	MyName =(PMyName)GetProcAddress(MyDLL,"MyName");
	if( MyGroup==NULL || MyName==NULL){
	FreeLibrary(MyDLL);
	return 0;
}
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}


	FreeLibrary(MyDLL);
	return 0;
}
//---------------------------------------------------------------------------
