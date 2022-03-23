//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
HINSTANCE MyDLL =LoadLibraryW(L"Project1.dll");
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	PMyGroup MyGroup;
	MyGroup =(PMyGroup)GetProcAddress(MyDLL,"MyGroup");
	Label1->Caption=MyGroup();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{

	PMyName MyName;
	MyName =(PMyName)GetProcAddress(MyDLL,"MyName");
    int length=80;
	wchar_t *a=new wchar_t[length];
	Label1->Caption=MyName(a,length);
}
//---------------------------------------------------------------------------
