#include<GL/glut.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_LEVEL 35
#define LAMBDA 0.1

void mydisplay()
{
	float p1x = 1.0f;
	float p1y = 1.0f; 
	float p2x = 1.0f; 
	float p2y = 0.0f;
	float p3x = 0.0f; 
	float p3y = 0.0f;
	float p4x = 0.0f;
	float p4y = 1.0f;


	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-0.5f, -0.5f, 0.0f);


	glFlush();
	sleep(1);

	for(int i = 0 ; i < MAX_LEVEL ; i++ )
	{
		//glRotatef(30, 1.0f, 1.0f, 0.0f);
		//glRotatef(30, 1.0f, 1.0f, 1.0f);
		glRotatef(180, 1.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
		//glBegin(GL_POLYGON);
		//glEnable(GL_BLEND);
		//glBegin(GL_LINE_LOOP);
		glColor3ub( rand() % 255, rand() % 255, rand() % 255 );

		//-------------------------
		glVertex2f(p1x,p1y);
		glVertex2f(p2x,p2y);
		//-------------------------
		glVertex2f(p2x,p2y);
		glVertex2f(p3x,p3y);
		//-------------------------
		glVertex2f(p3x,p3y);
		glVertex2f(p4x,p4y);
		//-------------------------
		glVertex2f(p4x,p4y);
		glVertex2f(p1x,p1y);
		//-------------------------

		p1x = p1x + (LAMBDA * (p2x - p1x));
		//p1x = p1x - (LAMBDA * (p2x - p1x));

		p1y = p1y + (LAMBDA * (p2y - p1y));
		//p1y = p1y - (LAMBDA * (p2y - p1y));

		p2x = p2x + (LAMBDA * (p3x - p2x));
		//p2x = p2x - (LAMBDA * (p3x - p2x));

		p2y = p2y + (LAMBDA * (p3y - p2y));
		//p2y = p2y - (LAMBDA * (p3y - p2y));

		p3x = p3x + (LAMBDA * (p4x - p3x));
		//p3x = p3x - (LAMBDA * (p4x - p3x));

		p3y = p3y + (LAMBDA * (p4y - p3y));
		//p3y = p3y - (LAMBDA * (p4y - p3y));

		p4x = p4x + (LAMBDA * (p1x - p4x));
		//p4x = p4x - (LAMBDA * (p1x - p4x));

		p4y = p4y + (LAMBDA * (p1y - p4y));
		//p4y = p4y - (LAMBDA * (p1y - p4y));


		glEnd();
		glFlush();
		usleep(50000);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH );

	glutCreateWindow("Charles Im: Rotating Square");

	glutDisplayFunc(mydisplay);
	glutMainLoop();
}
