# Křídla


### hlavní
Hlavní křídlo sem se rozhodl udělat o rozpětí 50cm a chord 13cm. Profil jsem si vybral **NACA 4412**, kvůli jeho dobrým vlastnostem při nizkých rychlostech. Ailerony budou odvozeny z profilu a budou mít asi 40cm dohromady. podle toho sem dá určit vše ostatní

### elevator
Pro elevátor by měl být profil neutrální takže sem zvolil profil **NACA 0012** bez nějakého vyššího důvodu. klapky budou po celé délce elvátoru.

### Fin
Pro rudder sem se rozhodl že ani nebude mít žádné servo nebude se dát ovládat a ani tam nebude klapka. Model velikosti jako chci postavit já ho nepotřbuje. Profil bude též NACA 0012.


### tabulka hodnot :

| Křídlo       |           Rozpětí |       Chord | Profil    |   Plocha       |
| ------------- | ----------------: | ----------: | ---------: | --------- |
| Hlavní křídlo |         **60 cm** | **13 cm** | NACA 4412 |   0,078 m²   |
| Horizontal stabilizer      |         **20 cm** |    **8 cm** | NACA 0012 | 0,016 m²     |
| Fin           | **12 cm (výška)** |    **7 cm** | NACA 0012 |  0,0084 m²    |

# Aero základy

### Hlavní síly
Na letadlo při letu působí 4 hlavní síly a to **Vztlak**, **Tíhová síla**, **Tah** a **Odpor**. 
![síly](./SÍLY.png)
obr 1

Tah působí ve směru letu, odpor vzduchu působí proti tahu, vztlak působí kolmo k směru letu a tíhová síla působí vždy směrem k zemi.

### Rovnováha sil
V ustáleném přímém ideálním letu bez zrychlení jsou síly v rovnováze. Vztlak je přibližně roven tíze letadla a tah motoru vyrovnává aerodynamický odpor.

$L = W$,    $T=D$

kde $L$ je **vztlak** (Lift), $W$ je **tíhová síla** (Weight), $T$ je **tah** (Thrust) a D je **aerodynamický odpor** (Drag).

### Vztlaková rovnice
Velikost vztlaku závisí na rychlosti letu, hustotě vzduchu, ploše křídla a tvaru profilu. Vztlak lze vyjádřit vztahem

$L = \frac{1}{2}ρV^{2}SC_L​$

kde $ρ$ je hustota vzduchu, $V$ je rychlost letu, $S$ je plocha křídel a $C_L$ je koeficient vztlaku.

$C_L$ ustáleného vodorovného letu jsem získal podle vzorece

$C_L = \frac{2W}{ρV^{2}S}$ .

Tohle je $C_L$ pro **ustálený let**, $C_L,max$ je potom maximální koeficient vztlaku kdy křídlo jestě generuje vztlak.

### Indukovaný odpor křídla
indukovaný odpor křídel vyjadřuje vztah 

<span style="text-align: center; font-size:2em;">$C_{Di} = \frac{C^{2}_L}{π⋅e⋅AR}$</span>,

kde $C_L$ je koeficient vztlaku, $e$ je Oswaldův faktor účinnosti který říká jak blízko má křídlo k ideálnímu rozložení vztlaku, kde 1 je ideální křídlo. Pro výpočet jsem počítal s $e=0,85$. $AR$ je poměr rozpětí křídla a plochy křídla

$AR = \frac{b^2}{S}$,

kde $b$ je rozpětí křídla a $S$ je plocha křídla.

![induced drag 0°](../XFLR/TEST/sim1/induced%20drag%20a=0.png)
obr 2: Indukovaný odpor křídla, $α = 0°$

![induced drag 0°](../XFLR/TEST/sim1/induced%20drag%20a=7.png)
obr 3: Indukovaný odpor křídla, $α = 7°$

V obr 1 jde vidět že $C_L = 0,26$ což znamená že vztlak je malý a tím pádem indukovaný odpor je malý. Podle výpočtů $C_{Di}=0,0054$. Naopak v Obr 2 je $C_L = 0,77$ proudění míří dolů a indukovaný odpor je vyší. Podle výpočtů $C_{Di}=0,048$. Analýza v XFLR potvrzuje tyto výpočty ale i přesto XFLR5 v některých bodech udává účinnost $e$ blízkou 1, což je chyba inviscidní metody simulace.

# Reynoldsovo číslo
Z rozměru popsaných výše můžeme vypočítat Re. Použijeme pro to vztah
   
<span style="text-align: center; font-size:2em;">$Re = \frac{V ⋅ c}{v}$</span>

kde $V$ je rychlost letu, $c$ je charakteristická délka neboli **chord** a $ν$ je kinematická viskozita vzduchu  (1.5 × 10⁻⁵ m²/s počítam jako konstantu).

při rychlsti 12 $ms^{-1}$ bude $Re$ hlavního křídla zhruba 104000. S tímhle číslem se dále pracuje při sumulacích. -> viz simulace


# objemový koeficient
(tail volume coefficient) určuje stabilitu výškovky. Pro moje použití chci 0,3 - 0,7.

<span style="text-align: center; font-size:2em;">$V_h = \frac{S_h ⋅ l_h}{S⋅c}$</span>

kde $S_h$ je **plochav výškovky**, $l_h$ je **rameno výškovky** neboli vzdálenost aerodynamického  středu (počítám u NACA 4412 tak 25% chordu) výškovky od hlavního křídla  , $S$ je **plocha hlavního křídla** a $c$ je **střední aerodynamická tětiva** u obdelníkového křídla (jako to moje) se $c =$ chord hlavního křídla 

takže po dasazení hodnot $s_h = 0,016$ $m^2$ 

 $l_h = l_{hl-vy} - \frac{C_{hl}}{4} + \frac{C_{vy}}{4} = 298,75$ $mm$ $=0,29875$ $m$, kde $l_{hl-vy}$ je vzdálenost výškovky od hlavního křídla, $C_{hl}$ je chord hlavního křídla a $C_{vy}$ je chord výškovky.
 
  $S = 0,078$ $m^2$ a $c = 0,13$ $m$ dostaneme $V_h$ = **0,471** . Výsledek odpovídá typickému rozsahu pro lehká letadla.


# Stall speed
pro výpočet rychlosti při který křídlo přestane generovat vztlak použijeme vzorec

<span style="text-align: center; font-size:2em;">$V_{stall} = \sqrt{\frac{2⋅W}{ρ⋅S⋅C_{Lmax}}}$</span>

kde $W$ je tíhová síla letadla ( $W = mg$ ), $ρ$ je hustota vzduchu (počítám s $ρ$ = 1.225 $kgm^{−3}$) $S$ je referenční plocha křídla, používá se plocha hlavního křídla a $C_{Lmax}$ je maximální součinitel vztlaku kdy křídlo jestě produkuje vztlak. Hodnotu $C_{Lmax}$ zjistim pomocí simulací v programu XFLR5.

váha podle odhadu vychází zhruba 400g.

$W = m⋅g = 3,92$ N , $S=0,078$ m²

$C_{l,max}$ podle simulace 2D profilu v Xfoil pro $Re=104000$, vyšel $C_{l,max}=1.32$ tohle je pro 2D křído, kde se nepočítají žádné koncové víry, downwash a to že vztlak nemusí být rovnoměrně rozložený. Proto abychom z 2D získali 3D typicky se to vynásobý 0,75-0,85. takže 
$C_{L,max}=C_{l,max}⋅0.8$

$C_{L,max} = 1,06$

<span style="text-align: center; font-size:2em;">​$V_{stall} = \sqrt{\frac{2⋅3,92}{1,225⋅0,078⋅1,05}}$</span>

$V_{stall} = 8,79$ $ms^{-1}$

tohle číslo je čistě pro hlavní křídlo když klapky jsou v neutrální pozici. Jakmile se klapky dají dolů/nahorů $C_{l,max}$ se změní. 
Z grafu v Xfoil vyčteme že $C_{l,max}$ když jsou klapky plně dolů $C_{l,max}=1,63$ které převedeme na 3D stejně jako předtím. Potom $V_{stall}$ pro klapky dolů je

$V_{stall} = 7,93$ $ms^{-1}$.

![grafy Cl](../XFLR/TEST/sim%20a%20=%205°/CL%20graf%20104k.png)
obr. 4 grafy Cl alpha 

# Letové podmínky
návrhová rychlost se kterou počítam 10-12 $ms^{-1}$

Re pro 10 $ms^{-1}$ je 87000, pro 12 $ms^{-1}$ 104000. Předpokládám že se bude letadlo pohybovat někde v rozmezí 80000-110000 Re. Jelokož tohle je pořád dost nízko tak klasický software jako je XFLR5 nebo openVSP neumí udělat správnou a přesnou viskózní 3D simulaci letu. Můžeme pouze udělat 2D simulace profilů.

XFLR není dokonalý a všehcny výpočty budu doplňovat realnými testy.

