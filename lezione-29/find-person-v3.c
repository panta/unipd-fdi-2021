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

int find_person(const char *name)
{
   for (int i = 0; ; i++) {
       if (people[i] == NULL)
            break;
        if (strcmp(people[i], name) != 0)
            continue;
        printf("found '%s' at index %d\n", name, i);
        return i;
    }
    printf("'%s' not found\n", name);
    return -1;
}

int find_person_ignorecase(const char *name)
{
    const char *person;
    for (int i = 0; ; i++) {
        person = people[i];
        if (person == NULL)
            break;
        if (strcasecmp(person, name) != 0)
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

int find_person_ignorespace(const char *name)
{
    for (int i = 0; ; i++) {
        if (people[i] == NULL)
            break;
        if (strcmp_ignorespace(people[i], name) != 0)
            continue;
        printf("found '%s' at index %d\n", name, i);
        return i;
    }
    printf("'%s' not found\n", name);
    return -1;
}

int main(void)
{
    find_person("Dexter");
    find_person("Homer Simpson");

    find_person_ignorecase("charlie brown");

    find_person_ignorespace("  Homer     Simpson");
    find_person_ignorespace("DonaldDuck");
    return 0;
}
