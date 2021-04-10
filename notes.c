#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOTES 200
#define MAX_ENTRY 1000

void print_notes(int num_note, char *notes[num_note]);
void add_note(int num_note, char *notes[MAX_NOTES]);
void delete_note(int num_note, char *notes[MAX_NOTES]);
int read_line(int num_note, char temp[]);

int main()
{
    //Declares values for main note function
    char *notes[MAX_NOTES];
    char choice;
    int i, num_note = 0;
    FILE *fp = fopen("notes.txt", "r+");
    
    fscanf(fp, "%d\n", &num_note);
    for(i = 0; i < num_note; i++)
    {
        notes[i] = malloc(MAX_ENTRY + 1);
        fgets(notes[i], MAX_ENTRY, fp);
    }
    
    while(choice != 'b')
    {
        printf("\nYou have %d notes.", num_note);
        printf("\nPlease Choose:\nView Notes - V\nAdd Note - A\nDelete Note - D\nBack- B\nEnter Choice: ");  //prints Notes menu
        scanf(" %c", &choice);  //scan for user menu choice
        printf("\n");
        switch(choice)
        {
            case 'V':   //print notes case
            case 'v':
            if(num_note == 0)
                printf("No Notes");
            else
                print_notes(num_note, notes);
            break;

            case 'A':   //add notes case
            case 'a':
            /* TRY TO RESIZE ARRAY HERE LATER
            notes = realloc(notes, (num_note + 1) * sizeof(char));
            if (notes == NULL)
            {
                printf("-- No space left (main function case a)--\n");
                exit(0);
            }
            */
            add_note(num_note, notes);
            num_note++;
            break;

            case 'D':   //delete note case
            case 'd':
            printf("Which note would you like to delete?\n");
            if(num_note == 0)
                printf("No note to Delete");
            else
                delete_note(num_note, notes);
                num_note--;
            /* TRY TO RESIZE ARRAY HERE LATER
            notes = realloc(notes, (num_note - 1) * sizeof(char));
            */
            break;

            case 'B':   //Return to main menu case
                choice = 'b';
            case 'b':
            break;

            default:
            printf("Invalid Option\n");  
            break;
        }
        printf("\n");
    }
    printf("Returning to main menu...\n"); //signify end of program
    //INSERT RETURN TO MAIN MENU HERE AND/OR CHANGE FROM "int main()" TO "int notes()"
    
    rewind(fp);
    fprintf(fp, "%d\n", num_note);
    for(i = 0; i < num_note; i++)
        fputs(notes[i],fp);
    fclose(fp);
    return 0;
    
}

int read_line(int n, char temp[])   //similar to lecture[13][0] read_line code
{
    int c, i = 0;
    while ((c = getchar()) != '\n')
        if (i < n)
            temp[i++] = c;
    temp[i] = '\0';
    return i;
}

void add_note(int num_note, char *notes[MAX_NOTES])
{

    int i, n;
    char ent[MAX_ENTRY+1]; //max entry = 2000
    
    printf("Enter Note: ");
    i = num_note;
    n = read_line(MAX_ENTRY, ent);
    n = read_line(MAX_ENTRY, ent);
    notes[i] = malloc(MAX_ENTRY + 1);
   
    if (notes[i] == NULL)
    {  
       printf("No space left - add_note\n");
    }
    
    strcpy(notes[i], ent);
}

void delete_note(int num_note, char *notes[num_note])
{
    int i;
    printf("Please enter number of note to delete: ");
    scanf("%d", &i);
    i--;
    for(i; i < (num_note - 1); i++)
        notes[i] = notes[i + 1];   
}

void print_notes(int num_note, char *notes[num_note])
{
    int i;
    for(i = 0; i < num_note; i++)
        printf("%3d %s\n", i+1, notes[i]); //attempts to print notes
}
