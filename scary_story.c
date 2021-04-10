#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for sleep function

void tell_story(int story, FILE *fp);

int main()
{
    int story;
    FILE *fp;
    
    printf("\nPick from 1 to 5 for a scary story: ");
    scanf("%d", &story);
    story--;
        
    switch(story)
    {
        case 0:
        fp = fopen("story1.txt", "r");
        printf("Story %d\n\n", story + 1);
        tell_story(story,fp);
        break;
        
        case 1:
        fp = fopen("story2.txt", "r");
        printf("Story %d\n\n", story + 1);
        tell_story(story,fp);
        break;
        
        case 2:
        fp = fopen("story3.txt", "r");
        printf("Story %d\n\n", story + 1);
        tell_story(story,fp);
        break;
        
        case 3:
        fp = fopen("story4.txt", "r");
        printf("Story %d\n\n", story + 1);
        tell_story(story,fp);
        break;
        
        case 4:
        fp = fopen("story5.txt", "r");
        printf("Story %d\n\n", story + 1);
        tell_story(story,fp);
        break;
    }
    return 0;   
}

void tell_story(int story, FILE *fp)
{
    int i, n, p;
    char *str = malloc(200);
    fscanf(fp, "%d\n", &n);
    for(i = 0; i < n; i++)
    {
        fgets(str, 200, fp);
        puts(str);
        sleep(4);
    }
    fscanf(fp, "%d", &p);
    for(i = 0; i < p; i++)
    {
        fgets(str, 200, fp);
        printf("%s", str);
    }
}

