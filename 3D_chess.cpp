#include<windows.h>
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
float _angle = 0;
float i;
float x = 0;
float tx,ty,tz,ox,oy,oz;
int k=0;
GLuint _displayListId_blackArea; //The OpenGL id
GLuint _displayListId_whiteArea; //The OpenGL id
 
//void handleKeypress(unsigned char key,int x,int y)
//{
//switch(key)
//{
//case 27:
//exit(0);
//}
//}
 
void handleResize(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0,(double)w/(double)h,1.0,200);
//gluLookAt(0.0f,8.0f, 18.0f,
//0.0f,0.0f,0.0f,
//0.0f,1.0f,0.0f);
gluLookAt(tx,ty,tz,
0.0f,0.0f,0.0f,
ox,oy,oz);
}

void handleKeypress(unsigned char key,int x,int y)
{
switch(key)
{
case 't':
		{
		tx=0.0f,ty=18.0f,tz=0.0f;
		ox=0.0f,oy=0.0f,oz=1.0f;
		handleResize(800,600);
		 break;
		 }
case 'd':
		{
		tx=0.0f,ty=-18.0f,tz=0.0f;
		ox=0.0f,oy=0.0f,oz=1.0f;
		handleResize(800,600);
		 break;
		 }
case 'f':
		{
		tx=0.0f,ty=8.8f,tz=18.0f;
		ox=0.0f,oy=1.0f,oz=0.0f;
		handleResize(800,600);
		 break;
		 }
case 'a':
		tx=-8.0f,ty=10.0f, tz=12.0f;
		ox=0.0f,oy=1.0f,oz=0.0f;
		handleResize(800,600);
		break;
//case 'b':
//		tx=-10.0f,ty=tz=0.0f;
//		ox=0.0f,oy=1.0f,oz=0.0f;
//		handleResize(800,600);
//		break;
case 'l':
		tx=0.0f,ty=0.0f,tz=18.0f;
		ox=0.0f,oy=1.0f,oz=0.0f;
		handleResize(800,600);
		break;
case 'r':
		tx=0.0f,ty=0.0f,tz=-18.0f;
		ox=0.0f,oy=1.0f,oz=0.0f;
		handleResize(800,600);
		break;
exit(0);
}
}
void draw_BlackArea()
{
// glPushMatrix();
//glTranslatef(1.5f,0.0f,0.0f);
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glTranslatef(0.0f,0.0f,0.0f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(1.50f,0.0f,0.0f);
glVertex3f(1.5f,0.3f,0.0f);
glVertex3f(0.0f,0.3f,0.0f);
glEnd();
 
 
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(0.0f,0.0f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,0.0f);
glEnd();
 
 
 
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(1.5f,0.0f,0.0f);
glVertex3f(1.5f,0.0f,-1.5f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(1.5f,0.3f,0.0f);
glEnd();
 
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,-1.5f);
glVertex3f(1.50f,0.0f,-1.5f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glEnd();
 
 
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(1.50f,0.0f,0.0f);
glVertex3f(1.5f,0.0f,-1.5f);
glVertex3f(0.0f,0.0f,-1.5f);
glEnd();
 
 
glBegin(GL_QUADS);
glColor3f(0.0f,0.0f,0.0f);
glVertex3f(0.0f,0.3f,0.0f);
glVertex3f(1.50f,0.3f,0.0f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glEnd();
//    glPopMatrix();
 
}
void draw_whiteArea()
{
// glPushMatrix();
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glTranslatef(0.0f,0.0f,0.0f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(1.50f,0.0f,0.0f);
glVertex3f(1.5f,0.3f,0.0f);
glVertex3f(0.0f,0.3f,0.0f);
glEnd();
 
 
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(0.0f,0.0f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,0.0f);
glEnd();
 
 
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(1.5f,0.0f,0.0f);
glVertex3f(1.5f,0.0f,-1.5f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(1.5f,0.3f,0.0f);
glEnd();


 
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,-1.5f);
glVertex3f(1.50f,0.0f,-1.5f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glEnd();
 
 
glBegin(GL_QUADS);
glColor3f(0.05f,0.05f,0.05f);
glVertex3f(0.0f,0.0f,0.0f);
glVertex3f(1.50f,0.0f,0.0f);
glVertex3f(1.5f,0.0f,-1.5f);
glVertex3f(0.0f,0.0f,-1.5f);
glEnd();
 
 
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);
glVertex3f(0.0f,0.3f,0.0f);
glVertex3f(1.50f,0.3f,0.0f);
glVertex3f(1.5f,0.3f,-1.5f);
glVertex3f(0.0f,0.3f,-1.5f);
glEnd();
// glPopMatrix();
 
}
 
void initRendering()
{
glEnable(GL_DEPTH_TEST);
glEnable(GL_COLOR_MATERIAL);
glClearColor(0.9f,0.8f,0.6f,0.0f);
 //Set up a display list for drawing a cube
_displayListId_blackArea = glGenLists(1); //Make room for the display list
glNewList(_displayListId_blackArea, GL_COMPILE); //Begin the display list
draw_BlackArea(); //Add commands for drawing a black area to the display list
glEndList(); //End the display list
// draw_figures();
//Set up a display list for drawing a cube
_displayListId_whiteArea = glGenLists(2); //Make room for the display list
glNewList(_displayListId_whiteArea, GL_COMPILE); //Begin the display list
draw_whiteArea(); //Add commands for drawing a black to the display list
glEndList(); //End the display list


}
void drawScene()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glRotatef(-_angle, 0.0f, 1.0f, 0.0f);
glTranslatef(-4*1.5, 0.0, 4*1.5);
 
for(float j=0.0;j>(-8*1.5);j-=1.5)
{
k++;
for(i=0.0;i<(4*3.0);i+=3.0)
{
if(k%2==0)
{
glPushMatrix();
glTranslatef(i,0.0,j);
glCallList(_displayListId_blackArea);
glPopMatrix();
 
}
else
{
glPushMatrix();
glTranslatef(i+1.5,0.0,j);
glCallList(_displayListId_blackArea);
glPopMatrix();
 
}
}
}
for(float j=0.0;j>(-8*1.5);j-=1.5)
{
k++;
for(i=0.0;i<(4*3.0);i+=3.0)
{
if(k%2!=0)
{
glPushMatrix();
glTranslatef(i,0.0,j);
glCallList(_displayListId_whiteArea);
glPopMatrix();
 
}
else
{
glPushMatrix();
glTranslatef(i+1.5,0.0,j);
glCallList(_displayListId_whiteArea);
glPopMatrix();
 
}
}
}

//________________________________________________________peshki 
 

glBegin( GL_TRIANGLES );

//for(int i=0; i<8; i++){

glColor3f( 1.0f, 1.0f, 0.0f ); glVertex3f( 0.75f, 1.2f, -2.25f );			//forward
glColor3f( 0.0f, 1.0f, 0.0f ); glVertex3f( 0.3f, 0.4f, -1.8f );
glColor3f( 0.0f, 0.0f, 1.0f ); glVertex3f( 1.2f, 0.4f, -1.8f);

glColor3f( 1.0f, 1.0f, 0.0f ); glVertex3f( 0.75f, 1.2f, -2.25f  );			//left
glColor3f( 0.0f, 1.0f, 0.0f ); glVertex3f(0.3f, 0.4f, -1.8f );
glColor3f( 0.0f, 0.0f, 1.0f ); glVertex3f( 0.75f, 0.4f, -2.7f);

glColor3f( 1.0f, 1.0f, 0.0f ); glVertex3f( 0.75f, 1.2f, -2.25f );			//right
glColor3f( 0.0f, 1.0f, 0.0f ); glVertex3f( 0.75f, 0.4f, -2.7f);
glColor3f( 0.0f, 0.0f, 1.0f ); glVertex3f( 1.2f, 0.4f, -1.8f);


glColor3f( 1.0f, 1.0f, 0.0f ); glVertex3f( 0.3f, 0.4f, -1.8f);			//bottom
glColor3f( 0.0f, 1.0f, 0.0f ); glVertex3f( 1.2f, 0.4f, -1.8f);
glColor3f( 0.0f, 0.0f, 1.0f ); glVertex3f( 0.75f, 0.4f, -2.7f);

//x+=1.5;
//}
glEnd();

//________________________________________________________figuri

glutWireTeapot(0.5);


glutSwapBuffers();
 
 
 
}
 void update(int value) {

glutPostRedisplay();
glutTimerFunc(25, update, 0);
}
int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(800,600);
 
glutCreateWindow("chess");
initRendering();
//glutFullScreen();
 
glutDisplayFunc(drawScene);
glutKeyboardFunc(handleKeypress);
glutReshapeFunc(handleResize);
glutTimerFunc(25, update, 0);
tx=0.0f,ty=8.0f,tz=18.0f;
ox=0.0f,oy=1.0f,oz=0.0f;

glutMainLoop();
 
return 0;
 
}
