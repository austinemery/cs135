#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 20
#define MAX_ENTRY 30
#define MAX_NUM 15

void print_contacts(int num_con, char *contacts[num_con][4]);
void add_contact(int num_con, char *contacts[MAX_CONTACTS][4]);
void delete_contact(int num_con, char *contacts[MAX_CONTACTS][4]);
int read_line(int num_con, char temp[]);

int main()
{
    //Declares values for main contact function
    char *contacts[MAX_CONTACTS][4];
    char choice, num_str[MAX_NUM+1], msg_str[MAX_ENTRY+1];
    int num_con = 0;
    
    while(choice != 'b')
    {
        printf("\nPlease Choose:\nView Contacts - V\nAdd Contact - A\nDelete Contact - D\nBack- B\n");  //prints contacts menu
        scanf(" %c", &choice);  //scan for user menu choice
        switch(choice)
        {
            case 'V':   //print contact case
            case 'v':
            if(num_con == 0)
                printf("No Contacts");
            else
                print_contacts(num_con, contacts);
            break;

            case 'A':   //add contact case
            case 'a':
            /* TRY TO RESIZE ARRAY HERE LATER
            contacts = realloc(contacts, (num_con + 1) * sizeof(char));
            if (contacts == NULL)
            {
                printf("-- No space left (main function case a)--\n");
                exit(0);
            }
            */
            add_contact(num_con, contacts);
            num_con++;
            break;

            case 'D':   //delete contact case
            case 'd':
            printf("Which contact would you like to delete?\n");
            if(num_con == 0)
                printf("No Contact to Delete");
            else
                delete_contact(num_con, contacts);
            /* TRY TO RESIZE ARRAY HERE LATER
            contacts = realloc(contacts, (num_con - 1) * sizeof(char));
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
    //INSERT RETURN TO MAIN MENU HERE AND/OR CHANGE FROM "int main()" TO "int contacts()"
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

void add_contact(int num_con, char *contacts[MAX_CONTACTS][4])
{
    int i, j, n;
    char num[MAX_NUM+1], ent[MAX_ENTRY+1], word[12];
    sprintf(word, "Name: ");
    printf("Name: ");
    n = read_line(MAX_ENTRY, ent);
    contacts[i][j] = malloc(2 + n + 1);
    if (contacts[i][j] == NULL)
    {  
        printf("No space left - add_contact(name)\n");
    }
    strcpy(contacts[i][j], word);
    strcat(contacts[i][j++], ent);
    
    sprintf(word, "Primary: ");
    printf("Primary: ");
    n = read_line(MAX_NUM, num);
    contacts[i][j] = malloc(2 + n + 1);
    if (contacts[i][j] == NULL)
    {  
        printf("No space left - add_contact(Primary)\n");
    }
    strcpy(contacts[i][j], word);
    strcat(contacts[i][j++], num);
    
    sprintf(word, "Secondary: ");
    printf("Secondary: ");
    n = read_line(MAX_NUM, num);
    contacts[i][j] = malloc(2 + n + 1);
    if (contacts[i][j] == NULL)
    {  
        printf("No space left - add_contact(secondary)\n");
    }
    strcpy(contacts[i][j], word);
    strcat(contacts[i][j++], num);
    
    sprintf(word, "E-mail: ");
    printf("E-mail: ");
    n = read_line(MAX_ENTRY, ent);
    contacts[i][j] = malloc(2 + n + 1);
    if (contacts[i][j] == NULL)
    {  
        printf("No space left - add_contact(e-mail)\n");
    }
    strcpy(contacts[i][j], word);
    strcat(contacts[i][j], ent);
}

void delete_contact(int num_con, char *contacts[num_con][4])
{
    int i;
    char word[7] = "Name: ", ent[MAX_ENTRY+1], search[MAX_ENTRY+7];
    read_line(MAX_ENTRY, ent);
    strcpy(search, word);
    strcat(search, ent);
    for (i = 0; i < num_con; i++)
        if (strcmp(search, contacts[i][0])==0)
            break;
    free(contacts[i][0]);
}

void print_contacts(int num_con, char *contacts[num_con][4])
{
    int i,j;
    for(i = 0; i < num_con; i++)
    {
        for(j = 0; j < 4; j++)  //runs through all pointers in the matrix
            printf("%s\t", contacts[i][j]); //attempts to print notes
        printf("\n");
    }
}
