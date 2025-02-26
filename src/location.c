#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "noun.h"

/*
 * Prints the location description if "around" is given
 *
 * @param noun The noun component of the input pair
 */
void executeLook(const char *noun)
{

    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("You are in %s.\n", player->location->description);
        listObjectsAtLocation(player->location);
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
    OBJECT *obj = getVisible("where you want to go", noun);
    if (obj == NULL)
        ;
    else if (obj->location == NULL && obj != player->location)
    {
        printf("Ok.\n");
        player->location = obj;
        executeLook("around");
    }

    else
        printf("You can't get any closer.\n");
}