object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'ToDoList'
  ClientHeight = 491
  ClientWidth = 321
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 38
    Width = 305
    Height = 6
    Style = bsRaised
  end
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 57
    Height = 25
    Caption = 'New Task'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 119
    Top = 8
    Width = 50
    Height = 25
    Caption = 'Save'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 71
    Top = 8
    Width = 42
    Height = 25
    Caption = 'Open'
    TabOrder = 2
    OnClick = Button3Click
  end
  object CheckListBox1: TCheckListBox
    Left = 8
    Top = 50
    Width = 305
    Height = 433
    OnClickCheck = CheckListBox1ClickCheck
    BorderStyle = bsNone
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 25
    ParentFont = False
    TabOrder = 3
  end
  object Button6: TButton
    Left = 175
    Top = 8
    Width = 42
    Height = 25
    Caption = 'About'
    TabOrder = 4
    OnClick = Button6Click
  end
  object Button4: TButton
    Left = 262
    Top = 8
    Width = 51
    Height = 25
    Caption = 'CLEAR'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = Button4Click
  end
  object CheckBox1: TCheckBox
    Left = 242
    Top = 11
    Width = 14
    Height = 17
    TabOrder = 6
    OnClick = CheckBox1Click
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 64
    Top = 56
  end
  object SaveTextFileDialog1: TSaveTextFileDialog
    DefaultExt = '*.txt'
    FileName = 'Untitled'
    Filter = 'Text Documents (*.txt)|*.txt|All Files (*.*)'
    Left = 128
    Top = 56
  end
  object ApplicationEvents1: TApplicationEvents
    OnMinimize = ApplicationEvents1Minimize
    Left = 152
    Top = 256
  end
  object TrayIcon1: TTrayIcon
    OnDblClick = TrayIcon1DblClick
    Left = 200
    Top = 256
  end
end
