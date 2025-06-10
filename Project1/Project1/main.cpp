#include "Sourse.h"




void Menu() {
	std::cout << "[1]������������� ������ �� �������� � ������� � �������� ����;\n[2]����� ������ � ��������;\n[0]�����.\n";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream fin("file.txt");

	try {
		CheckInputFile(fin);
		std::ofstream fout("file.txt", std::ios::app);
		CheckOutputFile(fout);

		int32_t size{ ItSize(fin) };
		Student* students = new Student[size];

		GoToArr(fin, fout, students, size);
		while (true) {
			Menu();
			int switch_on{};
			std::cout << "����� ������ == ";
			std::cin >> switch_on;
			std::cin.ignore();
			switch (switch_on)
			{
			default:
				break;
			case 1:
				FuncForA(fin, fout, students, size);
				std::cout << "your data was recorded\n";
				break;
			case 2: {
				std::string surname;
				std::cout << "������� �������: ";
				getline(std::cin, surname);
				FindSurname(students, size, surname.c_str());
				break;
			}
			case 0:
				fin.close();
				fout.close();
				delete[]students;
				return 0;
			}
		}
	}
	catch (const char* m) {
		std::cout << m;
	}

	fin.close();
	return 0;
}