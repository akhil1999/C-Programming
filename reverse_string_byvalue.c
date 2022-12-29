#include <stdio.h>

int checker(char inputstring[]){
	int i = 0;
	while(inputstring[i]!='\0'){
		i++;
	}
	return i;
}

void reverseString(char inputstring[]){
	int len = checker(inputstring);
	char reversedstring[len + 1];
	for(int i = 0; i < len ; i++){
		reversedstring[len - i -1] = inputstring[i];
	}
	reversedstring[len] = '\0';
	printf("reversed string:%s\n", reversedstring);
}

void main(){
	char string[] = "henlo vro";
	reverseString(string);
}
