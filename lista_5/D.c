#include<stdio.h>
#include<string.h>

int find(char *str, char *sub){
	if(*sub == '\0')
    	return 0;
  	if(*str != *sub)
  		return -1;
  	return find(str+1, sub+1);
}

int first_sub(char *str, char *sub, int index){
	if(*str != '\0') {
	int a = -1;
    a = find(str, sub);
    if(a == 0)
		return index;
    return first_sub(str + 1, sub, ++index);
    
  } else
	  return -1;
}

int last_sub(char *str, char *sub, int index){
	int a = -1;
	a = find(str, sub);
	if(a >= 0)
    	return index;
	return last_sub(str - 1, sub, --index);
}

int main() {
	char str[101], sub[101];
	scanf("%s", str);
	scanf("%s", sub);
	int init = 0, end = 0;
	init = first_sub(str, sub, 0);
	if(init != -1) {
    end = last_sub(&str[strlen(str)], sub, strlen(str));
    printf("%d\n", end - init + strlen(sub));
	} else
		printf("0\n");
  return 0;
}
