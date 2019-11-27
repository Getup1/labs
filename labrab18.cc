#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

struct Employee {
	std::wstring name;
	unsigned short birthYear;
	unsigned short employmentYear;
	unsigned short children;
	unsigned short salary;
};

Employee employees[30];
int lastEmployee = -1;

void showEmployee(size_t index) {
	std::wcout << employees[index].name << " " 
		   << employees[index].birthYear << " "
		   << employees[index].employmentYear << " " 
		   << employees[index].children << " " 
		   << employees[index].salary << " " 
		   << std::endl;
}

void add() {
	if(lastEmployee + 1 == 30) {
		std::wcout << L"Нет места для новой записи." << std::endl;
		return;
	}
	lastEmployee++;
	std::wcin >> employees[lastEmployee].name 
		  >> employees[lastEmployee].birthYear 
		  >> employees[lastEmployee].employmentYear 
		  >> employees[lastEmployee].children
		  >> employees[lastEmployee].salary;
}

void process() {
	if(lastEmployee < 0) {
		std::wcout << L"Отсутствуют записи." << std::endl;
		return;
	}

	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	time_t tt = std::chrono::system_clock::to_time_t(now);
	tm time = *localtime(&tt);
	int year = time.tm_year + 1900;

	for(int i = 0; i <= lastEmployee; i++) {
		if((year - employees[i].birthYear) % 10 == 0)
			showEmployee(i);
	}
}

void show() {
	if(lastEmployee < 0) {
		std::wcout << L"Отсутствуют записи." << std::endl;
		return;
	}
	for(int i = 0; i <= lastEmployee; i++) {
		showEmployee(i);
	}
}

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");

	bool running = true;
	while(running) {
		std::wcout << L"[д]обавить -- добавить запись\n[о]бработать -- обработать данные\n[п]оказать -- отобразить все записи\n[в]ыход -- выйти из программы\n";
		std::wstring ins;
		std::wcin >> ins;
		if(ins == L"в" || ins == L"выход")
			running = false;
		else if(ins == L"+" || ins == L"д" || ins == L"добавить")
			add();
		else if(ins == L"о" || ins == L"обрабоать")
			process();
		else if(ins == L"п" || ins == L"показать")
			show();	
	}
	return 0;
}
