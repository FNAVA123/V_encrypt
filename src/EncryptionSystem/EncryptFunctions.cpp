#include "EncryptFunction.h"

Message::Message() {
    std::srand(static_cast<unsigned int>(std::time(0))); 
}

void Message::encryption(TCHAR  * Message,int sizeMsg){
      EncryptedMsg = new  TCHAR[sizeMsg-1];
      Key = new TCHAR[sizeMsg-1];
      TCHAR k;
       for(int i=0; Message[i] != '\0';i++){
        do{
            k =  keyGenerator();
            EncryptedMsg[i] = Message[i] ^ k;
        } while ( EncryptedMsg[i] < 32 || EncryptedMsg[i] > 126);
        Key[i] = k;
    }
}

TCHAR Message::keyGenerator(){
    
    TCHAR word;
         int kind = std::rand() % 2; 
        (kind) ?   word  =  std::rand() % 26 + 97 : word = std::rand() % 26 + 65;
    return word;
}

int Message::Decryption(TCHAR  * Message,int sizeMsg){
    EncryptedMsg = new  TCHAR[sizeMsg-1];
     for(int i=0; Message[i] != '\0';i++){
        EncryptedMsg[i] = Message[i] ^ Key[i] ;
    }
  
    return 0;
}


 void Message::SetKey(TCHAR * key,int sizeMsg){
     Key = new TCHAR[sizeMsg-1];
      for(int i= 0; i<sizeMsg;i++){
        Key[i] = key[i];
    }
 }
void Message::clear(){
    delete[] EncryptedMsg;
    delete[] Key;
}