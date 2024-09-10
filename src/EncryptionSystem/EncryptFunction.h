#ifndef EncrypytFunction_H
#define EncrypytFunction_H
#include <windows.h>
#include <cstdlib>  
#include <ctime> 
//Class msg
class Message{
    int sizeKey;
    public:
    TCHAR *EncryptedMsg;
    TCHAR *  Key; 
    //Functions
    int Decryption(TCHAR  * Message,int sizeMsg);
    TCHAR keyGenerator();
    void encryption(TCHAR  * Message,int sizeMsg);
    void SetKey(TCHAR * key,int sizeMsg);
    void clear();
    Message();
};

#endif