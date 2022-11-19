#include<windows.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<time.h>
#include<stdio.h>
#include<math.h>

#include "common_functions.h"
#include "game_status.h"
#include "obstacles.h"
#include "jet.h"
#include "environment.h"
#include "pages.h"

#define BLOCKSPEED 0.3
#define BOOSTER_MAX 100


int SCREENH = 600, SCREENW = 800;

// declaration of objects
Building b;
Cloud s;
Tree t;
Jet j;

// flags init
Flags flags;


// declaration of variables
float blockSpeed = BLOCKSPEED;
float booster = BOOSTER_MAX, boost = 0;


// declaration of function signatures
void mouse(int button, int state, int x, int y);
void buildingBlock();
void cloudBlock();
void init();
void drawJet();
void gameEnd(Flags flags);
void drawEnvironment();
void welcome();
void drawBuilding(Building building);
void drawCloud(Cloud cloud);
void drawTree(float height, float base);
bool cloudHit(Cloud cloud, Jet jet);
bool buildingHit(Building building, Jet jet);
void printScore();
void display();
void moveJetUp();
void moveJetDown();


void buildingBlock()
{
	b.block_x = 50.0;
	srand(time(0));
	b.no_floors = rand() % 3 + 4;

	b.block_y = b.no_floors * 10 + 15;
	b.state = true;
	s.state = false;
	t.state = false;
}

void cloudBlock()
{
	s.block_x = 50.0;
	srand(time(0));
	s.block_y = (rand() % 30) + 50;
	s.state = true;
	b.state = false;
	t.state = false;
}

void treeBlock() {
	t.block_x = 50.0;

	srand(time(0));

	t.block_y = 10;
	t.state = true;
	b.state = false;
	s.state = false;
}

void printScore()
{
	glColor3f(1.0, 1.0, 0.0);

	sprintf_s(flags.slevel, "%d", (int)flags.level);
	drawString(58, 1.8, 0, GLUT_BITMAP_TIMES_ROMAN_10, (char*)"Level");
	drawString(58, 3.5, 0, GLUT_BITMAP_TIMES_ROMAN_24, flags.slevel);

	if (booster > 0 && boost)
		flags.score += 0.03;
	else
		flags.score += 0.005;

	drawString(38, 1.5, 0, GLUT_BITMAP_TIMES_ROMAN_10, (char*)"Distance");
	sprintf_s(flags.score_Str, "%d m", (int)flags.score);
	drawString(38, 3, 0, GLUT_BITMAP_TIMES_ROMAN_24, flags.score_Str);
}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (flags.gameEndStatus == true)
	{
		gameEnd(flags);
	}
	else if (flags.welcomeFlag == true)//Welcome Screen
	{
		welcome();
	}
	else if (flags.instructionFlag == true)
	{
		instructions();
	}
	else if ((b.state && buildingHit(b, j)) || boundHit(j) || (s.state && cloudHit(s, j)))
	{
		flags.gameEndStatus = true;
		gameEnd(flags);
	}
	else
	{
		// change level after 50 points
		if ((int)flags.score % 50 == 0 && flags.levelChangeFlag == true)
		{
			flags.levelChangeFlag = false;
			flags.level++;
			blockSpeed += 0.01;
		}
		else if ((int)flags.score % 50 != 0 && flags.levelChangeFlag == false)
		{
			flags.levelChangeFlag = true;
		}

		glPushMatrix();
		drawEnvironment();


		glPushMatrix();
		glTranslatef(0.0, j.plane_mvmt, 0.0);
		drawJet();
		glPopMatrix();


		if (booster <= BOOSTER_MAX && !boost)    // booster charging
			booster += 0.005;



		if ((b.state && b.block_x < -10) || (s.state && s.block_x < -10) || (t.state && t.block_x < -10))            //for new building //building has gone outside the screen- state=true
		{
			srand(time(NULL));
			int random = rand() % 3;//for random building, tree or cloud
			if (random == 0)
			{
				buildingBlock();
			}
			else if (random == 1)
			{
				cloudBlock();
			} 
			else
			{
				treeBlock();
			}
		}

		else if (b.state)
		{
			if (booster > 0 && boost)
			{
				b.block_x -= blockSpeed + boost;
				booster = booster - 0.02;//reduce to normal speed after leaving boost key
			}
			else
				b.block_x -= blockSpeed;
		}
		else if (s.state == true)
		{
			if (booster > 0 && boost)
			{
				s.block_x -= blockSpeed + boost;
				booster = booster - 0.02;

			}
			else
			{
				s.block_x -= blockSpeed;
			}
		}
		else if (t.state) {
			if (booster > 0 && boost) {
				t.block_x -= blockSpeed + boost;
				booster = booster - 0.02;
			}
			else t.block_x -= blockSpeed;
		}


		if (b.state)
		{
			glTranslatef(b.block_x, 0.0, 0.0);
			drawBuilding(b);
		}
		else if (s.state)
		{
			glTranslatef(s.block_x, 0.0, 0.0);
			drawCloud(s);
		}
		else if (t.state) {
			glTranslatef(t.block_x, t.block_y, 0.0);
			drawTree(5.0f, 0.2f);
		}
		glPopMatrix();

		printScore();
	}
	glFlush();
	glutSwapBuffers();
}


void moveJetUp()
{
	if (flags.start == false)
		glutPostRedisplay();
	j.plane_mvmt += 0.05;
	glutPostRedisplay();
}


void moveJetDown()
{
	if (flags.start == false)
		glutPostRedisplay();
	j.plane_mvmt -= 0.05;
	glutPostRedisplay();
}



void mouse(int button, int state, int x, int y)
{
	int mx = x * 100 / SCREENW, my = (SCREENH - y) * 100 / SCREENH;

	if (flags.instructionFlag || flags.gameEndStatus)
	{
		if (mx > 40 && mx < 60)
		{
			if (my > 5 && my < 10)
			{
				flags.welcomeFlag = true;
				if (flags.instructionFlag)
					flags.instructionFlag = false;
				if (flags.gameEndStatus)
				{
					flags.welcomeFlag = true;
					flags.gameEndStatus = false;
					j.plane_mvmt = 0;
					flags.start = false;
					init();
					blockSpeed = BLOCKSPEED;
					booster = BOOSTER_MAX;
					flags.score = 1;
					flags.level = 1;
					glutPostRedisplay();
				}

			}
		}
	}
	if (flags.welcomeFlag == true)
	{
		if (mx > 40 && mx < 60)
		{
			if (my > 40 && my < 45)
			{
				flags.start = true;
				flags.welcomeFlag = false;
			}
			else if (my > 30 && my < 35)
			{
				flags.instructionFlag = true;
				flags.welcomeFlag = false;
			}
			else if (my > 20 && my < 25)
			{
				exit(0);
			}
		}
	}
	else
	{

		if (button == GLUT_LEFT_BUTTON)
		{
			if (state == GLUT_DOWN)
				glutIdleFunc(moveJetUp);

			else if (state == GLUT_UP)
				glutIdleFunc(moveJetDown);
		}
		if (button == GLUT_RIGHT_BUTTON)
		{

			if (state == GLUT_DOWN)
			{
				if (booster > 0)
				{
					boost = 0.05;
				}
			}
			if (state == GLUT_UP)
			{
				boost = 0;
			}
		}
	}
}

void specialKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		glutIdleFunc(moveJetUp);
		break;
	case GLUT_KEY_DOWN:
		glutIdleFunc(moveJetDown);
		break;
	case GLUT_KEY_RIGHT:
		boost = 0.05;
		break;
	case GLUT_KEY_LEFT:
		boost = 0;
	}

	glutPostRedisplay();
}

void myReshape(int w, int h)
{
	SCREENH = h, SCREENW = w;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -5.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void init()
{
	srand(time(0));
	int random = rand() % 3;
	if (random == 0)
	{
		buildingBlock();
	}
	else if (random == 1)
	{
		cloudBlock();
	}
	else
	{
		treeBlock();
	}

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(SCREENW, SCREENH);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Aeroplane Game");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	glutMouseFunc(mouse);
	glutSpecialFunc(specialKey);
	glutMainLoop();
	return 0;

}