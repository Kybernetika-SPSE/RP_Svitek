# **Součástky potřebné na HC‑12 komunikaci**

Pro ovládání jsem se nakonec rozhodl použít **HC‑12** místo LoRa. Hlavní důvod je jednoduchost, HC‑12 funguje jako obyčejná sériová linka (UART) takže není potřeba řešit RF parametry ani žádnné knihovny. Pracuje v pásmu **433 MHz**, které je běžně používané a dostupné.

## Ovladač

Pro ovladač použiju klasické **ESP32** ke kterému bude připojen modul **HC‑12** přes UART. HC‑12 se umožňuje jednoduchý přenos dat, neboli se pošle na TX, to se objeví na RX druhého modulu.

### Zapojení HC‑12 k ESP32

- **VCC → 3.3 V**
- **GND → GND**
- **TXD HC‑12 → RX ESP32**
- **RXD HC‑12 → TX ESP32**
- **SET → HIGH** (běžný provoz)
- **ANT → anténa**

## Kód ovladače

Na rozdíl od LoRa zde není potřeba žádná knihovna. Stačí použít **HardwareSerial**, který je součástí ESP32.

Základní princip je, že hodnoty z páček / joysticků se zabalí do struktury a ta se pošle jako blok dat.

Příklad struktury dat (pomocí claude code):

```cpp
struct ControlPacket {
  int16_t throttle;
  int16_t pitch;
  int16_t roll;
  int16_t yaw;
};
```

Odesílání dat z ovladače:

```cpp
HardwareSerial HC12(1);
ControlPacket packet;

void setup() {
  HC12.begin(9600, SERIAL_8N1, 16, 17);
}

void loop() {
  packet.throttle = throttle;
  packet.pitch    = pitch;
  packet.roll     = roll;
  packet.yaw      = yaw;

  HC12.write((uint8_t*)&packet, sizeof(packet));
  delay(50); // cca 20 Hz
}
```

## Přijímač

Na straně přijímače (v letadle) je zapojení stejné, ESP32 + HC‑12. Přijímač pouze čeká, až dorazí celý paket, a následně si hodnoty přiřadí do proměnných pro řízení motoru a serv.

```cpp
HardwareSerial HC12(1);
ControlPacket packet;

void setup() {
  HC12.begin(9600, SERIAL_8N1, 16, 17);
}

void loop() {
  if (HC12.available() >= sizeof(packet)) {
    HC12.readBytes((uint8_t*)&packet, sizeof(packet));

    throttle = packet.throttle;
    pitch    = packet.pitch;
    roll     = packet.roll;
    yaw      = packet.yaw;
  }
}
```

## Fail‑Safe

Do budoucna je možná přidám **Fail‑Safe mód**, kdy pokud po určitou dobu nepřijdou žádná data, nastaví se nějaké hodnoty (např. vypnutí motoru a vycentrování řízení).

