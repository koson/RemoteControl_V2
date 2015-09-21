// Infrared Remoe Control
// Work with Hitachi Remote and 4 digit & segments display.
//





//#include "test.h"
#include "RELAY.h"
#include <IRDecode.h>
#include <Wire.h>
#include <TPIC6B595.h>
#include <config.h>
#include <IRremoteInt.h>
#include <IRremote.h>
#include <SWHandler.h>
#include <LEDhandler.h>
#include <LED.h>
#include "HardwareSerial.h"
#include <Seg7.h> 
int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int dataPin = 9;
const int dataClock = 10;
const int latchClock = 11;
const int dataClear = 7;
const int TPIC_CS = 8;




TPIC6B595 TPIC1(dataPin, dataClock, latchClock, dataClear);



int  counting_mode = 0;
RELAYClass  relay1;
RELAYClass  relay2;
RELAYClass  relay3;
RELAYClass  relay4;
RELAYClass  relay5;
RELAYClass  relay6;
RELAYClass  relay7;
RELAYClass  relay8;
unsigned char OutputValue = 0;
void setup()
{
	Serial.begin(9600);
	irrecv.enableIRIn(); // Start the receiver
	Serial.print("Hello");
	relay1.init(11);
	relay2.init(10);
	relay3.init(9);
	relay4.init(8);
	relay5.init(7);
	relay6.init(6);
	relay7.init(5);
	relay8.init(4);


	//TPIC1.begin();
	//TPIC1.write(OutputValue);
}




void loop()
{
	//unsigned long currentMillis = millis();
	//if (currentMillis - previousMillis > perDigitTime)
	//{
	//	previousMillis = currentMillis;
	//	if(counting_mode == 1)
	//		value++;
	//	if( counting_mode == -1   )
	//	{
	//		if(value == 0)
	//			counting_mode = 0;
	//		else
	//			value--;
	//	}
	//}
	//RefreshDisplay();
	resultDecode(results);

}

void resultDecode(decode_results &results)
{
	if (irrecv.decode(&results))
	{
		//Serial.println(results.value, HEX);
		switch (results.value)
		{
			// Hitachi
		case 0xEECFD03F:
			Serial.println("Power");
			break;
		case 0x6820D9DB:
			Serial.println("Mute");
			break;
		case 0x83AC8803:
		case 0x9716BE3F:
			relay1.Toggle();
			Serial.println("[1]");
			break;
		case 0xD7AC799B:
		case  0x3D9AE3F7:
			relay2.Toggle();
			Serial.println("[2]");
			break;
		case 0xC891B41F:
		case 0x6182021B:
			relay3.Toggle(); 
			Serial.println("[3]");
			break;
		case 0xDB77AE7B:
		case 0x8C22657B:
			relay4.Toggle();
			Serial.println("[4]");
			break;
		case 0x3525067F:
		case 0x488F3CBB:
			relay5.Toggle();
			Serial.println("[5]");
			break;
		case 0x8924F817:
		case 0x449E79F:
			relay6.Toggle();
			Serial.println("[6]");
			break;
		case 0x7A0A329B:
		case 0x32C6FDF7:
			relay7.Toggle();
			Serial.println("[7]");
			break;
		case 0xE4CCAEDB:
		case 0x1BC0157B:
			relay8.Toggle();
			Serial.println("[8]");
			break;
		case 0x3E7A06DF:
		case 0x3EC3FC1B:
			relay1.ON();
			relay2.ON();
			relay3.ON();
			relay4.ON();
			relay5.ON();
			relay6.ON();
			relay7.ON();
			relay8.ON();
			Serial.println("9");
			break;
		case 0x9279F877:
		case 0xC101E57B:
			relay1.OFF();
			relay2.OFF();
			relay3.OFF();
			relay4.OFF();
			relay5.OFF();
			relay6.OFF();
			relay7.OFF();
			relay8.OFF();
			Serial.println("0");
			counting_mode = 0;
			break;
		case 0x835F32FB:
			Serial.println("1*");
			break;
		case 0x29FF2FFF:
			Serial.println("2*");
			break;
		case 0x2A30ADBB:
			Serial.println("P+");
			break;
		case 0xD08355B7:
			Serial.println("P-");
			break;
		case 0x86603777:
			Serial.println("V+");
			//value ++;
			counting_mode = 1;
			break;
		case 0x36B15F9B:
			Serial.println("V-");
			counting_mode = -1;
			break;
			//    case 0x78B82F3F:
			//      Serial.println("TV/Video");
			//      break;
			//    case 0xC5AF6FB7:
			//      Serial.println("T-");
			//      break;
			//    case 0xA63D0D9F:
			//      Serial.println("T+");
			//      break;
			//    case 0x31DD05DF:
			//      Serial.println("OFF-TIMER");
			//      break;
			//    case 0xF46A73DB:
			//      Serial.println("MODE");
			//      break;
			//    case 0xD7317C3B:
			//      Serial.println("PC-");
			//      break;
			//    case 0x46BD2A3F:
			//      Serial.println("PC+");
			//      break;
			//    case 0xD82FADDB:
			//      Serial.println("RECALL");
			//      break;
			//      // car MP3
			//    case 0xE318261B:
			//      Serial.println("CH-");
			//      break;
			//    case 0x511DBB:
			//      Serial.println("CH");
			//      break;
			//    case 0xEE886D7F:
			//      Serial.println("CH+");
			//      break;
			//    case 0x52A3D41F:
			//      Serial.println("PREV");
			//      break;
			//    case 0xD7E84B1B:
			//      Serial.println("NEXT");
			//      break;
			//    case 0xF076C13B:
			//      Serial.println("-");
			//      break;
			//    case 0xA3C8EDDB:
			//      Serial.println("+");
			//      break;
			//    case 0xE5CFBD7F:
			//      Serial.println("EQ");
			//      break;
			//    case 0x20FE4DBB:
			//      Serial.println("PLAY/STOP");
			//      break;
			//    case 0x9716BE3F:
			//      Serial.println("1");
			//      break;
			//    case 0x3D9AE3F7:
			//      Serial.println("2");
			//      break;
			//    case 0x6182021B:
			//      Serial.println("3");
			//      break;
			//    case 0x8C22657B:
			//      Serial.println("4");
			//      break;
			//    case 0x488F3CBB:
			//      Serial.println("5");
			//      break;
			//    case 0x449E79F:
			//      Serial.println("6");
			//      break;
			//    case 0x32C6FDF7:
			//      Serial.println("7");
			//      break;
			//    case 0x1BC0157B:
			//      Serial.println("8");
			//      break;
			//    case 0x3EC3FC1B:
			//      Serial.println("9");
			//      break;
			//    case 0xC101E57B:
			//      Serial.println("0");
			//      break;
			//    case 0x97483BFB:
			//      Serial.println("FOL+");
			//      break;
			//    case 0xF0C41643:
			//      Serial.println("FOL-");
			//      break;
			//
			//      //car MP3
			//    case 0xFFA25D:
			//      Serial.println(" CH-            ");
			//      break;
			//    case 0xFF629D:
			//      Serial.println(" CH             ");
			//      break;
			//    case 0xFFE21D:
			//      Serial.println(" CH+            ");
			//      break;
			//    case 0xFF22DD:
			//      Serial.println(" PREV           ");
			//      break;
			//    case 0xFF02FD:
			//      Serial.println(" NEXT           ");
			//      break;
			//    case 0xFFC23D:
			//      Serial.println(" PLAY/PAUSE     ");
			//      break;
			//    case 0xFFE01F:
			//      Serial.println(" VOL-           ");
			//      break;
			//    case 0xFFA857:
			//      Serial.println(" VOL+           ");
			//      break;
			//    case 0xFF906F:
			//      Serial.println(" EQ             ");
			//      break;
			//    case 0xFF6897:
			//      Serial.println(" 0              ");
			//      break;
			//    case 0xFF9867:
			//      Serial.println(" 100+           ");
			//      break;
			//    case 0xFFB04F:
			//      Serial.println(" 200+           ");
			//      break;
			//    case 0xFF30CF:
			//      Serial.println(" 1              ");
			//      break;
			//    case 0xFF18E7:
			//      Serial.println(" 2              ");
			//      break;
			//    case 0xFF7A85:
			//      Serial.println(" 3              ");
			//      break;
			//    case 0xFF10EF:
			//      Serial.println(" 4              ");
			//      break;
			//    case 0xFF38C7:
			//      Serial.println(" 5              ");
			//      break;
			//    case 0xFF5AA5:
			//      Serial.println(" 6              ");
			//      break;
			//    case 0xFF42BD:
			//      Serial.println(" 7              ");
			//      break;
			//    case 0xFF4AB5:
			//      Serial.println(" 8              ");
			//      break;
			//    case 0xFF52AD:
			//      Serial.println(" 9              ");
			//      break;
		default:
			Serial.println(results.value, HEX);
			break;
		}


		irrecv.resume(); // Receive the next value
	}

}
