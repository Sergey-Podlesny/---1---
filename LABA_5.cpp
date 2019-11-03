#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void out_matr(int* matr, int size, int k) {   // ф-ия выода матрицы
	if (k == 1)   // исходная
		printf("Исходная матрица:\n");
	if (k == 2)   // с сорт диаг.
		printf("\n\nМатрица с отсортированной диагональю:\n");
	for (int i = 0; i < size; i++) {   // вывод матр
		for (int j = 0; j < size; j++) {
			printf("%3i", *(matr + size * i + j));
		}
		printf("\n");
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");   // русификаия
	int* matr, size, i, j, a ,t;  // переменные
	printf("Введите размер квадратной матрицы: ");   // ввод с клав. размера матр
	while (!scanf_s("%i", &size))   // умный ввод
		rewind(stdin);
	if(!((matr = (int*)malloc(size * size * sizeof(int)))))   // выделение памяти для матрицы с проверкой 
		return 0;
	for (i = 0; i < size; i++) {   // ввод матрицы рандомными числами
		for (j = 0; j < size; j++) {
			*(matr + size * i + j) = rand() % 50 + 1;
		}
	}
	out_matr(matr, size, 1);   // вызов ф-ии
	for (i = 0; i < size; i++) {  // соритровка отбором
		a = *(matr + size*i + i);
		t = i;
		for (j = i + 1; j < size; j++) {
			if (*(matr + j* size + j) < a) {
				a = *(matr + j * size + j);
				t = j;
			}
		}
		*(matr + t*size + t) = *(matr + i*size + i);
		*(matr + i* size + i) = a;
	}

	out_matr(matr, size, 2);   // вызов ф-ии
	free(matr);   // очистка памяти
	return 0;
}
