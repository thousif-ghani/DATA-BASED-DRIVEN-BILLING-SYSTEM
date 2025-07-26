#ifndef _LCD_H
#define _LCD_H
#include"types.h"
void writeLCD(u8 byte);
void CmdLCD(u8 cmd);
void InitLCD(void);
void CharLCD(u8 asciival);
void StrLCD(s8*);
void U32LCD(u32);
void s32LCD(s32);
void f32LCD(f32,u32);
void detcurcursorposition(u8,u8);
void buildCGRAM(u8 *p,u8);
void SetCursor(u8,u8);
#endif

