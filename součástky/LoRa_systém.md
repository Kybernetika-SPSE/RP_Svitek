# **Součástky potřebné na LoRa komunikaci**
Pro ovládání jsem se rozhodl použít systém LoRa. Musí to umět 868MHz což je legální frekvence v ČR a iděálně by to mělo mít nějakou anténu. 
## Ovladač
pro ovladač mám několik možností ale nejlepší mi příjde 
koupit **[ESP32 heltec V4](https://www.laskakit.cz/heltec-wifi-lora-32-v3-868mhz-0-96--wifi-modul/)**
což je esp které už má v sobě zabudovaný loRa čip SX1262 a má na sobě display který by mi v "poli" ukázal jestli funguje komunikace. V letadle by potom mohl být normální levnější modul bez displaye jako **[například tento](https://www.laskakit.cz/iot-868mhz-lora-lpwan-modul-sx1276/)** který by se musel pájet a klasicky spojit s normálním ESP32. Jediný problém je že heltec V4 je docela drahej. 

- **Kód ovladače**
  
    co jsem procházel knihovny pro ardino IDE tak nejlepší volba je **RadioLib** která je velice jednoduchá na použití a dokáže zorganizovat komunikaci mezi čipi **SX1262** a **SX1276**. Pomocí claude code jsem dostal takový jdenoduchý kód : 
    

        #include <RadioLib.h>

        #define LORA_NSS 8
        #define LORA_DIO1 14
        #define LORA_NRST 12
        #define LORA_BUSY 13

        SX1262 radio = new Module(LORA_NSS, LORA_DIO1, LORA_NRST, LORA_BUSY);

        void setup() {
        Serial.begin(115200);
        
        int state = radio.begin(
            868.0,    // frekvence
            125.0,    // bandwidth
            9,        // spreading factor
            7,        // coding rate
            0x12,     // sync word
            17        // output power (dBm)
        );
        
        if (state != RADIOLIB_ERR_NONE) {
            Serial.println("SX1262 init failed!");
            while(1);
        }
        }

        void loop() {
        String command = data;
        
        int state = radio.transmit(command);
        
        if (state == RADIOLIB_ERR_NONE) {
            Serial.println("Sent: " + command);
        }
        
        delay(50); // 20Hz refresh rate
        }


    kde naše hlavní informace z páček nebo joysticků (jestě sem se nerozhodl) by byli v stringu "command". 

          String command = "T:" + String(throttle) + 
                           ",P:" + String(pitch) + 
                           ",R:" + String(roll) + 
                           ",Y:" + String(yaw);



## Přijímač
Pro příjímač neboli letadlo by kód byl o dost složitější 


Dále bych mohl přidat něco jako Fail-Safe mód kde kdyby nějakou dobu neproběhla komunikace tak by se nastavyli nějaký defaultní hodnoty.