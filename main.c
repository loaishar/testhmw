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
int not_contain_zero(int from, int to, int *arraysum2)
{
    // int n = sizeof(arraysum2) / sizeof(int);
    for (int i = from; i < to; i++)
    {
        if (arraysum2[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}
int exist_in_the_rext(char c, char *str, int begin, int end)
{
    for (int i = begin; i <= end; i++)
    {
        if (str[i] == c)
        {
            return 1;
        }
    }
    return 0;
}
int IsFroBeToEn_included_in_word(int begin, int end, char *str, char *word)
{
    int wordlength = strlen(word);
    for (int i = 0; i < wordlength; i++)
    {
        if (!(exist_in_the_rext(word[i], str, begin, end)))
        {
            return 0;
        }
    }
    return 1;
}
void printanagram(int *str1_0, int *str2_spaces, int length, char *str, char *word)
{
    int spaces = 0;
    int c = 0, begin, end;
    int strLength = strlen(str);
    int *arrayssum = (int *)malloc(strLength * sizeof(int));
    for (int i = 0; i < strLength; i++)
        arrayssum[i] = str1_0[i] + str2_spaces[i];
    int cunter = 0;
    for (int x = 0; x < strLength; x++)
    {
        if ((arrayssum[x] == 0))
        {

            c = 0;
        }
        if ((arrayssum[x] == 2))
        {

            spaces++;
        }
        if ((arrayssum[x] == 1) && (c == 0))
        {
            begin = x;
            c++;
        }
        else
        {
            if ((arrayssum[x] == 1))
            {
                c++;
                if (c == length)
                {
                    end = x;
                    int shall = begin;
                    if (not_contain_zero(begin, end, arrayssum))
                    {
                        if (IsFroBeToEn_included_in_word(begin, end, str, word))
                        {
                            //printf("%d\n",begin);
                            while (begin < (end) + 1)
                            {
                                 
                                printf("%c", str[begin]);
                                begin++;
                            }
                            printf("~");
                        }
                        else{
                            x=x-spaces-1;
                        }
                    }
                    c = 0;
                    spaces=0;
                }
            }
        }
    }
}
void findAnagrams(char *str, char *word)
{
    int number = strlen(str);
    char *stringa_for_rem_space = (char *)malloc(number * sizeof(char));
    strcpy(stringa_for_rem_space, str);
    char *stringa_without_spaces = (char *)malloc(number * sizeof(char));
    strcpy(stringa_without_spaces, remove_white_spaces(stringa_for_rem_space));
    free(stringa_for_rem_space);
    int str_0[number]; // = (int *)malloc(number * sizeof(int));
    memset(str_0, 0, sizeof str_0);
    int str_spacec[number]; // = (int *)malloc(number * sizeof(int));
    memset(str_spacec, 0, sizeof str_spacec);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            str_spacec[i] += 2;
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
    int wl = strlen(word);
    printanagram(str_0, str_spacec, wl, str, word);
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
    // printf("Atbash Sequences: ");
    // hatbash(string1, word1);
    free(word1);
    // hatbash(string1, word2);
    free(word2);
    int xen = strlen(token);

    // int *ptr =
    printf("\nAnagram Sequences: ");
    findAnagrams(string1, token);
    // int n = sizeof(p) / sizeof(int);
    /* for (int i = 0; i < n; i++)
     {
         printf("%d\n", p[i]);
     }*/
}