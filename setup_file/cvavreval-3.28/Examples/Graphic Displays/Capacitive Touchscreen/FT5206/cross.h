/* Touched point's display functions */

#ifndef _CROSS_INCLUDED_
#define _CROSS_INCLUDED_

#include <glcd.h>
#include <ft5x06.h>

/* Display a cross for a touched point */
void display_ct_point(CTPOINT_t point);
/* Erase the cross for a touched point */
void erase_ct_point(CTPOINT_t point);

#endif

