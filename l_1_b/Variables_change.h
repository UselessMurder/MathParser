#pragma once

extern parser pars;
extern bool changeVariable;
extern double rightBorder;
extern double leftBorder;
extern double step;
extern bool basicEnable;
bool basicChange = false;
bool firstRestriction = false;
bool secondRestriction = false;
bool thirdRestriction = false;
bool one = false;

namespace l_1_b {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Variables_change
	/// </summary>
	public ref class Variables_change : public System::Windows::Forms::Form
	{
	public:
		Variables_change(void)
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
		~Variables_change()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  varComboBox;
	private: System::Windows::Forms::RadioButton^  basicButton;
	private: System::Windows::Forms::TextBox^  firstBox;
	private: System::Windows::Forms::TextBox^  secondBox;
	protected:



	private: System::Windows::Forms::Panel^  basicPanel;
	private: System::Windows::Forms::TextBox^  thirdBox;





	private: System::Windows::Forms::Label^  thirdLabel;


	private: System::Windows::Forms::Label^  secondLabel;


	private: System::Windows::Forms::Label^  firstLabel;


	private: System::Windows::Forms::RadioButton^  moreButton;
	private: System::Windows::Forms::RadioButton^  constButton;

	private: System::Windows::Forms::Button^  okButton;
	private: System::Windows::Forms::Button^  closeButton;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;












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
			this->varComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->basicButton = (gcnew System::Windows::Forms::RadioButton());
			this->firstBox = (gcnew System::Windows::Forms::TextBox());
			this->secondBox = (gcnew System::Windows::Forms::TextBox());
			this->basicPanel = (gcnew System::Windows::Forms::Panel());
			this->thirdBox = (gcnew System::Windows::Forms::TextBox());
			this->thirdLabel = (gcnew System::Windows::Forms::Label());
			this->secondLabel = (gcnew System::Windows::Forms::Label());
			this->firstLabel = (gcnew System::Windows::Forms::Label());
			this->moreButton = (gcnew System::Windows::Forms::RadioButton());
			this->constButton = (gcnew System::Windows::Forms::RadioButton());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->basicPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// varComboBox
			// 
			this->varComboBox->AllowDrop = true;
			this->varComboBox->FormattingEnabled = true;
			this->varComboBox->ImeMode = System::Windows::Forms::ImeMode::On;
			this->varComboBox->Location = System::Drawing::Point(172, 15);
			this->varComboBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->varComboBox->Name = L"varComboBox";
			this->varComboBox->Size = System::Drawing::Size(81, 24);
			this->varComboBox->TabIndex = 0;
			this->varComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Variables_change::varComboBox_SelectedIndexChanged);
			// 
			// basicButton
			// 
			this->basicButton->AutoSize = true;
			this->basicButton->Enabled = false;
			this->basicButton->Location = System::Drawing::Point(16, 59);
			this->basicButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->basicButton->Name = L"basicButton";
			this->basicButton->Size = System::Drawing::Size(63, 21);
			this->basicButton->TabIndex = 1;
			this->basicButton->Text = L"Basic";
			this->basicButton->UseVisualStyleBackColor = true;
			this->basicButton->CheckedChanged += gcnew System::EventHandler(this, &Variables_change::basicButton_CheckedChanged);
			// 
			// firstBox
			// 
			this->firstBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->firstBox->Location = System::Drawing::Point(95, 4);
			this->firstBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->firstBox->Name = L"firstBox";
			this->firstBox->Size = System::Drawing::Size(143, 22);
			this->firstBox->TabIndex = 2;
			this->firstBox->TextChanged += gcnew System::EventHandler(this, &Variables_change::firstBox_TextChanged);
			// 
			// secondBox
			// 
			this->secondBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->secondBox->Location = System::Drawing::Point(95, 36);
			this->secondBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->secondBox->Name = L"secondBox";
			this->secondBox->Size = System::Drawing::Size(143, 22);
			this->secondBox->TabIndex = 3;
			this->secondBox->TextChanged += gcnew System::EventHandler(this, &Variables_change::secondBox_TextChanged);
			// 
			// basicPanel
			// 
			this->basicPanel->Controls->Add(this->thirdBox);
			this->basicPanel->Controls->Add(this->thirdLabel);
			this->basicPanel->Controls->Add(this->secondLabel);
			this->basicPanel->Controls->Add(this->firstLabel);
			this->basicPanel->Controls->Add(this->firstBox);
			this->basicPanel->Controls->Add(this->secondBox);
			this->basicPanel->Location = System::Drawing::Point(16, 87);
			this->basicPanel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->basicPanel->Name = L"basicPanel";
			this->basicPanel->Size = System::Drawing::Size(256, 107);
			this->basicPanel->TabIndex = 4;
			// 
			// thirdBox
			// 
			this->thirdBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->thirdBox->Location = System::Drawing::Point(95, 69);
			this->thirdBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->thirdBox->Name = L"thirdBox";
			this->thirdBox->Size = System::Drawing::Size(143, 22);
			this->thirdBox->TabIndex = 7;
			this->thirdBox->TextChanged += gcnew System::EventHandler(this, &Variables_change::thirdBox_TextChanged);
			// 
			// thirdLabel
			// 
			this->thirdLabel->AutoSize = true;
			this->thirdLabel->Location = System::Drawing::Point(4, 73);
			this->thirdLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->thirdLabel->Name = L"thirdLabel";
			this->thirdLabel->Size = System::Drawing::Size(35, 17);
			this->thirdLabel->TabIndex = 6;
			this->thirdLabel->Text = L"step";
			// 
			// secondLabel
			// 
			this->secondLabel->AutoSize = true;
			this->secondLabel->Location = System::Drawing::Point(4, 39);
			this->secondLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->secondLabel->Name = L"secondLabel";
			this->secondLabel->Size = System::Drawing::Size(82, 17);
			this->secondLabel->TabIndex = 5;
			this->secondLabel->Text = L"right border";
			// 
			// firstLabel
			// 
			this->firstLabel->AutoSize = true;
			this->firstLabel->Location = System::Drawing::Point(4, 7);
			this->firstLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->firstLabel->Name = L"firstLabel";
			this->firstLabel->Size = System::Drawing::Size(73, 17);
			this->firstLabel->TabIndex = 4;
			this->firstLabel->Text = L"left border";
			// 
			// moreButton
			// 
			this->moreButton->AutoSize = true;
			this->moreButton->Enabled = false;
			this->moreButton->Location = System::Drawing::Point(92, 59);
			this->moreButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->moreButton->Name = L"moreButton";
			this->moreButton->Size = System::Drawing::Size(61, 21);
			this->moreButton->TabIndex = 5;
			this->moreButton->Text = L"More";
			this->moreButton->UseVisualStyleBackColor = true;
			this->moreButton->CheckedChanged += gcnew System::EventHandler(this, &Variables_change::moreButton_CheckedChanged);
			// 
			// constButton
			// 
			this->constButton->AutoSize = true;
			this->constButton->Enabled = false;
			this->constButton->Location = System::Drawing::Point(165, 59);
			this->constButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->constButton->Name = L"constButton";
			this->constButton->Size = System::Drawing::Size(85, 21);
			this->constButton->TabIndex = 6;
			this->constButton->Text = L"Constant";
			this->constButton->UseVisualStyleBackColor = true;
			this->constButton->CheckedChanged += gcnew System::EventHandler(this, &Variables_change::constButon_CheckedChanged);
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(16, 12);
			this->okButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(68, 28);
			this->okButton->TabIndex = 7;
			this->okButton->Text = L"Save";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &Variables_change::okButton_Click);
			// 
			// closeButton
			// 
			this->closeButton->Location = System::Drawing::Point(92, 12);
			this->closeButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(67, 28);
			this->closeButton->TabIndex = 8;
			this->closeButton->Text = L"Cancel";
			this->closeButton->UseVisualStyleBackColor = true;
			this->closeButton->Click += gcnew System::EventHandler(this, &Variables_change::closeButton_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Variables_change::timer1_Tick);
			// 
			// Variables_change
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(287, 208);
			this->ControlBox = false;
			this->Controls->Add(this->closeButton);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->varComboBox);
			this->Controls->Add(this->constButton);
			this->Controls->Add(this->basicButton);
			this->Controls->Add(this->moreButton);
			this->Controls->Add(this->basicPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Variables_change";
			this->Text = L"Variables proprties";
			this->Load += gcnew System::EventHandler(this, &Variables_change::Variables_change_Load);
			this->basicPanel->ResumeLayout(false);
			this->basicPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		System::String^ pointToComma(System::String^ text)
		{
			System::String^ tmp = L"";
			for (int i = 0;i < text->Length;i++)
			{
				if (text[i] == L'.')
					tmp += L',';
				else
					tmp += text[i];
			}
			return tmp;
		}
		bool doubleRestriction(System::String^ text)
		{
			bool result = true;
			bool exit = false;
			bool min = false;
			if (text->Length > 14 || text->Length == 0)
				result = false;
			if (text->Length == 1 && (text[0] == L',' || text[0] == L'-'))
				result = false;
			if (text->Length > 1)
			{
				if (text[0] == L'-'&&text[1] == L',')
					result = false;
			}
			if (result)
			{
				System::String^ restr = L"0123456789.,-";
				for (int i = 0;i < text->Length;i++)
				{
					if (!result)
						break;
					for (int j = 0;j < restr->Length;j++)
					{
						if (text[i] == L'-'&& i != 0)
						{
							result = false;
							break;
						}
						if (text[i] == restr[j])
							break;
						if (j == (restr->Length - 1))
							result = false;
					}
				}
				if (text->Length == 1 && text[0] != ',' && text[0]!=L'-')
					exit = true;
				if (result && !exit)
				{
					if (text[0] == L'0'&&text[1] != ',')
						result = false;
					if (text->Length == 2 && text[0] == L'0' && text[1] == ',')
						result = false;
					if (result)
					{
						for (int i = 0, j = 0;i < text->Length;i++)
						{
							if (text[i] == ',')
								j++;
							if (j > 1)
							{
								result = false;
								break;
							}
						}
					}

				}
			}
			return result;
		}
		bool basicRestriction()
		{
			bool result = true;
			double a = System::Convert::ToDouble(pointToComma(firstBox->Text));
			double b = System::Convert::ToDouble(pointToComma(secondBox->Text));
			System::String^ str = L"";
			str = pointToComma(thirdBox->Text);
			double s = System::Convert::ToDouble(pointToComma(thirdBox->Text));
			if (a>b)
				result = false;
			if (abs(b-a) < s)
				result = false;
			if (s <= 0)
				result = false;
			return result;
		}
private: System::Void basicButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		firstLabel->Text = L"left border";
		secondLabel->Text = L"right border";
		thirdLabel->Text = L"step";
		firstBox->Visible = true;
		secondBox->Visible = true;
		thirdBox->Visible = true;
		firstBox->Text = System::Convert::ToString(pars.showVariableValue(varComboBox->SelectedIndex).value);
		secondBox->Text = System::Convert::ToString(rightBorder);
		thirdBox->Text = System::Convert::ToString(pars.showVariableValue(varComboBox->SelectedIndex).step);
}
private: System::Void moreButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		firstLabel->Text = L"value";
		secondLabel->Text = L"step";
		thirdLabel->Text = L"";
		firstBox->Visible = true;
		secondBox->Visible = true;
		thirdBox->Visible = false;
		firstBox->Text = System::Convert::ToString(pars.showVariableValue(varComboBox->SelectedIndex).value);
		secondBox->Text = System::Convert::ToString(pars.showVariableValue(varComboBox->SelectedIndex).step);
}
private: System::Void constButon_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		firstLabel->Text = L"value";
		secondLabel->Text = L"";
		thirdLabel->Text = L"";
		firstBox->Visible = true;
		secondBox->Visible = false;
		thirdBox->Visible = false;
		firstBox->Text = System::Convert::ToString(pars.showVariableValue(varComboBox->SelectedIndex).value);
}
private: System::Void Variables_change_Load(System::Object^  sender, System::EventArgs^  e) {
	for (unsigned int i = 0;i < pars.numberVariables();i++)
	{
		varComboBox->Items->Add(pars.showVariable(i));
	}
	okButton->Enabled = false;
	firstLabel->Text = L"";
	secondLabel->Text = L"";
	thirdLabel->Text = L"";
	firstBox->Visible = false;
	secondBox->Visible = false;
	thirdBox->Visible = false;
}
private: System::Void closeButton_Click(System::Object^  sender, System::EventArgs^  e) {
	changeVariable = false;
	if (basicChange)
	{
		basicEnable = true;
	}
	this->Close();
}
private: System::Void varComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (pars.showVariableValue(varComboBox->SelectedIndex).basicVariable)
	{
		basicButton->Enabled = true;
		basicButton->Checked = true;
		if (pars.numberVariables() > 1)
		{
			moreButton->Enabled = true;
			constButton->Enabled = true;
		}
	}
	else if (pars.showVariableValue(varComboBox->SelectedIndex).moreVariable)
	{
		basicButton->Enabled = true;
		moreButton->Enabled = true;
		constButton->Enabled = true;
		moreButton->Checked = true;
		if (basicChange)
			basicButton->Enabled = false;
	}
	else if (pars.showVariableValue(varComboBox->SelectedIndex).constVariable)
	{
		basicButton->Enabled = true;
		moreButton->Enabled = true;
		constButton->Enabled = true;
		constButton->Checked = true;
		if (basicChange)
			basicButton->Enabled = false;
	}
	else
	{
		if (basicChange)
		{
			constButton->Checked = true;
			moreButton->Enabled= true;
			constButton->Enabled = true;
			basicButton->Enabled = false;
		}
		else
		{
			basicButton->Enabled = true;
			basicButton->Checked= true;
			moreButton->Enabled = false;
			constButton->Enabled = false;
		}
	}
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	for (unsigned int i = 0;i < pars.numberVariables();i++)
	{
		if (pars.showVariableValue(i).basicVariable)
		{
			basicChange = true;
			if (!one)
			{
				moreButton->Enabled = true;
				constButton->Enabled = true;
				one = true;
			}
			break;
		}
		if(i == (pars.numberVariables()-1))
		   basicChange = false;
	}
	if (!basicChange)
	{
		rightBorder = 0;
		leftBorder = 0;
		step = 0;
		one = false;
	}
	if (basicButton->Checked)
	{
		if (firstRestriction&&secondRestriction&&thirdRestriction&&basicRestriction())
				okButton->Enabled = true;
		else
			okButton->Enabled = false;
	}
	else if (moreButton->Checked)
	{
		if (firstRestriction&&secondRestriction)
			okButton->Enabled = true;
		else
		    okButton->Enabled = false;
	}
	else if (constButton->Checked)
	{
		if (firstRestriction)
			okButton->Enabled = true;
		else
			okButton->Enabled = false;
	}
}
private: System::Void firstBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (doubleRestriction(pointToComma(firstBox->Text)))
	{
		firstRestriction = true;
		firstBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
	}
	else
	{
		firstRestriction = false;
		firstBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
	}
}
private: System::Void secondBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (doubleRestriction(pointToComma(secondBox->Text)))
	{
		secondBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		secondRestriction = true;
	}
	else
	{
		secondBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		secondRestriction = false;
	}
}
private: System::Void thirdBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (doubleRestriction(pointToComma(thirdBox->Text)))
	{
		thirdBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		thirdRestriction = true;
	}
	else
	{
		thirdBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));
		thirdRestriction = false;
	}
}
private: System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (basicButton->Checked)
	{
		variableType tmp;
		tmp.basicVariable = true;
		tmp.moreVariable = false;
		tmp.constVariable = false;
		tmp.value = System::Convert::ToDouble(pointToComma(firstBox->Text));
		leftBorder = System::Convert::ToDouble(pointToComma(firstBox->Text));
		rightBorder = System::Convert::ToDouble(pointToComma(secondBox->Text));
		step = System::Convert::ToDouble(pointToComma(thirdBox->Text));
		tmp.step = System::Convert::ToDouble(pointToComma(thirdBox->Text));
		pars.setVariable(tmp, varComboBox->SelectedIndex);
	}
	else if (moreButton->Checked)
	{
		variableType tmp;
		tmp.basicVariable = false;
		tmp.moreVariable = true;
		tmp.constVariable = false;
		tmp.value = System::Convert::ToDouble(pointToComma(firstBox->Text));
		tmp.step = System::Convert::ToDouble(pointToComma(secondBox->Text));
		pars.setVariable(tmp, varComboBox->SelectedIndex);
	}
	else if (constButton->Checked)
	{
		variableType tmp;
		tmp.basicVariable = false;
		tmp.moreVariable = false;
		tmp.constVariable = true;
		tmp.value = System::Convert::ToDouble(pointToComma(firstBox->Text));
		pars.setVariable(tmp, varComboBox->SelectedIndex);
	}
	
}
};
}
