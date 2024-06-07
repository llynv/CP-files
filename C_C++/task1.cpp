//C internal library 
#include <iostream>
using std::wcin;
using std::wcout;
using std::wcerr;
using std::endl;
#include <string>
using std::string;
using std::wstring;
#include <cstdlib>
using std::exit;
#include "assert.h"

//Cryptopp Librari
#include "cryptopp/files.h"
using CryptoPP::FileSource;
using CryptoPP::FileSink;
using CryptoPP::BufferedTransformation;

#include "cryptopp/filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;
using CryptoPP::Redirector; // string to bytes

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;
using CryptoPP::byte;

#include "cryptopp/cryptlib.h"
using CryptoPP::Exception;

// convert string
// Hex <---> Binary
#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

// Base64 <---> Binary
#include "cryptopp/base64.h"
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;

// Block cipher
#include "cryptopp/des.h"
using CryptoPP::DES;
#include "cryptopp/aes.h"
using CryptoPP::AES;

//Mode of operations
#include "cryptopp/modes.h" //ECB, CBC, CBC-CTS, CFB, OFB, CTR
using CryptoPP::ECB_Mode;
using CryptoPP::CBC_Mode;
using CryptoPP::CFB_Mode;
using CryptoPP::OFB_Mode;
using CryptoPP::CTR_Mode;
#include "cryptopp/xts.h"
using CryptoPP::XTS;
#include <cryptopp/ccm.h>
using CryptoPP::CCM;
#include "cryptopp/gcm.h"
using CryptoPP::GCM;
//Ref: more here https://www.cryptopp.com/wiki/AEAD_Comparison


/* Set utf8 support for windows*/ 
#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#else
#endif
/* Convert string <--> utf8*/ 
#include <locale>
using std::wstring_convert;
#include <codecvt>
using  std::codecvt_utf8;
wstring string_to_wstring (const std::string& str);
string wstring_to_string (const std::wstring& str);

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

using namespace std;
using namespace CryptoPP;

wstring string_to_wstring(const string& str);
string wstring_to_string(const wstring& str);

int main(int argc, char* argv[])
{
    #ifdef __linux__
    setlocale(LC_ALL, "");
    #elif _WIN32
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    #endif

    int aescipher;
    wcout << "Would you like to encryption or decryption message:\n"
          << "1. key and iv generation;\n"
          << "2. encryption;\n"
          << "3. decryption;\n"
          << "Please enter your number?\n";
    wcin >> aescipher;
    wcin.ignore();
    CryptoPP::byte MainKey[AES::DEFAULT_KEYLENGTH];
    CryptoPP::byte MainIV[AES::BLOCKSIZE];
    HexDecoder Decoder;
    switch (aescipher) {
        case 1: {
            // Key and IV generation logic here
            int Generate_Key_IV_Choice;
            wcout << "Secret key,  Initialization Vector IV, and nonce generation logic here:\n"
                  << "1. Secret key and IV are randomly chosen for each run time using random generator\n"
                  << "2. Input Secret Key and IV from screen\n"
                  << "3. Input Secret Key and IV from file\n"
                  << "Enter your choice (1-3): ";
            wcin >> Generate_Key_IV_Choice;
            wcin.ignore();
            switch (Generate_Key_IV_Choice) {
                case 1: {
                    // Secret key and IV are randomly chosen for each run time using random generator
                    AutoSeededRandomPool prng;
                    prng.GenerateBlock(MainKey, sizeof(MainKey));
                    prng.GenerateBlock(MainIV, sizeof(MainIV));
                    wcout << "Secret key: " << MainKey << endl;
                    wcout << "IV: " << MainIV << endl;
                    break;
                }
                case 2: {
                    wstring wHexKey, wHexIV;
                    string decoded;
                    wcout << "Enter your secret key (in hex): ";
                    getline(wcin, wHexKey);
                    wcin.ignore();
                    wcout << "Enter your IV (in hex): ";
                    getline(wcin, wHexIV);

                    string HexKey = wstring_to_string(wHexKey);
                    string HexIV = wstring_to_string(wHexIV);
                    cout << HexKey << endl;
                    break;
                }
                case 3: {
                    break;
                }
            }
        }
        break;
        case 2: {
            int Encryption_Choice;
            wcout << "Select the encryption mode:\n"
                  << "1. ECB mode\n"
                  << "2. CBC mode\n"
                  << "3. CFB mode\n"
                  << "4. OFB mode\n"
                  << "5. CTR mode\n"
                  << "6. XTS mode\n"
                  << "7. CCM mode\n"
                  << "8. GCM mode\n"
                  << "Enter your choice(1-8): ";
            wcin >> Encryption_Choice;
            wcin.ignore();
            switch (Encryption_Choice) {
                case 1: {
                    // ECB mode
                    break;
                }
                case 2: {
                    // CBC mode
                    wcout << "CBC mode\n";
                    break;
                }
                case 3: {
                    // CFB mode
                    wcout << "CFB mode\n";
                    break;
                }
                case 4: {
                    // OFB mode
                    wcout << "OFB mode\n";
                    break;
                }
                case 5: {
                    // CTR mode
                    wcout << "CTR mode\n";
                    break;
                }
                case 6: {
                    // XTS mode
                    wcout << "XTS mode\n";
                    break;
                }
                case 7: {
                    // CCM mode
                    wcout << "CCM mode\n";
                    break;
                }
                case 8: {
                    // GCM mode
                    wcout << "GCM mode\n";
                    break;
                }
            }
            break;
        }
        case 3: {
            // Decryption logic here
            wcout << "Decryption logic here\n";
            break;
        }
        default:
            cout << "Invalid input\n";
            break;
    }
    return 0;
}

wstring string_to_wstring(const string& str) {
    wstring_convert<codecvt_utf8<wchar_t>> towstring;
    return towstring.from_bytes(str);
}

string wstring_to_string(const wstring& str) {
    wstring_convert<codecvt_utf8<wchar_t>> tostring;
    return tostring.to_bytes(str);
}
