#include <stdio.h>
#include "object.h"

/*
 * Lists objects from a location (i.e. the player's current location)
 *
 * @param location An OBJECT representing the player's current location.
 * @return The number of objects found.
 */
int listObjectsAtLocation(OBJECT *location){
    int count = 0;
    OBJECT *obj;
    for(obj = objs; obj < endOfObjs; obj++){
        if(obj != player && obj->location == location){
            if(count++ == 0) printf("You see:\n");
            printf("%s\n", obj->description);
        }
    }
    return count;   
}