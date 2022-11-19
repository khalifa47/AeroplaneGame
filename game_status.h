#pragma once

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
	background();
  
	borderBox(20.0, 20.0, 80.0, 80.0); // game over box
 
	// restart button
	borderBox(40, 5, 60, 10);
	glColor3f(0.137, 0.137, 0.556);
	drawString(43, 6, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"RESTART");

	drawString(41, 71, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"GAME OVER!");
	drawString(23, 61, 0, GLUT_BITMAP_HELVETICA_18, (char*)"DISTANCE:");
	drawString(40, 61, 0, GLUT_BITMAP_TIMES_ROMAN_24, flags.score_Str);
	drawString(23, 56, 0, GLUT_BITMAP_HELVETICA_18, (char*)"LEVEL:");
	drawString(40, 56, 0, GLUT_BITMAP_TIMES_ROMAN_24, flags.slevel);

	glutPostRedisplay();
}