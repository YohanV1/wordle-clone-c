#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 50

FILE *fr;
char str[100];
int c,l,test,playAgain,i,j;

bool process(const char* compAnswer, const char* userGuess)
{

  char clue[6] = {'-', '-', '-', '-', '-', '\0'};
  bool ansFlags[5] = {false, false, false, false, false};

  for (i=0; i<5; i++)
  {
    if (userGuess[i] == compAnswer[i])
    {
      clue[i] = 'G';
      ansFlags[i] = true;
    }
  }

  for (i=0; i<5; i++)
    {
    if (clue[i] == '-')
    {
      for (j=0; j<5; j++)
      {
        if (userGuess[i] == compAnswer[j] && !ansFlags[j])
        {
          clue[i] = 'Y';
          ansFlags[j] = true;
          break;
        }
      }
    }
  }

  for(i=0;i<5;i++)
  {
      if(clue[i]=='G')
      {
          printf("\033[1;92m");
          printf("%c",userGuess[i]);
          printf("\033[0m");
      }
      else if(clue[i]=='Y')
      {
          printf("\033[1;91m");
          printf("%c",userGuess[i]);
          printf("\033[0m");
      }
      else if(clue[i]=='-')
      {
          printf("\033[1;97m");
          printf("%c",userGuess[i]);
          printf("\033[0m");
      }
  }
  printf("\n");
  return strcmp(clue, "GGGGG") == 0;
}

void play()
{
    system("cls");
    printf("\n ");
    printf("\033[4;96m");
    printf("RULES :\n");
    printf("\033[0m");
    printf("\n  - Guess the WORD in 6 tries");
    printf("\n  - Each guess must be a valid 5-letter word. Hit ENTER to submit");
    printf("\n  - All alphabets are in lower case. Alphabets can be repeated");
    printf("\n  - After each guess, the color of the letters will change to show how \n    close your guess was to the word");
    printf("\n\n ");
    printf("\033[4;96m");
    printf("EXAMPLES :\n");
    printf("\033[0m");
    printf("\033[1;92m");
    printf("\n w");
    printf("\033[0m");
    printf("eary");
    printf("\n The letter 'w' is in the word and in the correct spot.");
    printf("\n\n p");
    printf("\033[1;91m");
    printf("i");
    printf("\033[0m");
    printf("lls");
    printf("\n The letter 'i' is in the word but in the wrong spot.");
    printf("\n\n vag");
    printf("\033[1;97m");
    printf("u");
    printf("\033[0m");
    printf("e");
    printf("\n The letter 'u' is not in the word in any spot.");
    printf("\033[1;96m");
    printf("\n\n --------------------------------------------------------------------- \n");
    printf("\033[0m");


    char** wordsList = calloc(MAX_WORDS, sizeof(char*));
    int wordCounter = 0;
    char* fiveLetterWordLoader = malloc(6*sizeof(char));
    fr = fopen("wordlist.txt", "r");

    while (fscanf(fr, "%s", fiveLetterWordLoader) != EOF && wordCounter < MAX_WORDS)
    {
        wordsList[wordCounter] = fiveLetterWordLoader;
        wordCounter++;
        fiveLetterWordLoader = malloc(6*sizeof(char));
    }
    fclose(fr);
    srand(time(NULL));

    char* randAnswer = wordsList[rand()%wordCounter];
    int numOfGuesses = 0;
    bool correctGuess = false;
    bool invalidInput = false;
    char* guess = malloc(6*sizeof(char));

    while (numOfGuesses < 6 && !correctGuess)
    {
        invalidInput = false;
        printf("\n Input a 5-letter word and press enter: ");
        scanf("%s", guess);
        if(strlen(guess)!=5)
        {
            printf("\n Invalid input.\n");
            continue;
        }
        for(i=0;guess[i]!='\n';i++)
        {
            if(!isalpha(guess[i]))
            {
                printf("\n Invalid input.\n ");
                invalidInput = true;
                break;
            }
        }
        if(invalidInput)
        {
            continue;
        }
        printf("\n ");
        printf("You have guessed:\n %s\n ", guess);
        numOfGuesses++;
        correctGuess = process(randAnswer, guess);
    }

    if (correctGuess)
    {
        printf("\033[1;96m");
        printf("\n Congratulations! You guessed the correct word in %d tries!\n\n ", numOfGuesses);
        printf("\033[0m");
    }
    else
    {
        printf("\n You have used up your guesses. The correct word is ");
        printf("\033[1;32m");
        printf("%s",randAnswer);
        printf("\033[0m");
        printf(".\n\n ");
    }

    for (int i=0; i<wordCounter; i++)
    {
        free(wordsList[i]);
    }
    free(wordsList);
    free(fiveLetterWordLoader);
    free(guess);

    printf("\033[1;97m");
    printf("Enter 1 to play again, 2 to quit.\n ");
    printf("\033[0m");
    scanf("%d",&playAgain);

    if(playAgain==1)
    {
        play();
    }
    else if(playAgain==2)
    {
        exit(0);
    }
    else
    {
        exit(0);
    }
}

void menu()
{
    fr = fopen("wordlist.txt", "a");
    fgets(str, sizeof(str), stdin);
    c = strcmp(str,"play\n");
    l = strlen(str);
    for(i=0;str[i]!='\n';i++)
    {
        if(!isalpha(str[i]))
        {
            printf("\n Invalid. Please enter a 5-letter word or continue playing.\n\n ");
            menu();
        }
    }
    if(l==6)
    {
        fprintf(fr, "%s", str);
        str[l-1] = 0;
        printf("\n %s has been added.\n\n ", str);
    }
    else if(c==0)
    {
        test=1;
        play();
    }
    else if(l!=6&&test==0)
    {
        printf("\n Invalid. Please enter a 5-letter word or continue playing.\n\n ");
        menu();
    }
    fclose(fr);
    menu();
}

void main()
{
    system("cls");
    printf("\n ");
    printf("\033[4;96m");
    printf("Welcome to C-Wordle!\n");
    printf("\033[0m");
    printf("\n If you'd like to add words to the game's vocabulary, put in a valid 5-letter word and press ENTER.\n");
    printf("\n Enter 'play' at any time if you'd like to continue playing.\n\n ");
    test=0;
    menu();
}
