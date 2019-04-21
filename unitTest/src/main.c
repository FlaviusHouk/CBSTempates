#include "stdio.h"
#include "stdarg.h"
#include "stddef.h"
#include "setjmp.h"
#include "stdint.h"

#include "cmocka.h"

static void
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
