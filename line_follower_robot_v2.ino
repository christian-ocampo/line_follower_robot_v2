// sets the motor pins to their respective pins.
int motor1pin1 = 1;
int motor1pin2 = 2;
int motor2pin1 = 3;
int motor2pin2 = 4;
int enb = 9;

int ir_left_pin = 5; // sets left ir sensor to pin 5.
int ir_right_pin = 6; // sets right ir sensor to pin 6.

void setup() {
  // configure the motor pins as output.
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(enb, OUTPUT);

  pinMode(ir_left_pin, INPUT); // left ir sensor initialized as input.
  pinMode(ir_right_pin, INPUT); // right ir sensor initialized as input.
}

void loop() {
  digitalWrite(enb, HIGH);
  int ir_left = digitalRead(ir_left_pin);
  int ir_right = digitalRead(ir_right_pin);

  // if both sensors detect a white surface, move forward.
  if (ir_left == 0 && ir_right == 0) {
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor2pin2, HIGH);
    }
   // if only the right sensor detects a black surface, move to the right.
   else if (ir_left == 1 && ir_right == 0) {
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
   }
   // if only the left sensor detects a black surface, move to the left.
   else if (ir_left == 0 && ir_right == 1) {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor2pin2, HIGH);    
   }
   // if both sensors detect a black surface, stop the robot.
   else {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor2pin2, LOW);
   }
  }
