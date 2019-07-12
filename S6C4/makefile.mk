placa.pdf: data.txt Tiempo0.txt Temp1.txt plots_difusion.py Difusion.cpp
	python plots_difusion.py
%.txt: a.out
	./a.out
a.out: Difusion.cpp
	g++ Difusion.cpp
