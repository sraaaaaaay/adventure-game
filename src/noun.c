#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "object.h"

/*
 * Checks that an OBJECT has a particular tag.
 *
 * @param obj An object.
 * @param noun The noun to search for in object tag(s).
 */
static bool objectHasTag(OBJECT *obj, const char *noun)
{
    return noun != NULL && *noun != '\0' && strcmp(noun, obj->tag) == 0;
}

/*
 * Helper function for getVisible(). Finds an object given a tag noun.
 *
 * @param noun The noun string to search for.
 * @return An OBJECT if found, or NULL.
 */
static OBJECT *getObject(const char *noun)
{
    OBJECT *obj, *res = NULL;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (objectHasTag(obj, noun))
            res = obj;
    }
    return res;
}

/*
 * Given a noun, output a generic message if an object isn't found, or if the match is not visible.
 *
 * @param intention Carry parameter from calling code. 
 * @param noun The noun term of user input.
 * @return NULL (calling code doesn't need to do anything else).
 */
OBJECT *getVisible(const char *intention, const char *noun)
{
    OBJECT *obj = getObject(noun);
    if (obj == NULL)
        printf("I don't understand %s.\n", intention);

    else if (!(obj == player ||
               obj == player->location ||
               obj->location == player ||
               obj->location == player->location ||
               obj->location == NULL ||
               obj->location->location == player ||
               obj->location->location == player->location))
    {
        printf("You don't see any %s here.\n", noun);
        obj = NULL;
    }
    return obj;
}
