cuerda.png: Plots_cuerda.py data.dat
	python Plots_cuerda.py
data.dat: ./a.out
	./a.out
./a.out: VargasDavid_S6C3.cpp
	g++ VargasDavid_S6C3.cpp