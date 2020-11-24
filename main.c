#include <stdio.h>

int main() {
    //PRE-SET ARRAY
    char arr[12] = {'B','D','Z','X','W','M','O','S','P','H','G','E'};
    char opt;

    while (opt != '0') { // Makes code re-run when user doesn't define opt as '0'
        // MAIN MENU -
        printf("Menu:\n");
        printf("1. Search the Array \n");
        printf("2. Delete the Array \n");
        printf("3. Sort Content of the Array\n");
        printf("0. Exit\n");
        printf("*--* Please take note that the program only takes first character in your input* --*\n");
        printf("Choose the typing number: ");
        scanf(" %c", &opt);

        while ( getchar() != '\n' ); //Remove extra characters from 'opt'. If this wasn't done, characters after first char will also be stored in opt
        printf("You chose: %c\n", opt);
        //NOTE
        /*
         I think this error handling is much more "convenient" for the user to use than just retrying to type the option again.
         I also had the option of identifying \n (user enters nothing) as an error, but I just didn't decide it to be since, again,
         It would be more "convenient" for the user
         */

        // - MAIN MENU
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
            case '0': // Only used when User Enters 0 during first instance of program
                printf("Program will now exit\n");
                break;
            default: //Checks if opt is in range or is a letter
                printf("Sorry, the character you entered wasn't in the options displayed \nPlease Try Again.\n");

        }
        if (opt == '1' || opt == '2' || opt == '3') { // Return to Menu or Exit
            printf("Enter any character to continue or 0 to exit: ");
            scanf(" %c", &opt);
        }
    }
    return 0;
}
