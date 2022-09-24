-O1 -O2 -O3 — разные уровни оптимизации<br/>
-Os — оптимизация размера (.text раздел в objdump 235)<br/>
-Ofast — оптимизация скорости (.text раздел в objdump 1438)<br/>
-Og — оптимизация для дебага<br/>
<br/>
<br/>
g++ complex.cpp<br/>
time: 0.662s 0.081s 0.240s size: 17408<br/>
<br/>
g++ -O0 complex.cpp<br/>
time: 0.301s 0.102s 0.047s size: 17408<br/>
<br/>
g++ -O1 complex.cpp<br/>
time: 0.282s 0.064s 0.076s size: 17272<br/>
<br/>
g++ -O2 complex.cpp<br/>
time: 0.285s 0.108s 0.034s size: 17272<br/>
<br/>
g++ -O3 complex.cpp<br/>
time: 0.280s 0.082s 0.056s size: 17272<br/>
<br/>
g++ -Os complex.cpp<br/>
time: 0.349s 0.133s 0.040s size: 17248<br/>
<br/>
g++ -Ofast complex.cpp<br/>
time: 0.351s 0.143s 0.031s size: 18848<br/>
<br/>
g++ -Og complex.cpp<br/>
time: 0.349s 0.126s 0.048s size: 17344a<br/>

