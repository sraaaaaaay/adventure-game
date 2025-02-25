#include "location.h"
#include "parsexec.h"
#include <stdbool.h>
#include <stdio.h>

static char input[100] = "look around";

/* 
 * Gets user input for a choice (usually a verb-noun pair)
 *
 */
static bool getInput(void)
{
  printf("\n--> ");
  return fgets(input, sizeof input, stdin) != NULL;
}

int main()
{
  printf("Welcome to the Aberdeen Text adventure\n");
  printf("It is very grey in this city\n");

  // Loop until input fails or user quits
  while (parseAndExecute(input) && getInput())
    ;

  printf("\nBye!\n");

  return 0;
}