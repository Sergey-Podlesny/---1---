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
	*w = t;
	str = (char*)malloc(1000);
	printf("Input string: ");
	gets_s(str, 1000);
	printf("Number of letters and characters: %i", str_len(str, w));
	printf("\nWord count: %i", t);
	return 0;
}
