#include <stdio.h>

char string[] = "henlo vro";

int checker(char *inputstring){
	int i = 0;
	while(*inputstring!='\0'){
		inputstring++ && i++;
	}
	return i;
}

void reverseString(char *inputstring){
	int len = checker(inputstring);
	char *startPtr = inputstring;
	char *endPtr = inputstring + len -1;
	for(int i = 0; i < len / 2 ; i++){
		*startPtr = *startPtr + *endPtr;
		*endPtr = *startPtr - *endPtr;
		*startPtr = *startPtr - *endPtr;
		startPtr++;
		endPtr--;
	}
}

void main(){
	printf("%d\n", checker(string));
	printf("%s\n", string);
	reverseString(string);
	printf("%s\n", string);
}
