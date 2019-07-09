VargasDavid_S6C1plot1.pdf: VargasDavid_S6C1.py datos.dat datos1.dat
	 python VargasDavid_S6C1.py
datos1.dat: ./a.out
datos.dat: ./a.out
	 ./a.out
./a.out: VargasDavid_S6C1.cpp
	 g++ VargasDavid_S6C1.cpp