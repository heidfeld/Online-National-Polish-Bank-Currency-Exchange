///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////  KALKULATOR WALUTOWY - £UKASZ KARMAÑSKI   ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <winsock.h>
#include "String"
#include <tchar.h>
#include "Autor.h"
#pragma comment(lib, "urlmon.lib")

using namespace std;

namespace Kantor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Xml;
	using namespace System::Text;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			timer1->Start();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^				label1;				//////// Aktualna DATA i GODZINA /////
	private: System::Windows::Forms::Timer^				timer1;				//////// TIMER Aktualnej DATY ////////
	private: System::Windows::Forms::ComboBox^			comboBox1;			//////// Pole wyboru Waluty 1 ////////
	private: System::Windows::Forms::ComboBox^			comboBox2;			//////// Pole wyboru Waluty 2 ////////
	private: System::Windows::Forms::Button^			button1;			//////// Przycisk ONLINE /////////////
	private: System::Windows::Forms::Button^			button2;			//////// Przycisk OBLICZ /////////////
	private: System::Windows::Forms::Button^			button3;			//////// Przycisk OFFLINE ////////////
	private: System::Windows::Forms::Button^			button4;			//////// Przycisk Odœwie¿ania ////////
	private: System::Windows::Forms::DateTimePicker^	dateTimePicker1;	//////// Pole Wyboru DATY ////////////
	private: System::Windows::Forms::PictureBox^		pictureBox1;		//////// Flaga Wyœwietlacza 1 ////////
	private: System::Windows::Forms::PictureBox^		pictureBox4;		//////// Flaga Wyœwietlacza 2 ////////
	private: System::Windows::Forms::PictureBox^		pictureBox3;		//////// Flaga Wyœwietlacza 3 ////////
	private: System::Windows::Forms::PictureBox^		pictureBox2;		//////// Flaga Wyœwietlacza 4 ////////		
	private: System::Windows::Forms::PictureBox^		pictureBox6;		//////// Flaga Wyœwietlacza 5 ////////	
	private: System::Windows::Forms::Label^				label2;				//////// Kursy Wyœwietlacza 1 ////////	
	private: System::Windows::Forms::Label^				label3;				//////// Kursy Wyœwietlacza 1 ////////	
	private: System::Windows::Forms::Label^				label4;				//////// Kursy Wyœwietlacza 2 ////////	
	private: System::Windows::Forms::Label^				label5;				//////// Kursy Wyœwietlacza 2 ////////	
	private: System::Windows::Forms::Label^				label6;				//////// Kursy Wyœwietlacza 3 ////////	
	private: System::Windows::Forms::Label^				label7;				//////// Kursy Wyœwietlacza 3 ////////	
	private: System::Windows::Forms::Label^				label8;				//////// Kursy Wyœwietlacza 4 ////////	
	private: System::Windows::Forms::Label^				label9;				//////// Kursy Wyœwietlacza 4 ////////	
	private: System::Windows::Forms::Label^				label10;			//////// Kursy Wyœwietlacza 5 ////////	
	private: System::Windows::Forms::Label^				label11;			//////// Kursy Wyœwietlacza 5 ////////	
	private: System::Windows::Forms::PictureBox^		pictureBox5;		//////// T³o Wyœwietlacza ////////////
	private: System::Windows::Forms::NumericUpDown^		num;				//////// WEJŒCIE NUMERYCZNE //////////
	private: System::Windows::Forms::Label^				label13;			//////// Kwota WYNIKU ////////////////
	private: System::Windows::Forms::Label^				label16;			//////// Waluta WYNIKU ///////////////
	private: System::Windows::Forms::Label^				label14;			//////// Kwota WEJŒCIA ///////////////
	private: System::Windows::Forms::Label^				label15;			//////// Waluta WEJŒCIA //////////////
	private: System::Windows::Forms::PictureBox^		pictureBox7;		//////// Grafika STATUSU /////////////
	private: System::Windows::Forms::Label^				label12;			//////// Tekst STATUSU ///////////////
	private: System::Windows::Forms::TextBox^			info;				//////// Pasek INFORMACYJNY //////////
	private: System::Windows::Forms::MenuStrip^			menuStrip1;			//////// Menu G³owne /////////////////
	private: System::Windows::Forms::PictureBox^		pictureBox8;		//////// LOGO G³ówne Programu ////////
	private: System::Windows::Forms::Button^			button5;			//////// Zmiana Walut Wyœwietlacza ///
	private: System::ComponentModel::IContainer^		components;
	private: System::Windows::Forms::ToolStripMenuItem^  programToolStripMenuItem;		//////// MENU PROGRAM //////////////
	private: System::Windows::Forms::ToolStripMenuItem^  wyjœcieToolStripMenuItem;		//////// MENU Wyjœcie //////////////
	private: System::Windows::Forms::ToolStripMenuItem^  informacjeToolStripMenuItem;	//////// MENU INFORMACJE ///////////
	private: System::Windows::Forms::ToolStripMenuItem^  autorToolStripMenuItem;		//////// MENU Autor ////////////////
	private: System::Windows::Forms::ToolStripMenuItem^  wygladToolStripMenuItem;		//////// MENU WYGL¥D ///////////////
	private: System::Windows::Forms::ToolStripMenuItem^  logoToolStripMenuItem;			//////// MENU Logo /////////////////
	private: System::Windows::Forms::ToolStripMenuItem^  defaultToolStripMenuItem;		//////// MENU Logo Default /////////
	private: System::Windows::Forms::ToolStripMenuItem^  zimoweToolStripMenuItem;		//////// MENU Logo Zimowe //////////
	private: System::Windows::Forms::ToolStripMenuItem^  dataToolStripMenuItem;			//////// MENU Data /////////////////
	private: System::Windows::Forms::ToolStripMenuItem^  onOffToolStripMenuItem;		//////// MENU Data On/Off //////////
	private: System::Windows::Forms::ToolStripMenuItem^  t³oToolStripMenuItem;			//////// MENU T³o //////////////////
	private: System::Windows::Forms::ToolStripMenuItem^  zielonyCiemnyToolStripMenuItem;//////// MENU T³o Zielone Ciemne ///
	private: System::Windows::Forms::ToolStripMenuItem^  niebieskiToolStripMenuItem;	//////// MENU T³o Niebieskie ///////
	private: System::Windows::Forms::ToolStripMenuItem^  czerwonyToolStripMenuItem;		//////// MENU T³o Czerwone /////////
	private: System::Windows::Forms::ToolStripMenuItem^  pomarañczowyToolStripMenuItem;	//////// MENU T³o Pomarañczowe /////
	private: System::Windows::Forms::ToolStripMenuItem^  ¿ó³tyToolStripMenuItem;		//////// MENU T³o ¯ó³te ////////////
	private: System::Windows::Forms::ToolStripMenuItem^  deafultToolStripMenuItem;		//////// MENU T³o Default //////////

	private:
		static ArrayList ^curr = gcnew ArrayList();					//////// Lista przechowuj¹ca KURSY ŒREDNIE /////////////
		static ArrayList ^sell_curr = gcnew ArrayList();			//////// Lista przechowuj¹ca KURSY SPRZEDA¯Y ///////////
		static ArrayList ^buy_curr = gcnew ArrayList();				//////// Lista przechowuj¹ca KURSY KUPNA ///////////////
		static ArrayList ^name1 = gcnew ArrayList();				//////// Lista przechowuj¹ca NAZWY WALUT ///////////////
		static ArrayList ^name2 = gcnew ArrayList();				//////// Lista przechowuj¹ca NAZWY WALUT ///////////////
		static ArrayList ^symbols = gcnew ArrayList();				//////// Lista przechowuj¹ca SYMBOLE WALUT /////////////
		static ArrayList ^wsp = gcnew ArrayList();					//////// Lista przechowuj¹ca WSPÓ£CZYNNIKI WALUT ///////
		static ArrayList ^temp1 = gcnew ArrayList();				//////// Lista przechowuj¹ca CHWILOWE WARTOŒCI XML-a ///
		static ArrayList ^temp2 = gcnew ArrayList();				//////// Lista przechowuj¹ca CHWILOWE WARTOŒCI XML-a ///
		static ArrayList ^nbp_txt = gcnew ArrayList();				//////// Lista przechowuj¹ca Linie z pliku dir.txt /////
		static int loc_pos_x = 3;									//////// Zmienna przesuwaj¹ca oœ X o sta³¹ /////////////
		static int loc_pos_y = 2;									//////// Zmienna przesuwaj¹ca oœ Y o sta³¹ /////////////
	private: System::Windows::Forms::Label^  label17;
			 static int val=0;											//////// Zmienna do obs³ugi zmian wyœwietlacza /////////

#pragma region Windows Form Designer generated code

		void ClearItems()		///////// FUNKCJA CZYSZCZ¥CA WSZYSTKIE LISTY ORAZ  PRZYWRACAJ¥CA WARTOŒCI DOMYŒLNE /////////
		{
			name1->Clear();
			name2->Clear();
			symbols->Clear();
			wsp->Clear();
			curr->Clear();
			buy_curr->Clear();
			sell_curr->Clear();
			temp1->Clear();
			temp2->Clear();

			this->comboBox1->DataSource=nullptr;
			this->comboBox1->Items->Clear();
			this->comboBox1->SelectedItem=-1;

			this->comboBox2->DataSource=nullptr;
			this->comboBox2->Items->Clear();
			this->comboBox2->SelectedItem=-1;

			this->button4->Enabled=false;
			this->button2->Enabled=true;
			this->comboBox1->Enabled=true;
			this->comboBox2->Enabled=true;

			this->label17->Visible=false;
			this->label13->Text="0,00";
		}
										////////// FUNKCJA PRZESZUKUJ¥CA PLIK dir.TXT ///////////
		int Dir_Search(){
			String ^date_day, ^date_month, ^date_year, ^date_year2, ^path;
			ArrayList ^temp3 = gcnew ArrayList();
			temp3 = nbp_txt;
			int found=-1, how=0;		///////// Found sprawdza czy data zosta³a ju¿ odnaleziona i na jakiej pozycji, How kontroluje, aby pêtla siê nie zapêtli³a ////////
			while (found == -1 && how<8){
			if (this->dateTimePicker1->Value.Day < 10)
				date_day="0"+this->dateTimePicker1->Value.Day.ToString();
			else
				date_day=this->dateTimePicker1->Value.Day.ToString();
			if (this->dateTimePicker1->Value.Month < 10)
				date_month="0"+this->dateTimePicker1->Value.Month.ToString();
			else
				date_month=this->dateTimePicker1->Value.Month.ToString();
			date_year2=this->dateTimePicker1->Value.Year.ToString();
			date_year=(this->dateTimePicker1->Value.Year.ToString())->Substring(2,2);
			path=date_year+date_month+date_day;
			for (int i=0; i<Convert::ToInt32(temp3->Count) ; i++)
			{
				if(Convert::ToString(temp3[i])->Substring(5,6)==path)
					found = i;
			}
			if (found == -1){
				System::TimeSpan *diff_limit = new TimeSpan(1, 0, 0, 0, 0);
				this->dateTimePicker1->Value = dateTimePicker1->Value.Subtract(*diff_limit);
				how++;
			}
			}
			if (how>0){
				this->info->Text="W bazie NBP nie ma kursów z tego dnia ! Przekierowanie na "+date_day+"."+date_month+"."+date_year+" !";
				this->dateTimePicker1->Value = System::DateTime(Convert::ToInt16(date_year2), Convert::ToInt16(date_month), Convert::ToInt16(date_day), 0, 0, 0, 0);
			}
			else
				this->info->Text="Pobrano kursy z bazy NBP z dnia: "+date_day+"."+date_month+"."+date_year2+" !";
			return found;
		}
									/////////// Funkcja odczytuj¹ca plik dir.txt z witryny NBP ////////////////
		void ReaderNBP_TXT(){
			nbp_txt->Clear();
			HRESULT hres = URLDownloadToFile(NULL, _T("http://www.nbp.pl/kursy/xml/dir.txt"), _T("dir.txt"), 0, NULL);
			try{
				String^ fileName = "dir.txt";
				StreamReader^ din2 = File::OpenText(fileName);
				String ^line_read;
				while ((line_read = din2->ReadLine()) != nullptr)  {
					if (line_read->Substring(0,1)=="a")
						nbp_txt->Add(line_read);
				}
			}
			catch (System::Exception^ e)
				 {
					 this->label12->Text = "online";
						this->pictureBox7->ImageLocation="img/status_404.png";
					 this->info->Text = "Nie mo¿na pobraæ pliku dir.txt z www.nbp.pl..";
				 }
		}
										/////////// Funkcja Odczytuj¹ca Kursy z NBP /////////////
		void ReaderXXML(){
			ClearItems();
			ReaderNBP_TXT();
			int iter = Dir_Search(); // nbp_txt[iter] = szukana sciezka do pliku 
			String^ filepath;
			if (iter > -1){
				filepath = "http://www.nbp.pl/kursy/xml/"+Convert::ToString(nbp_txt[iter])+".xml";
			}
			else{
				filepath = "http://www.nbp.pl/kursy/xml/a005z150109.xml";
				this->info->Text="Nie kursów z tego dnia w bazie NBP, przekierowano na: 09.01.15 !";
				this->dateTimePicker1->Value = System::DateTime(2015, 1, 9, 0, 0, 0, 0);
			}
			this->label12->Text = "online";
			this->pictureBox7->ImageLocation="img/status_ok.png";
			this->label12->ForeColor = System::Drawing::Color::Green;
			XmlTextReader ^xml_reader = gcnew XmlTextReader(filepath);
			while(xml_reader->Read()){
				switch(xml_reader->NodeType)
				{
							case XmlNodeType::Element: // Szczytywanie Kategorii <>
								if (xml_reader->Name != "pozycja" && xml_reader->Name !="tabela_kursow")
									temp2->Add(xml_reader->Name);
								break;
							case XmlNodeType::Text: // Sczytywanie Wartoœci w Kategoriach
									temp1->Add(xml_reader->Value);
								break;
				}
		}
			for (int i=0 ; i<Convert::ToInt32(temp2->Count) ; i++)
				{
					if (Convert::ToString(temp2[i]) == "nazwa_kraju" || Convert::ToString(temp2[i]) == "nazwa_waluty")
					{
						name1->Add(Convert::ToString(temp1[i]));
						name2->Add(Convert::ToString(temp1[i]));
					}
					if (Convert::ToString(temp2[i]) == "kod_waluty")
					{
						symbols->Add(Convert::ToString(temp1[i]));
					}
					if (Convert::ToString(temp2[i]) == "przelicznik")
					{
						wsp->Add(Convert::ToString(temp1[i]));
					}
					if (Convert::ToString(temp2[i]) == "kurs_sredni")
					{
						curr->Add(Convert::ToString(temp1[i]));
						buy_curr->Add(Convert::ToString(0.97*(Convert::ToDouble(Convert::ToString(temp1[i])))));
						sell_curr->Add(Convert::ToString(1.03*(Convert::ToDouble(Convert::ToString(temp1[i])))));
					}
				}
			name1->Add("zloty polski");
			name2->Add("zloty polski");
			symbols->Add("PLN");
			wsp->Add("1");
			curr->Add("1");
			buy_curr->Add("1");
			sell_curr->Add("1");
			this->comboBox1->DataSource = name1;
			this->comboBox2->DataSource = name2;
			Indicator();
			xml_reader->Close();
		}
									///////////// Wyœwietlanie Kursów oraz Flag na Wyœwietlaczu //////////////////
			void Indicator(){
			this->button5->Enabled=true;
			int i1,i2,i3,i4,i5,erro=0;
			String ^s1,^s2,^s3,^s4,^s5;
			if (val % 3 == 0){
				s1="EOR"; s2="GBP"; s3="USD"; s4="CHF"; s5="CZK";
			}
			if (val % 3 == 1){
				s1="UAH"; s2="NOK"; s3="HRK"; s4="RUB"; s5="BGN";
			}
			if (val % 3 == 2){
				s1="SEK"; s2="DKK"; s3="JPY"; s4="AUD"; s5="CAD";
			}
			while ((i1==NULL || i2==NULL || i3==NULL || i4==NULL || i5==NULL) && erro<2){
			for (int j=0 ; j<Convert::ToInt32(symbols->Count) ; j++)
			{
				if (Convert::ToString(symbols[j]) == s1) {i1=j;}
				if (Convert::ToString(symbols[j]) == s2) {i2=j;}
				if (Convert::ToString(symbols[j]) == s3) {i3=j;}
				if (Convert::ToString(symbols[j]) == s4) {i4=j;}
				if (Convert::ToString(symbols[j]) == s5) {i5=j;}
			}
			if(i1==NULL) {s1="EUR";}
			if(i2==NULL) {s2="GBP";}
			if(i3==NULL) {s3="USD";}
			if(i4==NULL) {s4="CHF";}
			if(i5==NULL) {s5="CZK";}
			erro++;
			}

			this->label2->Text = Convert::ToString(buy_curr[i1]);
			this->label3->Text = Convert::ToString(sell_curr[i1]);
			this->label4->Text = Convert::ToString(buy_curr[i2]);
			this->label5->Text = Convert::ToString(sell_curr[i2]);
			this->label6->Text = Convert::ToString(buy_curr[i3]);
			this->label7->Text = Convert::ToString(sell_curr[i3]);
			this->label8->Text = Convert::ToString(buy_curr[i4]);
			this->label9->Text = Convert::ToString(sell_curr[i4]);
			this->label10->Text = Convert::ToString(buy_curr[i5]);
			this->label11->Text = Convert::ToString(sell_curr[i5]);
			this->pictureBox1->ImageLocation="img/"+s1+".png";
			this->pictureBox4->ImageLocation="img/"+s2+".png";
			this->pictureBox3->ImageLocation="img/"+s3+".png";
			this->pictureBox2->ImageLocation="img/"+s4+".png";
			this->pictureBox6->ImageLocation="img/"+s5+".png";

		}
										////////////// Odczyt z pliku tekstowego ///////////////
		void TextFile(){
			ClearItems();
			try{
			String^ fileName = "kursy_"+this->dateTimePicker1->Value.Day.ToString()+"_"+this->dateTimePicker1->Value.Month.ToString()+"_"+this->dateTimePicker1->Value.Year.ToString()+".txt";
			StreamReader^ din = File::OpenText(fileName);
			String ^line_read;
			while ((line_read = din->ReadLine()) != nullptr)  {
				this->pictureBox7->ImageLocation="img/status_txt.png";
				this->label12->Text="offline";
				this->label12->ForeColor = System::Drawing::Color::Red;
					if (line_read->Substring(0,5) != "KURSY" && line_read->Substring(0,5) != "SKROT")
					{
						name1->Add(line_read->Split('	')[5]);
						name2->Add(line_read->Split('	')[5]);
						curr->Add(line_read->Split('	')[2]);
						sell_curr->Add(line_read->Split('	')[4]);
						buy_curr->Add(line_read->Split('	')[3]);
						symbols->Add(line_read->Split('	')[0]);
						wsp->Add(line_read->Split('	')[1]);
						Indicator();
					}
					}
					this->comboBox1->DataSource = name1;
					this->comboBox2->DataSource = name2;
					this->info->Text = "TRYB OFFLINE: Odczyt kursów z pliku z dnia: "+this->dateTimePicker1->Value.Day.ToString()+"."+this->dateTimePicker1->Value.Month.ToString()+"."+this->dateTimePicker1->Value.Year.ToString()+" !";
					}
					catch (Exception^ er){
					if (dynamic_cast<FileNotFoundException^>(er)){
						this->label12->Text = "offline";
						this->pictureBox7->ImageLocation="img/status_404.png";
						this->info->Text = "TRYB OFFLINE: Nie odczytano kursów - Brak Pliku !";
						this->button2->Enabled=false;
						this->comboBox1->Enabled=false;
						this->comboBox2->Enabled=false;
						this->label13->Text="0,00";
						this->label17->Visible=false;
					}
					else{
					this->info->Text = "TRYB OFFLINE: Nie odczytano kursów - B³¹d wczytywania Pliku !";
					this->label12->Text = "offline";
					this->pictureBox7->ImageLocation="img/status_404.png";
					this->button2->Enabled=false;
					this->comboBox1->Enabled=false;
					this->comboBox2->Enabled=false;
					this->label13->Text="0,00";
					this->label17->Visible=false;
					}
							}
		}
		void Calc()
		{
				Double Result;
				Result = Convert::ToDouble(this->num->Value) * Convert::ToDouble(buy_curr[(this->comboBox1->SelectedIndex)]) / Convert::ToDouble(wsp[(this->comboBox1->SelectedIndex)]) / Convert::ToDouble(sell_curr[(this->comboBox2->SelectedIndex)]) * Convert::ToDouble(wsp[(this->comboBox2->SelectedIndex)]);
				if (Result>9999999){
				this->label13->Text=Convert::ToString(Math::Round((Result/1000),2));
				this->label17->Visible=true;
				}
				else{
					this->label13->Text=Convert::ToString(Math::Round(Result,2));
					this->label17->Visible=false;
				}
		}
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->num = (gcnew System::Windows::Forms::NumericUpDown());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->info = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->programToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wyjœcieToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->informacjeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->autorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wygladToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->logoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->defaultToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zimoweToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->onOffToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->t³oToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deafultToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zielonyCiemnyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->niebieskiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->czerwonyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pomarañczowyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->¿ó³tyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->num))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label1->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(537, 0);
			this->label1->Name = L"label1";
			this->label1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label1->Size = System::Drawing::Size(145, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"xx.xx.xxxx xx:xx:xx";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// comboBox1
			// 
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Enabled = false;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(329, 131);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(161, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->Enabled = false;
			this->comboBox2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(329, 170);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(161, 21);
			this->comboBox2->TabIndex = 5;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Location = System::Drawing::Point(329, 85);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 31);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Kursy ONLINE";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dateTimePicker1->Location = System::Drawing::Point(515, 131);
			this->dateTimePicker1->MinDate = System::DateTime(2002, 1, 2, 0, 0, 0, 0);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(139, 20);
			this->dateTimePicker1->TabIndex = 8;
			this->dateTimePicker1->Value = System::DateTime(2015, 1, 6, 0, 0, 0, 0);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(31, 170);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(85, 42);
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(31, 314);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(85, 42);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(31, 266);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(85, 42);
			this->pictureBox3->TabIndex = 14;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(31, 218);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(85, 42);
			this->pictureBox4->TabIndex = 15;
			this->pictureBox4->TabStop = false;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label2->Location = System::Drawing::Point(122, 181);
			this->label2->MaximumSize = System::Drawing::Size(63, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 19);
			this->label2->TabIndex = 16;
			this->label2->Text = L"0,0000";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->MouseEnter += gcnew System::EventHandler(this, &MyForm::label2_MouseEnter);
			this->label2->MouseLeave += gcnew System::EventHandler(this, &MyForm::label2_MouseLeave);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Black;
			this->label3->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(191, 181);
			this->label3->MaximumSize = System::Drawing::Size(63, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 19);
			this->label3->TabIndex = 17;
			this->label3->Text = L"0,0000";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->MouseEnter += gcnew System::EventHandler(this, &MyForm::label3_MouseEnter);
			this->label3->MouseLeave += gcnew System::EventHandler(this, &MyForm::label3_MouseLeave);
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label4->Location = System::Drawing::Point(122, 229);
			this->label4->MaximumSize = System::Drawing::Size(63, 19);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 19);
			this->label4->TabIndex = 18;
			this->label4->Text = L"0,0000";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->MouseEnter += gcnew System::EventHandler(this, &MyForm::label4_MouseEnter);
			this->label4->MouseLeave += gcnew System::EventHandler(this, &MyForm::label4_MouseLeave);
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label5->Location = System::Drawing::Point(191, 229);
			this->label5->MaximumSize = System::Drawing::Size(63, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 19);
			this->label5->TabIndex = 19;
			this->label5->Text = L"0,0000";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label5->MouseEnter += gcnew System::EventHandler(this, &MyForm::label5_MouseEnter);
			this->label5->MouseLeave += gcnew System::EventHandler(this, &MyForm::label5_MouseLeave);
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label6->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label6->Location = System::Drawing::Point(122, 277);
			this->label6->MaximumSize = System::Drawing::Size(63, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(63, 19);
			this->label6->TabIndex = 20;
			this->label6->Text = L"0,0000";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label6->MouseEnter += gcnew System::EventHandler(this, &MyForm::label6_MouseEnter);
			this->label6->MouseLeave += gcnew System::EventHandler(this, &MyForm::label6_MouseLeave);
			// 
			// label7
			// 
			this->label7->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label7->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label7->Location = System::Drawing::Point(191, 277);
			this->label7->MaximumSize = System::Drawing::Size(63, 19);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 19);
			this->label7->TabIndex = 21;
			this->label7->Text = L"0,0000";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label7->MouseEnter += gcnew System::EventHandler(this, &MyForm::label7_MouseEnter);
			this->label7->MouseLeave += gcnew System::EventHandler(this, &MyForm::label7_MouseLeave);
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label8->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label8->Location = System::Drawing::Point(122, 325);
			this->label8->MaximumSize = System::Drawing::Size(63, 19);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(63, 19);
			this->label8->TabIndex = 22;
			this->label8->Text = L"0,0000";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label8->MouseEnter += gcnew System::EventHandler(this, &MyForm::label8_MouseEnter);
			this->label8->MouseLeave += gcnew System::EventHandler(this, &MyForm::label8_MouseLeave);
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label9->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label9->Location = System::Drawing::Point(191, 325);
			this->label9->MaximumSize = System::Drawing::Size(63, 19);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(63, 19);
			this->label9->TabIndex = 23;
			this->label9->Text = L"0,0000";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label9->MouseEnter += gcnew System::EventHandler(this, &MyForm::label9_MouseEnter);
			this->label9->MouseLeave += gcnew System::EventHandler(this, &MyForm::label9_MouseLeave);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(-13, 149);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(310, 313);
			this->pictureBox5->TabIndex = 24;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(31, 362);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(85, 41);
			this->pictureBox6->TabIndex = 25;
			this->pictureBox6->TabStop = false;
			// 
			// label10
			// 
			this->label10->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label10->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label10->Location = System::Drawing::Point(191, 371);
			this->label10->MaximumSize = System::Drawing::Size(63, 19);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(63, 19);
			this->label10->TabIndex = 27;
			this->label10->Text = L"0,0000";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label10->MouseEnter += gcnew System::EventHandler(this, &MyForm::label10_MouseEnter);
			this->label10->MouseLeave += gcnew System::EventHandler(this, &MyForm::label10_MouseLeave);
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label11->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label11->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label11->Location = System::Drawing::Point(122, 371);
			this->label11->MaximumSize = System::Drawing::Size(63, 19);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(63, 19);
			this->label11->TabIndex = 26;
			this->label11->Text = L"0,0000";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label11->MouseEnter += gcnew System::EventHandler(this, &MyForm::label11_MouseEnter);
			this->label11->MouseLeave += gcnew System::EventHandler(this, &MyForm::label11_MouseLeave);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(515, 170);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 72);
			this->button2->TabIndex = 28;
			this->button2->Text = L"Oblicz";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::White;
			this->label12->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(589, 290);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(69, 23);
			this->label12->TabIndex = 29;
			this->label12->Text = L"status";
			// 
			// num
			// 
			this->num->Cursor = System::Windows::Forms::Cursors::Hand;
			this->num->DecimalPlaces = 2;
			this->num->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->num->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->num->Location = System::Drawing::Point(326, 213);
			this->num->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1569325055, 23283064, 0, 0});
			this->num->Name = L"num";
			this->num->Size = System::Drawing::Size(164, 29);
			this->num->TabIndex = 30;
			this->num->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->num->ValueChanged += gcnew System::EventHandler(this, &MyForm::num_ValueChanged);
			// 
			// label13
			// 
			this->label13->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label13->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label13->Location = System::Drawing::Point(324, 359);
			this->label13->MinimumSize = System::Drawing::Size(170, 33);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(170, 33);
			this->label13->TabIndex = 6;
			this->label13->Text = L"0,00";
			this->label13->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label14
			// 
			this->label14->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label14->Font = (gcnew System::Drawing::Font(L"Tahoma", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label14->Location = System::Drawing::Point(324, 277);
			this->label14->MinimumSize = System::Drawing::Size(170, 33);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(170, 33);
			this->label14->TabIndex = 32;
			this->label14->Text = L"0,00";
			this->label14->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label15->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label15->Location = System::Drawing::Point(501, 283);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(48, 25);
			this->label15->TabIndex = 33;
			this->label15->Text = L"PLN";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label16->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label16->Location = System::Drawing::Point(501, 365);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(48, 25);
			this->label16->TabIndex = 34;
			this->label16->Text = L"PLN";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Location = System::Drawing::Point(515, 85);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(134, 31);
			this->button3->TabIndex = 35;
			this->button3->Text = L"Kursy OFFLINE";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(570, 277);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(112, 127);
			this->pictureBox7->TabIndex = 36;
			this->pictureBox7->TabStop = false;
			// 
			// info
			// 
			this->info->Cursor = System::Windows::Forms::Cursors::No;
			this->info->Location = System::Drawing::Point(303, 427);
			this->info->Name = L"info";
			this->info->ReadOnly = true;
			this->info->Size = System::Drawing::Size(379, 20);
			this->info->TabIndex = 37;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->programToolStripMenuItem, 
				this->informacjeToolStripMenuItem, this->wygladToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(694, 24);
			this->menuStrip1->TabIndex = 39;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// programToolStripMenuItem
			// 
			this->programToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->wyjœcieToolStripMenuItem});
			this->programToolStripMenuItem->Name = L"programToolStripMenuItem";
			this->programToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->programToolStripMenuItem->Text = L"Program";
			// 
			// wyjœcieToolStripMenuItem
			// 
			this->wyjœcieToolStripMenuItem->Name = L"wyjœcieToolStripMenuItem";
			this->wyjœcieToolStripMenuItem->Size = System::Drawing::Size(114, 22);
			this->wyjœcieToolStripMenuItem->Text = L"Wyjœcie";
			this->wyjœcieToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::wyjœcieToolStripMenuItem_Click);
			// 
			// informacjeToolStripMenuItem
			// 
			this->informacjeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->autorToolStripMenuItem});
			this->informacjeToolStripMenuItem->Name = L"informacjeToolStripMenuItem";
			this->informacjeToolStripMenuItem->Size = System::Drawing::Size(76, 20);
			this->informacjeToolStripMenuItem->Text = L"Informacje";
			// 
			// autorToolStripMenuItem
			// 
			this->autorToolStripMenuItem->Name = L"autorToolStripMenuItem";
			this->autorToolStripMenuItem->Size = System::Drawing::Size(104, 22);
			this->autorToolStripMenuItem->Text = L"Autor";
			this->autorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::autorToolStripMenuItem_Click);
			// 
			// wygladToolStripMenuItem
			// 
			this->wygladToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->logoToolStripMenuItem, 
				this->dataToolStripMenuItem, this->t³oToolStripMenuItem});
			this->wygladToolStripMenuItem->Name = L"wygladToolStripMenuItem";
			this->wygladToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->wygladToolStripMenuItem->Text = L"Wyglad";
			// 
			// logoToolStripMenuItem
			// 
			this->logoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->defaultToolStripMenuItem, 
				this->zimoweToolStripMenuItem});
			this->logoToolStripMenuItem->Name = L"logoToolStripMenuItem";
			this->logoToolStripMenuItem->Size = System::Drawing::Size(101, 22);
			this->logoToolStripMenuItem->Text = L"Logo";
			// 
			// defaultToolStripMenuItem
			// 
			this->defaultToolStripMenuItem->Name = L"defaultToolStripMenuItem";
			this->defaultToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->defaultToolStripMenuItem->Text = L"Default";
			this->defaultToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::defaultToolStripMenuItem_Click);
			// 
			// zimoweToolStripMenuItem
			// 
			this->zimoweToolStripMenuItem->Name = L"zimoweToolStripMenuItem";
			this->zimoweToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->zimoweToolStripMenuItem->Text = L"Zimowe";
			this->zimoweToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::zimoweToolStripMenuItem_Click);
			// 
			// dataToolStripMenuItem
			// 
			this->dataToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->onOffToolStripMenuItem});
			this->dataToolStripMenuItem->Name = L"dataToolStripMenuItem";
			this->dataToolStripMenuItem->Size = System::Drawing::Size(101, 22);
			this->dataToolStripMenuItem->Text = L"Data";
			// 
			// onOffToolStripMenuItem
			// 
			this->onOffToolStripMenuItem->Name = L"onOffToolStripMenuItem";
			this->onOffToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->onOffToolStripMenuItem->Text = L"On/Off";
			this->onOffToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::onOffToolStripMenuItem_Click);
			// 
			// t³oToolStripMenuItem
			// 
			this->t³oToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->deafultToolStripMenuItem, 
				this->zielonyCiemnyToolStripMenuItem, this->niebieskiToolStripMenuItem, this->czerwonyToolStripMenuItem, this->pomarañczowyToolStripMenuItem, 
				this->¿ó³tyToolStripMenuItem});
			this->t³oToolStripMenuItem->Name = L"t³oToolStripMenuItem";
			this->t³oToolStripMenuItem->Size = System::Drawing::Size(101, 22);
			this->t³oToolStripMenuItem->Text = L"T³o";
			// 
			// deafultToolStripMenuItem
			// 
			this->deafultToolStripMenuItem->Name = L"deafultToolStripMenuItem";
			this->deafultToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->deafultToolStripMenuItem->Text = L"Deafult";
			this->deafultToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deafultToolStripMenuItem_Click);
			// 
			// zielonyCiemnyToolStripMenuItem
			// 
			this->zielonyCiemnyToolStripMenuItem->Name = L"zielonyCiemnyToolStripMenuItem";
			this->zielonyCiemnyToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->zielonyCiemnyToolStripMenuItem->Text = L"Zielony Ciemny";
			this->zielonyCiemnyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::zielonyCiemnyToolStripMenuItem_Click);
			// 
			// niebieskiToolStripMenuItem
			// 
			this->niebieskiToolStripMenuItem->Name = L"niebieskiToolStripMenuItem";
			this->niebieskiToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->niebieskiToolStripMenuItem->Text = L"Niebieski";
			this->niebieskiToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::niebieskiToolStripMenuItem_Click);
			// 
			// czerwonyToolStripMenuItem
			// 
			this->czerwonyToolStripMenuItem->Name = L"czerwonyToolStripMenuItem";
			this->czerwonyToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->czerwonyToolStripMenuItem->Text = L"Czerwony";
			this->czerwonyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::czerwonyToolStripMenuItem_Click);
			// 
			// pomarañczowyToolStripMenuItem
			// 
			this->pomarañczowyToolStripMenuItem->Name = L"pomarañczowyToolStripMenuItem";
			this->pomarañczowyToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->pomarañczowyToolStripMenuItem->Text = L"Pomarañczowy";
			this->pomarañczowyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::pomarañczowyToolStripMenuItem_Click);
			// 
			// ¿ó³tyToolStripMenuItem
			// 
			this->¿ó³tyToolStripMenuItem->Name = L"¿ó³tyToolStripMenuItem";
			this->¿ó³tyToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->¿ó³tyToolStripMenuItem->Text = L"¯ó³ty";
			this->¿ó³tyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::¿ó³tyToolStripMenuItem_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(456, 85);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(34, 31);
			this->button4->TabIndex = 40;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(12, 27);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(285, 124);
			this->pictureBox8->TabIndex = 41;
			this->pictureBox8->TabStop = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::Control;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(274, 157);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(23, 247);
			this->button5->TabIndex = 42;
			this->button5->Text = L">";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label17
			// 
			this->label17->Cursor = System::Windows::Forms::Cursors::Cross;
			this->label17->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label17->Location = System::Drawing::Point(324, 392);
			this->label17->MinimumSize = System::Drawing::Size(170, 33);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(170, 33);
			this->label17->TabIndex = 43;
			this->label17->Text = L"x 1000";
			this->label17->TextAlign = System::Drawing::ContentAlignment::TopRight;
			this->label17->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(694, 459);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->info);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->num);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"KALKULATOR WALUT v1.0.15";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->num))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 DateTime datetime = DateTime::Now;
				 this->label1->Text=datetime.ToString();
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e){
				this->info->Text="Nawiazywanie polaczenia z internetem...";	
				 if (!system("ping www.nbp.pl -n 2")){
					ReaderXXML();
				 }
				else
				{
				this->info->Text="Nie uda³o siê po³¹czyæ z internetem...";
				this->button4->Enabled=true;
				this->label12->Text = "offline";
				this->pictureBox7->ImageLocation="img/status_bad.png";
				this->button2->Enabled=false;
				this->comboBox1->Enabled=false;
				this->comboBox2->Enabled=false;
				this->num->Value==0;
				this->label13->Text="0,00";
				this->label17->Visible=false;
				}
			}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->comboBox1->SelectedIndex==-1 || this->comboBox2->SelectedIndex==-1)
				 this->info->Text="Wybierz walutê !";
			 else{
				 this->info->Text="Obliczenia przebieg³y pomyœlnie.";
				 Calc();
			 }
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->comboBox1->DataSource != nullptr)
			 this->label15->Text=Convert::ToString(symbols[(this->comboBox1->SelectedIndex)]);
		 }
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (this->comboBox2->DataSource != nullptr)
			 this->label16->Text=Convert::ToString(symbols[(this->comboBox2->SelectedIndex)]);
		 }
private: System::Void num_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->label14->Text=Convert::ToString(Math::Round(this->num->Value,2));
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 TextFile();
		 }
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			this->dateTimePicker1->Value = System::DateTime::Now;
			this->dateTimePicker1->MaxDate = System::DateTime::Now;
		 }
private: System::Void label2_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			 this->label2->MaximumSize = System::Drawing::Size(70, 23); this->label2->Size = System::Drawing::Size(70, 23);
			 this->label2->Location = System::Drawing::Point(122-loc_pos_x, 181-loc_pos_y);
		 }
private: System::Void label2_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			this->label2->MaximumSize = System::Drawing::Size(63, 19); this->label2->Size = System::Drawing::Size(63, 19);
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(122, 181);		
		 }
private: System::Void label3_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			 this->label3->MaximumSize = System::Drawing::Size(70, 23); this->label3->Size = System::Drawing::Size(70, 23);
			 this->label3->Location = System::Drawing::Point(191-loc_pos_x, 181-loc_pos_y);
		 }
private: System::Void label3_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			this->label3->MaximumSize = System::Drawing::Size(63, 19); this->label3->Size = System::Drawing::Size(63, 19);
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(191, 181);		
		 }
private: System::Void label4_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			 this->label4->MaximumSize = System::Drawing::Size(70, 23); this->label4->Size = System::Drawing::Size(70, 23);
			 this->label4->Location = System::Drawing::Point(122-loc_pos_x, 229-loc_pos_y);
		 }
private: System::Void label4_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			this->label4->MaximumSize = System::Drawing::Size(63, 19); this->label4->Size = System::Drawing::Size(63, 19);
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(122, 229);		
		 }
private: System::Void label5_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			 this->label5->MaximumSize = System::Drawing::Size(70, 23); this->label5->Size = System::Drawing::Size(70, 23);
			 this->label5->Location = System::Drawing::Point(191-loc_pos_x, 229-loc_pos_y);
		 }
private: System::Void label5_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			this->label5->MaximumSize = System::Drawing::Size(63, 19); this->label5->Size = System::Drawing::Size(63, 19);
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(191, 229);		
		 }
private: System::Void label6_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 this->label6->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			 this->label6->MaximumSize = System::Drawing::Size(70, 23); this->label6->Size = System::Drawing::Size(70, 23);
			 this->label6->Location = System::Drawing::Point(122-loc_pos_x, 277-loc_pos_y);
		 }
private: System::Void label6_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			this->label6->MaximumSize = System::Drawing::Size(63, 19); this->label6->Size = System::Drawing::Size(63, 19);
			this->label6->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(122, 277);		
		 }
private: System::Void label7_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 this->label7->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			 this->label7->MaximumSize = System::Drawing::Size(70, 23); this->label7->Size = System::Drawing::Size(70, 23);
			 this->label7->Location = System::Drawing::Point(191-loc_pos_x, 277-loc_pos_y);
		 }
private: System::Void label7_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			this->label7->MaximumSize = System::Drawing::Size(63, 19); this->label7->Size = System::Drawing::Size(63, 19);
			this->label7->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(191, 277);		
		 }
private: System::Void label8_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 this->label8->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			 this->label8->MaximumSize = System::Drawing::Size(70, 23); this->label8->Size = System::Drawing::Size(70, 23);
			 this->label8->Location = System::Drawing::Point(122-loc_pos_x, 325-loc_pos_y);
		 }
private: System::Void label8_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			this->label8->MaximumSize = System::Drawing::Size(63, 19); this->label8->Size = System::Drawing::Size(63, 19);
			this->label8->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(122, 325);		
		 }
private: System::Void label9_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 this->label9->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			 this->label9->MaximumSize = System::Drawing::Size(70, 23); this->label9->Size = System::Drawing::Size(70, 23);
			 this->label9->Location = System::Drawing::Point(191-loc_pos_x, 325-loc_pos_y);
		 }
private: System::Void label9_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			this->label9->MaximumSize = System::Drawing::Size(63, 19); this->label9->Size = System::Drawing::Size(63, 19);
			this->label9->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(191, 325);		
		 }
private: System::Void label10_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 this->label10->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			 this->label10->MaximumSize = System::Drawing::Size(70, 23); this->label10->Size = System::Drawing::Size(70, 23);
			 this->label10->Location = System::Drawing::Point(191-loc_pos_x, 371-loc_pos_y);
		 }
private: System::Void label10_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			this->label10->MaximumSize = System::Drawing::Size(63, 19); this->label10->Size = System::Drawing::Size(63, 19);
			this->label10->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(191, 371);		
		 }
private: System::Void label11_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 this->label11->Font = (gcnew System::Drawing::Font(L"Consolas", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			 this->label11->MaximumSize = System::Drawing::Size(70, 23); this->label11->Size = System::Drawing::Size(70, 23);
			 this->label11->Location = System::Drawing::Point(122-loc_pos_x, 371-loc_pos_y);
		 }
private: System::Void label11_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			this->label11->MaximumSize = System::Drawing::Size(63, 19); this->label11->Size = System::Drawing::Size(63, 19);
			this->label11->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(122, 371);		
		 }
private: System::Void autorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Autor^ aut = gcnew Autor();
			 aut->ShowDialog();
		 }
private: System::Void wyjœcieToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->info->Text="Nawiazywanie polaczenia z internetem...";	
				 if (!system("ping www.nbp.pl -n 2")){
					ReaderXXML();
				 }
				else
				{
				this->info->Text="PONOWNIE nie uda³o siê po³¹czyæ z NBP, spróbuj OFFLINE !";
				this->button4->Enabled=true;
				this->label12->Text = "offline";
				this->pictureBox7->ImageLocation="img/status_bad.png";
				}
		 }
private: System::Void defaultToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->pictureBox8->ImageLocation="img/logo.png";
		 }
private: System::Void zimoweToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->pictureBox8->ImageLocation="img/logo_zima.png";
		 }
private: System::Void onOffToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->label1->Visible==true)
				 this->label1->Visible=false;
			 else
				 this->label1->Visible=true;
		 }
private: System::Void zielonyCiemnyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->BackColor = System::Drawing::Color::Green;
		 }
private: System::Void niebieskiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->BackColor = System::Drawing::Color::Blue;
		 }
private: System::Void czerwonyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->BackColor = System::Drawing::Color::Red;
		 }
private: System::Void pomarañczowyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->BackColor = System::Drawing::Color::Orange;
		 }
private: System::Void ¿ó³tyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->BackColor = System::Drawing::Color::Yellow;
		 }
private: System::Void deafultToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->BackColor = System::Drawing::SystemColors::Control;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 val=val+1;
			 Indicator();
		 }
};
}
