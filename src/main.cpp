#include <windows.h>
#include "EncryptionSystem/EncryptFunction.h"
#include "Front/front.h"

#define ID_MSG 0
#define ID_ENCRY 1
#define ID_ENCRYB 2
#define ID_DECRYB 3
#define ID_KEY 4

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND Message_textbox , Encrypt_Msg, Key;
    Message MsgUser;     
    ShapesD MsgTxb = {0,50,300,30} , EcryptTxb ={0,170,300, 30},  KeyTxb = {0,81,300, 30} , ButtEnc = {0,230,80,30} , ButtDes = {0,230,80,30};
    switch (uMsg) {


        case WM_CREATE: {
            Message_textbox = CreateWindowEx(0, TEXT("EDIT"), TEXT("INPUT"),
                                   TxtBoxStyle,
                                   MsgTxb.centerX(), MsgTxb.ypos, MsgTxb.sizewidth, MsgTxb.sizeheight,
                                   hwnd, (HMENU)ID_MSG, GetModuleHandle(NULL), NULL);
             
            Encrypt_Msg = CreateWindowEx(0, TEXT("EDIT"), TEXT("OUTPUT"),
                                   TxtBoxStyle,
                                   EcryptTxb.centerX(), EcryptTxb.ypos, EcryptTxb.sizewidth, EcryptTxb.sizeheight,
                                   hwnd, (HMENU)ID_ENCRY, GetModuleHandle(NULL), NULL);


            Key = CreateWindowEx(0, TEXT("EDIT"), TEXT("KEY"),
                                   WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER,
                                   KeyTxb.centerX(), KeyTxb.ypos, KeyTxb.sizewidth, KeyTxb.sizeheight,
                                   hwnd, (HMENU)ID_KEY, GetModuleHandle(NULL), NULL);

             CreateWindowEx(0, TEXT("BUTTON"), TEXT("ENCRYPT"),
                           ButtonStyle,
                           ButtEnc.centeryoffset(-50), ButtEnc.ypos, ButtEnc.sizewidth, ButtEnc.sizeheight,
                           hwnd, (HMENU)ID_ENCRYB, GetModuleHandle(NULL), NULL);
                           
              CreateWindowEx(0, TEXT("BUTTON"), TEXT("DECRYPT"),
                           ButtonStyle,
                           ButtDes.centeryoffset(50) , ButtDes.ypos, ButtDes.sizewidth, ButtDes.sizeheight,
                           hwnd, (HMENU)ID_DECRYB, GetModuleHandle(NULL), NULL);
            return 0;
        }
        case WM_COMMAND: {
            //Encrypt button
            if(LOWORD(wParam) == ID_ENCRYB){
                int sizeMsg = GetWindowTextLength(Message_textbox);
                if(sizeMsg >0){
                    TCHAR *  Buffer = new TCHAR[sizeMsg +1];
                    GetWindowText(Message_textbox, Buffer ,  sizeMsg + 1);
                    MsgUser.encryption(Buffer,sizeMsg);
                    SetWindowText(Encrypt_Msg ,TEXT(""));
                    SetWindowText(Key ,TEXT(""));
                    SetWindowText(Encrypt_Msg ,MsgUser.EncryptedMsg );
                    SetWindowText(Key ,MsgUser.Key );
                    delete Buffer;
                    
                }
                else{
                    SetWindowText(Message_textbox ,TEXT("Do not forget the input"));
                }
            }
            //Descrypt button
            if(LOWORD(wParam) == ID_DECRYB){
             int sizeMsg = GetWindowTextLength(Message_textbox);
             int keysize = GetWindowTextLength(Key);
             if( keysize >0){
                TCHAR *  Buffer = new TCHAR[sizeMsg +1];
                TCHAR *  KeyBuffer = new TCHAR[sizeMsg +1];
                GetWindowText(Message_textbox, Buffer ,  sizeMsg + 1);
                GetWindowText(Key, KeyBuffer ,  sizeMsg + 1);
                MsgUser.SetKey( KeyBuffer, sizeMsg);
                MsgUser.Decryption(Buffer,sizeMsg);
                SetWindowText(Encrypt_Msg ,TEXT(""));
                SetWindowText(Encrypt_Msg ,MsgUser.EncryptedMsg );
                delete Buffer;
                delete KeyBuffer;
             }else{
                 
                 SetWindowText(Key ,TEXT("Enter a Key"));
             }
            }
            return 0;

        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
          
        case WM_PAINT:
        {
            	PAINTSTRUCT screen;
                HDC hdc = BeginPaint(hwnd , &screen);
                FillRect(hdc , &screen.rcPaint ,CreateSolidBrush(bkcolor));
                const TCHAR TL[] = TEXT("V ENCRYPT");
                TextOut(hdc,MsgTxb.centeryoffset(110) ,20, TL, lstrlen(TL));
                EndPaint(hwnd , &screen);
                return 0;
           
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

// Punto de entrada de la aplicación Windows
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    // Definir y registrar la clase de ventana
    const char CLASS_NAME[] = "V_ENCRYPT window ";
    WNDCLASSA wc = { };

    wc.lpfnWndProc = WindowProc; // logic of the windo
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClassA(&wc);

    // Crear la ventana
    HWND hwnd = CreateWindowExA(
        0,                          // Estilos extendidos de ventana
        CLASS_NAME,                 // Nombre de la clase de ventana
        "V_ENCRYPT",            // Título de la ventana
         WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,        // Estilo de ventana

        // Posición y tamaño de la ventana
        CW_USEDEFAULT, CW_USEDEFAULT, width,height,

        NULL,                       // Ventana padre
        NULL,                       // Menú
        hInstance,                  // Instancia de la aplicación
        NULL                        // Parámetros adicionales
    );

    if (hwnd == NULL) {
        return 0;
    }
    ShowWindow(hwnd, nCmdShow);
    //CoInitializeEx(NULL ,COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    //CoUninitialize();

    // Ciclo de mensajes
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
