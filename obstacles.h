#pragma once
#include "jet.h"
typedef struct Building
{
	float block_x, block_y;
	bool state;
	int no_floors;
}Building;

typedef struct Cloud
{
	float block_x, block_y;
	bool state;
}Cloud;

typedef struct Tree {
	float block_x, block_y;
	bool state;
}Tree;

void drawBuilding(Building building)
{
	glPushMatrix();

	glTranslatef(building.block_x, building.no_floors * 10.0 + 10, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 3.0, 0.0);
	glVertex3f(20.0, 3.0, 0.0);
	glVertex3f(20.0, -building.no_floors * 10.0, 0.0);
	glVertex3f(0.0, -building.no_floors * 10.0, 0.0);
	glEnd();
	glPopMatrix();

	for (int i = 1; i <= building.no_floors; i++)
	{
		glPushMatrix();

		glTranslatef(building.block_x, 10.0 * i, 0.0);   //base
		glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(15.0, 0.0, 0.0);
		glVertex3f(15.0, 10.0, 0.0);
		glVertex3f(0.0, 10.0, 0.0);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);     // left window
		glBegin(GL_POLYGON);
		glVertex3f(2.5, 5.0, 0.0);
		glVertex3f(5.5, 5.0, 0.0);
		glVertex3f(5.5, 8.0, 0.0);
		glVertex3f(2.5, 8.0, 0.0);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);     // left window
		glBegin(GL_POLYGON);
		glVertex3f(2.5, 0.0, 0.0);
		glVertex3f(5.5, 0.0, 0.0);
		glVertex3f(5.5, 3.0, 0.0);
		glVertex3f(2.5, 3.0, 0.0);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);     // right window
		glBegin(GL_POLYGON);
		glVertex3f(12.5, 5.0, 0.0);
		glVertex3f(9.5, 5.0, 0.0);
		glVertex3f(9.5, 8.0, 0.0);
		glVertex3f(12.5, 8.0, 0.0);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);     // right window
		glBegin(GL_POLYGON);
		glVertex3f(12.5, .0, 0.0);
		glVertex3f(9.5, 0.0, 0.0);
		glVertex3f(9.5, 3.0, 0.0);
		glVertex3f(12.5, 3.0, 0.0);
		glEnd();
		glPopMatrix();
	}
	glPushMatrix();

	glTranslatef(building.block_x, 10.0, 0.0);   //base
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(15.0, 0.0, 0.0);
	glVertex3f(15.0, 10.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);     // door
	glBegin(GL_POLYGON);
	glVertex3f(5.5, 0.0, 0.0);
	glVertex3f(9.5, 0.0, 0.0);
	glVertex3f(9.5, 6.0, 0.0);
	glVertex3f(5.5, 6.0, 0.0);
	glEnd();
	glPopMatrix();
}

void drawCloud(Cloud cloud)
{
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(cloud.block_x, cloud.block_y, 0.0);
	glutSolidSphere(5, 100, 10);
	glTranslatef(6, -3.0, 0.0);
	glutSolidSphere(5, 100, 10);
	glTranslatef(0, 6.0, 0.0);
	glutSolidSphere(5, 100, 10);
	glTranslatef(6, -3.0, 0.0);
	glutSolidSphere(5, 100, 10);

}

void drawTree(float height, float base) {
	float angle;

	glPushMatrix();
	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	gluCylinder(qobj, base, base - (0.2 * base), height, 20, 20);
	glPopMatrix();
	glTranslatef(0.0f, height, 0.0f);

	height -= height * 0.2f;
	base -= base * 0.3f;

	if (height > 1) {
		angle = 22.5f;

		glPushMatrix();
		glRotatef(angle, -1.0f, 0.0f, 0.0f);
		drawTree(height, base);
		glPopMatrix();
		glPushMatrix();
		glRotatef(angle, 0.5f, 0.0f, 0.866f);
		drawTree(height, base);
		glPopMatrix();
		glPushMatrix();
		glRotatef(angle, 0.5f, 0.0f, -0.866f);
		drawTree(height, base);
		glPopMatrix();
	}

	glPopMatrix();
}

bool cloudHit(Cloud cloud, Jet jet)
{
	if (cloud.block_x < 13 && cloud.block_x> -5)
		if (jet.plane_mvmt - 3 + 50 > cloud.block_y - 3 && jet.plane_mvmt - 3 + 50 < cloud.block_y + 3)   // plane front to cloud mid box1
			return true;

	if (cloud.block_x < 12 && cloud.block_x> -4)
		if (jet.plane_mvmt - 3 + 50 > cloud.block_y - 5 && jet.plane_mvmt - 3 + 50 < cloud.block_y + 5)   // plane front to cloud mib box2
			return true;

	if (cloud.block_x < 10 && cloud.block_x> -1)
		if (jet.plane_mvmt - 3 + 50 > cloud.block_y - 6 && jet.plane_mvmt - 3 + 50 < cloud.block_y - 2)
			return true;

	//for top wing and bottom wing
	if (cloud.block_x < 5 && cloud.block_x> -3)
		if (jet.plane_mvmt - 3 + 50 > cloud.block_y - 11 && jet.plane_mvmt - 3 + 50 < cloud.block_y + 13)
			return true;

	return false;
}

bool buildingHit(Building building, Jet jet)
{
	if (((int)building.block_x <= 8 && (int)building.block_x >= -7 && ((int)jet.plane_mvmt + 50) - building.block_y <= 3))   //buildin back  body to tail
		return true;
	else if (((int)building.block_x <= 10 && (int)building.block_x >= -5 && ((int)jet.plane_mvmt + 50) - building.block_y <= 0))   //body to tail
		return true;
	else if (((int)building.block_x <= 6 && (int)building.block_x >= -3 && ((int)jet.plane_mvmt + 47) - building.block_y <= 0))  //right wing
		return true;
	else if (((int)building.block_x <= 4 && (int)building.block_x >= -4 && ((int)jet.plane_mvmt + 47) - building.block_y <= 3))  //   building back right wing
		return true;
	else
		return false;
}

bool boundHit(Jet jet)
{
	if (jet.plane_mvmt + 50 >= 100 || jet.plane_mvmt + 50 <= 18)   // top and bottom boundary
		return true;
	else
		return false;
}