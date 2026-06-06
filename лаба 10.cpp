#include <iostream>
#include "Money.h"
#include "File_work.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
  setlocale(LC_ALL, "RU");
  int choice = -1;
  string filename;

  do {
    cout << "1. Создать файл\n";
    cout << "2. Просмотреть файл\n";
    cout << "3. Удалить записи, не равные заданной сумме\n";
    cout << "4. Уменьшить заданную сумму в 2 раза\n";
    cout << "5. Добавить K записей в начало файла\n";
    cout << "0. Выход\n";
    cout << "Выбор: ";
    cin >> choice;

    if (choice == 0) break;

    cout << "Имя файла: ";
    cin >> filename;
    filename += ".txt";

    switch (choice) {
    case 1: {
      int count = makeFile(filename.c_str());
      if (count >= 0) cout << "Создано записей: " << count << "\n";
      else cout << "Ошибка создания файла\n";
      break;
    }
    case 2: {
      int count = printFile(filename.c_str());
      if (count == 0) cout << "Файл пуст\n";
      else if (count < 0) cout << "Ошибка чтения файла\n";
      break;
    }
    case 3: {
      Money target;
      cout << "Сумма для сохранения (рубли копейки): ";
      cin >> target;
      int deleted = del_file(filename.c_str(), target);
      if (deleted >= 0) cout << "Удалено записей: " << deleted << "\n";
      else cout << "Ошибка обработки файла\n";
      break;
    }
    case 4: {
      Money target;
      cout << "Сумма для уменьшения (рубли копейки): ";
      cin >> target;
      int changed = halve_file(filename.c_str(), target);
      if (changed >= 0) cout << "Изменено записей: " << changed << "\n";
      else cout << "Ошибка обработки файла\n";
      break;
    }
    case 5: {
      int k;
      cout << "Количество записей для добавления: ";
      cin >> k;
      int added = addElements(filename.c_str(), k);
      if (added >= 0) cout << "Добавлено записей: " << added << "\n";
      else cout << "Ошибка обработки файла\n";
      break;
    }
    default:
      cout << "Неверный выбор\n";
    }
    cout << "\n";
  } while (true);

  return 0;
}