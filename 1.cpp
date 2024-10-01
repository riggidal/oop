#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

struct Flat {
  int rooms;        // Количество комнат
  float total_area; // Общая площадь в квадратных метрах
  float living_area; // Жилая площадь в квадратных метрах
  int balconies;     // Количество балконов
  int floor;         // Этаж квартиры
  int storeys;       // Количество этажей в доме
  char district[50]; // Название района
};

void inputFlats(Flat flats[], int size);
void displayFlats(const Flat flats[], int size);
void displayTopFloorFlats(const Flat flats[], int size);
void calculateTotalAreaByInput(const Flat flats[], int size);
int getValidNumber(const char *prompt);

int main() {
  // Вводим количество квартир
  int num_flats = getValidNumber("Введите количество квартир (5-10): ");

  // Создаем массив структур Flat
  Flat *flats = new Flat[num_flats];

  // Ввод данных по каждой квартире
  inputFlats(flats, num_flats);

  // Данные для текстирования кода
  /*Flat flats[5] = {{3, 85.0, 65.0, 1, 5, 5, "Район_1"},*/
  /*                 {2, 60.0, 45.0, 0, 4, 6, "Район_1"},*/
  /*                 {4, 120.0, 90.0, 2, 6, 6, "Район_3"},*/
  /*                 {2, 50.0, 40.0, 1, 3, 3, "Район_4"},*/
  /*                 {3, 75.0, 60.0, 1, 5, 5, "Район_5"}};*/
  /**/
  /*int num_flats = 5;*/

  // Вывод содержимого всего массива
  displayFlats(flats, num_flats);

  calculateTotalAreaByInput(flats, num_flats); // Расчет общей площади по району
  displayTopFloorFlats(flats, num_flats); // Вывод квартир на верхних этажах

  // Очистка памяти
  delete[] flats;

  return 0;
}

// Функция для безопасного ввода числа с проверкой
int getValidNumber(const char *prompt) {
  int num;
  while (true) {
    printf("%s", prompt);
    if (scanf("%d", &num) == 1 && num >= 5 && num <= 10) {
      return num;
    } else {
      printf("Ошибка: введите целое число от 5 до 10.\n");
      while (getchar() != '\n')
        ; // Очистка буфера ввода
    }
  }
}

// Функция для ввода данных по каждой квартире
void inputFlats(Flat flats[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("\nВведите данные для квартиры #%d:\n", i + 1);

    printf("Количество комнат: ");
    scanf("%d", &flats[i].rooms);

    printf("Общая площадь (кв.м): ");
    scanf("%f", &flats[i].total_area);

    printf("Жилая площадь (кв.м): ");
    scanf("%f", &flats[i].living_area);

    printf("Количество балконов: ");
    scanf("%d", &flats[i].balconies);

    printf("Этаж: ");
    scanf("%d", &flats[i].floor);

    printf("Количество этажей в доме: ");
    scanf("%d", &flats[i].storeys);

    printf("Район: ");
    getchar(); // Очистка буфера перед вводом строки
    scanf("%50s", flats[i].district);
  }
}

// Функция для вывода данных по всем квартирам
void displayFlats(const Flat flats[], int size) {
  printf("\nДанные всех квартир:\n");
  for (int i = 0; i < size; ++i) {
    printf("Квартира #%d:\n", i + 1);
    printf("Количество комнат: %d, Общая площадь: %.2f кв.м, Жилая площадь: "
           "%.2f кв.м, Балконов: %d\n",
           flats[i].rooms, flats[i].total_area, flats[i].living_area,
           flats[i].balconies);
    printf("Этаж: %d, Этажей в доме: %d, Район: %s\n", flats[i].floor,
           flats[i].storeys, flats[i].district);
  }
}

// Функция для вывода квартир, находящихся на верхнем этаже в домах с 5 и более
// этажами
void displayTopFloorFlats(const Flat flats[], int size) {
  printf("\nКвартиры на верхних этажах домов с 5 и более этажами:\n");
  for (int i = 0; i < size; ++i) {
    if (flats[i].floor == flats[i].storeys && flats[i].storeys >= 5) {
      printf("Квартира в районе %s, Этаж: %d, Общая площадь: %.2f кв.м, "
             "Количество комнат: %d\n",
             flats[i].district, flats[i].floor, flats[i].total_area,
             flats[i].rooms);
    }
  }
}

// Функция для ввода названия района с клавиатуры
void calculateTotalAreaByInput(const Flat flats[], int size) {
  char district[50]; // Переменная для хранения введенного названия района
  int continue_input; // Переменная для ответа на вопрос о продолжении работы

  do {
    // Запрашиваем у пользователя название района
    printf("Введите название района для расчета общей площади: ");
    /*getchar(); // Очищаем буфер*/
    scanf("%49s", district);
    float total_area = 0; // Переменная для общей площади

    // Проходим по всем квартирам и суммируем площади, если район совпадает
    for (int i = 0; i < size; ++i) {
      if (strcmp(flats[i].district, district) ==
          0) { // Сравниваем название района
        total_area += flats[i].total_area;
      }
    }

    // Выводим результат на экран
    printf("Общая площадь квартир в районе %s: %.2f кв.м\n", district,
           total_area);

    // Спрашиваем у пользователя, хочет ли он продолжить работу
    do {
      printf("Хотите ли вы продолжить работу? (1 - да, 0 - нет): ");
      if (scanf("%d", &continue_input) != 1 ||
          (continue_input != 1 && continue_input != 0)) {
        printf("Ошибка: введите 1 для продолжения или 0 для выхода.\n");
        while (getchar() != '\n')
          ; // Очистка буфера
      } else {
        break; // Выходим из цикла при правильном вводе
      }
    } while (true);

  } while (continue_input == 1); // Если ответ 1, продолжаем работу
}
