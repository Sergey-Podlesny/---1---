#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int** matr1, ** matr2, m, n, i, i1, j, j1, min, pi, pj, t = 0;
	printf("Введите размеры матрицы: ");
	scanf_s("%i%i", &n, &m);
	if (!(matr1 = (int**)malloc(n * sizeof(int))))
		return 0;
	if (!(matr2 = (int**)malloc(n * sizeof(int))))
		return 0;
	for (i = 0; i < n; i++) {
		matr1[i] = (int*)malloc(m * sizeof(int));
		matr2[i] = (int*)malloc(m * sizeof(int));
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			matr1[i][j] = rand() % 201 - 100;
		}
	}
	printf("\nИсходная матрица:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%6i ", matr1[i][j]);
		}
		printf("\n\n");
	}

	//ОТБОР
	/*for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			min = matr1[i][j];
			pi = i;
			pj = j;
			for (i1 = i; i1 < n; i1++) {
				for (j1 = 0; j1 < m; j1++) {
					if ((matr1[i1][j1] < min) && ((i1 > i) || (j1 >= j))) {
						min = matr1[i1][j1];
						pi = i1;
						pj = j1;
					}
				}
			}
			matr1[pi][pj] = matr1[i][j];
			matr1[i][j] = min;
		}
	}*/

	// ПУЗЫР
	/*for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			for (i1 = i; i1 < n; i1++) {
				for (j1 = 0; j1 < m; j1++) {
					if (i1 + 1 == n && j1 + 1 == m)
						continue;
					else {
						if (j1 + 1 == m && matr1[i1][j1] < matr1[i1 + 1][0]) {
							min = matr1[i1][j1];
							matr1[i1][j1] = matr1[i1 + 1][0];
							matr1[i1 + 1][0] = min;
						}
						else {
							if (matr1[i1][j1] < matr1[i1][j1 + 1] && j1 + 1 != m) {
								min = matr1[i1][j1];
								matr1[i1][j1] = matr1[i1][j1 + 1];
								matr1[i1][j1 + 1] = min;
							}
						}
					}
				}
			}
		}
	}*/

	for (i = 0; i < n; i++) {
		for (j = 1; j < m; j++) {
			min = matr1[i][j];
			for (i1 = i; i1 >= 0; i1--) {
				for (j1 = j - 1; j1 >= 0;j1--) {
					if (j1 < 0 && i1 > 0 && matr1[i1 - 1][m - 1] > min) {
						if ((j1 + 1) > (m - 1) && (i1 < n -1)) {
							matr1[i1 + 1][0] = matr1[i1][j1];
						}
						else {
							matr1[i1][j1 + 1] = matr1[i1][j1];
						}
					}
					else {
						if (j1 >= 0 && matr1[i1][j1] > min) {
							if ((j1 + 1) > (m - 1) && (i1 < n - 1)) {
								matr1[i1 + 1][0] = matr1[i1][j1];
							}
							else {
								matr1[i1][j1 + 1] = matr1[i1][j1];
							}
						}
					}
				}
			}
			matr1[i1 + 1][j1 + 1] = min;
		}
	}

	printf("\nОтсортированная матрица:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%6i ", matr1[i][j]);
		}
		printf("\n\n");
	}

	pi = pj = 0;
	i = n;
	i1 = 0;
	j = j1 = 0;
	while (((pi + 1) * pj) < n * m) {
		switch (t) {
		case 0:
			for (i -= 1; i >= i1; i--) {
				if (pj == m) {
					pi++;
					pj = 0;
				}
				matr2[i][j] = matr1[pi][pj++];
			}
			i++;
			t = 1;
			break;
		case 1:
			for (j += 1; j < m - j1; j++) {
				if (pj == m) {
					pi++;
					pj = 0;
				}
				matr2[i][j] = matr1[pi][pj++];
			}
			j--;
			j1++;
			t = 2;
			break;
		case 2:
			for (i += 1; i < n - i1; i++) {
				if (pj == m) {
					pi++;
					pj = 0;
				}
				matr2[i][j] = matr1[pi][pj++];
			}
			i--;
			i1++;
			t = 3;
			break;
		case 3:
			for (j -= 1; j >= j1; j--) {
				if (pj == m) {
					pi++;
					pj = 0;
				}
				matr2[i][j] = matr1[pi][pj++];
			}
			j++;
			t = 0;
			break;
		}
	}

	printf("\nСортировка матрицы спиралью:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%6i ", matr2[i][j]);
		}
		printf("\n\n");
	}

	return 0;
}
