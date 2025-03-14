/* Setup functions which call low level input routines (maybe using <osbind.h>) */
/* Detect clock ticks in here? */
#include "input.h"

char keystroke(){
    if (Cconis()) {
        return (char)Cnecin();
    }
    
    return "\0";
}