#include <Servo.h>
// Declare the analog joystick pins
#define joyX A0
#define joyY A1
// Declare the digital servo pins
int servo1Pin = 3;
int servo2Pin = 4;
// Create a servo objects
Servo Servo1, Servo2;

// Need to convert analog joystick input into 180 arc
// 1023 / 180 = 5.683333333333333
double analogDivider = 5.683333333333333;

// Output from reading the joystick pins
int xValue = 0;
int yValue = 0;

// servo current arc
int x = 90;
int y = 90;

void setup()
{
  // Initialise serial connection to print results
  Serial.begin(9600);
  // Connect servos
  Servo1.attach(servo1Pin);
  Servo2.attach(servo2Pin);
}

void loop()
{
  // Read analog joystick output
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);

  // Convert analog readings into 180 degree arc
  int flooredX = trunc(xValue / analogDivider);
  int flooredY = trunc(yValue / analogDivider);

  // If our new values have changed update the servo
  if (flooredX != x)
  {
    x = flooredX;
    // Invert the axis for x
    Servo1.write(180 - flooredX);
    Serial.print("x");
    Serial.print(x);
    Serial.println();
  }
  if (flooredY != y)
  {
    y = flooredY;
    Servo2.write(y);
    Serial.print("y");
    Serial.print(y);
    Serial.println();
  }
}
