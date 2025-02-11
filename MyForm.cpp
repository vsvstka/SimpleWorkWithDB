#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::OleDb;

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	lab5PPP::MyForm form;
	Application::Run(% form);
}

System::Void lab5PPP::MyForm::button_close_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void lab5PPP::MyForm::button_download_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Clear();

	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "SELECT * FROM [table1]";
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

	if (dbReader->HasRows == false) {
		MessageBox::Show("Ошибка!","Ошибка!");
	}
	else {
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["id"], dbReader["name"], dbReader["salary"]);
		}
	}

	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void lab5PPP::MyForm::button_add_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите только одну строку!","Внимание!");
		return;
	}
	int index = dataGridView1->SelectedRows[0]->Index;
	if (dataGridView1->Rows[index]->Cells[0] == nullptr ||
		dataGridView1->Rows[index]->Cells[1] == nullptr ||
		dataGridView1->Rows[index]->Cells[2] == nullptr) {
		MessageBox::Show("Вы ввели не все данные!", "Внимание!");
		return;
	}


	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ name = dataGridView1->Rows[index]->Cells[1]->Value->ToString();
	String^ salary = dataGridView1->Rows[index]->Cells[2]->Value->ToString();

	bool fl = true;
	int kol = 0;
	for each (char ch in id) {
		if (ch < '0' || ch > '9') {
			fl = false;
			break;
		}
		kol += 1;
	}
	if (!fl || String::IsNullOrWhiteSpace(id) || kol > 7) {
		MessageBox::Show("Вы ввели некорректные данные!", "Внимание!");
		return;
	}

	kol = 0;
	fl = true;
	for each (char ch in salary) {
		if (ch < '0' || ch > '9') {
			fl = false;
			break;
		}
		kol += 1;
	}
	if (!fl || String::IsNullOrWhiteSpace(salary) || kol > 7) {
		MessageBox::Show("Вы ввели некорректные данные!", "Внимание!");
		return;
	}

	fl = true;
	for (int i = 0; i < index; i++) {
		if (id == dataGridView1->Rows[i]->Cells[0]->Value->ToString()) {
			fl = false;
			break;
		}
	}

	if (!fl) {
		MessageBox::Show("Вы ввели некорректные данные! ID должен быть различен","Внимание!");
		return;
	}

	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "INSERT INTO [table1] VALUES (" + id + ", '" + name + "', " + salary + ")";
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
	
	if (dbCommand->ExecuteNonQuery() != 1) {
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	}
	else {
		MessageBox::Show("Данные добавлены!", "Готово!");
	}

	dbConnection->Close();

	return System::Void();
}

System::Void lab5PPP::MyForm::button_delite_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("Выберите только одну строку!", "Внимание!");
		return;
	}
	int index = dataGridView1->SelectedRows[0]->Index;

	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();

	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "DELETE FROM [table1] WHERE id = " + id;
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);



	if (dbCommand->ExecuteNonQuery() != 1) {
		MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
	}
	else {
		MessageBox::Show("Данные удалены!", "Готово!");
		dataGridView1->Rows->RemoveAt(index);
	}

	dbConnection->Close();
	return System::Void();
}

System::Void lab5PPP::MyForm::button_sort_Click(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Clear();

	String^ connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();
	String^ query = "SELECT * FROM [table1] ORDER BY id";
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbCommand->ExecuteReader();

	if (dbReader->HasRows == false) {
		MessageBox::Show("Ошибка!", "Ошибка!");
	}
	else {
		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["id"], dbReader["name"], dbReader["salary"]);
		}
	}

	dbReader->Close();
	dbConnection->Close();
	return System::Void();
}
