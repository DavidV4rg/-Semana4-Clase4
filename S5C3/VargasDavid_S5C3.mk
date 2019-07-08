VargasDavidResorte.pdf: VargasDavid_S5C3_plots.py data.dat
	 python VargasDavid_S5C3_plots.py
data.dat: ./a.out
	./a.out
./a.out: VargasDavid_S5C3_ODEsTcasa.cpp
	g++ VargasDavid_S5C3_ODEsTcasa.cpp
    