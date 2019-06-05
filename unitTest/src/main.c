#include "stdio.h"
#include "stdarg.h"
#include "stddef.h"
#include "setjmp.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#include "cmocka.h"

char** tests;

char** 
get_available_tests(void)
{
	const int NumOfTests = 1;
	tests = (char**)malloc(sizeof(char*) * NumOfTests + 1);

	tests[0] = (char*)malloc(sizeof(char)*128);
	strcpy(tests[0], "my_test");
	
	tests[1] = NULL;

	return tests;
}

void
clean_up()
{
	for(int i = 0; tests[i]; i++)
	{
		free(tests[i]);
	}

	free(tests);
}

void**
get_states_for_test(void* key)
{

}

void
my_test(void** state)
{
	printf("%s\n", "Hello, world!");
}

int main(int argv, char** argc)
{
	const struct CMUnitTest tests[] = 
	{
		cmocka_unit_test(my_test),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);	
}
