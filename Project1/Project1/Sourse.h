#ifndef SOURSE_H
#define SOURSE_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

struct Student {
	char name[30];
	int group;
	double grade;
};


void CheckInputFile(std::ifstream& fin);
void CheckOutputFile(std::ofstream& fout);
int32_t ItSize(std::ifstream& fin);
int32_t compareName(const void* a, const void* b);
void FuncForA(std::ifstream& fin, std::ofstream& fout, Student* students, int32_t size);
void FindSurname(Student* students, int32_t size, const char* surname);
void GoToArr(std::ifstream& fin, std::ofstream& fout, Student* students, int32_t size);



#endif SOURSE_H