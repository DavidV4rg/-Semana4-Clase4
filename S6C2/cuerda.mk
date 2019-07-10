inicial.pdf: Plots_cuerda.py data.dat data1.dat
	python Plots_cuerda.py
data.dat: ./a.out
data1.dat: ./a.out
	./a.out
./a.out: VargasDavid_S6C2.cpp
	g++ VargasDavid_S6C2.cpp
    