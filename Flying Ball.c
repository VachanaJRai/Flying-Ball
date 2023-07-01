#include <stdarg.h>
#include <GL/glut.h>
#include <stdio.h>

GLfloat x = 0.5;
GLint submenu1, submenu2;
int count1 = 0, count2 = 0;

void stroke_output(GLfloat x, GLfloat y, char* format, ...)
{
    va_list args;
    char buffer[200], *p;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);
    glPushMatrix();
    glTranslatef(-3.2, y, 0);
    glScaled(0.003, 0.002, 0.000);
    for (p = buffer; *p; p++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
    glPopMatrix();
}

void d4()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2, 0.4, 0.3, 1.0);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -13.0f);
    stroke_output(-2.0, 3.0, " INSTRUCTIONS ");
    stroke_output(-2.0, 2.5, " i:increment ");
    stroke_output(-2.0, 2.0, " d:decrement ");
    stroke_output(-2.0, 1.5, " Press 'b' to next");
    glFlush();
    glutSwapBuffers();
}

void d6()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 0.0, 1.0, 1.0);
    glFlush();
    glutSwapBuffers();
}

void d7()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 1.0, 1.0, 1.0);
    glFlush();
    glutSwapBuffers();
}

void d8()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.3, 1.5, 0.5, 1.0);
    glFlush();
    glutSwapBuffers();
}

void flying(double ang)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, -0.5, -13.0);
    glRotatef(115, 1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(ang, 0.0, 0.0, 1.0);
    glScaled(2.9, 0.2, 0.1);
    glTranslatef(0.0, 0.0, 10.0);
    glColor3f(0.5, 0.0, 0.0);
    glRotatef(ang, 0.0, 0.0, 1.0);
    glutSolidSphere(0.7, 20, 60);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glRotatef(ang, 0.0, 0.0, 1.0);
    glScaled(0.2, 2.9, 0.1);
    glTranslatef(0.0, 0.0, 10.0);
    glRotatef(ang, 0.0, 0.0, 1.0);
    glutSolidSphere(0.7, 20, 60);
    glPopMatrix();
    glPushMatrix();
    glRotatef(ang + 50, 0.0, 0.0, 1.0);
    glScaled(2.9, 0.2, 0.1);
    glTranslatef(0.0, 0.0, 10.0);
    glRotatef(ang + 50, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(0.7, 20, 60);
    glPopMatrix();
    glPushMatrix();
    glRotated(ang, 0.0, 1.0, 0.0);
    glTranslatef(0.05, -4.0, 1.0);
    glRotated(ang, 0.0, 1.0, 0.0);
    glutSolidSphere(0.3, 20, 60);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.5, 0.5, 1.5);
    glRotated(ang, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 1.6, 0.0);
    glRotated(ang, 0.1, 3.0, 0.0);
    glutSolidSphere(0.15, 20, 60);
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void fly()
{
    x += 6;
    flying(x);
}

void slow()
{
    x += 0.03;
    flying(x);
}

void fast()
{
    x += 15;
    flying(x);
}

void fly1()
{
    x += 8;
    flying(x);
}

void fly2()
{
    x += 10;
    flying(x);
}

void fly3()
{
    x += 12;
    flying(x);
}

void fly4()
{
    x += 14;
    flying(x);
}

void flyd()
{
    x += 6;
    flying(x);
}

void flyd1()
{
    x += 7;
    flying(x);
}

void flyd2()
{
    x += 8;
    flying(x);
}

void flyd3()
{
    x += 9;
    flying(x);
}

void flyd4()
{
    x += 11;
    flying(x);
}

void nofly()
{
    flying(0);
}

void Init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (GLfloat)500 / (GLfloat)500, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.5, 0.5, 1.9);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -13.0f);
    stroke_output(-2.0, 3.0, " *WEL-COME* ");
    stroke_output(-2.0, 2.5, " To ");
    stroke_output(-2.0, 2.0, " CGV MINIPROJECT ");
    stroke_output(-2.0, 1.5, " Project Name: FLYING BALL ");
    stroke_output(-2.0, 0.5, " Project Created By: ");
    stroke_output(-2.0, -0.1, " Name: Vachana J Rai");
    stroke_output(-2.0, -0.6, " USN: 1TJ19CS081");
    stroke_output(-2.0, -1.3, " Name: Sankalp M R");
    stroke_output(-2.0, -1.7, " USN: 1TI18CS086");
    stroke_output(-2.0, -3.3, " press '2' to next");
    glFlush();
    glutSwapBuffers();
}

void Menu(int id)
{
    switch (id)
    {
    case 1:
        exit(0);
        break;
    }
}

void flying_ball(int id)
{
    switch (id)
    {
    case 2:
        glutIdleFunc(fly);
        glutPostRedisplay();
        break;
    case 3:
        glutIdleFunc(nofly);
        glutPostRedisplay();
        break;
    case 0:
        glutIdleFunc(slow);
        glutPostRedisplay();
        break;
    case 9:
        glutIdleFunc(fast);
        glutPostRedisplay();
        break;
    }
}

void Color(int id)
{
    switch (id)
    {
    case 4:
        glutIdleFunc(d6);
        glutPostRedisplay();
        break;
    case 5:
        glutIdleFunc(d7);
        glutPostRedisplay();
        break;
    case 6:
        glutIdleFunc(d8);
        glutPostRedisplay();
        break;
    }
}

void mykey(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
    {
        exit(0);
    }
    if (key == '2')
    {
        glutIdleFunc(d4);
    }
    if (key == 'b')
    {
        glutIdleFunc(fly);
    }
    if (key == 'B')
    {
        glutIdleFunc(nofly);
    }
    if (key == 'i' || key == 'I')
    {
        count1 = count1 + 1;
        if (count1 == 1)
            glutIdleFunc(fly1);
        if (count1 == 2)
            glutIdleFunc(fly2);
        if (count1 == 3)
            glutIdleFunc(fly3);
        if (count1 == 4)
            glutIdleFunc(fly4);
    }
    if (key == 'd' || key == 'D')
    {
        count1 = count1 - 1;
        if (count1 == 4)
            glutIdleFunc(flyd4);
        if (count1 == 3)
            glutIdleFunc(flyd3);
        if (count1 == 2)
            glutIdleFunc(flyd2);
        if (count1 == 1)
            glutIdleFunc(flyd1);
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Flying ball");
    glutDisplayFunc(Display);
    glutKeyboardFunc(mykey);
    submenu1 = glutCreateMenu(flying_ball);
    glutAddMenuEntry("fly", 2);
    glutAddMenuEntry("nofly", 3);
    glutAddMenuEntry("slow", 0);
    glutAddMenuEntry("fast", 9);
    submenu2 = glutCreateMenu(Color);
    glutAddMenuEntry("pink", 4);
    glutAddMenuEntry("blue", 5);
    glutAddMenuEntry("green", 6);
    glutCreateMenu(Menu);
    glutAddSubMenu("flying_ball", submenu1);
    glutAddSubMenu("Color", submenu2);
    glutAddMenuEntry("Quit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    Init();
    glutMainLoop();
    return 0;
}
