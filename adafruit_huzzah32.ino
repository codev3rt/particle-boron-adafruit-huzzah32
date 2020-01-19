/*****************************************************************************
 * Serial Communication between Adafruit Huzzah32 and Particle Boron
 * Upload this sketch to Adafruit Huzzah32
 * You can loop pin TX with RX to test it on Adafruit Huzzah32 itself
 *
 * Using Serial2
 * PIN RX = 16
 * PIN TX = 17
*****************************************************************************/

#define RXD2 16
#define TXD2 17

int counter;
//char example1[11] = "Example(1)";
char example1[14] = ">> From ESP32";

void setup()
{
  delay(1000);
  Serial.begin(9600);
  Serial2.begin(115200);

  Serial.println();
  Serial.println("Serial1 TX/Pin: " + String(TX));
  Serial.println("Serial1 RX/Pin: " + String(RX));
  Serial.println("Serial2 RX/Pin: " + String(RXD2));
  Serial.println("Serial2 TX/Pin: " + String(TXD2));
  Serial.println();
  Serial2.flush();
  delay(1000);
}

void loop()
{

  //Example 1
  Serial2.write(example1);
  //Serial1.print(example1);

  //Example 2
  //Serial1.write("Example(2)");
  //Serial1.print("Example(2)");

  delay(2000);
  while (Serial2.available() && counter == 0)
  {

    for (counter = 0; counter <= 12; counter++)
    {
      Serial.print(char(Serial2.read()));
      delay(100);
    }
  }

  counter = 0;
  Serial.println("\nFlushing Serial");
  Serial2.flush();
  Serial.println();
  delay(2000);
}
