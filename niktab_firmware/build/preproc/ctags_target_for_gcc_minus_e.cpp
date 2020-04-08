# 1 "/home/nik/Desktop/NightmareV2/software/niktab/niktab.ino"
# 1 "/home/nik/Desktop/NightmareV2/software/niktab/niktab.ino"
void setup(){
    Serial.begin(115200);
    pinMode(2, 0x1);
    pinMode(3, 0x1);
    digitalWrite(2,0x1);
    digitalWrite(3,0x1);
    pinMode(11, 0x2);
    pinMode(12, 0x2);
    pinMode(14, 0x0);
    pinMode(15, 0x0);
    pinMode(16, 0x0);
    pinMode(17, 0x0);
}

void loop(){
    float vrx1 = (analogRead(14) / 512.0) - 1.0;
    float vry1 = (analogRead(15) / 512.0) - 1.0;
    float vrx2 = (analogRead(16) / 512.0) - 1.0;
    float vry2 = (analogRead(17) / 512.0) - 1.0;

    float angle1 = (atan2(-vrx1, -vry1) * (180/3.1415926535897932384626433832795)) + 180;
    float speed1 = (sqrt(((vrx1)*(vrx1)) + ((vry1)*(vry1)))) / 1.41;
    float angle2 = (atan2(-vrx2, -vry2) * (180/3.1415926535897932384626433832795)) + 180;
    float speed2 = (sqrt(((vrx2)*(vrx2)) + ((vry2)*(vry2)))) / 1.41;

    /*Serial.println("btn1: " + String(digitalRead(11)) + 
                  " btn2: " + String(digitalRead(12)) +
                  " vrx1: " + String(vrx1) +
                  " vry1: " + String(vry1) +
                  " vrx2: " + String(vrx2) +
                  " vry2: " + String(vry2) +
                  " angle1: " + String(angle1) +
                  " speed1: " + String(speed1) +
                  " angle2: " + String(angle2) +
                  " speed2: " + String(speed2));*/

    Serial.write(0x55);
    Serial.write(0x55);
    Serial.write((byte)(angle1 * 0.7));
    Serial.write((byte)(angle2 * 0.7));
    Serial.write((byte)(speed1 * 100));
    Serial.write((byte)(speed2 * 100));
    Serial.write((byte)digitalRead(11));
    Serial.write((byte)digitalRead(12));

    delay(2);
}
