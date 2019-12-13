#include <stdio.h>
#include <stdlib.h>
#include <ctime>


////ФАКТОРЫ
//int factorial(int fact)
//{
//	return (fact > 1) ? fact * factorial(fact - 1) : 1;
//}
//
//int main()
//{
//	srand(time(NULL));
//	int fact;
//	fact = rand() % 91 + 10;
//	printf("Random number: %i", fact);
//	printf("\nFactorial: %i", factorial(fact));
//	return 0;
//}

////ФИБОНЫ
//void fibonachi(int fibon)
//{
//	static int a = 1, b = 1, c;
//	if (fibon > 0) {
//		printf("\n%i", a);
//		c = b; 
//		b = a;
//		a = b + c;
//		fibonachi(fibon - 1);
//	}
//	//return (fibon == 1 || fibon == 0) ? 1 : fibonachi(fibon - 1) + fibonachi(fibon - 2);
//	
//}
//
//int main()
//{
//	srand(time(NULL));
//	int fibon;
//	fibon = rand() % 71 + 5;
//	printf("Rand numb: %i", fibon);
//	/*for (int i = 0; i < fibon; i++)
//		printf("%i ", fibonachi(i));*/
//	fibonachi(fibon);
//	return 0;
//}

// СЛОЖЕНИЕ ВСЕХ ЭЛЕМЕНТОВ МАССИВА
//int sum(int* ms, int size)
//{
//	return (size > 1) ? sum(ms + 1, size - 1) + *ms: *ms;
//}
//
//int main()
//{
//	srand(time(NULL));
//	int* ms, size;
//	size = 5/*rand() % 45 + 7*/;
//	printf("size: %i\n", size);
//	ms = (int*)malloc(size * sizeof(int));
//	for (int i = 0; i < size; i++)
//		ms[i] = rand() % 151 - 70;
//	for (int i = 0; i < size; i++)
//		printf("%i ", ms[i]);
//	printf("\nSum: %i", sum(ms, size));
//	return 0;
//}

//// ЗАДАЧА #4
//int num(int n, int p)
//{
//	return (p > 0) ? num(n, p - 1) * (n - p) : n;
//}
//
//int main()
//{
//	srand(time(NULL));
//	int n, p;
//	p = 3/*rand() % 102 + 22*/;
//	printf("p: %i\n", p);
//	n =  6/*rand() % 80 + 73*/;
//	printf("n: %i ", n);
//	printf("\nSum: %i", num(n, p));
//	return 0;
//}
