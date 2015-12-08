#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <cmocka.h>

#include "../src/main.h"

static int setup_f()
{
	return 0;
}

static int teardown_f()
{
	return 0;
}

static void test_sum()
{
	int32_t x = 2;
	int32_t y = 2;

	int32_t xy;

	xy = sum(x,y);

	assert_int_equal(4, xy);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test_setup_teardown(test_sum, setup_f, teardown_f),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
