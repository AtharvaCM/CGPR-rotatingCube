#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
GLfloat angle = 0.0;
void spin(void)
{
	angle += 0.5;
	glutPostRedisplay();
}
void myDisplay(void)
{
	glClearColor(0.9,0.9,0.9,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glRotatef(angle,1,0,0);
	glRotatef(angle,0,1,0);
	glRotatef(angle,0,0,1);
	glColor3f(1.0,0.0,0.0);
	glutWireCube(2.0);
	glutSwapBuffers();
}
void reshape(int w,int h) // default w & h passed coz window size not changed
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//aspect ratios and distance from viewer to clipping plane
	gluPerspective(60,(GLfloat)w/(GLfloat)h,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key,int x,int y)
{
	if(key == 27) exit(0);	// escape key code
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Rotating cube");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(spin);
	glutMainLoop();
	return 0;
}
