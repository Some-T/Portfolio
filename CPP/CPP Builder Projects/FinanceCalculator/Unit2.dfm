object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'About'
  ClientHeight = 332
  ClientWidth = 311
  Color = clGray
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 270
    Height = 35
    Caption = 'Finance Calculator'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 298
    Height = 50
  end
  object Button1: TButton
    Left = 112
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 0
    OnClick = Button1Click
  end
  object RichEdit1: TRichEdit
    Left = 8
    Top = 80
    Width = 295
    Height = 170
    Color = clGray
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Lines.Strings = (
      'This program was created by Jamie Cropley.'
      ''
      'This program is licensed under '#39'Unlicense'#39
      ''
      'For more information, please refer to http://unlicense.org'
      ''
      'Released under the name only (not as a company): Jamie '
      'Cropley'
      ''
      'E-mail: jamie.cropley@gmail.com'
      ''
      'Website: http://www.jamie.zone'
      ''
      'Github: https://github.com/Some-'
      'T/Portfolio/FinanceCalculator')
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
    Zoom = 100
  end
end
