#pragma once




extern bool weightWindow;
extern std::vector<double> x_all;
extern std::vector<double> y_all;
extern std::vector<bool> break_point;
std::vector<double> tmp;
std::vector<std::complex<double>> result;
std::vector<std::complex<double>> back_result;
bool print = false;
bool breaknow = true;
int ns = -1;
unsigned int it = 0;
unsigned int jt = 0;
int type = 0;



namespace l_1_b {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Weight_window
	/// </summary>
	public ref class Weight_window : public System::Windows::Forms::Form
	{
	public:
		Weight_window(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Weight_window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  DFT;
	private: System::Windows::Forms::RadioButton^  IFT;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::RadioButton^  WeightButton;
	private: System::Windows::Forms::RadioButton^  OriginalButton;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->WeightButton = (gcnew System::Windows::Forms::RadioButton());
			this->DFT = (gcnew System::Windows::Forms::RadioButton());
			this->IFT = (gcnew System::Windows::Forms::RadioButton());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->OriginalButton = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(773, 203);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Close";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Weight_window::button1_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(13, 3);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(77, 17);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Бартлетта";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(13, 26);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(56, 17);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->Text = L"Ханна";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(13, 49);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(77, 17);
			this->radioButton3->TabIndex = 4;
			this->radioButton3->Text = L"Хэмминга";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::radioButton3_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(13, 95);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(76, 17);
			this->radioButton4->TabIndex = 5;
			this->radioButton4->Text = L"Блэкмана";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::radioButton4_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(13, 116);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(68, 17);
			this->radioButton5->TabIndex = 6;
			this->radioButton5->Text = L"Натолла";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::radioButton5_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(13, 139);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(48, 17);
			this->radioButton6->TabIndex = 7;
			this->radioButton6->Text = L"Гаус";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::radioButton6_CheckedChanged);
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(13, 162);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(114, 17);
			this->radioButton7->TabIndex = 8;
			this->radioButton7->Text = L"Кайзера-Бесселя";
			this->radioButton7->UseVisualStyleBackColor = true;
			this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::radioButton7_CheckedChanged);
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::SystemColors::Control;
			chartArea1->BackColor = System::Drawing::SystemColors::Control;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(667, 171);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->WeightButton);
			this->panel1->Controls->Add(this->radioButton4);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Controls->Add(this->radioButton7);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButton6);
			this->panel1->Controls->Add(this->radioButton3);
			this->panel1->Controls->Add(this->radioButton5);
			this->panel1->Location = System::Drawing::Point(685, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(163, 193);
			this->panel1->TabIndex = 9;
			// 
			// WeightButton
			// 
			this->WeightButton->AutoSize = true;
			this->WeightButton->Location = System::Drawing::Point(13, 72);
			this->WeightButton->Name = L"WeightButton";
			this->WeightButton->Size = System::Drawing::Size(142, 17);
			this->WeightButton->TabIndex = 9;
			this->WeightButton->Text = L"Взвешенные косинусы";
			this->WeightButton->UseVisualStyleBackColor = true;
			this->WeightButton->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::WeightButton_CheckedChanged);
			// 
			// DFT
			// 
			this->DFT->AutoSize = true;
			this->DFT->Location = System::Drawing::Point(272, 203);
			this->DFT->Name = L"DFT";
			this->DFT->Size = System::Drawing::Size(149, 17);
			this->DFT->TabIndex = 10;
			this->DFT->Text = L"Discrete Fourier Transform";
			this->DFT->UseVisualStyleBackColor = true;
			this->DFT->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::DFT_CheckedChanged);
			// 
			// IFT
			// 
			this->IFT->AutoSize = true;
			this->IFT->Location = System::Drawing::Point(512, 203);
			this->IFT->Name = L"IFT";
			this->IFT->Size = System::Drawing::Size(141, 17);
			this->IFT->TabIndex = 11;
			this->IFT->Text = L"Inverse Fourier transform";
			this->IFT->UseVisualStyleBackColor = true;
			this->IFT->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::IFT_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Weight_window::timer1_Tick);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Weight_window::backgroundWorker1_DoWork);
			// 
			// OriginalButton
			// 
			this->OriginalButton->AutoSize = true;
			this->OriginalButton->Checked = true;
			this->OriginalButton->Location = System::Drawing::Point(90, 203);
			this->OriginalButton->Name = L"OriginalButton";
			this->OriginalButton->Size = System::Drawing::Size(90, 17);
			this->OriginalButton->TabIndex = 12;
			this->OriginalButton->TabStop = true;
			this->OriginalButton->Text = L"Original signal";
			this->OriginalButton->UseVisualStyleBackColor = true;
			this->OriginalButton->CheckedChanged += gcnew System::EventHandler(this, &Weight_window::OriginalButton_CheckedChanged);
			// 
			// Weight_window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(860, 238);
			this->ControlBox = false;
			this->Controls->Add(this->OriginalButton);
			this->Controls->Add(this->IFT);
			this->Controls->Add(this->DFT);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button1);
			this->Name = L"Weight_window";
			this->Text = L"Fourier window";
			this->Load += gcnew System::EventHandler(this, &Weight_window::Weight_window_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void active()
		{
			DFT->Enabled = true;
			IFT->Enabled = true;
		}
		void passive()
		{
			DFT->Enabled = false;
			IFT->Enabled = false;
		}
private: System::Void Weight_window_Load(System::Object^  sender, System::EventArgs^  e) {
	OriginalButton_CheckedChanged(sender, e);
}
std::vector<double>Switch_type(int t)
{
	switch (t)
	{
	case 0: return Bartlet_window(y_all);
	case 1: return Hann_window(y_all);
	case 2: return Hamming_window(y_all);
	case 3: return WeightCos_window(y_all);
	case 4: return BlackMan_window(y_all);
	case 5: return Natoll_window(y_all);
	case 6: return Gaus_window(y_all);
	case 7: return KaizerBessele_window(y_all);
	}
	return Bartlet_window(y_all);
}
void compute()
{
	tmp.clear();
	result.clear();
	back_result.clear();
	tmp = Switch_type(type);
	std::vector<std::complex<double>> values;
	for (unsigned int i = 0;i < y_all.size();i++)
		values.push_back(tmp[i]);
	result = discrete_fourier_transform(values);
	back_result = inverse_fourier_transform(result);
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	weightWindow = false;
	this->Close();
}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 0;
	OriginalButton_CheckedChanged(sender, e);
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 1;
	OriginalButton_CheckedChanged(sender, e);
}
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 2;
	OriginalButton_CheckedChanged(sender, e);
}
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 4;
	OriginalButton_CheckedChanged(sender, e);
}
private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 5;
	OriginalButton_CheckedChanged(sender, e);
}
private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 6;
	OriginalButton_CheckedChanged(sender, e);
}
private: System::Void radioButton7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 7;
	OriginalButton_CheckedChanged(sender, e);
}
private: System::Void DFT_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	ns = -1;
	chart1->Series->Clear();
	compute();
	breaknow = true;
	passive();
	it = 0;
	jt = 0;
	print = true;
}
private: System::Void IFT_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	ns = -1;
	chart1->Series->Clear();
	compute();
	breaknow = true;
	passive();
	it = 0;
	jt = 0;
	print = true;
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (print)
	{
		if (DFT->Checked)
		{
			for (it, jt;it < break_point.size() && jt < x_all.size();it++)
			{
				if (break_point[it])
				{
					chart1->Series[ns]->Points->AddXY(x_all[jt], mod(result[jt]));
					jt++;
					breaknow = true;
				}
				else if (breaknow)
				{
					ns++;
					chart1->Series->Add(L"");
					chart1->Series[ns]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
					chart1->Series[ns]->Color = System::Drawing::Color::DarkBlue;
					breaknow = false;
				}
				if (jt == x_all.size() - 1)
				{
					print = false;
					active();
					break;
				}
			}
		}
		if (IFT->Checked)
		{
			for (it, jt;it < break_point.size() && jt < x_all.size();it++)
			{
				if (break_point[it])
				{
					chart1->Series[ns]->Points->AddXY(x_all[jt], real(back_result[jt]));
					jt++;
					breaknow = true;
				}
				else if (breaknow)
				{
					ns++;
					chart1->Series->Add(L"");
					chart1->Series[ns]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
					chart1->Series[ns]->Color = System::Drawing::Color::DarkBlue;
					breaknow = false;
				}
				if (jt == x_all.size() - 1)
				{
					print = false;
					active();
					break;
				}
			}
		}
		if (OriginalButton->Checked)
		{
			for (it, jt;it < break_point.size() && jt < x_all.size();it++)
			{
				if (break_point[it])
				{
					chart1->Series[ns]->Points->AddXY(x_all[jt], tmp[jt]);
					jt++;
					breaknow = true;
				}
				else if (breaknow)
				{
					ns++;
					chart1->Series->Add(L"");
					chart1->Series[ns]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
					chart1->Series[ns]->Color = System::Drawing::Color::DarkBlue;
					breaknow = false;
				}
				if (jt == x_all.size() - 1)
				{
					print = false;
					active();
					break;
				}
			}
		}
	}
}
private: System::Void OriginalButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	ns = -1;
	chart1->Series->Clear();
	compute();
	breaknow = true;
	passive();
	it = 0;
	jt = 0;
	print = true;
}
private: System::Void WeightButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	type = 3;
	OriginalButton_CheckedChanged(sender, e);
}
};
}
