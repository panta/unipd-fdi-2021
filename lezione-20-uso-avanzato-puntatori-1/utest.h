#ifndef UTEST_H
#define UTEST_H

/*
 * utest - (almost) minimal test framework loosely inspired by minunit and fff
 *
 * Copyright (C) 2020-2021 Marco Pantaleoni. All rights reserved.
 */

#include <stdio.h>
#include <assert.h>

typedef struct {
	int passed, failed;
} test_data_t;

typedef struct {
	int ok;
	const char *failure;
	const char *failed_func;
	const char *failed_file;
	int failed_line;
} test_result_t;

extern test_data_t test_data;

#define T_INIT() do {                 \
	test_data.passed = 0;             \
	test_data.failed = 0;             \
} while (0)

#define T_FUNC(NAME) test_data_t NAME()

#define T_OK() do {                              \
	test_result_t result = {                     \
		1,                                       \
		"OK",                                    \
		__PRETTY_FUNCTION__,                     \
		__FILE__,                                \
		__LINE__,                                \
	};                                           \
	return result;                               \
} while(0)

#define T_ASSERT(TEST) do {                          \
	if (!(TEST)) {                                   \
		test_result_t failure = {                    \
			0,                                       \
			(#TEST),                                 \
			__PRETTY_FUNCTION__,                     \
			__FILE__,                                \
			__LINE__,                                \
		};                                           \
		return failure;                              \
	}                                                \
} while (0)

#define T_RUN_TEST(TEST) do {                              \
	printf("+ Running %s: ", #TEST);                       \
	test_result_t result = TEST();                         \
	if (!result.ok) {                                      \
		test_data.failed++;                                \
		printf("FAILED\n\tERROR: %s is false\n"            \
			   "\t       in %s:%d   %s\n",                 \
			result.failure,                                \
			result.failed_file, result.failed_line,        \
			result.failed_func);                           \
		return 1;                                          \
	} else {                                               \
		test_data.passed++;                                \
		printf("OK\n");                                    \
	}                                                      \
} while (0)

#define T_MAIN()                                         \
int main(void)                                           \
{                                                        \
	T_INIT();                                            \
	int result = all_tests();                            \
	if (result != 0) {                                   \
		printf("\nFAILED\n");                            \
	} else {                                             \
		printf("\nALL TESTS PASSED\n");                  \
	}                                                    \
	printf("tests run: %d passed / %d failed\n",         \
		test_data.passed, test_data.failed);             \
	return result != 0;                                  \
}

#endif /* UTEST_H */
