#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

static int slices = 16;
static int stacks = 16;
int sqWid=15;
int centreX=50;
int centreY=50;
int alphaX=0;
int alphaY=0;
int phyWidth = 700;
int phyHeight = 700;
int logWidth = 100;
int logHeight = 100;
int status=0;
int mouseXX,mouseYY;
int RECTWid=10;
int cx1=50,cy1=30,cx2=50,cy2=45,cx3=50,cy3=60;
int cxx1=50,cyy1=-10,cxx2=50,cyy2=-25,cxx3=50,cyy3=-40,cxx4=50,cyy4=-55;
int score=0;
bool sqUp = true;
float sqDelta=0;
float sqDelta2=0;
int i=0,j=0,k=0,k2=0;
char equ2 [3]="";
int n1[60];
int n2[60];
int flags[60];
int scorearr[60];
char realAnswer[10]="";
char userAnswer[10]="";
char check[10]="";
int signDecision=1;
int answerDecision=1;
int myrank=1;
int sc=0;
int currentTime=0;
int totalTime=20;
int RandomTime=rand()%20;
bool freeze=false;
/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


void bubbleSort(int array[], int size) { // ----------------------------------------------- HANEEN

  // loop to access each array element
  for (int step = 0; step < size; ++step) {

    // loop to compare array elements
    for (int i = 0; i < size - step; ++i) {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] < array[i + 1]) {

        // swapping elements if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
  for(int x=0; x<size-1;x++){
    scorearr[x]=array[x+1];
  }
}


void DrawCircle(float cx, float cy, float r, int num_segments) {
glBegin(GL_POLYGON);
for (int i = 0; i < num_segments; i++) {
float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle
float x = r * cosf(theta);//calculate the x component
float y = r * sinf(theta);//calculate the y component
glVertex2f(x + cx, y + cy);//output vertex
}
glEnd();
}



void drawerect(){  // --------------------------------------------------------------------- HANEEN
glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2f(cx1-RECTWid/2-5, cy1-RECTWid/2); // x, y
glVertex2f(cx1+RECTWid/2+5, cy1-RECTWid/2); // x, y
glVertex2f(cx1+RECTWid/2+5, cy1+RECTWid/2); // x, y
glVertex2f(cx1-RECTWid/2-5, cy1+RECTWid/2); // x, y RECTWid


glEnd();
glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2f(cx2-RECTWid/2-5, cy2-RECTWid/2); // x, y
glVertex2f(cx2+RECTWid/2+5, cy2-RECTWid/2); // x, y
glVertex2f(cx2+RECTWid/2+5, cy2+RECTWid/2); // x, y
glVertex2f(cx2-RECTWid/2-5, cy2+RECTWid/2); // x, y
glEnd();
glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2f(cx3-RECTWid/2-5, cy3-RECTWid/2); // x, y
glVertex2f(cx3+RECTWid/2+5, cy3-RECTWid/2); // x, y
glVertex2f(cx3+RECTWid/2+5, cy3+RECTWid/2); // x, y
glVertex2f(cx3-RECTWid/2-5, cy3+RECTWid/2); // x, y
glEnd();
}

void specialKeyboard(int key, int x, int y) // -------------------------------------------- HANEEN
{
    if(key==GLUT_KEY_F2 && status==4){
        status=0;
        score=0;
        sqDelta2=0;
        sqDelta=0;

        //sc++;
        }
    else if(key==GLUT_KEY_F1 && status==4){
        status=3;
        score=0;
        sqDelta=0;
        sqDelta2=0;
        currentTime=0;
        strcpy(check,"");
        strcpy(userAnswer,"");
        strcpy(realAnswer,"");
        answerDecision=1;
        k=0;
        k2=0;
        freeze=false;
        myrank=1;
        //sc++;
    }
    glutPostRedisplay();
}
void mouseClick(int btn, int state, int x, int y)
{

    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
    mouseXX = x;
    mouseXX=0.5+1.0*mouseXX*logWidth/phyWidth;
    mouseYY = phyHeight - y;
    mouseYY=0.5+1.0*mouseYY*logHeight/phyHeight;
    if( mouseXX>=(cx1-RECTWid/2) && mouseXX<=(cx1+RECTWid/2) && mouseYY >=(cy1-RECTWid/2) && mouseYY <=(cy1+RECTWid/2) && status==0)
    {
    status=1;

    }
    if( mouseXX>=(cx2-RECTWid/2) && mouseXX<=(cx2+RECTWid/2) && mouseYY >=(cy2-RECTWid/2) && mouseYY <=(cy2+RECTWid/2) && status==0)
    {
    status=2;
    }
    if( mouseXX>=(cx3-RECTWid/2) && mouseXX<=(cx3+RECTWid/2) && mouseYY >=(cy3-RECTWid/2) && mouseYY <=(cy3+RECTWid/2) && status==0)
    {
    status=3;
    currentTime=0;
    strcpy(check,"");
    strcpy(userAnswer,"");
    strcpy(realAnswer,"");
    answerDecision=1;
    score=0;
    k=0;
    k2=0;
    freeze=false;
    myrank=1;
    }
    }
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN && status!=3 && status!=4)
    {
    status=0;
    sqDelta=0;
    }
    if( mouseXX>=(80-RECTWid/2) && mouseXX<=(80+RECTWid/2) && mouseYY >=(0-RECTWid/2+sqDelta*3-50*3) && mouseYY <=(0+RECTWid/2+sqDelta*3-50*3) && status==3 && freeze==false)
    {
        freeze=true;
        totalTime+=15;

    }

    glutPostRedisplay();
}



void printSome(char *str,int x,int y) { // ------------------------------------------- HANEEN & INGY
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
glFlush();
}
void printSome2(char *str,int x,int y) { // ------------------------------------------ HANEEN & INGY
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++)
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
glFlush();
}



void init2D(float r, float g, float b)
{

glClearColor(r,g,b,0.5);
glMatrixMode (GL_PROJECTION);
gluOrtho2D (0.0, 100.0, 0.0, 100.0);

}

void Timer(int value) // ----------------------------------------------- HANEEN
{
    if(value==0)
    {
       glutTimerFunc(50, Timer, value); // for animation
       glutPostRedisplay();
    }
    else if(value==2)
    {
       glutTimerFunc(100, Timer, value); //for arrays filling
       if(j<60){
       n1[j]=(rand())%10;
       n2[j]=(rand())%10;
       flags[j]=1;
       j++;
       }
    }

}

void stop1(){
    if(status==3 && currentTime>=totalTime){
        for(int x=0;x<60;x++)
            {
                if(score<scorearr[x]) myrank++;
            }
           // myrank--;
        scorearr[sc]=score;
        sc++;
        bubbleSort(scorearr,60);

        for(int x=0;x<60;x++) cout << scorearr[x] << " ";
        cout <<"\n";

        status=4;
        currentTime=0;
        k=0;
        k2=0;
    }
    else currentTime++;
}
void Timer1(int value){

        glutTimerFunc(1000, Timer1, value);
        stop1();
}


void equationsStream()
{
            for(i=0;i<60;i++){
            glColor3f(0.023, 0.035, 0.396);
            glBegin(GL_POLYGON);
            glVertex2f(cxx1-sqWid/2-5, cyy1-sqWid/2-(i*20)+sqDelta);
            glVertex2f(cxx1+sqWid/2+5, cyy1-sqWid/2-(i*20)+sqDelta);
            glVertex2f(cxx1+sqWid/2+5, cyy1+sqWid/2-(i*20)+sqDelta);
            glVertex2f(cxx1-sqWid/2-5, cyy1+sqWid/2-(i*20)+sqDelta);
            glEnd();
            glColor3f(1.0, 1.0, 1.0);
            char x1 [10];
            char x2 [10];

            char equation[30]="";
            itoa(n1[i],x1,10);
            itoa(n2[i],x2,10);
            strcat(equation,x1);
            if(signDecision==1)
            {
                strcat(equation,"+");
                signDecision=2;
            }
            else if(signDecision==2)
            {
                strcat(equation,"-");
                signDecision=3;
            }
            else if(signDecision==3)
            {
                strcat(equation,"*");
                signDecision=1;
            }
            strcat(equation,x2);
            printSome2(equation,cxx1-2, cyy1-(i*20)+sqDelta);
            }
            if (sqUp) {sqDelta+=0.3; sqDelta2+=0.3;}

            if(sqDelta2>=110)
            {
                sqDelta2-=20;
                if(flags[k2]==1)
                {
                    k++;
                    answerDecision++;
                    if(answerDecision>3) answerDecision=1;
                }
                k2++;
            }


}


void mainGame()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(48,0); // x, y
    glVertex2f(52,0); // x, y
    glVertex2f(52, 100); // x, y
    glVertex2f(48, 100); // x, y
    glEnd();
    char str [3];
    itoa(score,str,10);
    char scorestring [20] = "Score: ";
    strcat(scorestring,str);
    printSome2(scorestring,10,90);
    char strtemp [4];
    itoa(k,strtemp,10);
    printSome2(realAnswer,10,75);
    equationsStream();

    return;
}





static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.580, 0.976, 0.964);
    glVertex2f(0,0); // x, y
    glColor3f(0.580, 0.976, 0.964);
    glVertex2f(100, 0); // x, y
    glColor3f(0.023, 0.035, 0.396);
    glVertex2f(100, 100); // x, y
    glColor3f(0.023, 0.035, 0.396);
    glVertex2f(0, 100); // x, y
    glEnd();

    if(status==0){ // main page // ------------------------------------ HANEEN
    k=0;
    k2=0;
    strcpy(check,"");
    strcpy(userAnswer,"");
    strcpy(realAnswer,"");
    answerDecision=1;
    score=0; ////////////////////////////////////////////////////////////////////////////////////////
    j=0;
    Timer(2);
    glColor3f(1.0f,1.0f,1.0f);
    printSome2("MATH HERO",40,90);
    drawerect();
    glColor3f(0.023, 0.035, 0.396);
    printSome("Start",cx3-3,cy3);
    printSome("Scores",cx2-4,cy2);
    printSome("Exit",cx1-2,cy1);}


    else if(status==1) { // Exit // ------------------------------------------ HANEEN
    exit(0);
    glEnd();
    }
    else if(status==2) { // Scores
    char displayscore [10]="";
    char displaytemp [10]="";
    glColor3f(1.0f,1.0f,1.0f);
    printSome2("HIGH SCORES",40,80);
          for(int n=0;n<5;n++)
        {
            itoa((n+1),displayscore,10);
            strcat(displayscore,"-   ");
            itoa(scorearr[n],displaytemp,10);
            strcat(displayscore,displaytemp);
            printSome2(displayscore,30,(65-n*5));
        }

    }
    else if(status==3) { // Start (main game)

    mainGame();
    printSome2(userAnswer,10,50);
    printSome2(check,10,40);
                    char abos2edk[10];
                    itoa(currentTime,abos2edk,10);
                    printSome2("Time: ",10,80);
                    printSome2(abos2edk,20,80);
    if(currentTime>= RandomTime && currentTime < 60){
            if(!freeze){
            glColor3f(0.023, 0.396,0.035);
            glBegin(GL_POLYGON);
            glVertex2f(80-RECTWid/2, 0-RECTWid/2+sqDelta*3-50*3);
            glVertex2f(80+RECTWid/2, 0-RECTWid/2+sqDelta*3-50*3);
            glVertex2f(80+RECTWid/2, 0+RECTWid/2+sqDelta*3-50*3);
            glVertex2f(80-RECTWid/2, 0+RECTWid/2+sqDelta*3-50*3);
            glEnd();
            }

        }

    }
    else if(status==4) { // my score and rank // ---------------------------------- HANEEN
    k=0;
    k2=0;
    strcpy(check,"");
    strcpy(userAnswer,"");
    strcpy(realAnswer,"");
    j=0;
    Timer(2);


    glColor3f(1.0f,1.0f,1.0f);
    char strx [3];
    itoa(score,strx,10);
    char scorestringx [20] = " Your SCORE is: ";
    strcat(scorestringx,strx);
    printSome2(scorestringx,40,60);
    char stry [3];
    itoa(myrank,stry,10);
    char scorestringy [20] = " Your RANK is: ";
    strcat(scorestringy,stry);
    printSome2(scorestringy,40,55);
    }


    glutSwapBuffers();
    glFlush();
}



void keyboard(unsigned char key, int x, int y)
{
    if(answerDecision==1){
    int tempanswer = n1[k]+n2[k];
    itoa(tempanswer,realAnswer,10);
    }
    else if(answerDecision==2){
    int tempanswer = n1[k]-n2[k];
    itoa(tempanswer,realAnswer,10);
    }
    else if(answerDecision==3){
    int tempanswer = n1[k]*n2[k];
    itoa(tempanswer,realAnswer,10);
    }

    if(strcmp(userAnswer,realAnswer)==0 && key==13){
        score++;
        strcpy(check,"CORRECT!");
        strcpy(userAnswer,"");
        flags[k]=0;
        k++;
        answerDecision++;
        if(answerDecision>3) answerDecision=1;

    }
    else if(key==13)
    {
        strcpy(check,"NOT CORRECT");
        strcpy(userAnswer,"");
    }
    else
    {
    char key1[10]="";
    key1[0]=key;
    strcat(userAnswer,key1);
    }
    glutPostRedisplay();
}



static void idle(void)
{
    glutPostRedisplay();
}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Math Hero"); // window title
    init2D(0.0,0.0,0.0);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeyboard);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseClick);
    Timer(0);
    //Timer(2);
    Timer1(0);
    glutMainLoop();

    return EXIT_SUCCESS;
}
