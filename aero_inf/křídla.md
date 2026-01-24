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
| Hlavní křídlo |         **50 cm** | **13 cm** | NACA 4412 |   0,065 m²   |
| Horizontal stabilizer      |         **20 cm** |    **8 cm** | NACA 0012 | 0,016 m²     |
| Fin           | **12 cm (výška)** |    **7 cm** | NACA 0012 |  0,0084 m²    |

# objemový koeficient
(tail volume coefficient) určuje stabilitu výškovky. Pro moje použití chci 0,3 - 0,7.

<span style="text-align: center; font-size:2em;">$V_h = \frac{S_h ⋅ l_h}{S⋅c}$</span>

kde $S_h$ je **plochav výškovky**, $l_h$ je **rameno výškovky** neboli vzdálenost aerodynamického  středu (počítám u NACA 4412 tak 25% chordu) výškovky od hlavního křídla  , $S$ je **plocha hlavního křídla** a $c$ je **střední aerodynamická tětiva** u obdelníkového křídla (jako to moje) se $c =$ chord hlavního křídla 

takže po dasazení hodnot $s_h = 0,016$ $m^2$ 

 $l_h = l_{hl-vy} - \frac{C_{hl}}{4} + \frac{C_{vy}}{4} = 298,75$ $mm$ $=0,29875$ $m$, kde $l_{hl-vy}$ je vzdálenost výškovky od hlavního křídla, $C_{hl}$ je chord hlavního křídla a $C_{vy}$ je chord výškovky.
 
  $S = 0,065$ $m^2$ a $c = 0,13$ $m$ dostaneme $V_h$ = **0,566** . Výsledek odpovídá typickému rozsahu pro lehká letadla.


# Reynoldsovo číslo
Z rozměru popsaných výše můžeme vypočítat Re. Použijeme pro to vztah
   
<span style="text-align: center; font-size:2em;">$Re = \frac{V ⋅ c}{v}$</span>

kde *V* je rychlost letu, *c* je charakteristická délka neboli **chord** a *ν* je kinematická viskozita vzduchu  (1.5 × 10⁻⁵ m²/s počítam jako konstantu).

při rychlsti 10 $ms^{-1}$ bude $Re$ hlavního křídla zhruba 87000. S tímhle číslem se dále pracuje při sumulacích. -> viz simulace

# Stall speed
pro výpočet rychlosti při který křídlo přestane generovat vztlak použijeme vzorec


<span style="text-align: center; font-size:2em;">$V_{stall} = \sqrt{\frac{2⋅W}{ρ⋅S⋅C_{Lmax}}}$</span>

kde $W$ je tíhová síla letadla ( $W = mg$ ), $ρ$ je hustota vzduchu (počítám s $ρ$ = 1.225 $kgm^{−3}$) $S$ je referenční plocha křídla, používá se plocha hlavního křídla a $C_{Lmax}$ je maximální součinitel vztlaku kdy křídlo jestě produkuje vztlak. Hodnotu $C_{Lmax}$ zjistim pomocí simulací v programu XFLR5.

váha podle odhadu vychází zhruba 280g.

$W = 0,280kg = 2,75$ N , $S=0,065$ m²

$C_{l,max}$ podle simulace 2D profilu v Xfoil pro $Re=87000$, vyšel $C_{l,max}=1.31$ tohle je pro 2D křído, kde se nepočítají žádné koncové víry, downwash a to že vztlak nemusí být rovnoměrně rozložený. Proto abychom z 2D získali 3D typicky se to vynásobý 0,75-0,85. takže 
$C_{L,max}=C_{l,max}⋅0.8$

$C_{L,max} = 1,05$

​$V_{stall} = \sqrt{\frac{2⋅2,75}{1,225⋅0,065⋅1,05}}$

$V_{stall} = 8,11$ $ms^{-1}$

tohle číslo je čistě pro hlavní křídlo když klapky jsou v neutrální pozici. Jakmile se klapky dají dolů/nahorů $C_{l,max}$ se změní. 
Z grafu v Xfoil vyčteme že $C_{l,max}$ když jsou klapky plně dolů $C_{l,max}=1,61$ které převedeme na 3D stejně jako předtím. Potom $V_{stall}$ pro klapky dolů je

$V_{stall} = 7,32$ $ms^{-1}$.