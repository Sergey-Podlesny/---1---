int str_len(char *str, int* w) {
	int i = 0, i1 = 1, i2 = 0, len = 0;
	while (str[i] != '\0') {
		while (str[i] == ' ') i++;
		i1 = i;
		while (str[i] && str[i] != ' ') i++;
		i2 = i;
		(*w)++;
		len = len + i2 - i1;
	}
	return len;
}

int main()
{
	char* str;
	int i, *w, t = 0;
	w = &t;
	str = (char*)malloc(1000);
	printf("Input string: ");
	gets_s(str, 1000);
	printf("Number of letters and characters: %i", str_len(str, w));
	printf("\nWord count: %i", t);
	return 0;
}

//свапает первое и последнее слово
#include <stdio.h>
#include <stdlib.h>

void swap(char* s1, char* s2)
{
	int c;
	for (; s1 < s2; s1++, s2--) {
		c = *s1;
		*s1 = *s2;
		*s2 = c;
	}
}

int main()
{
	char* str;
	int i = 0, i1, i2, j1, j2;
	printf("Input string: ");
	str = (char*)malloc(1);
	rewind(stdin);
	while ((str[i] = (char)getchar()) != '\n')
		str = (char*)realloc(str, i++ + 2);
	str[i] = '\0';
	
	//нахождение начала и конца у первого и второго слова
	i--;
	while (str[i] == ' ') i--;
	j2 = i;
	while (str[i] && str[i] != ' ') i--;
	j1 = i + 1;
	i = 0;
	while (str[i] == ' ') i++;
	i1 = i;
	while (str[i] && str[i] != ' ') i++;
	i2 = i - 1;
	swap(&str[i1], &str[j2]);
	swap(&str[i1], &str[i1 + j2 - j1]);
	swap(&str[j2 + i1 - i2], &str[j2]);
	swap(&str[i1 + j2 - j1 + 1], &str[j2 - i2 + i1 - 1]);   // та самая строчка
	printf("\nNew string: %s", str);
	return 0;
}
