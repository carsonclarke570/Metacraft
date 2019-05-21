/*
entity.h

A model for physically affected objects.

Author:
  Wesley Dahar
*/
#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "common.h"



// The data necessary for existance (model and mesh are not included)
typedef struct {
    uint8_t status;          // {1: onGround, 2: noGravity, 4: invulnerable, 8: cnv,
                             //  16: silent, 32: glowing}
    double position[3];           // X, Y, Z position (m) (chunk relative to preserve precision)
    double velocity[3];           // dX, dY, and dZ velocity (m/tick)
    double rotation[3];           // yaw [0, 360], pitch [-90, 90] (deg)
    uint16_t fire;           // ticks until the fire stops (inf tick downcounter)
    uint16_t fallTime;       // ticks the entity has been falling (tick counter)
    uint16_t portalCooldown; // portal return delay (300 tick downcounter)
} Entity;



typedef struct {
    uint16_t itemID;  // item ID
    Entity *entity;   // base physical model
    uint16_t despawn; // despawn tick downcounter (reset if stack is incremented)
    uint8_t stack;    // number of items with identical 'tags' (exists as stack)
    uint8_t *tags;    // attributes, properties, and effects
} ItemEntity;



typedef struct {
    uint16_t blockID; // block ID
    Entity *entity;   // base physical model
    uint8_t *tags;    // attributes, properties, and effects
} BlockEntity;



typedef struct {
    uint16_t vehicleID; // vehicle ID
    Entity *entity;     // base physical model
    uint8_t *tags;      // attributes, properties, and effects
} VehicleEntity;



/*
Function Prototypes
*/
void create_entity(Entity *entity);
void delete_entity(Entity *entity);

void read_entity(Entity *entity, FILE *file);
void write_entity(Entity *entity, FILE *file);



#endif



