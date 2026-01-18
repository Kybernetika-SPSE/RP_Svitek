## Zapojení letadla
![image](./jednoduché%20schéma.png)

Jednoduché zapojení elektroniky v letadle, [baterie](https://www.rcprofi.cz/kavan-li-po-1300mah-11-1v-40-80c-14-4wh) dodává zhruba 11V a maximálně až 106A do [ESC](https://www.bighobby.cz/regulator-otacek-40a-hornet--2-4s-/), který vytvoří trojfázový AC pro napájení [motoru](https://www.houska-modelar.cz/shop/product_info.php?cPath=10093_359_368&products_id=24294&osCsid=3re1j6ab4b08gm9a0c9ueq79c3) který bere okolo 20-25A což baterie dokáže poskytnout bez problémů. Na baterii připojím [Step-Down](https://www.laskakit.cz/step-down-menic-5v-5a-tps40057/) který z 11V udělá 5V pro ESP32 a serva.

Kondenzátor slouží k potlačení napěťových špiček a stabilizaci 5V zdroje. Timto bude ESP napájeno stabilně a step-down zvládne zátěž až 5A což je víc než dost. Přes ESP pak budeme ovládat skrze ESC Throttle motoru.

Tenhle ESC má vlastní zdroj "BEC" ale má limit 3A což nestačí pro Serva + ESP. 3x Serva potřebují při maximální zátěži až 3A a ESP potřebuje něco okolo 0.5A.