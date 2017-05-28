#include "l_1_b.h"
#include "Variables_change.h"
#include "Weight_window.h"
#include <limits.h>
#include <Windows.h>
#include <ctime>

#pragma once

bool stop = false;
bool changeVariable = false;
bool weightWindow = false;
bool check = false;
bool basicEnable = false;
bool ready = false;
bool inProgress = false;
bool goodtxt = false;
bool active = true;
parser pars;
double rightBorder = 0;
double leftBorder = 0;
double step = 0;
std::vector<double> xBuffer;
std::vector<double> yBuffer;
std::vector<bool> pointType;
std::vector<double> x_all;
std::vector<double> y_all;
std::vector<bool> break_point;
unsigned int prog = 0;
unsigned int numberSeries = 1;
bool breakPoint = false;
unsigned int color = 0;
unsigned int last = 0;



namespace l_1_b {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ l_1_b_face
	/// </summary>
	public ref class l_1_b_face : public System::Windows::Forms::Form
	{
	public:
		l_1_b_face(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~l_1_b_face()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  functionBox;



	private: System::Windows::Forms::DataVisualization::Charting::Chart^  functionChart;
	private: System::Windows::Forms::Button^  CloseButton;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  RunButton;
	private: System::Windows::Forms::ListBox^  resultBox;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Button^  clearButton;
	private: System::Windows::Forms::Button^  helpButton;
	private: System::Windows::Forms::Button^  disButton;
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->functionBox = (gcnew System::Windows::Forms::TextBox());
			this->functionChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->CloseButton = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->RunButton = (gcnew System::Windows::Forms::Button());
			this->resultBox = (gcnew System::Windows::Forms::ListBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->helpButton = (gcnew System::Windows::Forms::Button());
			this->disButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->functionChart))->BeginInit();
			this->SuspendLayout();
			// 
			// functionBox
			// 
			this->functionBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->functionBox->Location = System::Drawing::Point(28, 13);
			this->functionBox->Name = L"functionBox";
			this->functionBox->Size = System::Drawing::Size(798, 20);
			this->functionBox->TabIndex = 0;
			this->functionBox->TextChanged += gcnew System::EventHandler(this, &l_1_b_face::functionBox_TextChanged);
			// 
			// functionChart
			// 
			this->functionChart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			chartArea1->AxisX->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Triangle;
			chartArea1->AxisX->Title = L"i";
			chartArea1->AxisX->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea1->AxisY->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Triangle;
			chartArea1->AxisY->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Horizontal;
			chartArea1->AxisY->Title = L"F";
			chartArea1->AxisY->TitleAlignment = System::Drawing::StringAlignment::Far;
			chartArea1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			chartArea1->Name = L"ChartArea";
			this->functionChart->ChartAreas->Add(chartArea1);
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->functionChart->Legends->Add(legend1);
			this->functionChart->Location = System::Drawing::Point(12, 39);
			this->functionChart->Name = L"functionChart";
			this->functionChart->Size = System::Drawing::Size(842, 337);
			this->functionChart->TabIndex = 4;
			this->functionChart->Text = L"chart1";
			// 
			// CloseButton
			// 
			this->CloseButton->Location = System::Drawing::Point(1036, 382);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(75, 23);
			this->CloseButton->TabIndex = 5;
			this->CloseButton->Text = L"Close";
			this->CloseButton->UseVisualStyleBackColor = true;
			this->CloseButton->Click += gcnew System::EventHandler(this, &l_1_b_face::CloseButton_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &l_1_b_face::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"F:";
			// 
			// RunButton
			// 
			this->RunButton->Enabled = false;
			this->RunButton->Location = System::Drawing::Point(12, 382);
			this->RunButton->Name = L"RunButton";
			this->RunButton->Size = System::Drawing::Size(75, 23);
			this->RunButton->TabIndex = 7;
			this->RunButton->Text = L"Run";
			this->RunButton->UseVisualStyleBackColor = true;
			this->RunButton->Click += gcnew System::EventHandler(this, &l_1_b_face::RunButton_Click);
			// 
			// resultBox
			// 
			this->resultBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->resultBox->FormattingEnabled = true;
			this->resultBox->Location = System::Drawing::Point(860, 12);
			this->resultBox->Name = L"resultBox";
			this->resultBox->Size = System::Drawing::Size(251, 355);
			this->resultBox->TabIndex = 8;
			this->resultBox->SelectedIndexChanged += gcnew System::EventHandler(this, &l_1_b_face::resultBox_SelectedIndexChanged);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &l_1_b_face::backgroundWorker1_DoWork);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(256, 382);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(774, 23);
			this->progressBar1->TabIndex = 9;
			// 
			// clearButton
			// 
			this->clearButton->Location = System::Drawing::Point(93, 382);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(75, 23);
			this->clearButton->TabIndex = 10;
			this->clearButton->Text = L"Clear";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &l_1_b_face::clearButton_Click);
			// 
			// helpButton
			// 
			this->helpButton->Location = System::Drawing::Point(830, 11);
			this->helpButton->Name = L"helpButton";
			this->helpButton->Size = System::Drawing::Size(24, 23);
			this->helpButton->TabIndex = 11;
			this->helpButton->Text = L"\?";
			this->helpButton->UseVisualStyleBackColor = true;
			this->helpButton->Click += gcnew System::EventHandler(this, &l_1_b_face::helpButton_Click);
			// 
			// disButton
			// 
			this->disButton->Enabled = false;
			this->disButton->Location = System::Drawing::Point(174, 382);
			this->disButton->Name = L"disButton";
			this->disButton->Size = System::Drawing::Size(75, 23);
			this->disButton->TabIndex = 12;
			this->disButton->Text = L"Fourier";
			this->disButton->UseVisualStyleBackColor = true;
			this->disButton->Click += gcnew System::EventHandler(this, &l_1_b_face::disButton_Click);
			// 
			// l_1_b_face
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(1117, 412);
			this->ControlBox = false;
			this->Controls->Add(this->disButton);
			this->Controls->Add(this->helpButton);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->resultBox);
			this->Controls->Add(this->RunButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->CloseButton);
			this->Controls->Add(this->functionChart);
			this->Controls->Add(this->functionBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"l_1_b_face";
			this->ShowIcon = false;
			this->Text = L"Parser window";
			this->Load += gcnew System::EventHandler(this, &l_1_b_face::l_1_b_face_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->functionChart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void colorChange (unsigned int number,unsigned int lastNumber)
		{
			srand(lastNumber);
			unsigned int position = (rand()*color) % 129;
			switch (position)
			{
			case 0: functionChart->Series[number]->Color = System::Drawing::Color::AliceBlue; break;
			case 1: functionChart->Series[number]->Color = System::Drawing::Color::Aqua; break;
			case 3: functionChart->Series[number]->Color = System::Drawing::Color::Aquamarine; break;
			case 4: functionChart->Series[number]->Color = System::Drawing::Color::Azure; break;
			case 5: functionChart->Series[number]->Color = System::Drawing::Color::Beige; break;
			case 6: functionChart->Series[number]->Color = System::Drawing::Color::Bisque; break;
			case 7: functionChart->Series[number]->Color = System::Drawing::Color::BlanchedAlmond; break;
			case 8: functionChart->Series[number]->Color = System::Drawing::Color::Blue; break;
			case 9: functionChart->Series[number]->Color = System::Drawing::Color::BlueViolet; break;
			case 10: functionChart->Series[number]->Color = System::Drawing::Color::Brown; break;
			case 11: functionChart->Series[number]->Color = System::Drawing::Color::BurlyWood; break;
			case 12: functionChart->Series[number]->Color = System::Drawing::Color::CadetBlue; break;
			case 13: functionChart->Series[number]->Color = System::Drawing::Color::Chartreuse; break;
			case 14: functionChart->Series[number]->Color = System::Drawing::Color::Chocolate; break;
			case 15: functionChart->Series[number]->Color = System::Drawing::Color::Coral; break;
			case 16: functionChart->Series[number]->Color = System::Drawing::Color::CornflowerBlue; break;
			case 17: functionChart->Series[number]->Color = System::Drawing::Color::Cornsilk; break;
			case 18: functionChart->Series[number]->Color = System::Drawing::Color::Crimson; break;
			case 19: functionChart->Series[number]->Color = System::Drawing::Color::Cyan; break;
			case 20: functionChart->Series[number]->Color = System::Drawing::Color::DarkBlue; break;
			case 21: functionChart->Series[number]->Color = System::Drawing::Color::DarkCyan; break;
			case 22: functionChart->Series[number]->Color = System::Drawing::Color::DarkGoldenrod; break;
			case 23: functionChart->Series[number]->Color = System::Drawing::Color::DarkGray; break;
			case 24: functionChart->Series[number]->Color = System::Drawing::Color::DarkGreen; break;
			case 25: functionChart->Series[number]->Color = System::Drawing::Color::DarkKhaki; break;
			case 26: functionChart->Series[number]->Color = System::Drawing::Color::DarkMagenta; break;
			case 27: functionChart->Series[number]->Color = System::Drawing::Color::DarkOliveGreen; break;
			case 28: functionChart->Series[number]->Color = System::Drawing::Color::DarkOrange; break;
			case 29: functionChart->Series[number]->Color = System::Drawing::Color::DarkOrchid; break;
			case 30: functionChart->Series[number]->Color = System::Drawing::Color::DarkRed; break;
			case 31: functionChart->Series[number]->Color = System::Drawing::Color::DarkSeaGreen; break;
			case 32: functionChart->Series[number]->Color = System::Drawing::Color::DarkSlateBlue; break;
			case 33: functionChart->Series[number]->Color = System::Drawing::Color::DarkSlateGray; break;
			case 34: functionChart->Series[number]->Color = System::Drawing::Color::DarkTurquoise; break;
			case 35: functionChart->Series[number]->Color = System::Drawing::Color::DarkViolet; break;
			case 36: functionChart->Series[number]->Color = System::Drawing::Color::DeepPink; break;
			case 37: functionChart->Series[number]->Color = System::Drawing::Color::DeepSkyBlue; break;
			case 38: functionChart->Series[number]->Color = System::Drawing::Color::DimGray; break;
			case 39: functionChart->Series[number]->Color = System::Drawing::Color::DodgerBlue; break;
			case 40: functionChart->Series[number]->Color = System::Drawing::Color::Firebrick; break;
			case 41: functionChart->Series[number]->Color = System::Drawing::Color::ForestGreen; break;
			case 42: functionChart->Series[number]->Color = System::Drawing::Color::Fuchsia; break;
			case 43: functionChart->Series[number]->Color = System::Drawing::Color::Gainsboro; break;
			case 44: functionChart->Series[number]->Color = System::Drawing::Color::Gold; break;
			case 45: functionChart->Series[number]->Color = System::Drawing::Color::Goldenrod; break;
			case 46: functionChart->Series[number]->Color = System::Drawing::Color::Gray; break;
			case 47: functionChart->Series[number]->Color = System::Drawing::Color::Honeydew; break;
			case 48: functionChart->Series[number]->Color = System::Drawing::Color::GreenYellow; break;
			case 49: functionChart->Series[number]->Color = System::Drawing::Color::HotPink; break;
			case 50: functionChart->Series[number]->Color = System::Drawing::Color::Indigo; break;
			case 51: functionChart->Series[number]->Color = System::Drawing::Color::Ivory; break;
			case 52: functionChart->Series[number]->Color = System::Drawing::Color::Khaki; break;
			case 53: functionChart->Series[number]->Color = System::Drawing::Color::LavenderBlush; break;
			case 54: functionChart->Series[number]->Color = System::Drawing::Color::LawnGreen; break;
			case 55: functionChart->Series[number]->Color = System::Drawing::Color::LemonChiffon; break;
			case 56: functionChart->Series[number]->Color = System::Drawing::Color::LightBlue; break;
			case 57: functionChart->Series[number]->Color = System::Drawing::Color::LightCoral; break;
			case 58: functionChart->Series[number]->Color = System::Drawing::Color::LightCyan; break;
			case 59: functionChart->Series[number]->Color = System::Drawing::Color::LightGoldenrodYellow; break;
			case 60: functionChart->Series[number]->Color = System::Drawing::Color::LightGray; break;
			case 61: functionChart->Series[number]->Color = System::Drawing::Color::LightGreen; break;
			case 62: functionChart->Series[number]->Color = System::Drawing::Color::LightPink; break;
			case 63: functionChart->Series[number]->Color = System::Drawing::Color::LightSalmon; break;
			case 64: functionChart->Series[number]->Color = System::Drawing::Color::LightSeaGreen; break;
			case 65: functionChart->Series[number]->Color = System::Drawing::Color::LightSkyBlue; break;
			case 66: functionChart->Series[number]->Color = System::Drawing::Color::LightSlateGray; break;
			case 67: functionChart->Series[number]->Color = System::Drawing::Color::LightSteelBlue; break;
			case 68: functionChart->Series[number]->Color = System::Drawing::Color::LightYellow; break;
			case 69: functionChart->Series[number]->Color = System::Drawing::Color::Lime; break;
			case 70: functionChart->Series[number]->Color = System::Drawing::Color::LimeGreen; break;
			case 71: functionChart->Series[number]->Color = System::Drawing::Color::Linen; break;
			case 72: functionChart->Series[number]->Color = System::Drawing::Color::Magenta; break;
			case 73: functionChart->Series[number]->Color = System::Drawing::Color::Maroon; break;
			case 74: functionChart->Series[number]->Color = System::Drawing::Color::MediumAquamarine; break;
			case 75: functionChart->Series[number]->Color = System::Drawing::Color::MediumBlue; break;
			case 76: functionChart->Series[number]->Color = System::Drawing::Color::MediumOrchid; break;
			case 77: functionChart->Series[number]->Color = System::Drawing::Color::MediumPurple; break;
			case 78: functionChart->Series[number]->Color = System::Drawing::Color::MediumSeaGreen; break;
			case 79: functionChart->Series[number]->Color = System::Drawing::Color::MediumSlateBlue; break;
			case 80: functionChart->Series[number]->Color = System::Drawing::Color::MediumTurquoise; break;
			case 81: functionChart->Series[number]->Color = System::Drawing::Color::MediumVioletRed; break;
			case 82: functionChart->Series[number]->Color = System::Drawing::Color::MidnightBlue; break;
			case 83: functionChart->Series[number]->Color = System::Drawing::Color::MintCream; break;
			case 84: functionChart->Series[number]->Color = System::Drawing::Color::MistyRose; break;
			case 85: functionChart->Series[number]->Color = System::Drawing::Color::Moccasin; break;
			case 86: functionChart->Series[number]->Color = System::Drawing::Color::Navy; break;
			case 87: functionChart->Series[number]->Color = System::Drawing::Color::OldLace; break;
			case 88: functionChart->Series[number]->Color = System::Drawing::Color::Olive; break;
			case 89: functionChart->Series[number]->Color = System::Drawing::Color::OliveDrab; break;
			case 90: functionChart->Series[number]->Color = System::Drawing::Color::Orange; break;
			case 91: functionChart->Series[number]->Color = System::Drawing::Color::OrangeRed; break;
			case 92: functionChart->Series[number]->Color = System::Drawing::Color::Orchid; break;
			case 93: functionChart->Series[number]->Color = System::Drawing::Color::PaleGoldenrod; break;
			case 94: functionChart->Series[number]->Color = System::Drawing::Color::PaleGreen; break;
			case 95: functionChart->Series[number]->Color = System::Drawing::Color::PaleTurquoise; break;
			case 96: functionChart->Series[number]->Color = System::Drawing::Color::PaleVioletRed; break;
			case 97: functionChart->Series[number]->Color = System::Drawing::Color::PapayaWhip; break;
			case 98: functionChart->Series[number]->Color = System::Drawing::Color::PeachPuff; break;
			case 99: functionChart->Series[number]->Color = System::Drawing::Color::Peru; break;
			case 100: functionChart->Series[number]->Color = System::Drawing::Color::Pink; break;
			case 101: functionChart->Series[number]->Color = System::Drawing::Color::Plum; break;
			case 102: functionChart->Series[number]->Color = System::Drawing::Color::PowderBlue; break;
			case 103: functionChart->Series[number]->Color = System::Drawing::Color::Purple; break;
			case 104: functionChart->Series[number]->Color = System::Drawing::Color::Green; break;
			case 105: functionChart->Series[number]->Color = System::Drawing::Color::Red; break;
			case 106: functionChart->Series[number]->Color = System::Drawing::Color::RosyBrown; break;
			case 107: functionChart->Series[number]->Color = System::Drawing::Color::RoyalBlue; break;
			case 108: functionChart->Series[number]->Color = System::Drawing::Color::SaddleBrown; break;
			case 109: functionChart->Series[number]->Color = System::Drawing::Color::Salmon; break;
			case 110: functionChart->Series[number]->Color = System::Drawing::Color::SandyBrown; break;
			case 111: functionChart->Series[number]->Color = System::Drawing::Color::SeaGreen; break;
			case 112: functionChart->Series[number]->Color = System::Drawing::Color::SeaShell; break;
			case 113: functionChart->Series[number]->Color = System::Drawing::Color::Sienna; break;
			case 114: functionChart->Series[number]->Color = System::Drawing::Color::Silver; break;
			case 115: functionChart->Series[number]->Color = System::Drawing::Color::SkyBlue; break;
			case 116: functionChart->Series[number]->Color = System::Drawing::Color::SlateBlue; break;
			case 117: functionChart->Series[number]->Color = System::Drawing::Color::SlateGray; break;
			case 118: functionChart->Series[number]->Color = System::Drawing::Color::SpringGreen; break;
			case 119: functionChart->Series[number]->Color = System::Drawing::Color::SteelBlue; break;
			case 120: functionChart->Series[number]->Color = System::Drawing::Color::Tan; break;
			case 121: functionChart->Series[number]->Color = System::Drawing::Color::Teal; break;
			case 122: functionChart->Series[number]->Color = System::Drawing::Color::Thistle; break;
			case 123: functionChart->Series[number]->Color = System::Drawing::Color::Tomato; break;
			case 124: functionChart->Series[number]->Color = System::Drawing::Color::Turquoise; break;
			case 125: functionChart->Series[number]->Color = System::Drawing::Color::Transparent; break;
			case 126: functionChart->Series[number]->Color = System::Drawing::Color::Violet; break;
			case 127: functionChart->Series[number]->Color = System::Drawing::Color::Yellow; break;
			case 128: functionChart->Series[number]->Color = System::Drawing::Color::YellowGreen; break;
			}

		}
		void checking()
		{
			check = true;
			pars = functionBox->Text;
			check = false;
		}
		bool strRestr(System::String^ text)
		{
			bool result = true;
			System::String^ restr = L"0123456789,-";
				for (int i = 0;i < text->Length;i++)
				{
					for (int j = 0; j < restr->Length;j++)
					{
						if (text[i] == restr[j])
							break;
						if (j == restr->Length - 1)
							result = false;
					}
				}
				return result;
		}
		
	private: System::Void CloseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (inProgress)
		{
			RunButton->Enabled = false;
			functionBox->Enabled = false;
			clearButton->Enabled = false;
		}
		else
		{
			clearButton->Enabled = true;
			functionBox->Enabled = true;
		}
		if(goodtxt&&!inProgress)
		{
			RunButton->Enabled = true;
		}
		else
		{
			RunButton->Enabled = false;
		}
		if (changeVariable || weightWindow)
		{
			this->Enabled = false;
			active = false;
		}
		else if(!active)
		{
			
			this->Enabled = true;
			this->Activate();
			active = true;
		}
		if (basicEnable)
		{
			if(leftBorder < functionChart->ChartAreas[0]->AxisX->Minimum)
			    functionChart->ChartAreas[0]->AxisX->Minimum = (int)leftBorder-1;
			if(rightBorder > functionChart->ChartAreas[0]->AxisX->Maximum)
			    functionChart->ChartAreas[0]->AxisX->Maximum = (int)rightBorder+1;
			prog = 0;
			progressBar1->Value = 0;
			functionChart->Series->Add(L"");
			numberSeries++;
			functionChart->Series[numberSeries]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			last = numberSeries;
			colorChange(numberSeries,numberSeries);
			breakPoint = false;
			break_point.push_back(false);
			backgroundWorker1->RunWorkerAsync();
			basicEnable = false;
			disButton->Enabled = true;
		}
		if (ready)
		{
			progressBar1->Value = prog;
			System::String^ x = L"i: ";
			System::String^ y = L" f: ";
			System::String^ yStr = L"";
			System::String^ xStr = L"";
			for (unsigned int i = 0;i < pointType.size();i++)
			{
				if (pointType[i])
				{
					x_all.push_back(xBuffer[i]);
					y_all.push_back(yBuffer[i]);
					yStr = System::Convert::ToString(yBuffer[i]);
					xStr = System::Convert::ToString(xBuffer[i]);
					functionChart->Series[numberSeries]->Points->AddXY(xBuffer[i], yBuffer[i]);
					resultBox->Items->Add(x + xStr + y + yStr);
					breakPoint = false;
					break_point.push_back(true);
				}
				else if(!breakPoint)
				{
					functionChart->Series->Add(L"");
					numberSeries++;
					functionChart->Series[numberSeries]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
					colorChange(numberSeries,last);
					breakPoint = true;
					break_point.push_back(false);
				}
			}
			xBuffer.clear();
			yBuffer.clear();
			pointType.clear();
			ready = false;
		}
	}
private: System::Void functionBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (!check)
	{
		checking();
	}
	if (pars.checkText())
	{
		this->functionBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		goodtxt = true;
	}
	else
	{
		functionBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		goodtxt = false;
	}
}
private: System::Void RunButton_Click(System::Object^  sender, System::EventArgs^  e) {
	pars.clear();
	pars.action();
	pars.findVariables();
	if (pars.numberVariables() == 0)
	{
		if (-1 < functionChart->ChartAreas[0]->AxisX->Minimum)
			functionChart->ChartAreas[0]->AxisX->Minimum = (int) -1;
		if (1 > functionChart->ChartAreas[0]->AxisX->Maximum)
			functionChart->ChartAreas[0]->AxisX->Maximum = (int) 1;
		System::String^ x = L"i: ";
		System::String^ y = L" f: ";
		if(leftBorder>-1)
		   functionChart->ChartAreas[0]->AxisX->Minimum = (int)-1;
		if(rightBorder<1)
		   functionChart->ChartAreas[0]->AxisX->Maximum = (int)1;
		System::String^ str = L"";
		double value = pars.run(0,0,0,0);
		str = System::Convert::ToString(value);
		if ((isnan(value) == 0) && (isinf(value) == 0) && strRestr(str))
		{
			resultBox->Items->Add(x + System::Convert::ToString(0) + y + str);
			functionChart->Series[1]->Points->AddXY(0.000000001, value);
		}
	}
	else
	{
		changeVariable = true;
		Variables_change^ g = gcnew Variables_change();
		g->Show();
		g->Visible = true;
	}
}
void sleep()
{
	while (ready)
	{
		Sleep(100);
	}
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	inProgress = true;
	basicEnable = false;
	pars.setVariables();
	double var = 0;
	unsigned int iterator = 0;
	unsigned int t = 0;
	double progress = abs(rightBorder - leftBorder);
	double iter = 0;
	System::String^ str = L"";
	for (double i = leftBorder,j=0;i <= rightBorder;i += step,j++)
	{
		prog = (unsigned int)((iter / progress)*100);
		if (stop)
		{
			break;
		}
		if (iterator == 200)
		{
			ready = true;
			sleep();
			iterator = 0;
		}
		var = pars.run(j,leftBorder,rightBorder,i);
		str = System::Convert::ToString(var);
		if ((isnan(var) == 0) && (isinf(var) == 0) && strRestr(str))
			pointType.push_back(true);
		else
			pointType.push_back(false);
		xBuffer.push_back(i);
		yBuffer.push_back(var);
		iterator++;
		iter += step;
	}
	prog = 100;
	ready = true;
	inProgress = false;
}
private: System::Void clearButton_Click(System::Object^  sender, System::EventArgs^  e) {
	disButton->Enabled = false;
	progressBar1->Value = 0;
	resultBox->Items->Clear();
	functionChart->Series->Clear();
	for (int i = 0;i < 2;i++)
	    functionChart->Series->Add(L"");
	srand((unsigned int)time(NULL));
	color = rand();
	functionChart->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
	colorChange(0,0);
	functionChart->Series[1]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
	colorChange(1,1);
	numberSeries = 1;
	functionChart->ChartAreas[0]->AxisX->Minimum = (int)-1;
	functionChart->ChartAreas[0]->AxisX->Maximum =  (int)1;
	pars.clear();
	x_all.clear();
	y_all.clear();
	break_point.clear();
}
private: System::Void resultBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	System::String^str = resultBox->Items[resultBox->SelectedIndex]->ToString();
	System::String^ valueX = L"";
	System::String^ valueY = L"";
		int i = 3;
		while(true)
		{
			if (str[i] == L' ')
				break;
			valueX += str[i];
			i++;
		}
		i += 4;
		while (true)
		{
			
			valueY += str[i];
			if (i == str->Length - 1)
				break;
			i++;
		}
		functionChart->Series[0]->Points->AddXY(System::Convert::ToDouble(valueX), System::Convert::ToDouble(valueY));
}
private: System::Void l_1_b_face_Load(System::Object^  sender, System::EventArgs^  e) {
	srand((unsigned int)time(NULL));
	color = rand();
	functionChart->ChartAreas[0]->AxisX->Minimum = (int)-1;
	functionChart->ChartAreas[0]->AxisX->Maximum = (int)1;
	for (int i = 0;i < 2;i++)
		functionChart->Series->Add(L"");
	functionChart->Series[0]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
	colorChange(0,0);
	functionChart->Series[1]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
	colorChange(1,1);
}
private: System::Void helpButton_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show(L"Implemented features:\n+\n-\n%\n/\n*\n^\nABS\nACOS\nACOSH\nASIN\nASINH\nATAN\nATANH\nCOS\nCBRT\nDER\nERF\nERFC\nEXP\nEXPS\nEXPMF\nINT\nLGAM\nLOGN\nLOGT\nLOGNF\nLOGS\nJZ\nJF\nNEG\nSIN\nSINH\nSQRT\nTAN\nTANH\nTGAM\nYZ\nYF");
}
private: System::Void disButton_Click(System::Object^  sender, System::EventArgs^  e) {
	weightWindow = true;
	Weight_window^ g = gcnew Weight_window();
	g->Show();
	g->Visible = true;
}
};
}
