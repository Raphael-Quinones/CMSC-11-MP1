#include <stdio.h>
#include <ctype.h> //for toupper() function


int main() {
    //PRE-SET ARRAY
    char arr[12] = {'B','D','Z','X','W','M','O','S','P','H','G','E'};
    char opt, search, tmp;
    int array_size = 12, k=0;

    while (opt != '0') { // Makes code re-run when user doesn't define opt as '0'
        // MAIN MENU -
        printf("Menu:\n"
        "1. Search the Array \n"
        "2. Delete the Array \n"
        "3. Sort Content of the Array\n"
        "0. Exit\n"
        "*--* Please take note that the program only takes first character in your input* --*\n"
        "Choose the typing number: ");
        scanf(" %c", &opt);

        fflush(stdin);  //Remove extra characters from 'opt'. If this wasn't done, characters after first char will also be parsed in next scanf, which is this
                        //clears buffer
                                    // NOTE: Program will go to an endless loop if user enters ^D in nix systems or ctrl D in windows
        printf("You chose: %c\n", opt);
        //NOTE
        /*
         I think this error handling is much more "convenient" for the user to use than just retrying to type the option again.
         I also had the option of identifying \n (user enters nothing) as an error, but I just didn't decide it to be since, again,
         It would be more "convenient" for the user
         Notable Solution for implementing said error handling: https://stackoverflow.com/questions/38440680/how-would-i-only-let-the-user-input-one-character-in-c
         */

        // - MAIN MENU
        switch (opt) {
            case '1'://Linear Search
                printf("You pressed 1\n"
                       "Input your letter to search: \n");
                scanf(" %c", &search);
                fflush(stdin); //Clears buffer to only accept one character as input
                search = toupper(search);//Transforms user input to upper
                printf("\nInput = %c\n", search);
                /* CORE */
                for (int i=0; i<array_size; i++)
                {
                    if (arr[i] == search) // Executes when 'search' has been found in char array
                    {
                        printf("%c found at position %d\n",arr[i],i);
                        break;
                    }
                    else if (i == (array_size - 1)) // Executes when loop has arrived to last char
                        printf("Input not found in array\n");
                }
                 /* CORE */
                break;
            case '2':
                printf("You pressed 2\n");
                //Print contents of original array
                printf("Before deletion:\n");
                for (int i = 0;i<array_size;i++)
                    printf("%c ", arr[i]);
                printf("\n--Your input will be converted to uppercase--\n");
                printf("\nEnter search: \n");
                scanf(" %c", &search);
                fflush(stdin); //Clears buffer to only accept one character as input
                search = toupper(search);//Transforms user input to upper
                printf("\nYour input was: %c\n", search);
                /* CORE */
                //Use Original Array to save Memory
                for (k;k<array_size;k++)//Searches from start of array
                {
                    if(search == arr[k])//Start process when 'search' has been found
                    {
                        for (k;k<array_size;k++)
                        {
                            arr[k] = arr[k+1];//Remove 'search' and shift left all elements after arr[j]
                            if (k == (array_size-1))
                                arr[k] = NULL;//Last item of array is considered none
                        }
                        array_size = array_size - 1; //Update array size. Minus one since one element has been deleted
                        printf("\nAfter Deletion:\n");
                        for (int i=0;i<array_size;i++)
                            printf("%c ", arr[i]);
                        break;
                    }
                    else if (k == array_size-1)
                        printf("\nSorry your input can't be found\n");
                }
                k=0; //restart value of k for repetitive instances
                /* CORE */
                break;
            case '3':
                printf("You pressed 3\n");                                                                              //This algorithm instead of this: https://onlinegdb.com/S1HWQvA9P
                /* CORE */                                                                                              //Since linked algorithm is hard to make a flowchart out of
                                                                                                                        //Shame since this algorithm is faster
                //Comparing all pairs in array (All combinations, with each combination having 2 elements)
                printf("Before sorting: \n");
                for (int i=0; i<array_size; i++)
                    printf("%c ", arr[i]);
                for (int i=0; i<array_size; i++)
                    for(int j=i+1; j<array_size; j++)
                        if(arr[j] <arr[i])
                        {
                            tmp = arr[i];       //Sorting
                            arr[i] = arr[j];    //Sorting
                            arr[j] = tmp;       //Sorting
                        }
                /* CORE */
                printf("\nAfter sorting: \n");
                for (int i=0; i<array_size; i++)
                    printf("%c ", arr[i]);
                break;
            case '0': // Only used when User is in Menu
                printf("Program will now exit\n");
                break;
            default: //Checks if opt is in range or is a letter
                printf("Sorry, the character you entered wasn't in the options displayed \nPlease Try Again.\n");

        }
        if (opt == "1"|| opt == "2"||opt=="3") // Return to Menu or Exit
            printf("\nEnter any character to continue or 0 to exit: ");
            scanf(" %c", &opt);
            fflush(stdin);

    }
    return 0;
}
