#include <stdio.h>
#include <string.h>

struct location
{
    const char *description;
    const char *tag;
}

/* Define some locations in the game */
locs[] = {{"your home", "home"}, {"the street", "street"}};

#define numberOfLocations (sizeof locs / sizeof *locs)

static unsigned locationOfPlayer = 0;

/*
 * Prints the location description if "around" is given
 *
 * @param noun The noun component of the input pair
 */
void executeLook(const char *noun)
{

    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("You are in %s.\n", locs[locationOfPlayer].description);
    }
    else
    {
        printf("I don't understand what you want to see.\n");
    }
}

/*
 * Moves the player if an existing location is given
 *
 * @param noun The noun component of the input pair
 */
void executeGo(const char *noun)
{
    unsigned i;
    for (i = 0; i < numberOfLocations; i++)
    {
        if (noun != NULL && strcmp(noun, locs[i].tag) == 0)
        {
            if (i == locationOfPlayer)
            {
                printf("You're as close as you can get!\n");
            }
            else
            {
                printf("Ok.\n");
                locationOfPlayer = i;
                executeLook("around");
            }
            return;
        }
    }
    printf("I don't understand where you want to go.\n");
}