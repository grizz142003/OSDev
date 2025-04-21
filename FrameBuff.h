#ifndef FrameBuff_h
#define FrameBuff_h

#include "io.h"

int fb_write(const char *buf, uint32_t len);

void fb_clear(void);

void fb_move_curser(uint16_t pos);

uint16_t fb_get_curser(void);



#endif