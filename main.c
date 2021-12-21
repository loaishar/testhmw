#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD 30
#define TXT 1024
int isSame(int *a, int *b) // compare whether two int arrays are the same
{
    int i;
    for (i = 0; i < 26; i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
char *remove_white_spaces(char str[])
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}
void findAnagrams2(char *str, char *word)
{
    int number = strlen(str);
    char *stringa_for_rem_space = (char *)malloc(number * sizeof(char));
    strcpy(stringa_for_rem_space, str);
    char *stringa_without_spaces = (char *)malloc(number * sizeof(char));
    strcpy(stringa_without_spaces, remove_white_spaces(str));
    free(stringa_for_rem_space);
    int *str_0 = (int *)malloc(number * sizeof(int));
    memset(str_0, 0, number * sizeof(str_0[0]));
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < strlen(word); j++)
        {
            if (word[j] == str[i])
            {
                if (str_0[i] == 0)
                {
                    str_0[i]++;
                    // i = 0;
                }
            }
        }
    }
}
/*****o be reviewed****/
int main()
{

    //   printf("Insert word_input: MAX 8 CHARS!\n\n");

    /*********** thhe word input ***********************************************/

    char string2[30];
    scanf("%30s", string2);
    // str will be modified by strtok
    const char deli1[] = " ";
    const char deli2[] = "\n";
    const char deli3[] = "\t"; // deli could also be declared as [2] or as const char *. Take your pick...
    char *token;

    token = strtok(string2, deli1);
    token = strtok(string2, deli2);
    token = strtok(string2, deli3);
    int i = 0;
    // while(token[i]!='\0') {
    //     printf("%c, ",token[i]);
    //     i++;
    // }

    /****************** end word input ************************************************/
    while ((getchar()) != '\n')
        ;

    char string1[1024];
    //  char string1[TXT];
    scanf("%[^~]s", string1);
    i = 0;
    // while(string1[i]!='\0') {
    //      printf("%c, ",string1[i]);
    //      i++;
    // }

    printf("\n");
    /******* print function for test ********/
    //  for (int i = 0; i < 8; ++i) {
    //      printf("%c, ",string2[i]);
    //  }
    /*******end print function for test ********/

    // int x = word_length_geo(token);
    // printf("Gematria Sequences: ");
    // text_length_geo(string1, x);
    printf("\n");

    //  for (int i = 0; i < length_of_string2; ++i)
    {
        //     printf("%c, ", word_for_atbash[i]);
    }
    /******reverse word*******/
    char *rev = malloc(sizeof token);
    int count = 0, j;
    while (token[count] != '\0')
    {
        count++;
    }
    j = count - 1;

    // reversing the string by swapping
    for (i = 0; i < count; i++)
    {
        rev[i] = token[j];
        j--;
    }
    /*****end reverse word*****/
    char *word1 = malloc(sizeof token);
    char *word2 = malloc(sizeof token);
    // memmove(word1, word_for_atbash_generate(token), sizeof token);
    //  printf("%s",word1);
    //  free(word1);
    // memmove(word2, word_for_atbash_generate(rev), sizeof token);
    //  printf("%s",word2);
    //  word_for_atbash_generate(rev);
    printf("Atbash Sequences: ");
    // hatbash(string1, word1);
    free(word1);
    // hatbash(string1, word2);
    free(word2);
    int xen = strlen(token);

    // int *ptr =
    printf("\nAnagram Sequences: ");
    int *p = findAnagrams(string1, token, 0);
    int n = sizeof(p) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", p[i]);
    }
}