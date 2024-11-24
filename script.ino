#include <NewPing.h>
#include <Servo.h>

#define trigPin 12
#define echoPin 13
#define max_distance 400

char t;

Servo myservo;
int pos = 0;
int distance;

NewPing sonar(trigPin, echoPin, max_distance);
int readPing(){
    distance = sonar.ping_cm();
    if (distance >= max_distance || distance <= 2) {
        Serial.println("Out of range");
    }
    else {
        Serial.print(distance);
        Serial.println(" cm");
        delay(250);
    }
      
    if (distance <= 20 || distance >= 2){
        Serial.print(distance);
        Serial.println(" cm");
        delay(250);
        }
    delay(250);
    return distance;
}
void setup() {
    myservo.attach(6);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    Serial.begin(9600);
}
void loop() {
    readPing();
    for (pos = 45; pos <= 135; pos += 1) {
        myservo.write(pos);              
        delay(20);                       
    }
    for (pos = 135; pos >= 45; pos -= 1) { 
        myservo.write(pos);             
        delay(20);  
    }
    if(Serial.available()){
        t = Serial.read();
        Serial.println(t);
    }
    else if(t == '1'){            //fwd
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
    }
    else if(t == '2'){            //rev
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
    }
    else if(t == '3'){            //right
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
    }
    else if(t == '4'){            //left
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
    }
    else if(t == '5'){            //spin right
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
    }
    else if(t == '6'){            //spin left
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
    }
    else if(t == '7'){            //stop
        digitalWrite(8,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);
    }
    delay(100);
}
