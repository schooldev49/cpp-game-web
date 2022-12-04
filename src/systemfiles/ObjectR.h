#pragma once

#ifndef OBJECTR_H
#define OBJECTR_H

#include <map>
#include <string>
#include <memory>
#include <functional>
#include "../player/GameObject.h"

class ObjectR {
    public:
        GameObject* CreateObject(std::string type, Properties* props);
        void RegisterType(std::string className, std::function<GameObject*(Properties* props)>type);
        static ObjectR* GetInstance(){
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new ObjectR();
        }
    protected:
        static ObjectR* s_Instance;
        ObjectR(){};
        std::map<std::string, std::function<GameObject*(Properties* props)>> m_typeRegistry;
    
};

template <class Type>
class Registrar {
    public:
        Registrar(std::string className){
            ObjectR::GetInstance()->RegisterType(className,[](Properties* props)->GameObject* {
                return new Type(props);
            }); 
        }
};

#endif