libre.pdf: Plots_cuerdayTambor libre.dat data1.dat
	python Plots_cuerdayTambor.py
libre.dat: ./a.out
data1.dat: ./a.out
	./a.out
./a.out: VargasDavid_cuerdayTambor.cpp
	g++ VargasDavid_cuerdayTambor.cpp