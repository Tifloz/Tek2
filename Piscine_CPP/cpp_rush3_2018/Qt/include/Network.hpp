/*
** EPITECH PROJECT, 2022
** MyGKrellm
** File description:
** Created by Florian Louvet,
*/
#ifndef MYGKRELLM_NETWORK_HPP
#define MYGKRELLM_NETWORK_HPP

#include <iostream>
#include <vector>
#include <map>

class NetWorkInfo {
    public :

    NetWorkInfo(void);

    ~NetWorkInfo(void);

    void clearStr(std::string &);

    std::vector<std::string> split(std::string, std::string);

    std::vector<unsigned long long> splitLong(std::string, std::string);

    std::map<std::string, std::vector<unsigned long long>> parseNetWorkInfo(void
    );

    void refreshNetWorkInfo(void);

    protected :

    private :

    unsigned int _stockBandWith;
    unsigned int _bandWith;
    unsigned int _Bytes;
    unsigned int _Packets;
    unsigned int _Errs;
    
    unsigned int _TBytes;
    unsigned int _TPackets;
    unsigned int _TErrs;
};

#endif //MYGKRELLM_NETWORK_HPP
