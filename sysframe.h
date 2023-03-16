#ifndef _SYSFRAME_H_
#define _SYSFRAME_H_

#include"common.h"

#define MAX_TITLE_SIZE 100

void SetCurPos(int x, int y);
void HideCursor();
void DrawCol(int x, int y);
void DrawRow(int x, int y);

void DrawFrame(char *title);
void DrawMenu();
void SystemEnd();


#endif /* _SYSFRAME_H_ */