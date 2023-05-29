#include <stdio.h>

//callee function
void function_1(){
	printf("enlo from func_1\n");
}

//callback function
void function_2(void (*func_ptr)(void)){
	printf("enlo from func_2\n");
	(*func_ptr)();
}

void main(){
	void (*func_ptr_main)(void) = *function_1;
	//this is same as void (*func_ptr_main)(void) = &function_1 as it is passing address of function_1. In C, there is implicit conversion hence *function_1 and function_1; are the same.
	function_2(function_1);
}
