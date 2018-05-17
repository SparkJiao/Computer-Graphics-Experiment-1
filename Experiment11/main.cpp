//#include "stdafx.h"  
#include <windows.h>  
#include <GL/glu.h>  
#include <GL/gl.h>  
#include <GL/glut.h>  
//#include <GL/glaux.h>  
#include <math.h>   
#include <stdio.h>  

//#pragma comment(lib,"glaux.lib")

#define Glass   1  
#define Stone   2  
#define Eye     3  
#define Eye1    4  
#define Nose    5  
#define Cap     6  
#define Crown   7  
#define Clothes 8  
#define Superman 9  
#define PI 3.1416  
#define MAX_CHAR 128    

static int EYE_COLOR = 0;
static int EYE1_COLOR = 0;
static int NOSE_COLOR = 0;
static int CROWN_COLOR = 6;
static int SUPERMAN_COLOR = 3;


GLuint texture[4];
GLuint base;

BOOL GLASS_STATE;
BOOL STONE_STATE;
BOOL EYE_STATE;
BOOL EYE1_STATE;
BOOL NOSE_STATE;
BOOL CAP_STATE;
BOOL CROWN_STATE;
BOOL CLOTHES_STATE;
BOOL SUPERMAN_STATE;


GLuint GlassCor[2] = { 0,0 };
GLuint StoneCor[2] = { 20,10 };
GLuint EyeCor[2] = { -12,60 };
GLuint EyeCor1[2] = { 12,60 };
GLuint NoseCor[2] = { 0,60 };
GLuint CapCor[2] = { 0,85 };
GLuint CrownCor[2] = { 0 + 118,9 + 70 };
GLuint ClothesCor[2] = { 0 + 110,0 - 50 };
GLuint SupermanCor[2] = { 0,0 };

int Wide = 0;
int High = 0;

const int N = 40;
float xx[50], yy[50] = { 0 };

int select_part = 0;

static GLfloat theta = 0;

static GLfloat colors[8][3] = {
	{ 0.0, 0.0, 0.0 },{ 1.0, 0.0, 0.0 },{ 0.0, 1.0, 0.0 },{ 0.5,0.5,0.75 },
	{ 0.0, 1.0, 1.0 },{ 1.0, 0.0, 1.0 },{ 1.0, 1.0, 0.0 },{ 1.0, 1.0, 1.0 } };

void paintViewportA();
void drawString(const char* str);
void selectFont(int size, int charset, const char* face);

void DrawSphereTexture(int x, int y)
{

	glEnable(GL_BLEND);             //启用混合功能，将图形颜色同周围颜色相混合    
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);       //点抗锯齿    
	glEnable(GL_LINE_SMOOTH);        //线抗锯齿    
	glEnable(GL_POLYGON_SMOOTH);     //多边形抗锯齿    



	glLoadIdentity();
	glRotatef(-30.0, 0.0, 0.0, 1.0);
	glRotatef(theta, 0.0, 0.0, 1.0);
	//第三步 画手臂   左  
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<N; i++)
	{
		xx[i] = 16 * cos(2 * i*PI / N) - 28;
		yy[i] = 40 * sin(2 * i*PI / N) - 10;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();
	//再描一遍线  
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i<N; i++)
	{
		xx[i] = 16 * cos(2 * i*PI / N) - 28;
		yy[i] = 40 * sin(2 * i*PI / N) - 10;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();

	//画手臂  右  

	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glRotatef(30.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<N; i++)
	{
		xx[i] = 16 * cos(2 * i*PI / N) + 28;
		yy[i] = 40 * sin(2 * i*PI / N) - 10;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();
	//再描一遍线  
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i<N; i++)
	{
		xx[i] = 16 * cos(2 * i*PI / N) + 28;
		yy[i] = 40 * sin(2 * i*PI / N) - 10;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();


	//开始画腿************************************************************************  
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glRotatef(8.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<N; i++)
	{
		xx[i] = 15 * cos(2 * i*PI / N) - 22;
		yy[i] = 33 * sin(2 * i*PI / N) - 37;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();
	//再描一遍线  
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i<N; i++)
	{
		xx[i] = 15 * cos(2 * i*PI / N) - 22;
		yy[i] = 33 * sin(2 * i*PI / N) - 37;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();


	//画右腿  
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glRotatef(-8.0, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<N; i++)
	{
		xx[i] = 15 * cos(2 * i*PI / N) + 22;
		yy[i] = 33 * sin(2 * i*PI / N) - 37;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();
	//再描一遍线  
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i<N; i++)
	{
		xx[i] = 15 * cos(2 * i*PI / N) + 22;
		yy[i] = 33 * sin(2 * i*PI / N) - 37;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();



	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	//再画身体*********************************************************************  
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<N; i++)
	{
		xx[i] = 40 * cos(2 * i*PI / N);
		yy[i] = 45 * sin(2 * i*PI / N);
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();
	//再描一遍线  
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i<N; i++)
	{
		xx[i] = 40 * cos(2 * i*PI / N);
		yy[i] = 45 * sin(2 * i*PI / N);
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();

	//画头部  
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<N; i++)
	{
		xx[i] = 30 * cos(2 * i*PI / N);
		yy[i] = 20 * sin(2 * i*PI / N) + 60;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();
	//再描一遍线  
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i<N; i++)
	{
		xx[i] = 30 * cos(2 * i*PI / N);
		yy[i] = 20 * sin(2 * i*PI / N) + 60;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();

}

//胸章  
void DrawXiongzhang(int x, int y)
{
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glTranslatef(0, 0, 30);
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<N; i++)
	{
		xx[i] = 10 * cos(2 * i*PI / N) + x;
		yy[i] = 10 * sin(2 * i*PI / N) + y;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();

	//再内嵌一个三角形  
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-5.0 + x, -2.5 + y);
	glVertex2f(5.0 + x, -2.5 + y);
	glVertex2f(0.0 + x, 5.0 + y);
	glEnd();
}

//眼部提取出来  
void DrawEye1(int x, int y)
{
	//画眼睛 左  
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glTranslatef(0, 0, 30);
	glColor3f(colors[EYE_COLOR][0], colors[EYE_COLOR][1], colors[EYE_COLOR][2]);
	//glColor3f(0.0f,0.0f,0.0f);   
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<N; i++)
	{
		xx[i] = 6 * cos(2 * i*PI / N) + x;
		yy[i] = 6 * sin(2 * i*PI / N) + y;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();
}

void DrawEye2(int x, int y)
{
	//画眼睛 右  
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glTranslatef(0, 0, 30);
	glColor3f(colors[EYE1_COLOR][0], colors[EYE1_COLOR][1], colors[EYE1_COLOR][2]);
	//glColor3f(0.0f,0.0f,0.0f);   
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<N; i++)
	{
		xx[i] = 6 * cos(2 * i*PI / N) + x;
		yy[i] = 6 * sin(2 * i*PI / N) + y;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();

}

void DrawNose(int x, int y)
{
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glTranslatef(0, 0, 30);
	//glColor3f(0.0f,0.0f,0.0f);  
	glColor3f(colors[NOSE_COLOR][0], colors[NOSE_COLOR][1], colors[NOSE_COLOR][2]);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(-12 + x, y);
	glVertex2f(12 + x, y);
	glEnd();
}

void DrawCap(int x, int y)
{

	//此处开始绘制帽子  
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glTranslatef(0, 0, 30);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0 + x, y - 5);
	glVertex2f(-13 + x, y - 10);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-25 + x, y - 10);
	glVertex2f(-12 + x, y - 2);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0 + x, y + 20);
	glVertex2f(12 + x, y - 2);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex2f(25 + x, y - 10);
	glVertex2f(13 + x, y - 10);
	glEnd();
}

void DrawCrown(int x, int y)
{
	//开始绘制王冠  
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glTranslatef(0, 0, 30);
	glColor3f(1.0f, 1.0f, 0.0f);
	glColor3f(colors[CROWN_COLOR][0], colors[CROWN_COLOR][1], colors[CROWN_COLOR][2]);
	glBegin(GL_POLYGON);
	glVertex2f(-10 + x, y - 9);
	glVertex2f(-13 + x, 6 + y);
	glVertex2f(-5 + x, y - 2);
	glVertex2f(0 + x, 9 + y);
	glVertex2f(5 + x, y - 2);
	glVertex2f(13 + x, 6 + y);
	glVertex2f(10 + x, y - 9);
	glEnd();
}

void DrawClothes(int x, int y)
{

	//衣服绘制  
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glTranslatef(0, 0, 30);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<8; i++)
	{
		xx[i] = 40 * cos(2 * i*PI / N) + x;
		yy[i] = 45 * sin(2 * i*PI / N) + y;
		glVertex2f(xx[i], yy[i]);
	}

	for (int i = 13; i<20; i++)
	{
		xx[i] = 40 * cos(2 * i*PI / N) + x;
		yy[i] = 45 * sin(2 * i*PI / N) + y;
		glVertex2f(xx[i], yy[i]);
	}

	for (int i = 20; i<N; i++)
	{
		xx[i] = 40 * cos(2 * i*PI / N) + x;
		yy[i] = 45 * sin(2 * i*PI / N) + y;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();

	//衣服上的一些纹理绘制  
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-7 + x, 40 + y);
	glVertex2f(0 + x, 20 + y);
	glVertex2f(7 + x, 40 + y);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glVertex2f(-20 + x, 20 + y);
	glVertex2f(-20 + x, 10 + y);
	glVertex2f(-10 + x, 10 + y);
	glVertex2f(-10 + x, 20 + y);
	glEnd();


	glBegin(GL_LINES);
	glVertex2f(0 + x, 0 + y);
	glVertex2f(0 + x, -25 + y);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0 + x, -25 + y);
	glVertex2f(-10 + x, -40 + y);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0 + x, -25 + y);
	glVertex2f(10 + x, -40 + y);
	glEnd();

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<N; i++)
	{
		xx[i] = 4 * cos(2 * i*PI / N) + x;
		yy[i] = 4 * sin(2 * i*PI / N) + y;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();

}

void DrawSuperman(int x, int y)
{
	//绘制超人装  
	glLoadIdentity();
	glRotatef(theta, 0.0, 0.0, 1.0);
	glTranslatef(0, 0, 20);
	//glColor3f(0.5f,0.5f,0.75f);   
	glColor3f(colors[SUPERMAN_COLOR][0], colors[SUPERMAN_COLOR][1], colors[SUPERMAN_COLOR][2]);
	glBegin(GL_POLYGON);          //用线进行图形连接    
	for (int i = 0; i<8; i++)
	{
		xx[i] = 40 * cos(2 * i*PI / N) + x;
		yy[i] = 45 * sin(2 * i*PI / N) + y;
		glVertex2f(xx[i], yy[i]);
	}

	for (int i = 13; i<20; i++)
	{
		xx[i] = 40 * cos(2 * i*PI / N) + x;
		yy[i] = 45 * sin(2 * i*PI / N) + y;
		glVertex2f(xx[i], yy[i]);
	}

	for (int i = 20; i<N; i++)
	{
		xx[i] = 40 * cos(2 * i*PI / N) + x;
		yy[i] = 45 * sin(2 * i*PI / N) + y;
		glVertex2f(xx[i], yy[i]);
	}
	glEnd();

	//绘制超人标志  
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-14 + x, 30 + y);
	glVertex2f(14 + x, 30 + y);
	glVertex2f(20 + x, 21 + y);
	glVertex2f(0 + x, 0 + y);
	glVertex2f(-20 + x, 21 + y);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(4);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-15 + x, 30 + y);
	glVertex2f(15 + x, 30 + y);
	glVertex2f(21 + x, 21 + y);
	glVertex2f(0 + x, -1 + y);
	glVertex2f(-21 + x, 21 + y);
	glEnd();

	//绘制 S  
	selectFont(80, ANSI_CHARSET, "Comic Sans MS");
	glColor3f(1.0f, 0.0f, 0.0f);     //设置字体颜色    
	glRasterPos2i(-6 + x, 10 + y);  //起始位置    
	drawString("S");   //输出的字符串    

					   //绘制衣领  
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0 + x, 40 + y);
	glVertex2f(-20 + x, 40 + y);
	glVertex2f(-17 + x, 45 + y);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0 + x, 40 + y);
	glVertex2f(20 + x, 40 + y);
	glVertex2f(17 + x, 45 + y);
	glEnd();

}
void RenderScene(void)
{
	// Clear the window with current clearing color  
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//旋转  

	paintViewportA();

	// Save the matrix state and do the rotations  
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	// Translate the whole scene out and into view    
	//  glTranslatef(150.0f, 0.0f, -50.0f);   

	// Initialize the names stack  
	glInitNames();
	glPushName(0);

	//glLoadIdentity();  
	glLoadName(Glass);
	DrawSphereTexture(GlassCor[0], GlassCor[1]);

	glPushMatrix();
	glLoadIdentity();
	glLoadName(Stone);
	DrawXiongzhang(StoneCor[0], StoneCor[1]);


	glPushMatrix();
	glLoadIdentity();
	glLoadName(Eye);
	DrawEye1(EyeCor[0], EyeCor[1]);

	glPushMatrix();
	glLoadIdentity();
	glLoadName(Eye1);
	DrawEye2(EyeCor1[0], EyeCor1[1]);

	glPushMatrix();
	glLoadIdentity();
	glLoadName(Nose);
	DrawNose(NoseCor[0], NoseCor[1]);

	glPushMatrix();
	glLoadIdentity();
	glLoadName(Cap);
	DrawCap(CapCor[0], CapCor[1]);
	glPopMatrix();

	glPushMatrix();
	glLoadIdentity();
	glLoadName(Crown);
	DrawCrown(CrownCor[0], CrownCor[1]);
	glPopMatrix();

	glPushMatrix();
	glLoadIdentity();
	glLoadName(Clothes);
	DrawClothes(ClothesCor[0], ClothesCor[1]);
	glPopMatrix();

	glPushMatrix();
	glLoadIdentity();
	glLoadName(Superman);
	DrawSuperman(SupermanCor[0], SupermanCor[1]);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();


	// Restore the matrix state  
	glPopMatrix();  // Modelview matrix  

	glutSwapBuffers();
}

//此处开始添加多重视口    此处简化 不采用多重视角  
void paintViewportA()
{
	int _width = Wide / 8;
	int _height = High / 6;

	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(_width, -_height);
	glVertex2f(_width, _height);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(_width, _height / 3);
	glVertex2f(2 * _width, _height / 3);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(_width, 2 * _height / 3);
	glVertex2f(2 * _width, 2 * _height / 3);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(_width, 0);
	glVertex2f(2 * _width, 0);
	glEnd();






}

void ProcessPlanet(GLuint id)
{
	switch (id)
	{

	case Glass:
		//  glutSetWindowTitle("You clicked on the Glass!");  
		GLASS_STATE = TRUE;
		STONE_STATE = FALSE;
		EYE_STATE = FALSE;
		EYE1_STATE = FALSE;
		NOSE_STATE = FALSE;
		CAP_STATE = FALSE;
		CROWN_STATE = FALSE;
		CLOTHES_STATE = FALSE;
		SUPERMAN_STATE = FALSE;

		select_part = Glass;
		printf("Glass \n");
		break;


	case Stone:
		//  glutSetWindowTitle("You clicked on Stone!");  
		STONE_STATE = TRUE;
		GLASS_STATE = FALSE;
		EYE_STATE = FALSE;
		EYE1_STATE = FALSE;
		NOSE_STATE = FALSE;
		CAP_STATE = FALSE;
		CROWN_STATE = FALSE;
		CLOTHES_STATE = FALSE;
		SUPERMAN_STATE = FALSE;

		select_part = Stone;
		printf("Stone \n");
		break;

	case Eye:
		STONE_STATE = FALSE;
		GLASS_STATE = FALSE;
		EYE_STATE = TRUE;
		EYE1_STATE = FALSE;
		NOSE_STATE = FALSE;
		CAP_STATE = FALSE;
		CROWN_STATE = FALSE;
		CLOTHES_STATE = FALSE;
		SUPERMAN_STATE = FALSE;

		select_part = Eye;
		printf("Eye \n");
		break;

	case Eye1:
		STONE_STATE = FALSE;
		GLASS_STATE = FALSE;
		EYE_STATE = FALSE;
		EYE1_STATE = TRUE;
		NOSE_STATE = FALSE;
		CAP_STATE = FALSE;
		CROWN_STATE = FALSE;
		CLOTHES_STATE = FALSE;
		SUPERMAN_STATE = FALSE;

		select_part = Eye1;
		break;

	case Nose:
		STONE_STATE = FALSE;
		GLASS_STATE = FALSE;
		EYE_STATE = FALSE;
		EYE1_STATE = FALSE;
		NOSE_STATE = TRUE;
		CAP_STATE = FALSE;
		CROWN_STATE = FALSE;
		CLOTHES_STATE = FALSE;
		SUPERMAN_STATE = FALSE;

		select_part = Nose;
		break;

	case Cap:
		STONE_STATE = FALSE;
		GLASS_STATE = FALSE;
		EYE_STATE = FALSE;
		EYE1_STATE = FALSE;
		NOSE_STATE = FALSE;
		CAP_STATE = TRUE;
		CROWN_STATE = FALSE;
		CLOTHES_STATE = FALSE;
		SUPERMAN_STATE = FALSE;

		select_part = Cap;
		break;

	case Crown:
		STONE_STATE = FALSE;
		GLASS_STATE = FALSE;
		EYE_STATE = FALSE;
		EYE1_STATE = FALSE;
		NOSE_STATE = FALSE;
		CAP_STATE = FALSE;
		CROWN_STATE = TRUE;
		CLOTHES_STATE = FALSE;
		SUPERMAN_STATE = FALSE;

		select_part = Crown;
		break;

	case Clothes:
		STONE_STATE = FALSE;
		GLASS_STATE = FALSE;
		EYE_STATE = FALSE;
		EYE1_STATE = FALSE;
		NOSE_STATE = FALSE;
		CAP_STATE = FALSE;
		CROWN_STATE = FALSE;
		CLOTHES_STATE = TRUE;
		SUPERMAN_STATE = FALSE;

		select_part = Clothes;
		break;

	case Superman:
		STONE_STATE = FALSE;
		GLASS_STATE = FALSE;
		EYE_STATE = FALSE;
		EYE1_STATE = FALSE;
		NOSE_STATE = FALSE;
		CAP_STATE = FALSE;
		CROWN_STATE = FALSE;
		CLOTHES_STATE = FALSE;
		SUPERMAN_STATE = TRUE;

		select_part = Superman;
		break;
	}
}


#define BUFFER_LENGTH 64  
void ProcessSelection(int xPos, int yPos)
{
	GLfloat fAspect;

	// Space for selection buffer  
	static GLuint selectBuff[BUFFER_LENGTH];

	// Hit counter and viewport storage  
	GLint hits, viewport[4];

	// Setup selection buffer  
	glSelectBuffer(BUFFER_LENGTH, selectBuff);

	// Get the viewport  
	glGetIntegerv(GL_VIEWPORT, viewport);

	// Switch to projection and save the matrix  
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

	// Change render mode  
	glRenderMode(GL_SELECT);

	// Establish new clipping volume to be unit cube around  
	// mouse cursor point (xPos, yPos) and extending two pixels  
	// in the vertical and horizontal direction  
	glLoadIdentity();
	gluPickMatrix(xPos, viewport[3] - yPos, 2, 2, viewport);

	//应用透视投影矩阵  
	fAspect = (float)viewport[2] / (float)viewport[3];
	if (viewport[2] <= viewport[3])
	{
		glOrtho(-100, 100, -100 * fAspect, 100 * fAspect, -100, 100);
	}
	else
	{
		glOrtho(-100 * fAspect, 100 * fAspect, -100, 100, -100, 100);
	}

	// Draw the scene  
	RenderScene();

	// Collect the hits  
	hits = glRenderMode(GL_RENDER);

	// If a single hit occurred, display the info.  
	if (hits > 0)
	{
		int Choose = selectBuff[3];
		int depth = selectBuff[1];
		printf("1       ************  %d       %d      ", Choose, depth);
		for (int loop = 1; loop<hits; loop++)
		{
			if (selectBuff[loop * 4 + 1] < GLuint(depth))
			{
				Choose = selectBuff[loop * 4 + 3];
				depth = selectBuff[loop * 4 + 1];
			}
			printf(">2       ************  %d       %d      ", Choose, depth);

		}
		printf("************  %d       %d      \n", hits, Choose);
		ProcessPlanet(GLuint(Choose));
	}

	// Restore the projection matrix  
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	// Go back to modelview for normal rendering  
	glMatrixMode(GL_MODELVIEW);
}



///////////////////////////////////////////////////////////  
// Process the mouse click  
void MouseCallback(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		ProcessSelection(x, y);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		GLASS_STATE = FALSE;
		STONE_STATE = FALSE;
		EYE_STATE = FALSE;
		EYE1_STATE = FALSE;
		NOSE_STATE = FALSE;
		CAP_STATE = FALSE;
		CROWN_STATE = FALSE;
		CLOTHES_STATE = FALSE;
		SUPERMAN_STATE = FALSE;
	}


}


void MouseMoveCallback(int x, int y)
{
	GLint viewport[4];
	GLfloat fA;
	glGetIntegerv(GL_VIEWPORT, viewport);
	fA = (float)viewport[2] / (float)viewport[3];


	if (GLASS_STATE == TRUE)
	{
		if (viewport[2] <= viewport[3])
		{
			GlassCor[0] = -100 + 200 * x / viewport[2];
			GlassCor[1] = -100 * fA + (viewport[3] - y) * 200 * fA / viewport[3];

		}
		else
		{
			GlassCor[0] = -100 * fA + 200 * fA*x / viewport[2];
			GlassCor[1] = -100 + (viewport[3] - y) * 200 / viewport[3];
		}
		RenderScene();

	}


	if (STONE_STATE == TRUE)
	{
		if (viewport[2] <= viewport[3])
		{
			StoneCor[0] = -100 + 200 * x / viewport[2];
			StoneCor[1] = -100 * fA + (viewport[3] - y) * 200 * fA / viewport[3];
		}
		else
		{
			StoneCor[0] = -100 * fA + 200 * fA*x / viewport[2];
			StoneCor[1] = -100 + (viewport[3] - y) * 200 / viewport[3];
		}
		RenderScene();
	}

	if (EYE_STATE == TRUE)
	{
		if (viewport[2] <= viewport[3])
		{
			EyeCor[0] = -100 + 200 * x / viewport[2];
			EyeCor[1] = -100 * fA + (viewport[3] - y) * 200 * fA / viewport[3];
		}
		else
		{
			EyeCor[0] = -100 * fA + 200 * fA*x / viewport[2];
			EyeCor[1] = -100 + (viewport[3] - y) * 200 / viewport[3];
		}
		RenderScene();
	}


	if (EYE1_STATE == TRUE)
	{
		if (viewport[2] <= viewport[3])
		{
			EyeCor1[0] = -100 + 200 * x / viewport[2];
			EyeCor1[1] = -100 * fA + (viewport[3] - y) * 200 * fA / viewport[3];
		}
		else
		{
			EyeCor1[0] = -100 * fA + 200 * fA*x / viewport[2];
			EyeCor1[1] = -100 + (viewport[3] - y) * 200 / viewport[3];
		}
		RenderScene();
	}

	if (NOSE_STATE == TRUE)
	{
		if (viewport[2] <= viewport[3])
		{
			NoseCor[0] = -100 + 200 * x / viewport[2];
			NoseCor[1] = -100 * fA + (viewport[3] - y) * 200 * fA / viewport[3];
		}
		else
		{
			NoseCor[0] = -100 * fA + 200 * fA*x / viewport[2];
			NoseCor[1] = -100 + (viewport[3] - y) * 200 / viewport[3];
		}
		RenderScene();
	}


	if (CAP_STATE == TRUE)
	{
		if (viewport[2] <= viewport[3])
		{
			CapCor[0] = -100 + 200 * x / viewport[2];
			CapCor[1] = -100 * fA + (viewport[3] - y) * 200 * fA / viewport[3];
		}
		else
		{
			CapCor[0] = -100 * fA + 200 * fA*x / viewport[2];
			CapCor[1] = -100 + (viewport[3] - y) * 200 / viewport[3];
		}
		RenderScene();
	}

	if (CROWN_STATE == TRUE)
	{
		if (viewport[2] <= viewport[3])
		{
			CrownCor[0] = -100 + 200 * x / viewport[2];
			CrownCor[1] = -100 * fA + (viewport[3] - y) * 200 * fA / viewport[3];
		}
		else
		{
			CrownCor[0] = -100 * fA + 200 * fA*x / viewport[2];
			CrownCor[1] = -100 + (viewport[3] - y) * 200 / viewport[3];
		}
		RenderScene();
	}

	if (CLOTHES_STATE == TRUE)
	{
		if (viewport[2] <= viewport[3])
		{
			ClothesCor[0] = -100 + 200 * x / viewport[2];
			ClothesCor[1] = -100 * fA + (viewport[3] - y) * 200 * fA / viewport[3];
		}
		else
		{
			ClothesCor[0] = -100 * fA + 200 * fA*x / viewport[2];
			ClothesCor[1] = -100 + (viewport[3] - y) * 200 / viewport[3];
		}
		RenderScene();
	}


	if (SUPERMAN_STATE == TRUE)
	{
		if (viewport[2] <= viewport[3])
		{
			SupermanCor[0] = -100 + 200 * x / viewport[2];
			SupermanCor[1] = -100 * fA + (viewport[3] - y) * 200 * fA / viewport[3];
		}
		else
		{
			SupermanCor[0] = -100 * fA + 200 * fA*x / viewport[2];
			SupermanCor[1] = -100 + (viewport[3] - y) * 200 / viewport[3];
		}
		RenderScene();
	}




}



///////////////////////////////////////////////////////////  
// This function does any needed initialization on the   
// rendering context.   
void InitGL()
{

	GLASS_STATE = FALSE;
	STONE_STATE = FALSE;
	EYE_STATE = FALSE;
	EYE1_STATE = FALSE;
	NOSE_STATE = FALSE;
	CAP_STATE = FALSE;
	CROWN_STATE = FALSE;
	CLOTHES_STATE = FALSE;
	SUPERMAN_STATE = FALSE;

	//  GlassCor[3] = {0,0,0};  
	//  StoneCor[3] = {50,0,-50};  

	//LoadGLTextures("glass.bmp",0);  
	//LoadGLTextures("glass4.bmp",1);  


	// Gray background  
	glEnable(GL_BLEND);
	//  glColor4f(1.0f, 1.0f, 1.0f, 0.3);                   // Full Brightness.  50% Alpha  
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//  glEnable(GL_COLOR_MATERIAL);  
	//  glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);  




}

void ChangeSize(int w, int h)
{
	GLfloat fAspect;

	// Prevent a divide by zero  
	if (h == 0)
		h = 1;

	Wide = w;
	High = h;

	// Set Viewport to window dimensions  
	glViewport(0, 0, w, h);

	// Calculate aspect ratio of the window  
	fAspect = (GLfloat)w / (GLfloat)h;

	// Set the perspective coordinate system  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Field of view of 45 degrees, near and far planes 1.0 and 425  
	//  gluPerspective(0.0f, fAspect, 1.0, 425.0);  

	if (w <= h)
	{
		glOrtho(-100, 100, -100 * fAspect, 100 * fAspect, -100, 100);
	}
	else
	{
		glOrtho(-100 * fAspect, 100 * fAspect, -100, 100, -100, 100);
	}
	// Modelview matrix reset  
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//开启反走样    
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

}


/*void drawString(const char* str) //屏幕显示字体    
{
	static int isFirstCall = 1;
	static GLuint lists;

	if (isFirstCall) {
		isFirstCall = 0;
		// 申请MAX_CHAR个连续的显示列表编号    
		lists = glGenLists(MAX_CHAR);
		// 把每个字符的绘制命令都装到对应的显示列表中    
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}
	// 调用每个字符对应的显示列表，绘制每个字符    
	for (; *str != '\0'; ++str) {
		glCallList(lists + *str);
	}
}*/

void selectFont(int size, int charset, const char* face) {
	HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
		charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);
	DeleteObject(hOldFont);
}

/*void menu(int index) {

	switch (select_part) {
	case Eye:
		EYE_COLOR = index;
		break;
	case Eye1:
		EYE1_COLOR = index;
		break;
	case Nose:
		NOSE_COLOR = index;
		break;
	case Crown:
		CROWN_COLOR = index;
		break;
	case Superman:
		SUPERMAN_COLOR = index;
		break;
	}

	//此处解决颜色闪烁问题  
	glutPostRedisplay();
	RenderScene();

}*/

void mySpecial(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		theta = (theta + 10);
		glutPostRedisplay();
		break;

	case GLUT_KEY_DOWN:
		theta = (theta - 10);
		glutPostRedisplay();
		break;
	}

}
void myKeyboard(unsigned char key, int x, int y) {
	switch (key)
	{

	}
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL");

	InitGL();

	glutReshapeFunc(ChangeSize);
	glutMouseFunc(MouseCallback);
	glutMotionFunc(MouseMoveCallback);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(mySpecial);
	glutDisplayFunc(RenderScene);

	/*glutCreateMenu(menu);
	glutAddMenuEntry("黑色", 0);
	glutAddMenuEntry("红色", 1);
	glutAddMenuEntry("绿色", 2);
	glutAddMenuEntry("蓝色", 3);
	glutAddMenuEntry("青色", 4);
	glutAddMenuEntry("紫色", 5);
	glutAddMenuEntry("黄色", 6);
	glutAddMenuEntry("白色", 7);

	glutAttachMenu(GLUT_RIGHT_BUTTON);*/


	glutMainLoop();

	return 0;
}