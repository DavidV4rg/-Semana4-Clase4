poltdatos.pdf: plotdatos.py datos.dat
	python plotdatos.py
datos.dat: ./a.out
	./a.out >> datos.dat    
	g++ VargasDavidS5C2.cpp


