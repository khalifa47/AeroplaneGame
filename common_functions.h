#pragma once
void drawString(float x, float y, float z, void* font, char* string)
{
	char* c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

void background()
{
	glColor3f(0.3, 0.56, 0.84);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glColor3f(0.137, 0.137, 0.556);
	glVertex3f(100.0, 0.0, 0.0);
	glColor3f(0.196, 0.196, 0.8);
	glVertex3f(100.0, 100.0, 0.0);
	glVertex3f(0.0, 100.0, 0.0);
	glEnd();
	drawJet();
}

void borderBox(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	glColor3f(0.196, 0.196, 0.8);
	glRectf(x1, y1, x2, y2);

	glColor3f(0.8, 0.8, 0.8);
	glRectf(x1 + 0.5, y1 + 0.5, x2 - 0.5, y2 - 0.5);
}