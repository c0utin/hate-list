#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hateList {
    char person_name[30];
    int age;
    char reason[100];
};

int main() {

    struct hateList hateArray[100];

    char person_name[30];
    int input, count;

    input = count = 0;

    while (input != 5) {

        printf("\n\n********######"
               "WELCOME TO HATE LIST "
               "#####********\n");
        printf("\n\n1. Add person to Hate List\n"
               "2. Display Hate List\n"
               "3. I FORGIVE YOU BROTHER\n"
               "4. I have no enemiest\n"
               "5. Exit\n");

        printf("\n\nEnter one of "
               "the above: ");
        scanf("%d", &input);

        switch (input) {

        case 1:
            printf("Enter person's name: ");
            scanf("%s", hateArray[count].person_name);

            printf("Enter person's age: ");
            scanf("%d", &hateArray[count].age);

            printf("Enter reason for hate: ");
            scanf(" %[^\n]s", hateArray[count].reason);

            count++;
            break;

        case 2:
            printf("You have hate for the following people:\n");
            if (count == 0){
                printf("All i feel towards them is pity\n");
            } else {
                for (int i = 0; i < count; i++) {
                    printf("Person's name: %s\n", hateArray[i].person_name);
                    printf("Age: %d\n", hateArray[i].age);
                    printf("Reason for hate: %s\n", hateArray[i].reason);
                    printf("\n");
                }
            }
            break;

        case 3:
            printf("Enter the name of the person to delete: ");
            scanf("%s", person_name);

            for (int i = 0; i < count; i++) {
                if (strcmp(person_name, hateArray[i].person_name) == 0) {
                    for (int j = i; j < count - 1; j++) {
                        strcpy(hateArray[j].person_name, hateArray[j + 1].person_name);
                        hateArray[j].age = hateArray[j + 1].age;
                        strcpy(hateArray[j].reason, hateArray[j + 1].reason);
                    }
                    count--; 
                    printf("Person '%s' deleted from Hate List.\n", person_name);
                    break;
                }
            }
            break;
        case 4:
            count = 0;
            printf("I have no enemies\n");
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
