/*******************************

  Motor  driver definitions
  
*******************************/
//Motor pin define 
const int A_IN1 = 39;
const int A_IN2 = 40;
const int A_PWM = 8;  //A_WHEEL

const int B_IN1 = 52;
const int B_IN2 = 53;
const int B_PWM = 7;

const int C_IN1 = 26;
const int C_IN2 = 27;
const int C_PWM = 6;

boolean direcA = false;
boolean direcB = false;
boolean direcC = false;


/*
 * get wheel run direction
*/

boolean directionWheel(int wheel) 
{
  if (wheel == A_WHEEL) 
  {
    return direcA;
  }
  else if (wheel == B_WHEEL)
  {
    return direcB;
  }
   else  (wheel == C_WHEEL)
  {
    return direcC;
  }
}

/* Wrap the motor driver initialization,
   set all the motor control pins to outputs **/
void initMotorController()
{
  pinMode(A_IN1, OUTPUT);
  pinMode(A_IN2, OUTPUT);
  pinMode(A_PWM, OUTPUT);

  pinMode(B_IN1, OUTPUT);
  pinMode(B_IN2, OUTPUT);
  pinMode(B_PWM, OUTPUT);

  pinMode(C_IN1, OUTPUT);
  pinMode(C_IN2, OUTPUT);
  pinMode(C_PWM, OUTPUT);


}

/* Wrap the drive motor set speed function */
void setMotorSpeed(int wheel, int spd)
{
  if (spd > MAX_PWM) 
  {
    spd = MAX_PWM;
  }
  if (spd < -MAX_PWM) 
  {
    spd = -1 * MAX_PWM;
  }

  if (wheel == A_WHEEL)
  {
    if (spd >= 0) 
    {
      direcA = FORWARDS;
      digitalWrite(A_IN1, HIGH);
      digitalWrite(A_IN2, LOW);
      analogWrite(A_PWM, spd);
    }
    else if (spd < 0) 
    {
      direcA = BACKWARDS;
      digitalWrite(A_IN1, LOW);
      digitalWrite(A_IN2, HIGH);
      analogWrite(A_PWM, -spd);
    }
  }
  else if (wheel == B_WHEEL)
  {
    if (spd >= 0) 
    {
      direcB = FORWARDS;
      digitalWrite(B_IN1, HIGH);
      digitalWrite(B_IN2, LOW);
      analogWrite(B_PWM, spd);
    }
    else if (spd < 0) 
    {
      direcB = BACKWARDS;
      digitalWrite(B_IN1, LOW);
      digitalWrite(B_IN2, HIGH);
      analogWrite(B_PWM, -spd);
    }
  }
  else  (wheel == C_WHEEL)
  {
    if (spd >= 0) 
    {
      direcC = FORWARDS;
      digitalWrite(C_IN1, HIGH);
      digitalWrite(C_IN2, LOW);
      analogWrite(C_PWM, spd);
    }
    else if (spd < 0) 
    {
      direcC = BACKWARDS;
      digitalWrite(C_IN1, LOW);
      digitalWrite(C_IN2, HIGH);
      analogWrite(C_PWM, -spd);
    }
  }
  
}

// A convenience function for setting both motor speeds
void setMotorSpeeds(int ASpeed, int BSpeed, int CSpeed,int DSpeed)
{
  setMotorSpeed(A_WHEEL, ASpeed);
  setMotorSpeed(B_WHEEL, BSpeed);
  setMotorSpeed(C_WHEEL, CSpeed);
}

