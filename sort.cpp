
int main()
{
	int* matr, * mt, i, i1, i2, j, j1, j2, n, m, min;
	setlocale(LC_ALL, "Russian");
	printf("Введите размерность матрицы: ");
	printf("\nКоличество строк: ");
	while(!(scanf_s("%i", &n)))
		rewind(stdin);
	printf("Количество столбцов: ");
	while (!(scanf_s("%i", &m)))
		rewind(stdin);
	if (!(matr = (int*)malloc(m * n * sizeof(int))))
		return 0;
	if (!(mt = (int*)malloc(m * n * sizeof(int))))
		return 0;
	srand(time(0));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			*(matr + i * m + j) = rand() % 21 -10;
			/*printf("MT[%i][%i] = ", i, j);
			scanf_s("%i", (matr + i * m + j));*/
		}
	}
	system("CLS");
	printf("Исходная матрица:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%6i", *(matr + i * m + j));
		}
		printf("\n\n");
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			min = *(matr + i * m + j);
			j1 = i * m + j;
			for (i1 = j1 + 1; i1 < m * n; i1++) {
				if (*(matr + i1) < min) {
					min = *(matr + i1);
					j1 = i1;
				}
			}
			*(matr + j1) = *(matr + i * m + j);
			*(matr + i * m + j) = min;
		}
	}

	printf("Отсоритированная матрица:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%6i", *(matr + i * m + j));
		}
		printf("\n\n");
	}

	i = 0;
	j2 = m - 1;
	i1 = i2 = 0;
	min = 0;
	while(i < n * m) {

		switch(min) {

		case 0:
			for (j1 = j2; j1 >= (m - j2 - 1); j1--)
				*(mt + i1 * m + j1) = *(matr + i++);
			j1++;
			min = 1;
			break;
		case 1:
			for (i1 += 1; i1 < n - i2; i1++)
				*(mt + i1 * m + j1) = *(matr + i++);
			i1--;
			i2++;
			min = 2;
			break;
		case 2:
			for (j1 += 1; j1 < j2 + 1; j1++)
				*(mt + i1 * m + j1) = *(matr + i++);
			j1--;
			j2--;
			min = 3;
			break;
		case 3:
			for (i1 -= 1; i1 >= i2; i1--)
				*(mt + i1 * m + j1) = *(matr + i++);
			i1++;
			min++;
			min = 0;
			break;
		}
	}

	printf("Отсоритированная матрица 2:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%6i", *(mt + i * m + j));
		}
		printf("\n\n");
	}

	return 0;
}
