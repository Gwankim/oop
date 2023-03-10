float s,x,y;
void setup(){
  size(1000,1000);
  x=400;
  y= 100;
  s= 1000;
  face();
  x= 400;
  y= 100;
  s= 1000;
  body();
  x= 100;
  y= 100;
  s= 100;
  arm();
  x = 100;
  y = 100;
  s = 100;
  leg();
}
void face(){
   s = s * 0.2;
   fill(200,100,0);
  square(x,y,s);//s=200, x= 400, y =100;
  x += 50;
  y += 50;
  s = s * 0.15;
  fill(0,0,0);
  circle(x,y,s);
  x += 100;
  circle(x,y,s);
  x -= 50;
  y += 100;
  s = s*2;
  circle(x,y,s);
}
void body(){
  x -= 100;
  y += 350;
  s = s * 0.4;
  fill(0,0,200);
  square(x,y,s); // x = 300 , y = 450, s = 400;
  x += 150;
  y -= 150;
  fill(0,0,250);
  rect(x,y,s*0.25,s*150/400);
}
void arm(){
  float s1, s2;
  y = y  * 5.5;
  s1 = s * 2;
  s2 = s;
  fill(0,200,0);
  rect(x,y,s1,s2);
  x += 600;
  rect(x,y,s1,s2);
}
void leg(){
  x = x * 3.8;
  y = y * 8.5;
  float s1, s2;
  s1 = s * 0.8;
  s2 = s * 1.2;
  fill(250,250,100);
  rect(x,y,s1,s2);
  x += 150;
  rect(x,y,s1,s2);
}
