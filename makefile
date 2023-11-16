hepsi:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Basamak.cpp -o ./lib/Basamak.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Sayi.cpp -o ./lib/Sayi.o
	g++ -c -I "./include" ./src/SayilarListesi.cpp -o ./lib/SayilarListesi.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
bagla:
	g++ ./lib/Basamak.o ./lib/main.o ./lib/Sayi.o ./lib/SayilarListesi.o ./lib/Dugum.o -o ./bin/program
calistir:
	./bin/program