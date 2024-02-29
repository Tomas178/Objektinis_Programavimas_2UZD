main: Vector_v0_3.cpp funckjijos.cpp
	g++ Vector_v0_3.cpp funckjijos.cpp -o main

clear:
	rm main


run:
	rm main
	g++ Vector_v0_3.cpp funckjijos.cpp -o main
	./main