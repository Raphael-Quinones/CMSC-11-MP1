#include <stdio.h>

int main() {
    //PRE-SET ARRAY
    char arr[12] = {'B','D','Z','X','W','M','O','S','P','H','G','E'};
    char opt;

    while (opt != '0') {
        printf("Menu:\n");
        printf("1. Search the Array \n");
        printf("2. Delete the Array \n");
        printf("3. Sort Content of the Array\n");
        printf("0. Exit\n");
        printf("Choose the typing number: ");
        scanf(" %c", &opt);
        switch (opt) {
            case '1':
                printf("You pressed 1\n");
                break;
            case '2':
                printf("You pressed 2\n");
                break;
            case '3':
                printf("You pressed 3\n");
                break;
            default: //Checks if opt is in range
                printf("Sorry, the character you entered wasn't in the options displayed \nPlease Try Again.\n");

        }
        if (opt == '1' || opt == '2' || opt == '3') { // Return to Menu or Exit
            printf("Enter any character to continue or 0 to exit: ");
            scanf(" %c", &opt);
        }
    }
    return 0;
}
