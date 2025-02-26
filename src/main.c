#include "location.h"
#include "parsexec.h"
#include <stdbool.h>
#include <stdio.h>

static char input[100] = "look around";

/*
 * Gets user input for a choice (usually a verb-noun pair)
 *
 * @return True if user input is not NULL.
 */
static bool getInput(void)
{
  printf("\n--> ");
  return fgets(input, sizeof input, stdin) != NULL;
}

/*
 * Main event loop keep going until parsing fails, or user quits.
 *
 * @return Status code.
 */
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