#pragma once
void welcome()
{
	glColor3f(0.3, 0.56, 0.84);   //welcome background
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glColor3f(0.137, 0.137, 0.556);
	glVertex3f(100.0, 0.0, 0.0);
	glColor3f(0.196, 0.196, 0.8);
	glVertex3f(100.0, 100.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);
	glEnd();
	drawJet();

	// button 1 .. PLAY
	glColor3f(0.196, 0.196, 0.8);
	glRectf(39.5, 39.5, 60.5, 45.5);

	glColor3f(0.8, 0.8, 0.8);
	glRectf(40, 40, 60, 45);
	glColor3f(0.137, 0.137, 0.556);
	drawString(47, 42, 0, GLUT_BITMAP_HELVETICA_18, (char*)"PLAY");

	// button 2 .. instructions
	glColor3f(0.196, 0.196, 0.8);
	glRectf(39.5, 29.5, 60.5, 35.5);

	glColor3f(0.8, 0.8, 0.8);
	glRectf(40, 30, 60, 35);
	glColor3f(0.137, 0.137, 0.556);
	drawString(41, 31, 0, GLUT_BITMAP_HELVETICA_18, (char*)"INSTRUCTIONS");

	// button 3 .. ABOUT
	glColor3f(0.196, 0.196, 0.8);
	glRectf(39.5, 19.5, 60.5, 25.5);

	glColor3f(0.8, 0.8, 0.8);
	glRectf(40, 20, 60, 25);
	glColor3f(0.137, 0.137, 0.556);
	drawString(46, 21, 0, GLUT_BITMAP_HELVETICA_18, (char*)"ABOUT");

	// button 4 .. exit
	glColor3f(0.196, 0.196, 0.8);
	glRectf(39.5, 9.5, 60.5, 15.5);

	glColor3f(0.8, 0.8, 0.8);
	glRectf(40, 10, 60, 15);
	glColor3f(0.137, 0.137, 0.556);
	drawString(47, 11, 0, GLUT_BITMAP_HELVETICA_18, (char*)"EXIT");


	glPushMatrix();

	glColor3f(0.8, 0.8, 0.8);
	drawString(25.5, 92, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"COMPUTER GRAPHICS PROJECT ");
	drawString(35.5, 80, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"AIRPLANE GAME ");
	glPopMatrix();
	glColor3f(0.137, 0.137, 0.556);

}