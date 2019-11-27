#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int atoi(char*);
//
//int main()
//{
//	int i = 0;
//	char* str;
//	printf("Enter a string: ");
//	str = (char*)malloc(1);
//	while ((str[i] = (char)getchar()) != '\n')
//		str = (char*)realloc(str, i++ + 2);
//	str[i] = '\0';
//	printf("%i", atoi(str));
//	return 0;
//}
//
//int atoi(char* ss)
//{
//	int znak, numb, i = 0;
//	while (ss[i] == ' ') i++;
//	znak = (ss[i] == '-') ? -1 : 1;
//	if (ss[i] == '+' || ss[i] == '-') i++;
//	for (numb = 0; ss[i] >= '0' && ss[i] <= '9'; i++)
//		numb = numb * 10 + (ss[i] - '0');
//	return znak * numb;
//}

// УДАЛЕНИЕ ВСЕХ СИМВОЛА ИЗ СТРОКИ (ВСЕХ)
//int main()
//{
//	char* str, a;
//	int i = 0, len, j;
//	printf("Enter a string: ");
//	str = (char*)malloc(1);
//	while ((str[i] = (char)getchar()) != '\n')
//		str = (char*)realloc(str, i++ + 2);
//	str[i] = '\0';
//	len = i;
//	printf("Your string: %s", str);
//	printf("\nEnter a symbol: ");
//	scanf_s("%c", &a);
//	i = 0;
//	while(str[i]) {
//		if (str[i] == a) {
//			for (j = i; j + 1 < len; j++) {
//				str[j] = str[j + 1];
//			}
//			len--;
//			str[len] = '\0';
//		}
//		else i++;
//	}
//	printf("New string: %s", str);
//	return 0;
//}

// ПЕРЕСТАНОВКА СЛОВ
//void swap(char* str1, char* str2)
//{
//	int y;
//	for (; str1 < str2; str1++, str2--) {
//		y = *str1;
//		*str1 = *str2;
//		*str2 = y;
//	}
//}
//
//int main()
//{
//	char* str;
//	int i = 0, i1 = 0, i2 = 0, j1 = 0, j2 = 0, w1, w2, count = 0;
//	printf("Enter a string: ");
//	str = (char*)malloc(1);
//	while ((str[i] = (char)getchar()) != '\n')
//		str = (char*)realloc(str, i++ + 2);
//	str[i] = '\0';
//	puts(str);
//	printf("Enter a numbers of words: ");
//	scanf_s("%i %i", &w1, &w2);
//	i = 0;
//	while (count < w1) {
//		while (str[i] == ' ') i++;
//		i1 = i;
//		while (str[i] && str[i] != ' ')i++;
//		i2 = i - 1;
//		count++;
//	}
//	while (count < w2) {
//		while (str[i] == ' ') i++;
//		j1 = i;
//		while (str[i] && str[i] != ' ')i++;
//		j2 = i - 1;
//		count++;
//	}
//	swap(&str[i1], &str[j2]);
//	swap(&str[i1], &str[i1 + j2 - j1]);
//	swap(&str[j2 + i1 - i2], &str[j2]);
//	swap(&str[i1 + j2 - j1 + 1], &str[j2 - i2 + i1 - 1]);
//	puts(str);
//	return 0;
//}



// ВСТАВКА СЛОВА ПОЛСЕ ОПРЕДЕЛЕННОГО СЛОВА
//int countWord(char* str)
//{
//	int i = 0, count = 0, k = 1;
//	while (str[i]) {
//		switch (k) {
//		case 1:
//			while (str[i] == ' ') i++;
//			k = 2;
//			break;
//		case 2:
//			while (str[i] && str[i] != ' ') i++;
//			k = 1;
//			count++;
//			break;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	char* str, * word;
//	int i = 0, count = 0, i1, j, j1, lenStr, lenWord, numb, countW;
//	printf("Enter a string: ");
//	str = (char*)malloc(1);
//	while ((str[i] = (char)getchar()) != '\n')
//		str = (char*)realloc(str, i++ + 2);
//	str[i] = '\0';
//	lenStr = i;
//	printf("Your string: %s", str);
//	printf("\nEnter a word: ");
//	i = 0;
//	word = (char*)malloc(1);
//	while ((word[i] = (char)getchar()) != '\n')
//		word = (char*)realloc(word, i++ + 2);
//	word[i] = '\0';
//	lenWord = i;
//	printf("Your word: %s", word);
//	str = (char*)realloc(str, lenStr + lenWord);
//	printf("\nEnter a number: ");
//	do {
//		i = scanf_s("%i", &numb);
//		rewind(stdin);
//	} while (numb < 0 || !i);
//	countW = countWord(str);
//	if (numb == 0) count--;
//	i = 0;
//	if (numb > countW) j = lenStr - 1;
//	while (count < numb) {
//		while (str[i] == ' ') i++;
//		j = i;
//		while (str[i] && str[i] != ' ')i++;
//		count++;
//	}
//	for (j1 = lenStr, i1 = lenStr + lenWord; j1 >= j; j1--, i1--)
//		str[i1] = str[j1];
//	for (j1 = j, i1 = 0; word[i1]; j1++, i1++)
//		str[j1] = word[i1];
//	printf("New string: %s", str);
//	return 0;
//}

// УДВОЕНИЕ ВВЕДЕНОГО СИМВОЛА В СТРОКЕ
//int main()
//{
//	char* str, a;
//	int i = 0, j, len;
//	printf("Enter a string: ");
//	str = (char*)malloc(1);
//	while ((str[i] = (char)getchar()) != '\n')
//		str = (char*)realloc(str, i++ + 2);
//	str[i] = '\0';
//	len = i;
//	printf("Enter a symbol: ");
//	scanf_s("%c", &a);
//	for (i = 0; i < len;) {
//		if (str[i] == a) {
//			str = (char*)realloc(str, ++len);
//			str[len - 1] = '\0';
//			for (j = len; j - 1 >= i; j--)
//				str[j] = str[j - 1];
//			i += 2;
//		}
//		else i++;
//	}
//	printf("New string: %s", str);
//	return 0;
//}

// ПОДСЧЕТ КОЛИЧЕСТВА ОПРЕДЕЛЕННЫХ СЛОВ В СТРОКЕ ( СЛОВО ВВОДИМ С КЛАВИАТУРЫ)
//int strcmp(char* str, char* word)
//{
//	while (*str && *word && !(*str - *word)) {
//		str++;
//		word++;
//	}
//	if (*word == ' ' || *word == '\0') word--;
//	if (*str == ' ' || *str == '\0') str--;
//	return *str - *word;
//}
//
//int main()
//{
//	char* str, word[100];
//	int i = 0, i1, i2, count = 0;
//	printf("Enter a string: ");
//	str = (char*)malloc(1);
//	while ((str[i] = (char)getchar()) != '\n')
//		str = (char*)realloc(str, i++ + 2);
//	str[i] = '\0';
//	printf("Enter a word: ");
//	scanf_s("%s", word, 100);
//	i = 0;
//	while (str[i] != '\0') {
//		while (str[i] == ' ') i++;
//		i1 = i;
//		while (str[i] && str[i] != ' ') i++;
//		i2 = i;
//		if(!(strcmp(&str[i1], word)))
//			count++;
//	}
//	printf("Count: %i", count);
//	return 0;
//}
