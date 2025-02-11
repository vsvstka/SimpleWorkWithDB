#pragma once

namespace lab5PPP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_close;

	private: System::Windows::Forms::Button^ button_sort;
	private: System::Windows::Forms::Button^ button_delite;






	private: System::Windows::Forms::Button^ button_add;

	private: System::Windows::Forms::Button^ button_download;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ salary;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->salary = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_close = (gcnew System::Windows::Forms::Button());
			this->button_sort = (gcnew System::Windows::Forms::Button());
			this->button_delite = (gcnew System::Windows::Forms::Button());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->button_download = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id, this->name,
					this->salary
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(582, 177);
			this->dataGridView1->TabIndex = 0;
			// 
			// id
			// 
			this->id->HeaderText = L"ID";
			this->id->MinimumWidth = 6;
			this->id->Name = L"id";
			this->id->Width = 125;
			// 
			// name
			// 
			this->name->HeaderText = L"Название";
			this->name->MinimumWidth = 6;
			this->name->Name = L"name";
			this->name->Width = 125;
			// 
			// salary
			// 
			this->salary->HeaderText = L"Зарплата";
			this->salary->MinimumWidth = 6;
			this->salary->Name = L"salary";
			this->salary->Width = 125;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_close);
			this->groupBox1->Controls->Add(this->button_sort);
			this->groupBox1->Controls->Add(this->button_delite);
			this->groupBox1->Controls->Add(this->button_add);
			this->groupBox1->Controls->Add(this->button_download);
			this->groupBox1->Location = System::Drawing::Point(600, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(347, 177);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Действия";
			// 
			// button_close
			// 
			this->button_close->Location = System::Drawing::Point(242, 21);
			this->button_close->Name = L"button_close";
			this->button_close->Size = System::Drawing::Size(105, 29);
			this->button_close->TabIndex = 4;
			this->button_close->Text = L"Закрыть";
			this->button_close->UseVisualStyleBackColor = true;
			this->button_close->Click += gcnew System::EventHandler(this, &MyForm::button_close_Click);
			// 
			// button_sort
			// 
			this->button_sort->Location = System::Drawing::Point(25, 126);
			this->button_sort->Name = L"button_sort";
			this->button_sort->Size = System::Drawing::Size(215, 29);
			this->button_sort->TabIndex = 3;
			this->button_sort->Text = L"Сортировать по ID";
			this->button_sort->UseVisualStyleBackColor = true;
			this->button_sort->Click += gcnew System::EventHandler(this, &MyForm::button_sort_Click);
			// 
			// button_delite
			// 
			this->button_delite->Location = System::Drawing::Point(25, 91);
			this->button_delite->Name = L"button_delite";
			this->button_delite->Size = System::Drawing::Size(215, 29);
			this->button_delite->TabIndex = 2;
			this->button_delite->Text = L"Удалить";
			this->button_delite->UseVisualStyleBackColor = true;
			this->button_delite->Click += gcnew System::EventHandler(this, &MyForm::button_delite_Click);
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(25, 56);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(215, 29);
			this->button_add->TabIndex = 1;
			this->button_add->Text = L"Добавить";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// button_download
			// 
			this->button_download->Location = System::Drawing::Point(25, 21);
			this->button_download->Name = L"button_download";
			this->button_download->Size = System::Drawing::Size(215, 29);
			this->button_download->TabIndex = 0;
			this->button_download->Text = L"Загрузить";
			this->button_download->UseVisualStyleBackColor = true;
			this->button_download->Click += gcnew System::EventHandler(this, &MyForm::button_download_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 264);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void button_close_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_download_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_delite_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_sort_Click(System::Object^ sender, System::EventArgs^ e);

};
}
