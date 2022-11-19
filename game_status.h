#pragma once
#include "jet.h"

typedef struct Flags
{
	bool levelChangeFlag = true, welcomeFlag = true, gameEndStatus = false, instructionFlag = false, start = false;
	float score = 1;
	char score_Str[20], slevel[20];
	int level = 1;
}Flags;

void gameEnd(Flags flags)
{
	flags.gameEndStatus = true;
	glColor3f(0.3, 0.56, 0.84);   //game end background screen
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glColor3f(0.137, 0.137, 0.556);
	glVertex3f(100.0, 0.0, 0.0);
	glColor3f(0.196, 0.196, 0.8);
	glVertex3f(100.0, 100.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);
	glEnd();
	glPushMatrix();
	glScalef(0.8, 0.8, 0);
	drawJet();
	glPopMatrix();

	glColor3f(0.196, 0.196, 0.8);  // disp box
	glRectf(20.0, 20.0, 80.0, 80.0);
	glColor3f(0.8, 0.8, 0.8);
	glRectf(21.0, 21.0, 79.0, 79.0);

	glColor3f(0.196, 0.196, 0.8);   //restart button
	glRectf(40, 5, 60, 10);
	glColor3f(0.8, 0.8, 0.8);
	glRectf(40.5, 5.5, 59.5, 9.5);
	glColor3f(0.137, 0.137, 0.556);

	drawString(43, 6, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"RESTART");
	drawString(41, 71, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"GAME OVER!!!");
	drawString(23, 61, 0, GLUT_BITMAP_HELVETICA_18, (char*)"DISTANCE :");
	drawString(40, 61, 0, GLUT_BITMAP_TIMES_ROMAN_24, flags.score_Str);
	drawString(23, 56, 0, GLUT_BITMAP_HELVETICA_18, (char*)"LEVEL         :");
	drawString(40, 56, 0, GLUT_BITMAP_TIMES_ROMAN_24, flags.slevel);

	glutPostRedisplay();

}