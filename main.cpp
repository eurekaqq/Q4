/* Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/* File for "Drawing Reflections" lesson of the OpenGL tutorial on
 * www.videotutorialsrock.com
 */



#define GLUT_DISABLE_ATEXIT_HACK

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include "../freeglut-3.0.0/include/glut.h"
#endif

static int draw_mode = 1;
static int action = 0;
static GLuint inner_mode = GL_SMOOTH;
static GLuint tex_state = GL_TRUE;
static int state_chang;

float anklea = 0, anklex = 0, ankley = 0, anklez = 1;		//��y
float plama, plamx = 0, plamy = 0, plamz = 0;			//��x (�R��)
float anklef1a[2], anklef1x[2], anklef1y[2], anklef1z[2];	//���
float anklef2a[3], anklef2x[3], anklef2y[3], anklef2z[3];	//����
float anklef3a[3], anklef3x[3], anklef3y[3], anklef3z[3];	//����
float anklef4a[3], anklef4x[3], anklef4y[3], anklef4z[3];	//�L�W��
float anklef5a[3], anklef5x[3], anklef5y[3], anklef5z[3];	//�p��
//	  ^^^��ʶq		^^^��ʶbx		^^^��ʶby		^^^��ʶbz

int state = 1;

static int WinWidth = 600;
static int WinHeight = 600;

void standby() {
	state = 1;
	anklea = 120, anklex = 0, ankley = 0, anklez = 1;  //��x
	plama = 0, plamx = 0, plamy = 0, plamz = 0;//��x



//-----------------------------------------	
	anklef2a[0] = -10;		//�������x
	anklef2x[0] = 0;
	anklef2y[0] = 0;
	anklef2z[0] = 1;

	anklef2a[1] = 3;	//����1
	anklef2x[1] = 0;
	anklef2y[1] = 0;
	anklef2z[1] = 1;

	anklef2a[2] = 3;	//����2
	anklef2x[2] = 0;
	anklef2y[2] = 0;
	anklef2z[2] = 1;
//-----------------------------------------	
	anklef3a[0] = 10;		//�������x
	anklef3x[0] = 0;
	anklef3y[0] = 0;
	anklef3z[0] = 1;

	anklef3a[1] = -10;	//����1
	anklef3x[1] = 0;
	anklef3y[1] = 0;
	anklef3z[1] = 1;

	anklef3a[2] = -10;	//����2
	anklef3x[2] = 0;
	anklef3y[2] = 0;
	anklef3z[2] = 1;
//-----------------------------------------	
	anklef4a[0] = 10;		//�������x
	anklef4x[0] = 0;
	anklef4y[0] = 0;
	anklef4z[0] = 1;

	anklef4a[1] = -10;	//����1
	anklef4x[1] = 0;
	anklef4y[1] = 0;
	anklef4z[1] = 1;

	anklef4a[2] = -10;	//����2
	anklef4x[2] = 0;
	anklef4y[2] = 0;
	anklef4z[2] = 1;
//-----------------------------------------	
	anklef5a[0] = 10;		//�������x
	anklef5x[0] = 0;
	anklef5y[0] = 0;
	anklef5z[0] = 1;

	anklef5a[1] = -10;	//����1
	anklef5x[1] = 0;
	anklef5y[1] = 0;
	anklef5z[1] = 1;

	anklef5a[2] = -10;	//����2
	anklef5x[2] = 0;
	anklef5y[2] = 0;
	anklef5z[2] = 1;

//-------------------------------											   //-----------------------------------------	
	anklef1a[0] = 15;		//�������x
	anklef1x[0] = 0;
	anklef1y[0] = 0;
	anklef1z[0] = 0;

	anklef1a[1] = -10;	//����1
	anklef1x[1] = 0;
	anklef1y[1] = 0;
	anklef1z[1] = 0;

	anklef1a[2] = -10;	//����2
	anklef1x[2] = 0;
	anklef1y[2] = 0;
	anklef1z[2] = 0;
}

void draw_hand(void)
{
	glPushMatrix();						//�W�u
	glScalef(4, 1, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(7.0, 30.0, 30.0);
	glPopMatrix();

	glTranslatef(anklex - 25, 0.0, 0.0);	//�y���`
	glRotatef(anklea, anklex, ankley, anklez);

	glPushMatrix();						//�y���`
	glColor3ub(219, 156, 53);
	glutSolidSphere(5.0, 30.0, 30.0);
	glPopMatrix();

	glTranslatef(-22.0, 0.0, 0.0);		//�U�u

	glPushMatrix();						//�U�u
	glScalef(4, 1, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(6.0, 30.0, 30.0);
	glPopMatrix();

	glTranslatef(-22.0, 0.0, 0.0);		//�x���`
	glRotatef(0, 0, 0, 0);

	glPushMatrix();						//�x���`
	glColor3ub(219, 156, 53);
	glutSolidSphere(3.0, 30.0, 30.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.0, 0.0, 3);		//�x

	glPushMatrix();
	glColor3ub(255, 102, 125);
	glScalef(1, 1, 0.5);
	glutSolidSphere(8, 30.0, 30.0);
	glPopMatrix();
	glPopMatrix();

//------------------------------
	glTranslated(-11.0, -0.5, -3);
	
	glPushMatrix();//�������x���`
	glScaled(0.85, 0.85, 0.85);
//------------------------------------------------------------����
	glTranslatef(-7, -5, 0.0);
	glRotatef(anklef2a[0], anklef2x[0], anklef2y[0], anklef2z[0]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.5, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-4, 0, 0);//�����`3

	glPushMatrix();
	glScalef(1.2, 0.6, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-4, 0, 0);//���������`
	glRotatef(anklef2a[1], anklef2x[1], anklef2y[1], anklef2z[1]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-3.0, 0, 0.0);//�����`2

	glPushMatrix();
	glScalef(1, 0.6, 1);
	glColor3ub(89, 197, 255);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-3, 0, 0.0);//�����W���`
	glRotatef(anklef2a[2], anklef2x[2], anklef2y[2], anklef2z[2]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-2.5, 0.0, 0.0); //�����`3

	glPushMatrix();
	glRotatef(20.0, 0, 1, 1.0);
	glScalef(1.0, 0.6, 1.0);
	glColor3ub(0, 177, 98);
	glutSolidSphere(1.7, 30.0, 30.0);
	glPopMatrix();

	glPopMatrix();
//--------�@�ڤ��--------
	glTranslatef(-1, 4, 0);

	glPushMatrix();
//------------------------------------------------------------����
	glTranslated(-7, -4.5, 0.0);
	glRotatef(anklef3a[0], anklef3x[0], anklef3y[0], anklef3z[0]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.5, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-4, 0, 0);//�����`3

	glPushMatrix();
	glScalef(1.2, 0.6, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-4, 0, 0);//���������`
	glRotatef(anklef3a[1], anklef3x[1], anklef3y[1], anklef3z[1]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-3.0, 0, 0.0);//�����`2

	glPushMatrix();
	glScalef(1, 0.6, 1);
	glColor3ub(89, 197, 255);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-3, 0, 0.0);//�����W���`
	glRotatef(anklef3a[2], anklef3x[2], anklef3y[2], anklef3z[2]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-2.5, 0.0, 0.0); //�����`3

	glPushMatrix();
	glRotatef(20.0, 0, 1, 1.0);
	glScalef(1.0, 0.6, 1.0);
	glColor3ub(0, 177, 98);
	glutSolidSphere(1.7, 30.0, 30.0);
	glPopMatrix();

	glPopMatrix();
//--------�@�ڤ��--------
	glTranslatef(-1, 4, 0);

	glPushMatrix();
	glScaled(0.9, 0.9, 0.9);
	//------------------------------�L�W��
	glTranslatef(-7, -5, 0.0);
	glRotatef(anklef4a[0], anklef4x[0], anklef4y[0], anklef4z[0]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.5, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-4, 0, 0);//�����`3

	glPushMatrix();
	glScalef(1.2, 0.6, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-4, 0, 0);//���������`
	glRotatef(anklef4a[1], anklef4x[1], anklef4y[1], anklef4z[1]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-3.0, 0, 0.0);//�����`2

	glPushMatrix();
	glScalef(1, 0.6, 1);
	glColor3ub(89, 197, 255);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-3, 0, 0.0);//�����W���`
	glRotatef(anklef4a[2], anklef4x[2], anklef4y[2], anklef4z[2]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-2.5, 0.0, 0.0); //�����`3

	glPushMatrix();
	glRotatef(20.0, 0, 1, 1.0);
	glScalef(1.0, 0.6, 1.0);
	glColor3ub(0, 177, 98);
	glutSolidSphere(1.7, 30.0, 30.0);
	glPopMatrix();

	glPopMatrix();
//--------�@�ڤ��--------
	glTranslatef(1.5, 2, 0);

	glPushMatrix();
	glScaled(0.7, 0.7, 0.7);
	//------------------------------�p��
	glTranslatef(-7, -5, 0.0);
	glRotatef(anklef5a[0], anklef5x[0], anklef5y[0], anklef5z[0]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.5, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-4, 0, 0);//�����`3

	glPushMatrix();
	glScalef(1.2, 0.6, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-4, 0, 0);//���������`
	glRotatef(anklef5a[1], anklef5x[1], anklef5y[1], anklef5z[1]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-3.0, 0, 0.0);//�����`2

	glPushMatrix();
	glScalef(1, 0.6, 1);
	glColor3ub(89, 197, 255);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-3, 0, 0.0);//�����W���`
	glRotatef(anklef5a[2], anklef5x[2], anklef5y[2], anklef5z[2]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-2.5, 0.0, 0.0); //�����`3

	glPushMatrix();
	glRotatef(20.0, 0, 1, 1.0);
	glScalef(1.0, 0.6, 1.0);
	glColor3ub(0, 177, 98);
	glutSolidSphere(1.7, 30.0, 30.0);
	glPopMatrix();

	glPopMatrix();
//--------�@�ڤ�u----------------------
	glTranslatef(1, -13.0, 0);

	glPushMatrix();//�������x���`
	glRotated(30, 0, 0, 1);
	glScaled(0.65, 0.65, 0.65);
//------------------------------����
	glTranslatef(-7, -5, 0.0);
	glRotatef(anklef1a[0], anklef1x[0], anklef1y[0], anklef1z[0]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.5, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-4, 0, 0);//�����`3

	glPushMatrix();
	glScalef(1.2, 0.6, 1);
	glColor3ub(255, 177, 98);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-4, 0, 0);//���������`
	glRotatef(anklef1a[1], anklef1x[1], anklef1y[1], anklef1z[1]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-3.0, 0, 0.0);//�����`2

	glPushMatrix();
	glScalef(1, 0.6, 1);
	glColor3ub(89, 197, 255);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-3, 0, 0.0);//�����W���`
	glRotatef(anklef1a[2], anklef1x[2], anklef1y[2], anklef1z[2]);

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glutSolidSphere(1.0, 30.0, 30.0);
	glPopMatrix();

	//-----------------------------
	glTranslatef(-2.5, 0.0, 0.0); //�����`3

	glPushMatrix();
	glRotatef(20.0, 0, 1, 1.0);
	glScalef(1.0, 0.6, 1.0);
	glColor3ub(0, 177, 98);
	glutSolidSphere(1.7, 30.0, 30.0);
	glPopMatrix();

	glPopMatrix();
}


void draw(void)
{
	glTranslatef(55.0, 0.0, -200.0);
	glRotatef(180, 1, 0, 0);            //����,X,Y,Z      
	draw_hand();
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(inner_mode);

	//Viewport 1
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,WinWidth,WinHeight);			
	gluPerspective(45.0, 1.0, 1.0, 400);// fov, aspect ratio ,near,far
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw();

	//Viewport 2
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(600,0,600,600);
	gluPerspective(45.0, 1.0, 1.0, 400);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(100, 0, -10, 0, 0, -200, 0.0, 1.0, 0.0);
	draw();

	glutSwapBuffers();
}
void reshape(int w, int h)
{
	WinWidth = w;
	WinHeight = h;
	GLfloat aspect;
	aspect = (GLfloat)w / (GLfloat)h;
	//glViewport(0,0,(GLsizei)w,(GLsizei)h);
	if (aspect > 1.0f)
		glViewport((w - h) / 2.0f, 0, (GLsizei)h, (GLsizei)h);
	else
		glViewport(0, (h - w) / 2.0f, (GLsizei)w, (GLsizei)w);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 1.0f, 500.0f);
	glMatrixMode(GL_MODELVIEW);
}
void init(void)
{
	GLfloat  ambientLight[] = { 1, 1, 1, 0.0f };
	GLfloat  diffuseLight[] = { 0, 0, 0, 1.0f };
	GLfloat  specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat  ambientLight2[] = { 0.9f, 0.1f, 0.1f, 1.0f };
	GLfloat  specular2[] = { 0.3f, 0.3f, 0.3f, 1.3f };
	GLfloat  specref[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat  pos[] = { 0.0f, 20.0f, -100.0f, 1.0f };
	GLfloat  dir[] = { 0.0f, 0.0f, -1.0f };

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);

	// Setup and enable light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, ambientLight2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular2);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 100);
	glLightfv(GL_LIGHT1, GL_POSITION, pos);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	// All materials hereafter have full specular reflectivity with a high shine
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	//glGenTextures(2, &texture[0]);
	//glBindTexture(GL_TEXTURE_2D, texture[0]);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void rock_pos(void) //���Y
{
	if (anklea >= 0)
		anklea--;
	state = 0;

	//-----------------------------------------	
	if (anklef1a[0] <= 60)
		anklef1a[0]++;    //�������x
	anklef1x[0] = 0;
	anklef1y[0] = 0;
	anklef1z[0] = 0;

	if (anklef1a[1] >= -90)
		anklef1a[1]--;    //����1
	anklef1x[1] = 0;
	anklef1y[1] = -1;
	anklef1z[1] = 0;

	if (anklef1a[2] >= -90)
		anklef1a[2]--;    //����2
	anklef1x[2] = 0;
	anklef1y[2] = -1;
	anklef1z[2] = 0;
	//-----------------------------------------	
	if (anklef2a[0] >= -90)
		anklef2a[0]--;    //�������x
	anklef2x[0] = 0;
	anklef2y[0] = 1;
	anklef2z[0] = 0;

	if (anklef2a[1] >= -90)
		anklef2a[1]--;    //����1
	anklef2x[1] = 0;
	anklef2y[1] = 1;
	anklef2z[1] = 0;

	if (anklef2a[2] >= -90)
		anklef2a[2]--;    //����2
	anklef2x[2] = 0;
	anklef2y[2] = 1;
	anklef2z[2] = 0;
	//------------------------------------
	if (anklef3a[0] >= -90)
		anklef3a[0]--;    //�������x
	anklef3x[0] = 0;
	anklef3y[0] = 1;
	anklef3z[0] = 0;

	if (anklef3a[1] >= -90)
		anklef3a[1]--;    //����1
	anklef3x[1] = 0;
	anklef3y[1] = 1;
	anklef3z[1] = 0;

	if (anklef3a[2] >= -90)
		anklef3a[2]--;    //����2
	anklef3x[2] = 0;
	anklef3y[2] = 1;
	anklef3z[2] = 0;
	//------------------------------------
	if (anklef4a[0] >= -90)
		anklef4a[0]--;    //�������x
	anklef4x[0] = 0;
	anklef4y[0] = 1;
	anklef4z[0] = 0;

	if (anklef4a[1] >= -90)
		anklef4a[1]--;    //����1
	anklef4x[1] = 0;
	anklef4y[1] = 1;
	anklef4z[1] = 0;

	if (anklef4a[2] >= -90)
		anklef4a[2]--;    //����2
	anklef4x[2] = 0;
	anklef4y[2] = 1;
	anklef4z[2] = 0;
	//------------------------------------
	if (anklef5a[0] >= -90)
		anklef5a[0]--;    //�������x
	anklef5x[0] = 0;
	anklef5y[0] = 1;
	anklef5z[0] = 0;

	if (anklef5a[1] >= -90)
		anklef5a[1]--;    //����1
	anklef5x[1] = 0;
	anklef5y[1] = 1;
	anklef5z[1] = 0;

	if (anklef5a[2] >= -90)
		anklef5a[2]--;    //����2
	anklef5x[2] = 0;
	anklef5y[2] = 1;
	anklef5z[2] = 0;


	glutPostRedisplay();
}

void one(void)                 //��
{
	if (anklea >= 0)
		anklea--;
	state = 0;

	//-----------------------------------------	
	if (anklef2a[0] <= 25)
		anklef2a[0]++;

	anklef2x[0] = 0;    //�������x
	anklef2y[0] = 0;
	anklef2z[0] = 1;

	anklef2x[1] = 0;    //����1
	anklef2y[1] = 0;
	anklef2z[1] = 0;

	anklef2x[2] = 0;    //����2
	anklef2y[2] = 0;
	anklef2z[2] = 0;
	//-----------------------------------------	
	if (anklef3a[0] <= 10)
		anklef3a[0]++;

	anklef3x[0] = 0;    //�������x
	anklef3y[0] = 0;
	anklef3z[0] = 1;

	anklef3x[1] = 0;    //����1
	anklef3y[1] = 0;
	anklef3z[1] = 0;

	anklef3x[2] = 0;    //����2
	anklef3y[2] = 0;
	anklef3z[2] = 0;
	//-----------------------------------------	
	if (anklef4a[0] >= -15)
		anklef4a[0]--;

	anklef4x[0] = 0;    //�������x
	anklef4y[0] = 0;
	anklef4z[0] = 1;

	anklef4x[1] = 0;    //����1
	anklef4y[1] = 0;
	anklef4z[1] = 0;

	anklef4x[2] = 0;    //����2
	anklef4y[2] = 0;
	anklef4z[2] = 0;
	//-----------------------------------------
	if (anklef5a[0] >= -30)
		anklef5a[0]--;

	anklef5x[0] = 0;    //�������x
	anklef5y[0] = 0;
	anklef5z[0] = 1;

	anklef5x[1] = 0;    //����1
	anklef5y[1] = 0;
	anklef5z[1] = 0;

	anklef5x[2] = 0;    //����2
	anklef5y[2] = 0;
	anklef5z[2] = 0;

	glutPostRedisplay();
}

void scissors(void)                 //�ŤM
{
	if (anklea >= 0)
		anklea--;
	state = 0;


	//-----------------------------------------	
	if (anklef1a[0] <= 90)
		anklef1a[0]++;    //�������x
	anklef1x[0] = 0;
	anklef1y[0] = 0;
	anklef1z[0] = 1;

	if (anklef1a[1] >= -90)
		anklef1a[1]--;    //����1
	anklef1x[1] = 0;
	anklef1y[1] = 1;
	anklef1z[1] = 0;

	if (anklef1a[2] >= -90)
		anklef1a[2]--;    //����2
	anklef1x[2] = 0;
	anklef1y[2] = 0;
	anklef1z[2] = 0;
	//-----------------------------------------	
	if (anklef2a[0] <= 25)
		anklef2a[0]++;    //�������x

	anklef2x[0] = 0;    //�������x
	anklef2y[0] = 0;
	anklef2z[0] = 1;

	anklef2x[1] = 0;    //����1
	anklef2y[1] = 0;
	anklef2z[1] = 0;

	anklef2x[2] = 0;    //����2
	anklef2y[2] = 0;
	anklef2z[2] = 0;
	//-----------------------------------------	
	if (anklef3a[0] >= -15)
		anklef3a[0]--;    //�������x

	anklef3x[0] = 0;    //�������x
	anklef3y[0] = 0;
	anklef3z[0] = 1;

	anklef3x[1] = 0;    //����1
	anklef3y[1] = 0;
	anklef3z[1] = 0;

	anklef3x[2] = 0;    //����2
	anklef3y[2] = 0;
	anklef3z[2] = 0;
	//-----------------------------------------	
	if (anklef4a[0] >= -90)
		anklef4a[0]--;    //�������x
	anklef4x[0] = 0;
	anklef4y[0] = 1;
	anklef4z[0] = 0;

	if (anklef4a[1] >= -90)
		anklef4a[1]--;    //����1
	anklef4x[1] = 0;
	anklef4y[1] = 1;
	anklef4z[1] = 0;


	if (anklef4a[2] >= -90)
		anklef4a[2]--;    //����2
	anklef4x[2] = 0;
	anklef4y[2] = 1;
	anklef4z[2] = 0;
	//------------------------------------
	if (anklef5a[0] >= -90)
		anklef5a[0]--;    //�������x
	anklef5x[0] = 0;
	anklef5y[0] = 1;
	anklef5z[0] = 0;

	if (anklef5a[1] >= -90)
		anklef5a[1]--;    //����1
	anklef5x[1] = 0;
	anklef5y[1] = 1;
	anklef5z[1] = 0;

	if (anklef5a[2] >= -90)
		anklef5a[2]--;    //����2
	anklef5x[2] = 0;
	anklef5y[2] = 1;
	anklef5z[2] = 0;

	glutPostRedisplay();
}

void cheat(void)                 //�@��
{
	if (anklea >= 0)
		anklea--;
	state = 0;

	//-----------------------------------------	
	anklef2x[0] = 0;    //�������x
	anklef2y[0] = 0;
	anklef2z[0] = 0;

	anklef2x[1] = 0;    //����1
	anklef2y[1] = 0;
	anklef2z[1] = 0;

	anklef2x[2] = 0;    //����2
	anklef2y[2] = 0;
	anklef2z[2] = 0;
	//-----------------------------------------	
	anklef3x[0] = 0;    //�������x
	anklef3y[0] = 0;
	anklef3z[0] = 0;

	anklef3x[1] = 0;    //����1
	anklef3y[1] = 0;
	anklef3z[1] = 0;

	anklef3x[2] = 0;    //����2
	anklef3y[2] = 0;
	anklef3z[2] = 0;
	//-----------------------------------------	
	if (anklef4a[0] >= -90)
		anklef4a[0]--;    //�������x
	anklef4x[0] = 0;
	anklef4y[0] = 1;
	anklef4z[0] = 0;

	if (anklef4a[1] >= -90)
		anklef4a[1]--;    //����1
	anklef4x[1] = 0;
	anklef4y[1] = 1;
	anklef4z[1] = 0;

	if (anklef4a[2] >= -90)
		anklef4a[2]--;    //����2
	anklef4x[2] = 0;
	anklef4y[2] = 1;
	anklef4z[2] = 0;
	//------------------------------------
	if (anklef5a[0] >= -90)
		anklef5a[0]--;    //�������x
	anklef5x[0] = 0;
	anklef5y[0] = 1;
	anklef5z[0] = 0;

	if (anklef5a[1] >= -90)
		anklef5a[1]--;    //����1
	anklef5x[1] = 0;
	anklef5y[1] = 1;
	anklef5z[1] = 0;

	if (anklef5a[2] >= -90)
		anklef5a[2]--;    //����2
	anklef5x[2] = 0;
	anklef5y[2] = 1;
	anklef5z[2] = 0;
	//-----------------------------------------	
	anklef1x[0] = 0;    //�������x
	anklef1y[0] = 0;
	anklef1z[0] = 0;

	anklef1x[1] = 0;    //����1
	anklef1y[1] = 0;
	anklef1z[1] = 0;

	anklef1x[2] = 0;    //����2
	anklef1y[2] = 0;
	anklef1z[2] = 0;

	glutPostRedisplay();
}

void keyin(unsigned char key, int x, int y)
{
	if (state != 1) {
		action = 0;
		standby();
	}

	switch (key)
	{
	case 'z':
		action = 1;
		break;
	case 'x':
		action = 2;
		break;
	case 'c':
		action = 3;
		break;
	case 'v':
		action = 4;
		break;
	}
}
void timerFunction(int value)
{
	switch (action)
	{
	case 0:
		standby();
		break;
	case 1://��
		one();
		break;
	case 2:  //���Y
		rock_pos();
		break;
	case 3://�ŤM
		scissors();
		break;
	case 4:
		cheat();
		break;
	}
	glutPostRedisplay();
	glutTimerFunc(5, timerFunction, 1);
}
int main(int argc, char** argv)
{
	int main_menu, action_menu, count_menu;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	//glutInitWindowSize(1200,600);	//< Dual view
	glutInitWindowSize(WinWidth, WinHeight);	//< Single view

	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);

	init();
	standby();

	glutKeyboardFunc(keyin);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutTimerFunc(5, timerFunction, 1);
	glutMainLoop();
	return 0;

}









