#include "Sourse.h"


void CheckInputFile(std::ifstream& fin) {
	if (!fin.good()) {
		throw "file isnt exist\n";
	}
	if (!fin) {
		throw "input file error\n";
	}
	if (fin.peek() == EOF) {
		throw "file is empty\n";
	}
}


void CheckOutputFile(std::ofstream& fout) {
	if (!fout.good()) {
		throw "file isnt exist\n";
	}
	if (!fout) {
		throw "output file error\n";
	}
}

int32_t ItSize(std::ifstream& fin) {
	int32_t size = 0;
	std::string str;
	while (std::getline(fin, str)) {
		++size;
	}
	fin.clear();
	fin.seekg(0);
	return size;
}


int32_t compareName(const void* a, const void* b) {
	return *(char*)a - *(char*)b;
}

void GoToArr(std::ifstream& fin, std::ofstream& fout, Student* students, int32_t size) {
	char delim[] = ";";
	fin.clear();
	fin.seekg(0);

	int32_t i{};
	std::string str;
	while (getline(fin, str)) {
		char* copy = new char[str.length() + 1];
		std::strcpy(copy, str.c_str());
		std::strcpy(students[i].name, strtok(copy, delim));
		students[i].group = std::stoi(strtok(NULL, delim));
		students[i].grade = std::stod(strtok(NULL, delim));
		++i;
		delete[]copy;
	}

	fin.close();
}

void FuncForA(std::ifstream& fin, std::ofstream& fout, Student* students, int32_t size) {
	qsort(students, size, sizeof(Student), compareName);
	for (int32_t i{}; i < size; ++i) {
		fout << students[i].name << ";";
		fout << students[i].group << ";";
		fout << students[i].grade << '\n';
	}

}


void FindSurname(Student* students, int32_t size, const char* surname) {
	bool find{ false };

	for (int32_t i{}; i < size; ++i) {
		if (std::strncmp(students[i].name, surname, std::strlen(surname)) == 0) {
			std::cout << "Наш студент " << surname << ", в группе " << students[i].group << ", со средним баллом " << students[i].grade << std::endl;
			find = true;
		}
	}
	if (!find) {
		std::cout << "Такого студента нет." << std::endl;
	}

}