/* Touched point's display functions */

#include "cross.h"

#include <glcd.h>
#include <stdio.h>
#include <delay.h>

/* Display buffer */
extern char display_buf[];

/* Display a cross using the current foreground color */
void display_cross(CTPOINT_t point)
{
short text_width,xt;
short text_height,yt,t;
/* Display the cross */
glcd_line(point.x-5,point.y,point.x+5,point.y);
glcd_line(point.x,point.y-5,point.x,point.y+5);
/* Prepare to display cross center coordinates */
sprintf(display_buf,"(%d,%d)",point.x,point.y);
/* Establish displayed text size */
text_width=glcd_textwidth(display_buf);
text_height=glcd_textheight();
/* Try to display the text centered under the cross */
if ((t=point.y+5+text_height)<_GLCD_MAXY_) goto l0;
/* Try to display the text centered above the cross */
if ((t=point.y-5-text_height)>=0)
   {
   l0:
   yt=t;
   /* Ensure the text fits the screen horizontally */
   xt=point.x-text_width/2;
   if (xt<0) xt=0;
   else if ((xt+text_width)>=_GLCD_MAXX_) xt=_GLCD_MAXX_-1-text_width;
   }
/* If not possible, display on the same line with the cross */
else
    {
    yt=point.y-text_height/2;
    /* Try to display the text to the right of the cross */
    if ((t=point.x+5+text_width)<_GLCD_MAXX_) xt=t;
    /* Try to display the text to the left of the cross */
    else if ((t=point.x-5-text_width)>=0) xt=t;
    else xt=point.x-5;
    }
/* Display the cross center coordinates */
glcd_outtextxy(xt,yt,display_buf);
}

/* Display a cross for a touch point */
void display_ct_point(CTPOINT_t point)
{
glcd_setcolor(GLCD_CL_WHITE);
/* Draw the cross with white color */
display_cross(point);
}

/* Erase the cross for a touch point */
void erase_ct_point(CTPOINT_t point)
{
GLCDCOL_t c;
/* Save foreground color */
c=glcd_getcolor();
/* Set foreground color same as background */
glcd_setcolor(glcd_getbkcolor());
/* Draw the cross with the background color (erase it) */
display_cross(point);
/* Restore the foreground color */
glcd_setcolor(c);
}

