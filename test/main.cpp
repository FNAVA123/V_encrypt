#include <iostream>
#include <cstdlib>  
#include <ctime>  
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
// encry

class Message{
    char *  Key; 
    int sizeKey;
    char * DescryptedMsg;
    int  blanks ;
    int KeyGenerator(int sizeMsg);
    public:
    char *EncryptedMsg;
    //funciones
    int Encryption(char  * Message);
    void printKey();
    void printDesMsg();
    int CountMsg(char * Message);
    void Desencrypt(char * Message,char * InputKey);
    void clear();
    void countBlanks();
Message() {
        std::srand(static_cast<unsigned int>(std::time(0))); // Inicializar la semilla una vez
    }

     char keyGenerator();
    void encryption(char  * Message,int sizeMsg);
};

int main(){
char a[] = {22, 17, 54, 11, 28, 14, 17, 40, 35, 6, 61, 82, 71, 122,};
char k[] = {"ZxUjrzcGSiNcuT"};

char password[] = "Licantropos12.";
Message MSG;

MSG.encryption(password,14);

   for (int i = 0; password[i] != '\0'; i++) {
        std::cout << MSG.EncryptedMsg[i]<< " " ; 
    }

     
MSG.printKey();


MSG.clear();
    return 0;
}

int Message::Encryption(char  * Message){
    KeyGenerator(CountMsg(Message));
    EncryptedMsg = new  char[CountMsg(Message)];
     for(int i=0; Message[i] != '\0';i++){
        EncryptedMsg[i] = Message[i] ^ Key[i] ;
    }
  
    return 0;
}

int Message::KeyGenerator(int sizeMsg){
    std::srand(static_cast<unsigned int>(std::time(0)));
    Key = new char[sizeMsg];
    sizeKey = sizeMsg;
    for(int i= 0; i<sizeMsg;i++){
        int kind = std::rand() % 2; 
        (kind) ?   Key[i] =  std::rand() % 26 + 97 : Key[i] = std::rand() % 26 + 65;
    }
    return 0;
}

void Message::printKey(){
    std::cout << std::endl;
      for (int i = 0;i< sizeKey; i++) {
        std::cout << Key[i];
    }
    std::cout <<" "<< sizeKey << std::endl;
}

 int Message::CountMsg(char* Message){
    int sizePassword = 0;
    for(int i=0; Message[i] != '\0';i++){
    sizePassword++;
    }
    return sizePassword;
 }


 void Message::Desencrypt(char * Message,char * InputKey){
    DescryptedMsg = new char[CountMsg(Message)];
      for(int i=0; Message[i] != '\0';i++){
            DescryptedMsg[i]= Message[i] ^  InputKey[i];
    }
 }

 void Message::printDesMsg(){
    std::cout << std::endl;
      for (int i = 0;DescryptedMsg[i]!='\0'; i++) {
        std::cout << DescryptedMsg[i];
    }
    std::cout << std::endl;


}
void Message::countBlanks(){
    blanks=0 ;
    for(int i = 0; i<sizeKey;i++){
        if(EncryptedMsg[i]>= 10){
            blanks =blanks | (int)pow(2,i); 
        } 
    }
         std::string blank = std::to_string(blanks);
  
}
void Message::clear(){
    delete[] EncryptedMsg;
    delete[] Key;
    delete[] DescryptedMsg;

}

char Message::keyGenerator(){
    
    char word;
         int kind = std::rand() % 2; 
        (kind) ?   word  =  std::rand() % 26 + 97 : word = std::rand() % 26 + 65;
    return word;
}

void Message::encryption(char  * Message,int sizeMsg){
      EncryptedMsg = new  char[sizeMsg+1];
      Key = new char[sizeMsg+1];
      sizeKey = sizeMsg;
      char k;
       for(int i=0; Message[i] != '\0';i++){
        while ( EncryptedMsg[i] < 32 || EncryptedMsg[i] > 126)
        {
            k =  keyGenerator();
            EncryptedMsg[i] = Message[i] ^ k;
        }
        Key[i] = k;
    }
    
}