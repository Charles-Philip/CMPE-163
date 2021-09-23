/* ----------------------------------------------------------*
 * Program name: Rotating Squares; Coded by: Charles Im      *
 * Date        : 9/23/2021;        Version : 0x1.0;          *
 * Status      : Tested;                                     *
 * Note        : 1. Developed on Ubuntu 64-bit               *
 *               2. Required Libraries: opengl               *
 *               3. Language(s) used: C++                    *
 *               4. Command(s) used in terminal :            * 
 *   gcc CPI_Square.cpp -o CPI_Square.o -lGL -lGLU -lglut    *
 *                                                           *
 * ----------------------------------------------------------*
 **/

#include<GL/glut.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_LEVEL 150
#define LAMBDA 0.0125

void mydisplay()
{
	
	float p1x = -0.50f;
	float p1y = -0.50f; 
	float p2x = -0.50f; 
	float p2y = 0.50f;
	float p3x = 0.50f; 
	float p3y = 0.50f;
	float p4x = 0.50f;
	float p4y = -0.50f;
	
	float anchor_x = 0.25f;
	float anchor_y = 0.25f;

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-0.35f, -0.35f, 0.0f);


	glFlush();
	sleep(1);

	for(int i = 0 ; i < MAX_LEVEL ; i++ )
	{
		glBegin(GL_LINES);
		glColor3ub( 0, 200, 0 );

		//-------------------------
		glVertex2f(p1x + anchor_x,p1y + anchor_y);
		glVertex2f(p2x + anchor_x,p2y + anchor_y);
		//-------------------------
		glVertex2f(p2x + anchor_x,p2y + anchor_y);
		glVertex2f(p3x + anchor_x,p3y + anchor_y);
		//-------------------------
		glVertex2f(p3x + anchor_x,p3y + anchor_y);
		glVertex2f(p4x + anchor_x,p4y + anchor_y);
		//-------------------------
		glVertex2f(p4x + anchor_x,p4y + anchor_y);
		glVertex2f(p1x + anchor_x,p1y + anchor_y);
		//-------------------------

		p1x = p1x + (LAMBDA * (p2x - p1x));

		p1y = p1y + (LAMBDA * (p2y - p1y));

		p2x = p2x + (LAMBDA * (p3x - p2x));

		p2y = p2y + (LAMBDA * (p3y - p2y));

		p3x = p3x + (LAMBDA * (p4x - p3x));

		p3y = p3y + (LAMBDA * (p4y - p3y));

		p4x = p4x + (LAMBDA * (p1x - p4x));

		p4y = p4y + (LAMBDA * (p1y - p4y));


		glEnd();
		
		glBegin(GL_LINES);

		//-------------------------
		glVertex2f(p1x*0.25 + anchor_x/-5,p1y*0.25 + anchor_y/-5);
		glVertex2f(p2x*0.25 + anchor_x/-5,p2y*0.25 + anchor_y/-5);
		//-------------------------
		glVertex2f(p2x*0.25 + anchor_x/-5,p2y*0.25 + anchor_y/-5);
		glVertex2f(p3x*0.25 + anchor_x/-5,p3y*0.25 + anchor_y/-5);
		//-------------------------
		glVertex2f(p3x*0.25 + anchor_x/-5,p3y*0.25 + anchor_y/-5);
		glVertex2f(p4x*0.25 + anchor_x/-5,p4y*0.25 + anchor_y/-5);
		//-------------------------
		glVertex2f(p4x*0.25 + anchor_x/-5,p4y*0.25 + anchor_y/-5);
		glVertex2f(p1x*0.25 + anchor_x/-5,p1y*0.25 + anchor_y/-5);
		//-------------------------

		p1x = p1x + (LAMBDA * (p2x - p1x));

		p1y = p1y + (LAMBDA * (p2y - p1y));

		p2x = p2x + (LAMBDA * (p3x - p2x));

		p2y = p2y + (LAMBDA * (p3y - p2y));

		p3x = p3x + (LAMBDA * (p4x - p3x));

		p3y = p3y + (LAMBDA * (p4y - p3y));

		p4x = p4x + (LAMBDA * (p1x - p4x));

		p4y = p4y + (LAMBDA * (p1y - p4y));


		glEnd();
		
		glBegin(GL_LINES);


		//-------------------------
		glVertex2f(p1x*0.50 + anchor_x/5,p1y*0.50 + anchor_y/5);
		glVertex2f(p2x*0.50 + anchor_x/5,p2y*0.50 + anchor_y/5);
		//-------------------------
		glVertex2f(p2x*0.50 + anchor_x/5,p2y*0.50 + anchor_y/5);
		glVertex2f(p3x*0.50 + anchor_x/5,p3y*0.50 + anchor_y/5);
		//-------------------------
		glVertex2f(p3x*0.50 + anchor_x/5,p3y*0.50 + anchor_y/5);
		glVertex2f(p4x*0.50 + anchor_x/5,p4y*0.50 + anchor_y/5);
		//-------------------------
		glVertex2f(p4x*0.50 + anchor_x/5,p4y*0.50 + anchor_y/5);
		glVertex2f(p1x*0.50 + anchor_x/5,p1y*0.50 + anchor_y/5);
		//-------------------------

		p1x = p1x + (LAMBDA * (p2x - p1x));

		p1y = p1y + (LAMBDA * (p2y - p1y));

		p2x = p2x + (LAMBDA * (p3x - p2x));

		p2y = p2y + (LAMBDA * (p3y - p2y));

		p3x = p3x + (LAMBDA * (p4x - p3x));

		p3y = p3y + (LAMBDA * (p4y - p3y));

		p4x = p4x + (LAMBDA * (p1x - p4x));

		p4y = p4y + (LAMBDA * (p1y - p4y));

		glEnd();
		
		glFlush();
		usleep(50000);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH );
	glutInitWindowSize(900, 900);
    glutInitWindowPosition(100, 100);
	glutCreateWindow("Charles Im: Rotating Squares");

	glutDisplayFunc(mydisplay);
	glutMainLoop();
}