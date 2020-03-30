#include <cstdio>
#include<GL/gl.h>
#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

int sunstatus=1,cloudstatus=0,waterstatus=0;
float sunX=0,sunY=0,cloudX=0,cloudY=0,waterX=0,waterY=0;
int day=1;
//////draw circle starts//////
 void DrawCircle(float cx, float cy, float r, int num_segments) {

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get current angle

		float x = r * cosf(theta);//calculate x
		float y = r * sinf(theta);//calculate y

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
	glFlush();
}
//////draw circle ends//////


void movesun()
{
 //////moving sun////
    if (sunstatus == 1)
    {
            sunX -= 1.5;
            sunY += 0.5;

    }
        if(sunX<=-700)
        {
            sunX=300;
            sunY=-100;
        }
        glutPostRedisplay();

}
//////moving sun ends////
///////move wave & boat////////
void movewater()
{
    if (waterstatus ==1)
    {
        waterX += 1;
    }
    if (waterX>680)
    {
        waterX = -500;
        waterY = 0;

    }
}
///////move wave & boat ends////////
////clouds//////
void clouds() {
    glColor3ub(200, 220, 220);
	DrawCircle(100, 360, 25, 1000);
	DrawCircle(130, 360, 35, 1000);
	DrawCircle(160, 360, 25, 1000);

    glColor3ub(200, 220, 220);
	DrawCircle(170, 400, 15, 2000);
	DrawCircle(200, 400, 25, 2000);
	DrawCircle(230, 400, 15, 2000);

    glColor3ub(200, 220, 220);
	DrawCircle(300, 420, 25, 2000);
	DrawCircle(330, 420, 35, 2000);
	DrawCircle(360, 420, 25, 2000);

    glColor3ub(200, 220, 220);
	DrawCircle(400, 400, 25, 2000);
	DrawCircle(430, 400, 35, 2000);
	DrawCircle(460, 400, 25, 2000);
	glFlush();
}
/////clouds/////
//////hills/////
void hills(int x,int y,int z)
{

    //glColor3ub(0, 0, 153);
    glColor3ub(x,y,z);
    glBegin(GL_TRIANGLES);///////// gradually from left
    glVertex2i(80, 255);
    glVertex2i(120, 290);
    glVertex2i(160, 255);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(80, 255);
    glVertex2i(120, 290);

    glVertex2i(120, 290);
    glVertex2i(160, 255);
    glEnd();

    //glColor3ub(0, 0, 153);
    glColor3ub(x,y,z);
    glBegin(GL_TRIANGLES);
    glVertex2i(140, 255);
    glVertex2i(170, 280);
    glVertex2i(200, 255);
    glEnd();

    //glColor3ub(0, 0, 153);
    glColor3ub(x,y,z);
    glBegin(GL_TRIANGLES);
    glVertex2i(180, 255);
    glVertex2i(270, 320);
    glVertex2i(360, 255);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(180, 255);
    glVertex2i(270, 320);

    glVertex2i(270, 320);
    glVertex2i(360, 255);
    glEnd();

    //glColor3ub(0, 0, 153);
    glColor3ub(x,y,z);
    glBegin(GL_TRIANGLES);
    glVertex2i(260, 255);
    glVertex2i(320, 300);
    glVertex2i(380, 255);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(260, 255);
    glVertex2i(320, 300);

    glVertex2i(320, 300);
    glVertex2i(380, 255);
    glEnd();

    //glColor3ub(0, 0, 153);
    glColor3ub(x,y,z);
    glBegin(GL_TRIANGLES);
    glVertex2i(370, 255);
    glVertex2i(420, 275);
    glVertex2i(470, 255);

    glEnd();
    glFlush();
}
//////////
////////move clouds///

void movecloud()
{
	if (cloudstatus == 1)
        {
            cloudX +=0.3;
        }
	if (cloudX>680)
        {
            cloudX = -500;
            cloudY =0;
        }
}
/////////this side tree/////////////
void trees()
{
    //////////////////////////////////////pata
    glColor3ub (51, 204, 51);
    DrawCircle(50, 280, 50, 2000);//1
    DrawCircle(50, 320, 35, 3000);//1
    glEnd();
    glFlush();
    ////////////////////////////////majher daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(40, 155);
    glVertex2i(60, 155);
    glVertex2i(60, 245);
    glVertex2i(40, 245);
    glEnd();
    //////////////////////////////////bam daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(40, 245);
    glVertex2i(50, 245);
    glVertex2i(40, 270);
    glVertex2i(30, 270);
    glEnd();
    /////////////////////////////////right daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(50, 245);
    glVertex2i(60, 245);
    glVertex2i(70, 270);
    glVertex2i(60, 270);
    glEnd();
    glFlush();
    /////////////////////////////////////////////////tree shadow
        /////////////////////tree shadow
    glColor3ub (79, 214, 72);
    glBegin(GL_QUADS);
    glVertex2i(15, 120);
    glVertex2i(35, 120);
    glVertex2i(55, 155);
    glVertex2i(40, 155);
    glEnd();

    glColor3ub (79, 214, 72);
    DrawCircle(20,100,30,1000);
    glEnd();
}
//////////////////////rivers oposite side village
void oposite_village(int x,int y,int z)
{
    //////////////////////tree 1st/////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(110, 255);
    glVertex2i(110, 270);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(110, 270, 5, 5000);//1
    DrawCircle(110, 274, 3, 5000);//1
    glEnd();
    glFlush();
        //////////////////////tree 2nd////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(200, 255);
    glVertex2i(200, 270);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(200, 270, 5, 5000);//1
    DrawCircle(200, 274, 3, 5000);//1
    glEnd();
    glFlush();
    //////////////////////tree 3rd//////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(250, 255);
    glVertex2i(250, 275);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(250, 275, 5, 5000);
    DrawCircle(250, 279, 3, 6000);
    glEnd();
    glFlush();
    ///////////////////////tree 4th///////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(270, 255);
    glVertex2i(270, 275);
    glEnd();

   // glColor3ub (51, 204, 51);
   glColor3ub (x, y, z);
    DrawCircle(270, 275, 5, 5000);//1
    DrawCircle(270, 279, 3, 6000);//1
    glEnd();
    glFlush();
    ///////////////////////////tree 5th////////
    glColor3ub (148, 124, 84);
    glBegin(GL_LINES);
    glVertex2i(300, 255);
    glVertex2i(300, 275);
    glEnd();

    //glColor3ub (51, 204, 51);
    glColor3ub (x, y, z);
    DrawCircle(300, 275, 5, 6000);
    DrawCircle(300, 279, 3, 6000);
    glEnd();
    glFlush();
    ///////////////////////house 1st//////
    glColor3ub (181, 158, 90);
    glBegin(GL_POLYGON);//roof
    glVertex2i(150, 260);
    glVertex2i(165, 260);
    glVertex2i(163, 265);
    glVertex2i(152, 265);
    glEnd();

    glColor3ub(153, 153, 153);
    glBegin(GL_QUADS);//body
    glVertex2i(152, 255);
    glVertex2i(163, 255);
    glVertex2i(163, 260);
    glVertex2i(152, 260);
    glEnd();
    glFlush();
    ///////////////////////////house 2nd///////
    glColor3ub (181, 158, 90);
    glBegin(GL_POLYGON);//roof
    glVertex2i(220, 260);
    glVertex2i(235, 260);
    glVertex2i(233, 265);
    glVertex2i(222, 265);
    glEnd();

    glColor3ub(153, 153, 153);
    glBegin(GL_QUADS);//body
    glVertex2i(222, 255);
    glVertex2i(233, 255);
    glVertex2i(233, 260);
    glVertex2i(222, 260);
    glEnd();
    glFlush();
}

void wave()
{
        /////wave////////////////
    glColor3ub (169, 242, 242);
    glBegin(GL_LINES);
    glVertex2i(200, 220);
    glVertex2i(220, 220);

    glVertex2i(210, 230);
    glVertex2i(220, 230);

    glVertex2i(300, 220);
    glVertex2i(320, 220);

    glVertex2i(400, 220);
    glVertex2i(420, 220);

    glVertex2i(100, 240);
    glVertex2i(120, 240);

    glVertex2i(150, 180);
    glVertex2i(150, 180);

    glVertex2i(0, 190);
    glVertex2i(10, 190);

    glVertex2i(0, 200);
    glVertex2i(10, 200);

    glVertex2i(30, 185);
    glVertex2i(40, 185);

    glVertex2i(100, 250);
    glVertex2i(125, 250);

    glVertex2i(150,240);
    glVertex2i(165,240);

    glVertex2i(90,200);
    glVertex2i(100,200);

    glVertex2i(300,190);
    glVertex2i(320,190);

    glVertex2i(270,235);
    glVertex2i(275,235);

    glVertex2i(500,200);
    glVertex2i(510,200);

    glVertex2i(600,220);
    glVertex2i(615,220);

    glVertex2i(550,200);
    glVertex2i(555,200);

    glVertex2i(520,225);
    glVertex2i(540,225);

    glVertex2i(370,215);
    glVertex2i(380,215);
    glEnd();
}
/////////////////////boat & wave/////////////////////
void boat_wave()
{
    wave();  ////just wave
    ///////////////////boat body///////////////////////
    glColor3ub (150, 129, 117);
    glBegin(GL_QUADS);
    glVertex2i(20, 220);
    glVertex2i(60, 220);
    glVertex2i(70, 230);
    glVertex2i(10, 230);
    glEnd();
    /////////////////boat ar oporer part///////////////
    glColor3ub (206, 175, 109);
    glBegin(GL_POLYGON);
    glVertex2i(27, 230);
    glVertex2i(57, 230);
    glVertex2i(57, 240);
    glVertex2i(27, 240);
    glEnd();
    //////////////pal er chera cloths///////
    glColor3ub (209, 102, 27);
    glBegin(GL_TRIANGLES);
    glVertex2i(57, 230);
    glVertex2i(90, 280);
    glVertex2i(50, 290);
    glEnd();
    /////////boat ar pal ar bamboo//////////
    glColor3ub (206, 175, 109);
    glBegin(GL_LINES);
    glVertex2i(57, 230);
    glVertex2i(73, 290);
    glEnd();
    ///////////////boat shadow////////////
    glColor3ub (149, 187, 198);
    glBegin(GL_QUADS);
    glVertex2i(15, 210);
    glVertex2i(55, 210);
    glVertex2i(60, 220);
    glVertex2i(20, 220);
    glEnd();
}
///////////////////////////water////////////
void water(int x,int y,int z)
{
    glColor3ub(x,y,z);
    glBegin(GL_QUADS);
    glVertex2i(0, 180);
    glVertex2i(640, 180);
    glVertex2i(640, 255);
    glVertex2i(0, 255);
    glEnd();
}
void line()
{
    glColor3ub (153, 153, 102);
    glBegin(GL_QUADS);
    glVertex2i(0, 50);
    glVertex2i(640, 50);
    glVertex2i(640, 60);
    glVertex2i(0, 60);
    glEnd();
}
////////land//////
void land(int x,int y,int z)
{
    glColor3ub (x,y,z);
    glBegin(GL_QUADS);
    glVertex2i(0, 60);
    glVertex2i(640, 60);
    glVertex2i(640, 180);
    glVertex2i(0, 180);
    glEnd();
}
///////land ends////////
///////tree///////////
void tree()
{
    //////////leaf///////////
    glColor3ub(58,95,11);
    DrawCircle(65,280,50,2000);
    DrawCircle(40,280,50,2000);
    DrawCircle(50,320,50,2000);
    //////////leaf ends///////////
    glColor3ub (180, 180, 40);////main guri
    glBegin(GL_QUADS);
    glVertex2i(40, 155);
    glVertex2i(60, 155);
    glVertex2i(60, 245);
    glVertex2i(40, 245);
    glEnd();
    ////////left///////////////////////////
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(40, 245);
    glVertex2i(50, 245);
    glVertex2i(40, 270);
    glVertex2i(30, 270);
    glEnd();
    ///////right /////////
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(50, 245);
    glVertex2i(60, 245);
    glVertex2i(70, 270);
    glVertex2i(60, 270);
    glEnd();
    glFlush();
}
////////tree ends/////

////////road////////////
void road()
{
    glColor3ub (153,76,0);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(640, 0);
    glVertex2i(640, 50);
    glVertex2i(0, 50);
    glEnd();
    glFlush();
    line();
    glColor3ub (0,0,0);
    glBegin(GL_LINES);
    glVertex2i(0, 5);
    glVertex2i(640, 5);
    glVertex2i(0, 15);
    glVertex2i(640, 15);
    glVertex2i(0,25);
    glVertex2i(640,25);
    glVertex2i(0,35);
    glVertex2i(640,35);
    glVertex2i(0,45);
    glVertex2i(640,45);
    glEnd();
}
///////////road/////////////
void day_night()
{
    if(day==1)
    {
        /////draw sky starts///
            glColor3ub (90, 196, 242);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(640, 255);
            glVertex2i(640, 480);
            glVertex2i(0, 480);
            glEnd();
            glFlush();
        /////draw sky ends///
          /////draw sun/////

            glPushMatrix();
            glTranslatef(sunX, sunY, 0);
            glColor3ub (225,201,34);
            DrawCircle(550, 275, 40, 1000);
            glEnd();
            glFlush();
            glPopMatrix();
        /////draw sun ends////
             movesun();
             ////clouds/////
            glPushMatrix();
            glTranslatef(cloudX, cloudY, 0);
            clouds();
            glEnd();
            glFlush();
            glPopMatrix();
            movecloud();
             ////clouds////
             /////oposite grass////
            glColor3ub (46, 148, 49);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(500, 255);
            glVertex2i(500, 258);
            glVertex2i(0, 258);
            glEnd();
            ////draw ends//////////
            hills(208,176,45);
            oposite_village(51, 204, 51);
            water(142, 227, 227);
            /////moving wave & boat//////
            glPushMatrix();
            glTranslatef(waterX, waterY, 0);
            boat_wave();
            glPopMatrix();
            glEnd();
            glFlush();
            movewater();
            /////moving wave & boat ends//////
            land(31, 242, 7);
            tree();
            road();

    }
    else
    {
        /////draw sky ////////
            glColor3ub (0, 0, 0);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(640, 255);
            glVertex2i(640, 480);
            glVertex2i(0, 480);
            glEnd();
        /////draw sky ends///
         /////draw moon/////
            glPushMatrix();
            glTranslatef(sunX, sunY, 0);
            glColor3ub (255,255,255);
            DrawCircle(550, 275, 40, 1000);
            glEnd();
            glFlush();
            glPopMatrix();
        /////draw moon ends////
            movesun();//moving moon
            //star 1
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(15,408);
            glVertex2i(10,400);
            glVertex2i(20,400);
            glVertex2i(15,397);
            glVertex2i(10,405);
            glVertex2i(20,405);
            glEnd();
             //star 2
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(35,450);
            glVertex2i(30,442);
            glVertex2i(40,442);
            glVertex2i(35,439);
            glVertex2i(30,447);
            glVertex2i(40,447);
            glEnd();
            //star 3
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(75,311);
            glVertex2i(70,303);
            glVertex2i(80,303);
            glVertex2i(75,300);
            glVertex2i(70,308);
            glVertex2i(80,308);
            glEnd();
            //star 3
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(155,350);
            glVertex2i(150,342);
            glVertex2i(160,342);
            glVertex2i(155,339);
            glVertex2i(150,347);
            glVertex2i(160,347);
            glEnd();

            //star 4
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(205,508);
            glVertex2i(200,500);
            glVertex2i(210,500);
            glVertex2i(205,497);
            glVertex2i(200,505);
            glVertex2i(210,505);
            glEnd();

            //star 5
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(315,388);
            glVertex2i(310,380);
            glVertex2i(320,380);
            glVertex2i(315,377);
            glVertex2i(310,385);
            glVertex2i(320,385);
            glEnd();
            //star6
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(375,515);
            glVertex2i(370,507);
            glVertex2i(380,507);
            glVertex2i(375,504);
            glVertex2i(370,512);
            glVertex2i(380,512);
            glEnd();
            //star7
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(415,398);
            glVertex2i(410,390);
            glVertex2i(420,390);
            glVertex2i(415,387);
            glVertex2i(410,395);
            glVertex2i(420,395);
            glEnd();

             //star8
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(475,350);
            glVertex2i(470,342);
            glVertex2i(480,342);
            glVertex2i(475,339);
            glVertex2i(470,347);
            glVertex2i(480,347);
            glEnd();

            //star9
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(525,450);
            glVertex2i(520,442);
            glVertex2i(530,442);
            glVertex2i(525,439);
            glVertex2i(520,447);
            glVertex2i(530,447);
            glEnd();
            //star10
            glColor3f(255,255,255);
            glBegin(GL_TRIANGLES);
            glVertex2i(575,398);
            glVertex2i(570,390);
            glVertex2i(580,390);
            glVertex2i(575,387);
            glVertex2i(570,395);
            glVertex2i(580,395);
            glEnd();
            glColor3f(128,128,128);
            /////oposite grass////
            glColor3ub (128,128,128);
            glBegin(GL_QUADS);
            glVertex2i(0, 255);
            glVertex2i(500, 255);
            glVertex2i(500, 258);
            glVertex2i(0, 258);
            glEnd();
            ////draw ends//////////
            hills(0,0,153);
            oposite_village(128,128,128);
            water(0,0,39.9);
            /////moving wave & boat//////
            glPushMatrix();
            glTranslatef(waterX, waterY, 0);
            wave();
            glPopMatrix();
            glEnd();
            glFlush();
            movewater();
            /////moving wave & boat ends//////
            land(5,102,8);
            tree();

    }
}


////////////////////////////////////////displayvillage function starts////////////////////////////////////////////////////////////////
void displayvillage(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    day_night();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}
////////////////////////////////////////displayvillage function ends////////////////////////////////////////////////////////////////

void myInit (void)
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
/////////////////////////////////////////keyboard function starts////////////////////////////////////////////////////////////////
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'S':
        case 's':
            sunstatus=1;
            break;
        case 'A':
        case 'a':
            sunstatus=0;
            break;
        case 'N':
        case 'n':
            day=0;
            break;
        case 'D':
        case 'd':
            day=1;
            break;
        case 'C':
        case 'c':
            cloudstatus=1;
            break;
        case 'X':
        case 'x':
            cloudstatus=0;
            break;
        case 'W':
        case 'w':
            waterstatus=1;
            break;
        case 'Q':
        case 'q':
            waterstatus=0;
            break;
    }

}
/////////////////////////////////////////keyboard function ends////////////////////////////////////////////////////////////////



int main(int argc, char** argv)
{
glutInit(&argc, argv);
//glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Rural Village Scenario");
glutPostRedisplay();
glutDisplayFunc(displayvillage); //called displayvillage() function
glutKeyboardFunc(keyboard); //called keyboard() function
myInit ();
glutMainLoop();
return 0;
}

