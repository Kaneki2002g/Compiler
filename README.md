# Compiler
Kompilator na przedmiot JFTT.
Wystarczy mieć C++17, w Makefile jest już flaga.

Jak działa?
W parserze(grammar.y) opakowuję "od dołu" każdy możliwy element kodu,
elementy zawierające w sobie coś mają je jako dzieci, a elementy równoważne
jako następne w kolejce. Powstaje coś w rodzaju drzewa, ale brzydsze.
Następnie, logiką zajmuje się część "brainpart", w której dzięki strukturze
można od góry budować kod (Bez opakowywania w strukturę też by było można,
ale na początku pisania nie potrafiłem sobie tego wyobrazić).

Jest dużo niepotrzebnych rzeczy w kodzie, ponieważ trochę rzeczy odbiegało
od moich początkowych założeń, a czas naglił, ale kompilator działa (Przynajmniej
na dostarczonych testach i testach zrobionych przeze mnie).

