#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#include <bios.h>
#include <dos.h>


void Treedfern(void)
{
 int b[100];
 register int k;
 int n, x=0, y=0, z=0, newx, newy;
 int a[4][3][4] = {{ {0,0,0,0}, {0,20,0,0}, {0,0,0,0} },
                   { {85,0,0,0}, {0,85,11,70},{0,-10,85,0}},
                   { {31,-41,0,0},{10,21,0,21},{0,0,30,0}},
                   { {-29,40,0,0},{10,19,0,56},{0,0,30,0} }};
 randomize();
 while( !bioskey(1) )
 {
  for(k=1;k<100;++k)
  {
   b[k]=random(10);
   if(b[k] > 3 ) b[k]=1;
  }
  for(k=1;k<100;++k)
  {
   newx=(a[b[k]][0][0]*x + a[b[k]][0][1]*y + a[b[k]][0][2]*z )/100 + a[b[k]][0][3];
   newy=(a[b[k]][1][0]*x + a[b[k]][1][1]*y + a[b[k]][1][2]*z )/100 + a[b[k]][1][3];
   z=(a[b[k]][2][0]*x + a[b[k]][2][1]*y + a[b[k]][2][2]*z )/100 + a[b[k]][2][3];
   x=newx;
   y=newy;
   putpixel(300-x+z,350-y,GREEN);
  }
  delay(50);
 }
}


void main ( void )
{
 int GraphDriver,GraphMode;
 GraphDriver = DETECT;

 initgraph(&GraphDriver,&GraphMode,"");

 Treedfern();

 closegraph();
}
