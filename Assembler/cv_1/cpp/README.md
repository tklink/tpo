# AVRREP

Tento program ukazuje, jak řešit domácí úlohy o programování v assembleru AVR pomocí překladače C++.

## Překlad programu do assembleru

Zdrojový soubor `avrrep.cpp` přeložíme pomocí následujícího příkazu:

```bash
avr-g++ -S -O2 avrrep.cpp
```

Volba `-S` způsobí vytvoření souboru s assemblerem `avrrep.s` a volba `-O2` zapíná optimalizace, které jsou nutné k tomu, aby vygenerovaný assembler vypadal, jako by ho vytvořil člověk.

## Překlad assembleru do strojového kódu

Soubor `avrrep.s` necháme zpracovat následujícím příkazem:

```bash
avr-as -a avrrep.s >avrrep.lst
```

Výsledný soubor `avrrep.lst` obsahuje mimo jiné i hexadecimální výpis jednotlivých použitých strojových instrukcí.