/* Setup functions which call low level input routines (maybe using <osbind.h>) */
/* Detect clock ticks in here? */
#include <osbind.h>

/**
 * @brief Reads a keystroke from the keyboard (if any)
 */
char keystroke();