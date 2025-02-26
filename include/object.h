/* All game entities are grouped as OBJECT to provide more freedom*/
typedef struct object
{
    const char *description;
    const char *tag;
    struct object *location;
} OBJECT;

extern OBJECT objs[];

#define home (objs + 0)
#define street (objs + 1)
#define monsterEnergy (objs + 2)
#define mcdonalds (objs + 3)
#define deliverooDriver (objs + 4)
#define player (objs + 5)

#define endOfObjs (objs + 6)
