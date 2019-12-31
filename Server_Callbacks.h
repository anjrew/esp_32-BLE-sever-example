#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#define SWITCH_PIN 4


class ServerCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristics)
    {
        std::string rxValue = pCharacteristics->getValue();
        if (rxValue.length() > 0)
        {
            Serial.println(" === Start Recieve === ");
            for (int index = 0; index < rxValue.length(); index++)
            {
                Serial.print(rxValue[index]);
            }
            Serial.println("");
            Serial.println(" === End Recieve === ");

            char fistChar = rxValue[0];

            if ( fistChar == '1' ){
                Serial.println("Switching OFF");
                digitalWrite( SWITCH_PIN, HIGH );
            }

            if ( fistChar ==  '0' ) {
                Serial.println("Switching ON");
                digitalWrite( SWITCH_PIN, LOW );
            }
        }
    }

    void onRead(BLECharacteristic *pCharacteristics)
    {
        Serial.println("A device is reading data Data");
    }
};