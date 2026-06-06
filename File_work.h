#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int makeCount() {
  bool value = false;
  int count;
  do {
    cin >> count;
    if (cin.fail()) {
      cin.clear(); //сброс флага ошибки
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Вы ввели не число, попробуйте снова: ";

    }
    else if (count < 1) {
      cout << "Введите натуральное число: ";
    }
    else
      value = true;
  } while (!value);

  return count;
}

int makeFile(const char* f_name) {
  ofstream file(f_name);
  int count;
  if (!file.is_open()) {
    cerr << "Файл не открыт!!" << "\n";
    return -1;
  }
  else {
    cout << "Введите количество элементов Money, которые вы бы хотели добавить в файл: ";
    
    count = makeCount();
    for (int i = 0; i < count; ++i)
    {
      Money a;
      cout << "Введите через пробел кол-во рублей и копеек для Money[" << i + 1 << "]: ";
      cin >> a;
      file << a;
    }

    file.close();
  }
  return count;
}

int printFile(const char* f_name) {
  fstream file;
  
  int count = 0;
  file.open(f_name, ios::in);
  if (!file.is_open()) {
    cerr << "Файл не открыт!!" << endl;
    return -1;
  }
  else {
    Money m;
    while (file >> m) {
      if (file.eof()) break; //если достигли конец файла
      cout << m;
      count++;
    }
    file.close();
  }
  return count;
}

int del_file(const char* f_name, Money& target) {
  int count = 0;
  fstream file(f_name, ios::in);
  
  if (!file.is_open()) {
    cerr << "Файл не открыт)))" << endl;
    return -1;
  }

  fstream result;
  result.open("result.txt", ios::out);
  if (!result.is_open()) {
    cerr << "Файл не открыт!!" << endl;
    return -1;
  }

  Money m;
  while (file >> m) {
    if (file.eof()) break; //если достигли конец файла
    if (m == target) {
      result << m;
    }
    else {
      count++;
    }
      
      
  }
  file.close();
  result.close();
  remove(f_name); // стирание старого файла
  rename("result.txt", f_name); //переименование старого файла
  
  return count;
}

int halve_file(const char* f_name, Money& target) {
  int count = 0;
  fstream file(f_name, ios::in);
  if (!file.is_open()) {
    cerr << "Файл не открыт)))" << endl;
    return -1;
  }

  fstream result;
  result.open("result.txt", ios::out);
  if (!result.is_open()) {
    cerr << "Файл не открыт!!" << endl;
    return -1;
  }

  Money m;
  while (file >> m) {
    if (file.eof()) break; //если достигли конец файла
    if (m == target) {
      result << m*0.5;
      count++;
    }
    else {
      result << m;
    }
  }

  file.close();
  result.close();
  remove(f_name); // стирание старого файла
  rename("result.txt", f_name); //переименование старого файла

  return count;
}

int addElements(const char* f_name, int k) {
  fstream file(f_name, ios::in);
  if (!file.is_open()) {
    cerr << "Файл не открыт)))" << endl;
    return -1;
  }

  fstream result;
  result.open("result.txt", ios::out);
  if (!result.is_open()) {
    cerr << "Файл не открыт!!" << endl;
    return -1;
  }

  for (int i = 0; i < k; ++i) {
    Money a;
    cout << "Введите через пробел кол-во рублей и копеек для Money[" << i + 1 << "]: ";
    cin >> a;
    result << a;
  }

  Money m;
  while (file >> m) {
    if (file.eof()) break; //если достигли конец файла
    result << m;
  }

  file.close();
  result.close();
  remove(f_name); // стирание старого файла
  rename("result.txt", f_name);
  return k;
}