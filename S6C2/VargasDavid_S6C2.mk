inicial.pdf: plot.py data.dat
	python plot.py
data.dat: ./a.out
	./a.out
./a.out: a.cpp
	g++ a.cpp
    