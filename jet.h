#pragma once
typedef struct Jet
{
	float plane_mvmt = 0.0;
}Jet;

void drawJet()
{
	//left tail wing
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(5.5, 47.0);
	glVertex2f(8.5, 47.0);
	glVertex2f(5.5, 48.0);
	glVertex2f(4.5, 48.0);
	glEnd();


	//left front wing

	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(13.0, 47.0);
	glVertex2f(20.0, 47.0);
	glVertex2f(13.0, 50.0);
	glVertex2f(11.0, 50.0);
	glEnd();

	//tail
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(4.7, 45.0);
	glVertex2f(5.5, 51.0);
	glVertex2f(7.0, 51.0);
	glVertex2f(9.0, 45.0);
	glEnd();


	//body
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(5.0, 48.0);
	glVertex2f(11.0, 48.0);
	glVertex2f(22.0, 46.5);
	glVertex2f(22.0, 45.0);
	glVertex2f(5.0, 45.0);
	glEnd();


	//right front wing
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(13.0, 46.0);
	glVertex2f(18.0, 46.0);
	glVertex2f(13.0, 41.0);
	glVertex2f(11.0, 41.0);
	glEnd();


	//dome
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(13.0, 47.0);
	glVertex2f(15.0, 48.5);
	glVertex2f(17.0, 49.0);
	glVertex2f(19.0, 48.0);
	glVertex2f(21.0, 46.0);
	glVertex2f(17.0, 46.0);
	glVertex2f(15.0, 47.5);
	glVertex2f(13.0, 47.0);
	glEnd();


	//right tail wing
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(5.5, 47.0);
	glVertex2f(8.5, 47.0);
	glVertex2f(5.5, 43.0);
	glVertex2f(4.5, 43.0);
	glEnd();


	// front tip
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex2f(22.0, 45.0);
	glVertex2f(22.3, 45.375);
	glVertex2f(22.6, 45.75);
	glVertex2f(22.3, 46.125);
	glVertex2f(22.0, 46.5);
	glEnd();
}