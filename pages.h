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

	// button 1 -> PLAY
	glColor3f(0.196, 0.196, 0.8);
	glRectf(39.5, 39.5, 60.5, 45.5);

	glColor3f(0.8, 0.8, 0.8);
	glRectf(40, 40, 60, 45);
	glColor3f(0.137, 0.137, 0.556);
	drawString(47, 42, 0, GLUT_BITMAP_HELVETICA_18, (char*)"PLAY");

	// button 2 -> instructions
	glColor3f(0.196, 0.196, 0.8);
	glRectf(39.5, 29.5, 60.5, 35.5);

	glColor3f(0.8, 0.8, 0.8);
	glRectf(40, 30, 60, 35);
	glColor3f(0.137, 0.137, 0.556);
	drawString(41, 31, 0, GLUT_BITMAP_HELVETICA_18, (char*)"INSTRUCTIONS");

	// button 3 -> EXIT
	glColor3f(0.196, 0.196, 0.8);
	glRectf(39.5, 19.5, 60.5, 25.5);

	glColor3f(0.8, 0.8, 0.8);
	glRectf(40, 20, 60, 25);
	glColor3f(0.137, 0.137, 0.556);
	drawString(46, 21, 0, GLUT_BITMAP_HELVETICA_18, (char*)"EXIT");


	glPushMatrix();

	glColor3f(0.8, 0.8, 0.8);
	drawString(25.5, 92, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"COMPUTER GRAPHICS GROUP 1 PROJECT");
	drawString(35.5, 80, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"AEROPLANE GAME ");
	glPopMatrix();
	glColor3f(0.137, 0.137, 0.556);

}

void instructions()
{
	glColor3f(0.3, 0.56, 0.84);   // background
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
	glColor3f(0.137, 0.137, 0.556);
	glRectf(20.0, 20.0, 80.0, 80.0);
	glColor3f(0.8, 0.8, 0.8);
	glRectf(21.0, 21.0, 79.0, 79.0);


	glColor3f(0.196, 0.196, 0.8);
	glRectf(40, 5, 60, 10);
	glColor3f(0.8, 0.8, 0.8);
	glRectf(40.5, 5.5, 59.5, 9.5);

	glColor3f(0.137, 0.137, 0.556);
	drawString(46, 6, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"BACK");

	glColor3f(0.137, 0.137, 0.556);
	drawString(37, 75, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"HOW TO PLAY");
	drawString(23, 69, 0, GLUT_BITMAP_HELVETICA_18, (char*)"- Click and hold mouse left key to gain altitude of ");
	drawString(23, 65, 0, GLUT_BITMAP_HELVETICA_18, (char*)"    the plane.");
	drawString(23, 61, 0, GLUT_BITMAP_HELVETICA_18, (char*)"- Release the mouse left key to reduce the altitude.");
	drawString(23, 57, 0, GLUT_BITMAP_HELVETICA_18, (char*)"- Use the Right mouse key to speed up the plane(NOS)");
	drawString(23, 53, 0, GLUT_BITMAP_HELVETICA_18, (char*)"- Main aim of the game is to avoid the obstacles ");
	drawString(23, 49, 0, GLUT_BITMAP_HELVETICA_18, (char*)"    such as buildings and clouds.");
	drawString(23, 45, 0, GLUT_BITMAP_HELVETICA_18, (char*)"- Also the meter at the bottom shows the distance ");
	drawString(23, 41, 0, GLUT_BITMAP_HELVETICA_18, (char*)"    travelled,NITROS left,Atitude and the LEVEL.");
	drawString(23, 37, 0, GLUT_BITMAP_HELVETICA_18, (char*)"- As you reach distance multples of 50 tour level ");
	drawString(23, 33, 0, GLUT_BITMAP_HELVETICA_18, (char*)"    increases as well as the speed of the plane.");
	drawString(33, 27, 0, GLUT_BITMAP_HELVETICA_18, (char*)" ENJOY PLAYING THE GAME");

	glutPostRedisplay();
}