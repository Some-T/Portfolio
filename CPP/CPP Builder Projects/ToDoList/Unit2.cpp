//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "string.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
switch(Key)
	{
	case VK_RETURN:
		String taskStore;

		taskStore = Edit1->Text;
		Form1->CheckListBox1->AddItem(taskStore,Edit1);
		Edit1->Clear();
		Form1->CheckListBox1->ScrollWidth = 999999;
		Form2->Close();
		break;
	}
}
//---------------------------------------------------------------------------

