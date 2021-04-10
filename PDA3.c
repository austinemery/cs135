#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//for contacts
#define MAX_CONTACTS 200
#define MAX_ENTRY 1000
#define MAX_NUM 50

//for calender
#define maxRemind 50
#define msgLen 60 

//for calculator
void add();
void subtract();
void multiply();
void divide();
void cm_in();
void km_m();
void mile_km();
void square_meter_to_square_foot();
void matrix_calc();
int conversion();
void user_define();
int controller();

//for contacts
void print_contacts(int num_con, char *contacts[num_con][4]);
void add_contact(int num_con, char *contacts[MAX_CONTACTS][4]);
void delete_contact(int num_con, char *contacts[MAX_CONTACTS][4]);
int read_line(int num_con, char temp[]);
int contacts_function();

//for calander
int readLine(char str[], int n);
int calanderFunction();

int main(void)

{
	char *reminders[maxRemind];
	char day_str[3], msg_str[msgLen+1];

	int x;

	for (;;)
	 {		
		printf("\nMain Menu:\n\n1. Calculator...\n2. Calender...\n3. Contacts...\n4. Notes...(not ready)\n");
		printf("5. Personal Information...(not ready)\n6. Exit...\n\nCommand: ");

		scanf("%d", &x);
		
		if (x == 1)
		 {
			controller();
		 }
		else if (x == 2)
		 {
			calanderFunction();
		 }
		else if (x == 3)
		 {
			contacts_function();
		 }
		else if (x == 6)
		 {
			return 0;
		 }
		else
		 {
			printf("\nInvalid command...\n\n");
		 }
	 }			

	return 0;	

}

						//for contacts
int contacts_function()
{
    //Declares values for main contact function
    char *contacts[MAX_CONTACTS][4];
    char num_str[MAX_NUM+1], msg_str[MAX_ENTRY+1]; 
    int num_con = 0;
	int choice;
    
    for(;;)
    {
        printf("\nContacts Menu:\n1. View Contacts\n2. Add Contact\n3. Delete Contact\n4. Back\nCommand: ");  //prints contacts menu
        scanf(" %d", &choice);  //scan for user menu choice
        switch(choice)
        {
            case 1:   //print contact case
            if(num_con == 0)
                printf("\n--No Contacts--");
            else
                print_contacts(num_con, contacts);
            break;

            case 2:   //add contact case
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

            case 3:   //delete contact case
            printf("Which contact would you like to delete?\n");
            if(num_con == 0)
                printf("--No Contact to Delete--");
            else
                delete_contact(num_con, contacts);
                num_con--;
            /* TRY TO RESIZE ARRAY HERE LATER
            contacts = realloc(contacts, (num_con - 1) * sizeof(char));
            */
            break;

            case 4:   //Return to main menu case
			return 0;
            break;

            default:
            printf("--Invalid Option--\n");  
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

    int i, j = 0, n;
    char num[MAX_NUM+1], ent[MAX_ENTRY+1], word[MAX_NUM + 1]; //max num = 50, max entry = 1000

    i = num_con; 
    sprintf(word, "Name: "); 
    printf("Name: ");
    n = read_line(MAX_ENTRY, ent);
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
    contacts[i][j] = malloc(2 + n + 1); //segfault occurs at this line
    
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
    contacts[i][j] = malloc(10 + n + 1 );
    
    if (contacts[i][j] == NULL)
    {  
        printf("No space left - add_contact(e-mail)\n");
    }
    
    strcpy(contacts[i][j], word);
    strcat(contacts[i][j], ent);

}

void delete_contact(int num_con, char *contacts[num_con][4])
{
    int i, j;
    char word[7] = "Name: ", ent[MAX_ENTRY+1], search[MAX_ENTRY+7];
    read_line(MAX_ENTRY, ent);
    read_line(MAX_ENTRY, ent);
    strcpy(search, word);
    strcat(search, ent);
    for (i = 0; i < num_con; i++)
        if (strcmp(search, contacts[i][0])==0)
            break;
    free(contacts[i][0]);
    for(i; i < (num_con - 1); i++)
        for(j = 0; j < 4; j++)
            contacts[i][j] = contacts[i + 1][j];   
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

						//for calander

int calanderFunction()
 {
	int x;
	char *reminders[maxRemind];
	char day_str[3], msg_str[msgLen+1];

	int day, i, j, numRemind = 0;

  	for (;;)
   	 {
	printf("\nWhat would you like to do?\n\n");
	printf("1. View reminders\n2. Add reminders\n3. Go back\nCommand: ");

	scanf("%d", &x);

	if (x == 1)
	 {
		printf("\nDate Reminder\n\n");

  		for (i = 0; i < numRemind; i++)
		 {
    			printf(" %s\n", reminders[i]);
		 }
		if (numRemind == 0)
		 {
			printf("--There are no reminders--");
 		 }
	 }
	

  
	else if (x == 2)
	 {
		printf("\nReady to add reminders.\nPress ""0"" to stop.\n");

	for (;;) 
	 {
		
		if (numRemind == maxRemind) 
		 {

      			printf("--No space left--\n");

     			break;
		 }

		printf("Enter date and reminder: ");

   		scanf("%2d", &day);

    		if (day == 0)
		 {
			break;
		 }
		sprintf(day_str, "%2d", day);

    		readLine(msg_str, msgLen);

 		for (i = 0; i < numRemind; i++)
		 {
      			if (strcmp(day_str, reminders[i]) < 0)
			 {
        			break;
			 }
		 }

    		for (j = numRemind; j > i; j--)

      			reminders[j] = reminders[j-1];

			reminders[i] = malloc(2 + strlen(msg_str) + 1);

  				if (reminders[i] == NULL) 
				 {

      					printf("--No space left--\n");

      					break;
				 }

		strcpy(reminders[i], day_str);

   		strcat(reminders[i], msg_str);

    		numRemind++;

	 }
	 }

	else if (x == 3)
	 {
		return 0;
	 }

	else 
	 {
		printf("\n--Invalid option--\n");
	 }		
	 }
 }

int readLine(char str[], int n)
 {
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
	 {
		if (i < n)
		 {
			str[i++] = ch;
		 }
		str[i] = '\0';
	 }
	return i;
 }
						//for calculator 
void add()
{
	//adding numbers
	printf("Enter how many numbers you want to add\n");
	int count = 0;
	scanf("%d", &count);
	int i = 0;
	int array[100];
	int get = 0;
	for(i = 0; i < count; i++)
	{
		printf("Enter number %d:", (i + 1));
		scanf("%d", &array[i]);
		get += array[i];

	}
	printf("The answer is: %d ", get); //adds up the numbers you want to add
	printf("\n");
}

void subtract()
{
   printf("Enter the numbers you want to subtract\n");
	 printf("**Note** this calculator supports upto 20 numbers at max\n");
	 printf("How many numbers would you like to subtract\n");
	 int amount;
	 bool check_amount = false;
	 scanf("%d", &amount);

	if (amount > 20)
	{
		check_amount = true;
		if (check_amount = true)
		printf("Error: Enter a valid number from 1 - 20\n");
		scanf("%d", &amount);
	}

	 float num1,num2,num3,num4,num5,num6,num7,num8,num9,num10,num11,num12,num13,num14,num15,num16,num17,num18,num19,num20;
	 float answer;
	 char selecton;

	 if (amount == 2)
	 {
		 printf("Enter your two numbers\n");
		 scanf("%f %f", &num1, &num2);
		 answer = num1 - num2;
		 printf("Your answer is: %.2f", answer);
	 }

	 if(amount == 3)
	 {
		 printf("Enter your three numbers\n");
		 scanf("%f %f %f", &num1, &num2, &num3);
		 answer = num1 - num2 - num3;
		 printf("Your answer is: %.2f", answer);
	 }

	 if(amount == 4)
	 {
		 printf("Enter your four numbers\n");
		 scanf("%f %f %f %f", &num1, &num2, &num3, &num4);
		 answer = num1 - num2 - num3 - num4;
		 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 5)
	 {
		 printf("Enter your five numbers\n");
		 scanf("%f %f %f %f %f", &num1, &num2, &num3, &num4, &num5);
		 answer = num1 - num2 - num3 - num4 - num5;
		 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 6)
	 {
		 printf("Enter your six numbers\n");
		 scanf("%f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6);
		 answer = num1 - num2 - num3 - num4 - num5 - num6;
		 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 7)
	 {
		 printf("Enter your seven numbers\n");
		 scanf("%f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7);
		 answer = num1 - num2 - num3 - num4 - num5 - num6 - num7;
		 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 8)
	 {
		 printf("Enter your eight numbers\n");
		 scanf("%f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8);
		 answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8;
		 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 9)
	 {
		 printf("Enter your nine numbers\n");
		 scanf("%f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9);
		 answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8 - num9;
		 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 10)
	 {
		 printf("Enter your ten numbers\n");
 		scanf("%f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10);
 		answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8 - num9 - num10;
 		printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 11)
	 {
		 printf("Enter your eleven numbers\n");
		 scanf("%f %f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11);
		 answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8 - num9 - num10 - num11;
		 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 12)
	 {
		printf("Enter your twelve numbers\n");
		scanf("%f %f %f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12);
		answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8 - num9 - num10 - num11 - num12;
		printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 13)
	 {
		printf("Enter your thirteen numbers\n");
 		scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12, &num13);
 		answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8 - num9 - num10 - num11 - num12 - num13;
 		printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 14)
	 {
		 printf("Enter your fouteen numbers\n");
		 scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12, &num13, &num14);
		 answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8, num9 - num10 - num11 - num12 - num13 - num14;
		 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 15)
	 {
		 printf("Enter your fifteen numbers\n");
		 scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12, &num13, &num14, &num15);
		 answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8, num9 - num10 - num11 - num12 - num13 - num14 - num15;
		 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 16)
	 {
		printf("Enter your sixteen numbers\n");
 		scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12, &num13, &num14, &num15, &num16);
 		answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8, num9 - num10 - num11 - num12 - num13 - num14 - num15 - num16;
 		printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 17)
	 {
		printf("Enter your seventeen numbers\n");
  	scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12, &num13, &num14, &num15, &num16, &num17);
  	answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8, num9 - num10 - num11 - num12 - num13 - num14 - num15 - num16 - num17;
  	printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 18)
	 {
	 printf("Enter your eighteen numbers\n");
 	 scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12, &num13, &num14, &num15, &num16, &num17, &num18);
 	 answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8, num9 - num10 - num11 - num12 - num13 - num14 - num15 - num16 - num17 - num18;
 	 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 19)
	 {
		 printf("Enter your nineteen numbers\n");
   	 scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12, &num13, &num14, &num15, &num16, &num17, &num18, &num19);
   	 answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8, num9 - num10 - num11 - num12 - num13 - num14 - num15 - num16 - num17 - num18 - num19;
   	 printf("Your answer is: %.2f", answer);
	 }

	 if (amount == 20)
	 {
		 printf("Enter your twenty numbers\n");
		 scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12, &num13, &num14, &num15, &num16, &num17, &num18, &num19, &num20);
   	 answer = num1 - num2 - num3 - num4 - num5 - num6 - num7 - num8, num9 - num10 - num11 - num12 - num13 - num14 - num15 - num16 - num17 - num18 - num19 - num20;
   	 printf("Your answer is: %.2f", answer);
	 }

}

void multiply()
{
	printf("Enter how many numbers you want to multiply\n");
	printf("**Note this calculator can multiply upto 20 numbers at max\n");
	int amount;
	bool check = false;
	scanf("%d", &amount);
	if (amount > 20)
	{
		check = true;
		if(check = true)
		{
			printf("Error: Enter a valid number from 1 - 20\n");
			scanf("%d", &amount);
		}
	}
	float mult1,mult2,mult3,mult4,mult5,mult6,mult7,mult8,mult9,mult10,mult11,mult12,mult13,mult14,mult15,mult16,mult17,mult18,mult19,mult20;
	float answer;

	if (amount == 2)
	{
		printf("Enter the two numbers you want to multiply\n");
		scanf("%f %f", &mult1, &mult2);
		answer = mult1 * mult2;
		printf("Your answer is: %.2f", answer);
	}

	if (amount == 3)
	{
		printf("Enter the three numbers you want to multiply\n");
		scanf("%f %f %f", &mult1, &mult2, &mult3);
		answer = mult1 * mult2 * mult3;
		printf("Your answer is: %.2f", answer);
	}

	if (amount == 4)
	{
	 printf("Enter the four numbers you want to multiply\n");
	 scanf("%f %f %f %f", &mult1, &mult2, &mult3, &mult4);
	 answer = mult1 * mult2 * mult3 * mult4;
	 printf("Your answer is: %.2f", answer);
	}

	if (amount == 5)
	{
	 printf("Enter the five numbers you want to multiply\n");
 	 scanf("%f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5);
 	 answer = mult1 * mult2 * mult3 * mult4 * mult5;
 	 printf("Your answer is: %.2f", answer);
	}

	if (amount == 6)
	{
		printf("Enter the six numbers you want to multiply\n");
  	scanf("%f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6);
  	answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6;
  	printf("Your answer is: %.2f", answer);
	}

	if (amount == 7)
	{
	 printf("Enter the seven numbers you want to multiply\n");
	 scanf("%f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7);
	 answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7;
	 printf("Your answer is: %.2f", answer);
	}

	if (amount == 8)
	{
	 printf("Enter the eight numbers you want to multiply\n");
 	 scanf("%f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8);
 	 answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8;
 	 printf("Your answer is: %.2f", answer);
	}

	if (amount == 9)
	{
		printf("Enter the nine numbers you want to multiply\n");
  	scanf("%f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9);
  	answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9;
  	printf("Your answer is: %.2f", answer);
	}

	if (amount == 10)
	{
	 printf("Enter the ten numbers you want to multiply\n");
 	 scanf("%f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10);
 	 answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10;
 	 printf("Your answer is: %.2f", answer);
	}

	if (amount == 11)
	{
		 printf("Enter the eleven numbers you want to multiply\n");
  	 scanf("%f %f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10, &mult11);
  	 answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10 * mult11;
  	 printf("Your answer is: %.2f", answer);
	}

	if (amount == 12)
	{
		printf("Enter the twelve numbers you want to multiply\n");
		scanf("%f %f %f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10, &mult11, &mult12);
		answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10 * mult11 * mult12;
		printf("Your answer is: %.2f", answer);
	}

	if (amount == 13)
	{
		printf("Enter the thirteen numbers you want to multiply\n");
		scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10, &mult11, &mult12, &mult13);
		answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10 * mult11 * mult12 * mult13;
		printf("Your answer is: %.2f", answer);
	}

	if (amount == 14)
	{
		printf("Enter the fourteen numbers you want to multiply\n");
		scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10, &mult11, &mult12, &mult13, &mult14);
		answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10 * mult11 * mult12 * mult13 * mult14;
		printf("Your answer is: %.2f", answer);
	}

	if (amount == 15)
	{
		printf("Enter the fifteen numbers you want to multiply\n");
		scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10, &mult11, &mult12, &mult13, &mult14, &mult15);
		answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10 * mult11 * mult12 * mult13 * mult14 * mult15;
		printf("Your answer is: %.2f", answer);
	}

	if (amount == 16)
	{
		printf("Enter the sixteen numbers you want to multiply\n");
		scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10, &mult11, &mult12, &mult13, &mult14, &mult15, &mult16);
		answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10 * mult11 * mult12 * mult13 * mult14 * mult15 * mult16;
		printf("Your answer is: %.2f", answer);
	}

	if (amount == 17)
	{
		printf("Enter the seventeen numbers you want to multiply\n");
		scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10, &mult11, &mult12, &mult13, &mult14, &mult15, &mult16, &mult17);
		answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10 * mult11 * mult12 * mult13 * mult14 * mult15 * mult16 * mult17;
		printf("Your answer is: %.2f", answer);
	}

	if (amount == 18)
	{
		printf("Enter the eighteen numbers you want to multiply\n");
		scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10, &mult11, &mult12, &mult13, &mult14, &mult15, &mult16, &mult17, &mult18);
		answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10 * mult11 * mult12 * mult13 * mult14 * mult15 * mult16 * mult17 * mult18;
		printf("Your answer is: %.2f", answer);
	}

	if (amount == 19)
	{
		printf("Enter the nineteen numbers you want to multiply\n");
		scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10, &mult11, &mult12, &mult13, &mult14, &mult15, &mult16, &mult17, &mult18, &mult19);
		answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10 * mult11 * mult12 * mult13 * mult14 * mult15 * mult16 * mult17 * mult18 * mult19;
		printf("Your answer is: %.2f", answer);
	}

	if (amount == 20)
	{
		printf("Enter the twenty numbers you want to multiply\n");
		scanf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f", &mult1, &mult2, &mult3, &mult4, &mult5, &mult6, &mult7, &mult8, &mult9, &mult10, &mult11, &mult12, &mult13, &mult14, &mult15, &mult16, &mult17, &mult18, &mult19, &mult20);
		answer = mult1 * mult2 * mult3 * mult4 * mult5 * mult6 * mult7 * mult8 * mult9 * mult10 * mult11 * mult12 * mult13 * mult14 * mult15 * mult16 * mult17 * mult18 * mult19 * mult20;
		printf("Your answer is: %.2f", answer);
	}
}

void divide()
{
	printf("Enter two numbers that you want to divide\n");
	float number1;
	float number2;
	float answer_div;
	scanf("%f %f", &number1, &number2);
	answer_div = (number1 / number2);
	printf("Your answer is: %.2f\n", answer_div);
}

void cm_in()
{
	//converts your number from centimeters to inches
	printf("Enter your number in centimeters\n");
	float cent;
	scanf("%f", &cent);
	float inch = 0.393701;
	float answer;
	answer = cent * inch;
	printf("Your number is: %.3f inches\n", answer);
}

void km_m()
{
	//converts your number from kilometers to meters
	printf("Enter your number in kilometers\n");
	float kilo;
	scanf("%f", &kilo);
	float meters = 1000;
	float answer;
	answer = kilo * meters;
	printf("%.2f in meters is: %.2f\n", kilo, answer);
}

void mile_km()
{
	//converts from miles to kilometers
	printf("Enter your number in miles\n");
	float miles;
	scanf("%f",&miles);
	float kilo = 1609;
	float answer;
	answer = (miles * kilo) / 1000;
	printf("%.2f in kilometers is: %.2f\n", miles,answer);
}

void square_meter_to_square_foot()
{
	printf("Enter your number in square meters\n");
	float square_meter;
	scanf("%f", &square_meter);
	float square_foot = 10.7639;
	float answer;

	answer = square_meter * square_foot;
	printf("%.2f in square foot is: %.2f\n", square_meter, answer);
}

void matrix_calc()
{
	int row;
	int col;
	int array[100][100];
	int row2;
	int col2;
	printf("Enter the sizes of your rows and columns of your first matrix\n");
	scanf("%d %d", &row, &col);
	printf("Enter the sizes of your second matrix\n");
	scanf("%d %d", &row2, &col2);
	if (row != row2 && col != col2)
	{
		printf("Error: Your rows and columns are not equal cannot calculate sum\n");
		printf("Enter the rows and columns for your first matrix again\n");
		scanf("%d %d", &row, &col);

		printf("Enter the rows and columns for your second matrix again\n");
		scanf("%d %d", &row2, &col2);
	}
	int i = 0;
	int j = 0;

	int store[100][100];

	for(i = 0; i < row; i++)
	{
		printf("Enter row %d:", i);

		for(j = 0; j < col; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}


	int array2[row2][col2];

	int a = 0;
	int b = 0;

	for(i = 0; i < row2; i++)
	{
		printf("Enter row %d:", i);
		for(j = 0; j < col2; j++)
		{
			scanf("%d", &array2[i][j]);
		}
	}

	printf("Would you like to add multiply,subtract?\n");
	printf("Press A to add\n");
	printf("Press S to subtract\n");
	printf("Press M to multiply\n");
	char choose;
  while(choose != 'a' || 's' || 'm')
	{
	scanf("%c", &choose);

	if (choose == 'a')
	{
		printf("The sum of your elements:\n");
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < col; j++)
			{
				store[i][j] = array[i][j] + array2[i][j];
				printf("%2d\t", store[i][j]);

			}
			printf("\n");

		}
		break;
	}


	if (choose == 's')
	{
		printf("Your elements subtracted:\n");
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < col; j++)
			{
				store[i][j] = array[i][j] - array2[i][j];
				printf("%2d\t", store[i][j]);

			}
			printf("\n");

		}
		break;
	}


	if (choose == 'm')
	{
		printf("Your elements multiplied:\n");
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < col; j++)
			{
				store[i][j] = array[i][j] * array2[i][j];
				printf("%2d\t", store[i][j]);

			}
			printf("\n");

		}
		break;
	}
}
}

int conversion()
{
	int select;

	for (;;)
	{	
		printf("\nConversion Menu:\n");
		printf("1. Centemeters to Inches\n");
		printf("2. Kilometers to Meters\n");
		printf("3. Miles to Kilometers\n");
		printf("4. Square Meters to Square Feet\n");
		printf("5. Exit\n");
  		printf("Command: ");

		scanf("%d", &select);

		switch(select)
		{
			case 1:
			{
				cm_in();
				break;
			}

			case 2:
			{
				km_m();
				break;
			}

			case 3:
			{
				mile_km();
				break;
			}

			case 4:
			{
				square_meter_to_square_foot();
				break;
			}
			case 5:
			{
				return 0;

			}
		}
	}
}

void user_define()
{
	int selection;

	printf("\nWelcome to Math\n");

	for (;;)
	{
		printf("1. Addition\n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("5. Matrix Math\n");
 		printf("6. Exit\n");
		printf("Command: ");

		scanf("%d", &selection);
		switch(selection)
		{
			case 1:
			{
				add();
				break;

			}

		  	case 2:
		   	{
		   		subtract();
				break;
		   	}

			case 3:
			{
				multiply();
				break;
			}

			case 4:
			{
				divide();
				break;
			}

			case 5:
			{
				matrix_calc();
				break;
			}

			case 6:
			{
				return;
			}

		}
	}
}



int controller()
{
	int select;
	char convert;

	for (;;)
	{
		printf("\nCalculator Menu:\n");
		printf("1. Calculations\n");
		printf("2. Conversions\n");
		printf("3. Exit\n");
		printf("Command: ");
		scanf("%d", &select);
	
		if (select == 1)
		{
			user_define();
		}
		else if (select == 2)
		{
			conversion();
		}
		else if (select == 3)
		{
			return 0;
		}
		else 
		{
			printf("--Invalid Key--\n");
		}	
	}
}
