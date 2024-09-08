#include <stdio.h>

struct employee {
    char name[100];
    int age;
    float salary;
    char id[10];
};

int main() {
    struct employee EM[100];

    // Input for each employee
    for(int i = 0; i <3; i++) {
        printf("Enter details for employee %d (name, age, salary, id):\n", i+1);
        scanf(" %99s %d %f %9s", EM[i].name, &EM[i].age, &EM[i].salary, EM[i].id); // Including space before % to skip any newline left in the input buffer
    }

    // Output names of employees over 20
    for(int i = 0; i <3; i++) {
        if(EM[i].age > 20) {
            printf("%s\n", EM[i].name);
        }
    }

    return 0;
}