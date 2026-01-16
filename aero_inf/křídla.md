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
| Elevator      |         **20 cm** |    **8 cm** | NACA 0012 | 0,016 m²     |
| Fin           | **12 cm (výška)** |    **7 cm** | NACA 0012 |  0,0084 m²    |

# objemový koeficient
(tail volume coefficient) určuje stabilitu křídla. Pro moje použití chci 0,03 - 0,08.

<span style="text-align: center; font-size:2em;">$V_h = \frac{S_h ⋅ l_h}{S⋅c}$</span>

kde $S_h$ je plocha rudderu, $l_h$ je rameno rudderu, $S$ je plocha hlavního křídla a $c$ je střední aerodynamická tětiva u obdelníkového křídla (jako to moje) se $c =$ chord hlavního křídla 

takže po dasazení hodnot $s_h = 0,0084$ $m^2$ , $l_h = 0,05$ $m$ , $S = 0,065$ $m^2$ a $c = 0,12$ $m$ dostaneme $V_h$ = **0,054** . Výsledek odpovídá typickému rozsahu pro lehké letadla.


# Reynoldsovo číslo
Z rozměru popsaných výše můžeme vypočítat Re. Použijeme pro to vztah
   
<span style="text-align: center; font-size:2em;">$Re = \frac{V ⋅ c}{v}$</span>

kde *V* je rychlost letu, *c* je charakteristická délka neboli **chord** a *ν* je kinematická viskozita vzduchu  (1.5 × 10⁻⁵ m²/s počítam jako konstantu).

při rychlsti 8 $ms^{-1}$ bude $Re$ hlavního křídla zhruba 70000. S tímhle číslem se dále pracuje při sumulacích. -> viz simulace
