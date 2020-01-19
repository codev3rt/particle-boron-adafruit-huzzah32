 /***************************************************8
 * Particle Boron using Serial1
 * 
 * Loop RX with TX to test the sketch
 ***************************************************/

#include "Particle.h"

SYSTEM_MODE(SEMI_AUTOMATIC);

int counter;

//char example1[11] = "Example(1)";
char example1[14] = ">> From Boron";

void setup()
{
  delay(1000);
  Serial.begin(9600);
  Serial1.begin(115200);

  Serial.println();
  Serial.println("Serial1 TX/Pin: " + String(TX));
  Serial.println("Serial1 RX/Pin: " + String(RX));
  Serial.println();
  Serial1.flush();
  delay(1000);
}

void loop()
{

  //Example 1
  Serial1.write(example1);
  //Serial1.print(example1);

  //Example 2
  //Serial1.write("Example(2)");
  //Serial1.print("Example(2)");

  delay(2000);

  while (Serial1.available() && counter == 0)
  {

    for (counter = 0; counter <= 12; counter++)
    {
      Serial.print(char(Serial1.read()));
      delay(100);
    }
  }

  counter = 0;
  Serial.println("\nFlushing Serial");
  Serial1.flush();
  Serial.println();
  delay(2000);
}
