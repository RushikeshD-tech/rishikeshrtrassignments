
//Header File
#include <GL/glut.h>
#include<math.h> 

//int x, y;
//float i, j;

GLfloat angle = 0.0f;  // rotational angle of the shapes
int refreshMills = 30; // refresh interval in milliseconds


/*void keyboard(unsigned char key, int x, int y);
void display(void);
void TimerFunc(int);
static float x_start = 0.0f, y_start = 0.0f;
static float x_end = 0.0f, y_end = 0.0f;
static float x = 0.0f, y = 0.0f;*/

//code

void init2D(float r, float g, float b)
{
	glClearColor(r, g, b, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 400.0, 0.0, 350.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	//draw a line
	glPushMatrix();                     
	glTranslatef(-0.4f, -0.3f, 0.0f);  
	glRotatef(angle, 0.0f, 0.0f, 0.0f); 
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	
//glVertex2f(x_start, y_start);
//glVertex2f(x_end, y_end);

	glVertex2f(165.0, 50.0);
	glVertex2f(165.0, 305.0);

	glVertex2f(225.0, 305.0);
	glVertex2f(120.0, 305.0);

	glVertex2f(120.0, 50.0);
	glVertex2f(225.0, 50.0);

	glEnd();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	angle += 1.0f;
}
	

	/*for (j = 0; j < 10; j += 0.01)
	{
		for (i = 165; i >= -50; i--)
		{
			glVertex2i(0, i);
			glVertex2i(-165 * cos(j), i / 2 - 50 * sin(j));
		}
	}*/
	



void Timer(int value) {
	glutPostRedisplay();      
	glutTimerFunc(refreshMills, Timer, 0); 
}

void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Alphabetic Letter 'I' ");
	init2D(0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	//glutReshapeFunc(reshape);
	//glutKeyboardFunc(&keyboard);
	glutTimerFunc(0, Timer, 0);
	glutMainLoop();
}


