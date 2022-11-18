#pragma once
void drawEnvironment()
{
	glPushMatrix();

	glColor3f(0.0, 0.48, 0.047);		// green floor

	glBegin(GL_POLYGON);
	glVertex3f(0.0, 9.0, 0.0);
	glVertex3f(100.0, 9.0, 0.0);
	glColor3f(0.0, 0.3, 0.03);
	glVertex3f(100.0, 10.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glVertex3f(0.0, 9.0, 0.0);
	glEnd();

	glColor3f(0.474, 0.298, 0.074);  // brown ground
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);
	glColor3f(0.3, 0.1, 0.03);
	glVertex3f(100.0, 9.0, 0.0);
	glVertex3f(0.0, 9.0, 0.0);
	glEnd();

	glColor3f(0.5, 0.6, 0.79);
	glBegin(GL_POLYGON);				//ceiling
	glVertex3f(0.0, 100.0, 0.0);
	glVertex3f(100.0, 100.0, 0.0);
	glColor3f(0.6, 0.7, 0.89);
	glVertex3f(100.0, 80.0, 0.0);
	glVertex3f(0.0, 80.0, 0.0);
	glEnd();

	glColor3f(0.5, 0.6, 0.79);// sky blue
	glBegin(GL_POLYGON);   //background screen
	glVertex3f(0.0, 90.0, 5.0);
	glVertex3f(100.0, 90.0, 5.0);
	glColor3f(0.7, 0.8, 0.99);//sky
	glVertex3f(100.0, 10.0, 5.0);
	glVertex3f(0.0, 10.0, 5.0);
	glEnd();

	glPopMatrix();
}