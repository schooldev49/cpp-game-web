#include "ObjectR.h"
#include "../player/MainChar.h"

ObjectR* ObjectR::s_Instance = nullptr;

void ObjectR::RegisterType(std::string className, std::function<GameObject*(Properties* props)> type){
    m_typeRegistry[className] = type;
}

GameObject* ObjectR::CreateObject(std::string type, Properties* props){
    GameObject* obj = nullptr;
    auto it = m_typeRegistry.find(type);

    if (it != m_typeRegistry.end()){
        obj = it->second(props);
    }
    return obj;
}