#ifndef CORE_H_
#define CORE_H_
#include<stdio.h>
#include<vector>
#include<memory>
#include<map>
#include<unordered_map>

namespace ly
{  
/**
 * @brief define common dataTypes
 *
 */
template<typename T>
    using unique = std::unique_ptr<T>;
template<typename T>
    using shared = std::shared_ptr<T>;
template<typename T>
    using weak = std::weak_ptr<T>;
template<typename T>
    using List = std::vector<T>;
template<typename keytype , typename valuetype ,typename pr = std::less<keytype>>
    using Map = std::map<keytype,valuetype,pr>;
// dictionary is faster than map 
template<typename keytype , typename valuetype ,typename hasher = std::hash<keytype>>
    using Doctionary = std::unordered_map<keytype,valuetype,hasher>;


    //define macro for loging
    #define LOG(M, ...)   printf(M, ##__VA_ARGS__)
    
}


#endif // !CORE_H_
