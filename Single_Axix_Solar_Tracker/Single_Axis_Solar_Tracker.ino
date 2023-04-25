/*The source code from
 * Md. Riyad Hasan
 * www.github.com/riyadhasan24
*/

#include <Servo.h>
Servo MyServo;

#define LDR_1 A0
#define LDR_2 A1

int Value_1;
int Value_2;
int Position = 90;
int Tolerance = 15;
   
void setup()
{
  MyServo.attach(2);
  MyServo.write(Position);
  pinMode(LDR_1, INPUT);
  pinMode(LDR_2, INPUT);
  delay(1000);
}
void loop()
{      
  Value_1 = analogRead(LDR_1);
  Value_2 = analogRead(LDR_2);
        
  if((abs(Value_1 - Value_2) <= Tolerance) || (abs(Value_2 - Value_1) <= Tolerance))
  {
    // No command.....
  }
  
  else 
  {
    if(Value_1 > Value_2)
    {
    Position = Position + 1;
    }
    
    if(Value_1 < Value_2)
    {
    Position = Position - 1;
    }
  }
       
  if(Position > 180) 
  {
    Position = 180;
  }
  if(Position < 0) 
  {
    Position = 0;
  }
  
  MyServo.write(Position);
  delay(50);

}
