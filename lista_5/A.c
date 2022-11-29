#include <stdio.h>
#include <string.h>

int string_pairs(char *c, int begin, int npairs) {
	if (strlen(c) < 2)
		return 0;
	else if (begin == strlen(c) - 2)
		return npairs;
	else if (c[begin] == c[begin + 2]) 
		npairs++;
	return string_pairs(c, ++begin, npairs);	
}

int main() {
	char str[201];
	scanf("%s", str);
	printf("%d\n", string_pairs(str, 0, 0));
	return 0;
}
