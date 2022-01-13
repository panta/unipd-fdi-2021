#include <stdio.h>
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
    for (int i = 0; ; i++) {
        if (people[i] == NULL)
            break;
        if (strcasecmp(people[i], name) != 0)
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

    return 0;
}
