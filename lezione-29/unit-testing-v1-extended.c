#include <stdio.h>
#include <ctype.h>

#define mu_assert(message, test) do {    \
    if (!(test)) {                       \
        printf("FAILED: %s\n", message); \
        return 0;                        \
    }                                    \
} while (0)

#define mu_run_test(test) do { \
    if ((test)() <= 0)         \
        tests_failed++;        \
    tests_run++;               \
} while (0)

int tests_run = 0;
int tests_failed = 0;

/* Versione corretta */
int strcmp_ignorespace(const char *s1, const char *s2)
{
    const char *p1 = s1, *p2 = s2;

    int equal = 1;
    while (equal) {
        while (*p1 == *p2) {
            if (*p1 == '\0')
                return 0;
            p1++;
            p2++;
        }
        while (isspace(*p1))
            p1++;
        while (isspace(*p2))
            p2++;
        equal = (*p1 == *p2);
    }
    return (*p1 - *p2);
}

static int test_strcmp_ignorespace(void)
{
    mu_assert("only spaces - 1", strcmp_ignorespace("   ", "") == 0);
    mu_assert("only spaces - 2", strcmp_ignorespace("", "   ") == 0);
    mu_assert("only spaces - 3", strcmp_ignorespace("      ", "   ") == 0);
    mu_assert("beginning - 1", strcmp_ignorespace("   abcdef", "abcdef") == 0);
    mu_assert("beginning - 2", strcmp_ignorespace("abcdef", "   abcdef") == 0);
    mu_assert("end - 1", strcmp_ignorespace("abcdef   ", "abcdef") == 0);
    mu_assert("end - 2", strcmp_ignorespace("abcdef", "abcdef   ") == 0);
    mu_assert("simple - 1", strcmp_ignorespace("abc def", "abcdef") == 0);
    mu_assert("simple - 2", strcmp_ignorespace("abcdef", "abc def") == 0);
    mu_assert("mixed - 1", strcmp_ignorespace("    a b   cd  e f   ", "abcdef") == 0);
    mu_assert("mixed - 2", strcmp_ignorespace("abcdef", "    a b   cd  e f   ") == 0);
    return 1;
}


static void all_tests(void)
{
    mu_run_test(test_strcmp_ignorespace);
}
 
int main(void)
{
    all_tests();
    printf("\nok/FAILED/all: %d/%d/%d\n", (tests_run-tests_failed), tests_failed, tests_run);
    if ((tests_run > 0) && (tests_failed == 0)) {
        printf("\nALL TESTS PASSED\n");
    }

    return (tests_failed == 0);
}
