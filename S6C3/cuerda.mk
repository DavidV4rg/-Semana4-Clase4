cuerda.pdf: Plots_cuerda.py data.dat inicial.dat
	python Plots_cuerda.py
data.dat: ./a.out
inicial.dat: ./a.out
	./a.out
./a.out: VargasDavid_S6C3.cpp
	g++ VargasDavid_S6C3.cpp