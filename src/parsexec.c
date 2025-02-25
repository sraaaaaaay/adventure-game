#include "location.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*
 * Parse potential user inputs and call relevant handlers
 * 
 * @param input user input of a verb-noun pair
 * @return false for "quit", true for other actions
 */
bool parseAndExecute(char *input)
{
  char *next_token;
  char *verb = strtok_s(input, " \n", &next_token);
  char *noun = strtok_s(NULL, " \n", &next_token);

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