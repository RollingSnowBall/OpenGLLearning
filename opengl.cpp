#include <GL/glut.h>
#include <iostream>

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0);//设置白色窗口，

    //使用正投影将世界坐标系二维矩形区域的内容映射到屏幕上
    //因为下面要画二维图形，所以正投影将图形贴到窗口上
    glMatrixMode(GL_PROJECTION);

    //区域x的坐标值从0到200，y的坐标值从0到150
    //0,0为左下角，200，150为右上角
    gluOrtho2D(0, 100, 0, 50);//
}

void DisplayCB(void)
{
    glClear(GL_COLOR_BUFFER_BIT);//指定颜色缓存中的位值

    //画线
    glColor3f(1, 0, 0);//设置颜色

    //图元类型，begin和end之间必须有glVertex
    glBegin(GL_TRIANGLES);

    glVertex2i(0, 50);
    glVertex2i(50, 0);
    glVertex2i(100, 50);

    glEnd();

    //强制执行由计算机系统存放在缓存中不同位置的OpenGL函数
    //例如繁忙的网络中，可能因处理某些缓存出现延缓现象
    //该函数可以强制清空所有缓存来处理OpenGL函数
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("First Window");

    init();

    //DisplayCB，显示回调函数
    //窗口需要重新显示时来调用
    glutDisplayFunc(DisplayCB);
    glutMainLoop();
}