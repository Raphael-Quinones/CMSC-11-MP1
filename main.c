#include <stdio.h>
#include <ctype.h> //for toupper() function
int search(char ch_search, int array_size, char const arr[], int* index){ //pass pointer of char arr since passing whole arrays are considered inefficient
    for (int i=0; i<array_size; i++)
    {
        if (arr[i] == ch_search) // Executes when 'ch_search' has been found in char array
        {
            *index = i;//we can't return 2 values so we'll use pointers to access this processed value
            return 1; //as stated in MP2 instructions
        }
        else if (i == (array_size - 1)) // Executes when loop has arrived to last char
            return 0;
    }
}

int delete(char ch_search, int* array_size, char arr[] ){ //"char* arr" is a character array
    //remember "*" are dereferencing operators, means that it uses the pointer to find the value of the variable
    for (int k=0;k<*array_size;k++)//searches from start of array
    {
        if(ch_search == arr[k])//Start process when 'ch_search' has been found
        {
            for (;k<*array_size;k++)
            {
                arr[k] = arr[k+1];//Remove 'ch_search' and shift left all elements after arr[j]
                if (k == (*array_size-1))
                    arr[k] = '\0';//Last item of array is considered none
            }
            *array_size = *array_size - 1; //Update array size. Minus one since one element has been deleted
            return 1;
        }
        else if (k == *array_size-1)
            return 0;
    }

}

void sort(char arr[], int array_size){
    char tmp;
    for (int i=0; i<array_size; i++)
        for(int j=i+1; j<array_size; j++)
            if(arr[j] <arr[i])
            {
                tmp = arr[i];       //Sorting
                arr[i] = arr[j];    //Sorting
                arr[j] = tmp;       //Sorting
            }
}

int main() {
    //THIS CODE BLOCK INITIATES ARRAY TO BE USED
    //Temporary array for reading all lines in a file
    //A text file with newlines is a 2d array
    char arr[12];
    char line[12][1]; //12 rows since there are 12 rows in input file and 1 column for each character
    FILE *fptr;
    int j = 0;
    fptr = fopen("INPUT.txt", "r");
    while(fgets(line[j], 3, fptr))//1 doesn't work, 2 doesn't work. Finally 3 works. This was only supposed to get the first character of each line in the file
        j++;
    //transfer all chars to own array
    for (int k = 0; k<12; k++)
        arr[k] = line[k][0];
    fclose(fptr);




    char opt = '+', ch_search;//opt is initialized as '+' arbitrarily to avoid getting a '0' randomly when main is initialized
    int array_size = 12, index;

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
            case '1'://Linear ch_search
                printf("You pressed 1\n"
                       "Input your letter to search: \n");
                scanf(" %c", &ch_search);
                fflush(stdin); //Clears buffer to only accept one character as input
                ch_search = toupper(ch_search);//Transforms user input to upper
                printf("\nInput = %c\n", ch_search);
                /* CORE */
                if (search(ch_search, array_size, arr, &index)) //Search Function
                    printf("%c found at position %d\n",arr[index],index);   //Print if function returns 1
                else
                    printf("Input not found in array\n"); //print if function returns 0
                 /* CORE */
                break;
            case '2':
                printf("You pressed 2\n");
                //Print contents of original array
                printf("Before deletion:\n");
                for (int i = 0;i<array_size;i++)
                    printf("%c ", arr[i]);
                printf("\n--Your input will be converted to uppercase--\n");
                printf("\nEnter letter to be deleted: \n");
                scanf(" %c", &ch_search);
                fflush(stdin); //Clears buffer to only accept one character as input
                ch_search = toupper(ch_search);//Transforms user input to upper
                printf("\nYour input was: %c\n", ch_search);
                /* CORE */
                if (delete(ch_search, &array_size, arr)) //Search Function
                {
                    printf("\nAfter Deletion:\n");
                    for (int i = 0; i < array_size; i++)
                        printf("%c ", arr[i]);
                }
                else
                    printf("\nSorry your input can't be found\n");
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
                sort(arr, array_size);
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
        if (opt == '1'|| opt == '2'||opt=='3') // Return to Menu or Exit
        {
            printf("\nEnter any character to continue or 0 to exit: ");
            scanf(" %c", &opt);
            fflush(stdin);
        }
    }

    //Write data to "OUTPUT.txt"
    FILE *outputptr;
    outputptr = fopen("OUTPUT.txt", "w");
    fputs("Array Me! ver 2.0 project by: Raphael Quinones\n"
          "The final array content:\n", outputptr);
    for (int i = 0; i<array_size; i++){
        fputc(arr[i], outputptr);
        fputs(" ", outputptr);
    }
    fclose(outputptr);
    return 0;
}
