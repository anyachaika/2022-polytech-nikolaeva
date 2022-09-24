-O1 -O2 -O3 — разные уровни оптимизации

-Os — оптимизация размера (.text раздел в objdump 235)

-Ofast — оптимизация скорости (.text раздел в objdump 1438)

-Og — оптимизация для дебага


g++ complex.cpp

time: 0.662s 0.081s 0.240s size: 17408

g++ -O0 complex.cpp

time: 0.301s 0.102s 0.047s size: 17408

g++ -O1 complex.cpp

time: 0.282s 0.064s 0.076s size: 17272

g++ -O2 complex.cpp

time: 0.285s 0.108s 0.034s size: 17272

g++ -O3 complex.cpp

time: 0.280s 0.082s 0.056s size: 17272

g++ -Os complex.cpp

time: 0.349s 0.133s 0.040s size: 17248

g++ -Ofast complex.cpp

time: 0.351s 0.143s 0.031s size: 18848

g++ -Og complex.cpp

time: 0.349s 0.126s 0.048s size: 17344a

