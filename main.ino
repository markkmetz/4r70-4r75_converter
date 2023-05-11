unsigned long time;
bool OSS_High = 0;
bool readings [10];

int currentreading = 0;
bool Last_Read = 0;
int OSS_Pin = 0;
int OSS_Count = 0;

void setup() {
  pinMode(OSS_Pin,INPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop() {  

  read();

}

void read(){
int sumofreadings = 0;
readings[currentreading] = digitalRead(OSS_Pin);

for(int i = 0; i < 10; i++){
  sumofreadings += readings[i];
}

if(sumofreadings == 10 && OSS_High == 0 )
{
  OSS_Count++;
  OSS_High = 1;
}
else if(sumofreadings == 0 && OSS_High == 1 ) 
{
  OSS_High = 0;
}

if(OSS_Count > 3){
  OSS_Count = 0;
}

currentreading++;
if(currentreading > 9){
  currentreading = 0;
}
  
if(OSS_Count == 1){
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
}else if(OSS_Count == 2){
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
}else {
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
}

}

void test (){
  delay(100);
  digitalWrite(1,LOW);
  digitalWrite(2,HIGH);
  delay(100);
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
}
