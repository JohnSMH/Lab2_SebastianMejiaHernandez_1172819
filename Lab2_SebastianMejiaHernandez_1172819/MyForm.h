#pragma once
#include <chrono>
#include <thread>

namespace Lab2SebastianMejiaHernandez1172819 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std::this_thread; 
	using namespace std::chrono; 
	using std::chrono::system_clock;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 96);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(37, 173);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 52);
			this->label2->TabIndex = 1;
			this->label2->Text = L"1- Tortuga\r\n2- Liebre\r\n3- OUCH\r\n9- Meta";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::Label2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(119, 173);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Empezar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(883, 278);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void Label2_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("BANG \n Y ARRANCAN");
		int camino[78];

		Random r;
;
		int rtort;
		int rlieb;

		for (int i = 0; i < 78; i++)
		{
			camino[i] = 0;
		}

		for (int i = 69; i < 78; i++)
		{
			camino[i] = 9;
		}

		for (int *i = &camino[0]; *i < 9; i++)
		{
			label1->Text = label1->Text + *i;

		}

		int* t;
			t= &camino[0];
			int* l;
			l= &camino[0];
			bool ganar = false;
			
		while (!ganar)
		{
			*t = 0;
			*l = 0;
			label1->Text = "";
			rtort = r.Next(10);
			rlieb = r.Next(10);
			switch (rtort)
			{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				t = t + 3;
				break;
			case 6:
			case 7:
				if (t - 6 < &camino[0])
				{
					t = &camino[0];
				}
				else
				{
					t = t - 6;
				}
				break;
			case 8:
			case 9:
			case 10:
				t++;
				break;
			default:
				break;
			}

			switch (rlieb)
			{
			case 1:
			case 2:
				break;
			case 3:
			case 4:
				l = l + 9;
				break;
			case 5:
				if (l - 12 < &camino[0])
				{
					l = &camino[0];
				}
				else
				{
					l = l - 12;
				}
				break;
			case 6:
			case 7:
			case 8:
				l = l + 1;
				break;
			case 9:
			case 10:
				if (l - 2 < &camino[0])
				{
					l = &camino[0];
				}
				else
				{
					l = l - 2;
				}
				break;
			default:
				break;
			}

			if (*t == 9)
			{
				ganar = true;
			}

			if (*l == 9)
			{
				ganar = true;
			}

			if (l==t)
			{
				*t = 3;
			}
			else {
				*t = 1;
				*l = 2;
			}
			
			for (int* i = &camino[0]; *i < 9; i++)
			{
				label1->Text = label1->Text + *i;

			}
			
			sleep_for(10000ns);
		}

		
		label1->Text = "";
		for (int* i = &camino[0]; *i < 9; i++)
		{
			label1->Text = label1->Text + *i;

		}

		if (t > &camino[68])
		{
			MessageBox::Show("La tortuga ha ganado!!!");
		}

		if (l > &camino[68])
		{
			MessageBox::Show("La liebre ganó");
		}

		/*switch (rtort)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			t = t + 3;
		case 6:
		case 7:
			if (t - 6 < 0)
			{
				t = &camino[0];
			}
			else
			{
				t = t - 6;
			}
			break;
		case 8:
		case 9:
		case 10:
			t++;
		default:
			break;
		}

		switch (rlieb)
		{
		case 1:
		case 2:
			break;
		case 3:
		case 4:
			l = l + 9;
			break;
		case 5:
			if (l - 12 < 0)
			{
				l = &camino[0];
			}
			else
			{
				l = l - 12;
			}
		case 6:
		case 7:
		case 8:
			l = l + 1;
			break;
		case 9:
		case 10:
			if (l - 2 < 0)
			{
				l = &camino[0];
			}
			else
			{
				l = l - 2;
			}
		default:
			break;
		}*/

		


	}
	};
}
