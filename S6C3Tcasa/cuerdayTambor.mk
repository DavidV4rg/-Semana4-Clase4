cuerda.pdf: Plots_cuerdayTambor.py data.dat inicial.dat
libre.pdf: Plots_cuerdayTambor libre.dat data1.dat
	python Plots_cuerdayTambor.py
data.dat: ./a.out
inicial.dat: ./a.out
	./a.out
./a.out: VargasDavid_cuerdayTambor.cpp
	g++ VargasDavid_cuerdayTambor.cpp
