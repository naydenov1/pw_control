	
/*
	AC/DC 12V Power Supply Remote Control - (MeanWell RSP-150-12)

        This code is intended to be monitorized with screen.
          * start - will be used to put the pin 8 in low mode (start PW Supply)
          * stop - will be used to put the pin 8 in high mode (stop PW supply)
          
        By stopping the Power Supply, the HPA, its venitlator and the LNA will be also stopped.
        
	The circuit:
	* Cable from pin 8 to PW Supply RC input
	* Cable from pin GND to PW Supply RC input
        * Resistor of 10k between both cables. (pull-down)

	06 / 06 / 17
	Boyan Naydenov
        Thesis: Project for the construction of a LEO Ground Station

*/


int controlPin = 8;
String str;

void setup()
{
    pinMode(controlPin, OUTPUT); 
    Serial.begin(9600);
}

void loop()
{
    // send data only when you receive data:
    if (Serial.available() > 0) {
            // read the incoming command:
            str = Serial.readStringUntil('\n');

            // say what you got:
            Serial.print("Control command: ");
            Serial.println(str);
            Serial.println("-");
            
            if (str == "stop") {
                digitalWrite(controlPin, HIGH);
            }
            else if (str == "start") {
                digitalWrite(controlPin, LOW);
            }
            else {
              Serial.println("Command not valid, please send 'start' or 'stop'");
            }
    }
}
