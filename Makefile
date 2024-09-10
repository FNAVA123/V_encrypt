all:
	 g++ -o v_encrypt src/main.cpp src/EncryptionSystem/EncryptFunctions.cpp src/Front/front.cpp -mwindows 
	./v_encrypt.exe

