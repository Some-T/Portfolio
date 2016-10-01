//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
  OpenTextFileDialog1->Filter = "Text files (*.txt)|*.txt|Any file (*.*)|*.*";
  SaveTextFileDialog1->Filter = "Text files (*.txt)|*.txt|Any file (*.*)|*.*";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{


  if (SaveTextFileDialog1->Execute())

	if (FileExists(OpenTextFileDialog1->FileName))

	  throw(Exception("File already exists. Cannot overwrite."));
	else

	  CheckListBox1->Items->SaveToFile(SaveTextFileDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckListBox1ClickCheck(TObject *Sender)
{
for (int index = CheckListBox1->Items->Count-1; index >= 0; --index)
    {
		if (CheckListBox1->Checked[index])
			CheckListBox1->Items->Delete(index);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{

  if (OpenTextFileDialog1->Execute())

	if (FileExists(OpenTextFileDialog1->FileName))

	  CheckListBox1->Items->LoadFromFile(OpenTextFileDialog1->FileName);
    else

      throw(Exception("File does not exist."));
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button6Click(TObject *Sender)
{
ShowMessage ("This program was created by Jamie Cropley.\n This program is licensed under 'Unlicense'\n For more information, please refer to http://unlicense.org\n Released under the name only (not as a company): Jamie Cropley\n E-mail: jamie.cropley@gmail.com\n Website: http://www.jamie.zone\n Github: https://github.com/Some-T/Portfolio/CPP/CPP Builder Projects/ToDoList");
}
//---------------------------------------------------------------------------






void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{


if (Button4 -> Enabled == False) {
Button4 -> Enabled = True;
}


else if (Button4 -> Enabled == True) {
Button4 -> Enabled = False;
	 }



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
CheckListBox1->Clear();
}
//---------------------------------------------------------------------------





