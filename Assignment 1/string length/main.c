#include <stdio.h>
#include <string.h>

int main() {
    char name[100];

    printf("Enter a name: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    // Count characters
    int length = strlen(name);

    printf("Number of characters: %d\n", length);

    return 0;
}
