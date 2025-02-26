#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "location.h"


/*
 * Parse potential user inputs and call relevant handlers
 * 
 * @param input user input of a verb-noun pair
 * @return false for "quit", true for other actions
 */
bool parseAndExecute(char *input)
{
  char *next_token;
  char *next_token_2;
  char *verb = strtok(input, " \n");
  char *noun = strtok(NULL, " \n");

  if (verb != NULL)
  {
    if (strcmp(verb, "quit") == 0)
    {
      return false;
    }
    else if (strcmp(verb, "look") == 0)
    {
      executeLook(noun);
    }
    else if (strcmp(verb, "go") == 0)
    {
      executeGo(noun);
    }
    else
    {
      printf("I don't know how to %s.\n", verb);
    }
  }

  return true;
}