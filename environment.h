#pragma once
void drawEnvironment()
{
	glPushMatrix();

	// green floor
	glColor3f(0.0, 0.48, 0.047);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 9.0, 0.0);
	glVertex3f(100.0, 9.0, 0.0);
	glColor3f(0.0, 0.3, 0.03);
	glVertex3f(100.0, 10.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glVertex3f(0.0, 9.0, 0.0);
	glEnd();

	// brown ground
	glColor3f(0.474, 0.298, 0.074);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);
	glColor3f(0.3, 0.1, 0.03);
	glVertex3f(100.0, 9.0, 0.0);
	glVertex3f(0.0, 9.0, 0.0);
	glEnd();

	// blue sky
	glColor3f(0.5, 0.6, 0.79);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 100.0, 0.0);
	glVertex3f(100.0, 100.0, 0.0);
	glColor3f(0.7, 0.8, 0.99);
	glVertex3f(100.0, 10.0, 5.0);
	glVertex3f(0.0, 10.0, 5.0);
	glEnd();

	glPopMatrix();
}