//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TDateTimePicker *DateTimePicker1;
	TDateTimePicker *DateTimePicker2;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TLabel *Label5;
	TLabel *Label3;
	TBevel *Bevel1;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Help1;
	TMenuItem *About1;
	TMenuItem *Exit1;
	TLabel *Label4;
	TEdit *Edit2;
	TLabel *Label10;
	TLabel *Label11;
	TEdit *Edit3;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label13;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TBevel *Bevel2;
	TBevel *Bevel3;
	TBevel *Bevel4;
	void __fastcall DateTimePicker2Change(TObject *Sender);
	void __fastcall DateTimePicker1Change(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	double bankStore;
	double outgoingsStore;
	double totalOutgoings;
    int weekStore;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
