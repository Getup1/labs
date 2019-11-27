#include <iostream>
#include <cwchar>
#include <vector>
#include <string>

struct Student {
	std::wstring name;
	short birthYear;
	short year;
	short marks[6];
};

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	
	int studentCount;
	std::wcin >> studentCount;
	Student *students = new Student[studentCount]();
	for(int i = 0; i < studentCount; i++) {
		std::wcin >> students[i].name;
		std::wcin >> students[i].birthYear;
	        std::wcin >> students[i].year;
   		for(int j = 0; j < 6; j++)
			std::wcin >> students[i].marks[j];		
	}
	for(int i = 0; i < studentCount; i++) {
		if(students[i].name[0] == L'Б')
			std::wcout << students[i].name << L" " << students[i].birthYear << std::endl;
	}
	return 0;
}
