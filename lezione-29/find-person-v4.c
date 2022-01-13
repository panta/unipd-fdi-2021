#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

const char *people[] = {
    "Anakin Skywalker",
    "Charlie Brown",
    "Dexter",
    "Donald Duck",
    "Homer Simpson",
    "Peter Griffin",
    "Snoopy",
    NULL,
};

typedef int (*comparison_fun)(const char *s1, const char *s2);

// equivalent to:
//   int find_person_generic(const char *name, int (*cmp_fn)(const char *, const char *))
int find_person_generic(const char *name, comparison_fun cmp_fn)
{
    for (int i = 0; ; i++) {
        if (people[i] == NULL)
            break;
        if (cmp_fn(people[i], name) != 0)
            continue;
        printf("found '%s' at index %d\n", name, i);
        return i;
    }
    printf("'%s' not found\n", name);
    return -1;
}

int strcmp_ignorespace(const char *s1, const char *s2)
{
    const char *p1 = s1;
    const char *p2 = s2;

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

int main(void)
{
    find_person_generic("Dexter", strcmp);
    find_person_generic("Homer Simpson", strcmp);

    find_person_generic("charlie brown", strcasecmp);

    find_person_generic("  Homer     Simpson", strcmp_ignorespace);
    find_person_generic("DonaldDuck", strcmp_ignorespace);

    return 0;
}
