#pragma once
void welcome()
{
	background();

	// button 1 -> PLAY
	borderBox(39.5, 39.5, 60.5, 45.5);
	glColor3f(0.137, 0.137, 0.556);
	drawString(47, 42, 0, GLUT_BITMAP_HELVETICA_18, (char*)"PLAY");

	// button 2 -> CONTROLS
	borderBox(39.5, 29.5, 60.5, 35.5);
	glColor3f(0.137, 0.137, 0.556);
	drawString(41, 31, 0, GLUT_BITMAP_HELVETICA_18, (char*)"CONTROLS");

	// button 3 -> EXIT
	borderBox(39.5, 19.5, 60.5, 25.5);
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
	background();

	// back button
	borderBox(40, 5, 60, 10);
	glColor3f(0.137, 0.137, 0.556);
	drawString(46, 6, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"BACK");

	// content
	borderBox(20.0, 20.0, 80.0, 80.0);
	glColor3f(0.137, 0.137, 0.556);
	drawString(37, 75, 0, GLUT_BITMAP_TIMES_ROMAN_24, (char*)"CONTROLS");
	drawString(23, 69, 0, GLUT_BITMAP_HELVETICA_18, (char*)"- LEFT MOUSE or UP keys: Gain Altitude");
	drawString(23, 65, 0, GLUT_BITMAP_HELVETICA_18, (char*)"- DOWN key or release mouse: Reduce Altitude");
	drawString(23, 61, 0, GLUT_BITMAP_HELVETICA_18, (char*)"- RIGHT MOUSE or RIGHT key: Boost");
	drawString(23, 57, 0, GLUT_BITMAP_HELVETICA_18, (char*)"- LEFT key: Reduce Boost");

	drawString(23, 45, 0, GLUT_BITMAP_HELVETICA_18, (char*)"* Avoid buildings and clouds");
	drawString(23, 41, 0, GLUT_BITMAP_HELVETICA_18, (char*)"* Next level after 50 points increases speed");

	drawString(42, 27, 0, GLUT_BITMAP_HELVETICA_18, (char*)"HAPPY FLYING!");

	glutPostRedisplay();
}