#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

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
            Serial.println(" === End Recieve === ");
        }
    }

    void onRead(BLECharacteristic *pCharacteristics)
    {
        Serial.println("A device is reading data Data");
    }
};