int p1=1,p2=2,p3=3,p4=9,p5=10,p6=11;
void pin_set(){
  pinMode(p1,OUTPUT);
  pinMode(p2,OUTPUT);
  pinMode(p3,OUTPUT);
  pinMode(p4,OUTPUT);
  pinMode(p5,OUTPUT);
  pinMode(p6,OUTPUT);
}
void car_forward(){
  digitalWrite(p1,HIGH);
 digitalWrite(p2,LOW);
 digitalWrite(p3,HIGH);
 digitalWrite(p4,LOW);
 digitalWrite(p5,LOW);
 digitalWrite(p6,LOW);
}
void car_backward(){
  digitalWrite(p1,LOW);
 digitalWrite(p2,HIGH);
digitalWrite(p3,LOW);
 digitalWrite(p4,HIGH);
  digitalWrite(p5,LOW);
 digitalWrite(p6,LOW);
}
void car_stop(){
  digitalWrite(p1,LOW);
 digitalWrite(p2,LOW);
digitalWrite(p3,LOW);
digitalWrite(p4,LOW);
 digitalWrite(p5,LOW);
 digitalWrite(p6,LOW);
}
void car_left(){
  digitalWrite(p1,LOW);
digitalWrite(p2,HIGH);
digitalWrite(p3,HIGH);
digitalWrite(p4,LOW);
 digitalWrite(p5,LOW);
 digitalWrite(p6,LOW);
}
void car_right(){
  digitalWrite(p1,HIGH);
digitalWrite(p2,LOW);
 digitalWrite(p3,LOW);
 digitalWrite(p4,HIGH);
  digitalWrite(p5,LOW);
 digitalWrite(p6,LOW);
}
void car_sweep(){
  digitalWrite(p1,LOW);
digitalWrite(p2,LOW);
 digitalWrite(p3,LOW);
 digitalWrite(p4,LOW);
  digitalWrite(p5,HIGH);
 digitalWrite(p6,LOW);
}
void car_heat(){
  digitalWrite(p1,LOW);
digitalWrite(p2,LOW);
 digitalWrite(p3,LOW);
 digitalWrite(p4,LOW);
  digitalWrite(p5,LOW);
 digitalWrite(p6,HIGH);
}
#include <SoftwareSerial.h>
SoftwareSerial BT(8, 9);  //新建对象，接收脚为8，发送脚为9
char val='0';  //存储接收的变量
void setup() {
 Serial.begin(9600);   //与电脑的串口连接
  Serial.println("BT is ready!");
 BT.begin(9600);  //设置蓝牙模块波特率
 }
 void loop() {
 //如果串口接收到数据，就输出到蓝牙串口
 if (Serial.available()) {
  val= Serial.read();
  BT.print(val);}
 //如果接收到蓝牙模块的数据，输出到屏幕
 if (BT.available()) {
 val= BT.read();
 Serial.print(val);}
 
if(Serial.available()>0)
{
char val=Serial.read(); //读入接收的信号值
if(val=='1'){
  car_forward();
}
else if(val=='2'){
  car_backward();
}
else if(val=='3'){
  car_left;
}
else if(val=='4'){
  car_right;
}
else if(val=='5'){
  car_stop();
}
else if(val=='6'){
  car_sweep();
  }
else if(val=='7'){
  car_heat();
  
}
}
}
