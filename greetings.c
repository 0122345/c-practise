#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char *name;
    int age;
} Student;

void Greetings(Student *st);

int main() {
    //TODO: Dynamic memory allocation for student struct
    Student *st = (Student *)malloc(sizeof (st));

    if (st == NULL) {
        printf("Memory allocatoin failed\n");
        return 1;
    }
    
    //TODO: ALlocating memory for the name String
    char tempName[100];
    printf("Enter Your Name: ");
    fgets(tempName, sizeof(tempName), stdin);
    tempName[strcspn(tempName, "\n")] = '\0';

    st ->name = (char *)malloc((strlen(tempName) + 1) * sizeof(char));
    if (st -> name == NULL) {
        printf("Memory allocation for name failed!\n");
        free(st);
        return 1;
    }  

    strcpy(st ->name, tempName);

    printf("Enter Your age: ");
    scanf("%d", &st->age);

    Greetings(st);

    free(st -> name);
    free(st);

    printf("Goodbye");
    return 0;
}

void Greetings(Student *st) {
    printf("\n\n____ Greetings____\n\n");
    printf("Hello, %s!\n", st -> name);
    printf("You're %d years old!\n", st -> age);
    printf("This is Muvunyi C programming Class\n");
    printf("____________________________________");
}