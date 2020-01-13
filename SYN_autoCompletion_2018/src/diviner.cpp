/*
** EPITECH PROJECT, 2022
** SYN_autoCompletion_2018
** File description:
** Created by Florian Louvet,
*/
#include "diviner.hpp"
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <string>
#include <boost/algorithm/string.hpp>

bool sortinrev(const std::pair<char, int> &a, const std::pair<char, int> &b)
{
    return (a.second > b.second);
}

bool sortNumber(const std::pair<int, Address *> &a,
    const std::pair<int, Address *> &b
)
{
    return (a.first < b.first);
}

void Diviner::insertInVector(char letter)
{
    auto it = find_if(_prob.begin(), _prob.end(),
        [&letter](std::pair<char, int> &element) {
            return element.first == letter;
        });
    if (it != _prob.end())
        it->second++;
    else
        _prob.emplace_back(letter, 1);
}

void Diviner::splitAndInsert(const std::string &str, int occur)
{
    std::vector<std::string> res = _utils->Split(str, " ");

    for (auto &item:res)
        for (int i = 0; i < occur; i++)
            insertInVector(std::tolower(item.front()));
}

void Diviner::setChances()
{
    for (auto &item:*_dictionary->getCities()) {
        splitAndInsert(item.getName(), item.getOccur());
    }
    std::sort(_prob.begin(), _prob.end(), sortinrev);
}

int Diviner::answerChoice()
{
    int nb = _query.back() - '0';
    if (nb <= (int)_choices.size()) {
        _dictionary->printAddress(((City *)_current), *_choices[nb - 1].second);
        return 0;
    }
    return 1;
}

void Diviner::askChoice(std::string &hint)
{
    std::vector<std::pair<int, Address *>> tmp;
    std::list<Address> *addresses = ((City *)_current)->getAddresses();
    int nb = 1;

    for (auto &item:*addresses)
        if (boost::algorithm::to_lower_copy(item.getStreet()).find(hint) !=
            std::string::npos)
            tmp.emplace_back(item.getNb(), &item);
    if (!tmp.empty()) {
        std::sort(tmp.begin(), tmp.end(), sortNumber);
        for (auto it = tmp.begin(); it != tmp.end(); ++it) {
            std::cout << "{" << nb << " : " << boost::algorithm::to_upper_copy(
                ((City *)_current)->getName()) << ", " << it->second->getNb()
                << " " << boost::algorithm::to_upper_copy(it->second->getType())
                << boost::algorithm::to_upper_copy(it->second->getStreet())
                << "}";
            if (it + 1 != tmp.end())
                std::cout << " ";
            nb++;
        }
        std::cout << std::endl;
        _state = "choice";
        _choices = tmp;
    }
}

struct size_less {
    template<class T>
    bool operator()(T const &a, T const &b) const
    {
        return a.size() < b.size();
    }
};

static size_t max_line_length(std::vector<std::string> const &lines)
{
    if (!lines.empty())
        return std::max_element(lines.begin(), lines.end(),
            size_less())->size();
    return 0;
}

void Diviner::printPossibilities(const std::vector<std::string> &vect)
{
    std::vector<std::string> hints;
    int size = _query.size();
    int same = 0;
    int diff = 0;
    int verif = max_line_length(vect);

    while (!diff && verif > 0) {
        for (auto &name:vect) {
            if (name.substr(0, _query.size()).find(_query) !=
                std::string::npos) {
                for (auto &item:vect)
                    if (item.substr(0, size).find(name.substr(0, size)) ==
                        std::string::npos) {
                        diff++;
                        break;
                    } else
                        same++;
                if (!diff && same) {
                    size++;
                }
            }
        }
        verif--;
    }
    for (auto &name:vect)
        hints.push_back(name.substr(0, size));
    auto last = std::unique(hints.begin(), hints.end());
    hints.erase(last, hints.end());
    if (size > ((int)_query.size()))
        _query = hints.front().substr(0, size - 1);
    if (hints.size() == 1)
        askChoice(hints.front());
    else {
        for (auto it = hints.begin(); it != hints.end(); ++it) {
            std::cout << "{";
            if (_state == "street")
                std::cout << boost::algorithm::to_upper_copy(
                    ((City *)_current)->getName()) << ",";
            std::cout
                << boost::algorithm::to_upper_copy(it->substr(0, _query.size()))
                << it->substr(_query.size());
            if (it + 1 == hints.end())
                std::cout << "}" << std::endl;
            else
                std::cout << "} ";
        }
    }
}

void Diviner::Checker()
{
    std::vector<std::string> names;
    if (_state == "city") {
        std::list<City> *tmp = _dictionary->getCities();
        for (auto &city:*tmp)
            if (boost::algorithm::to_lower_copy(
                city.getName().substr(0, _query.size())).find(_query) !=
                std::string::npos) {
                _current = &city;
                names.push_back(
                    boost::algorithm::to_lower_copy(city.getName()));
            }
        if (names.empty())
            throw std::runtime_error("Unknown address");
        if (names.size() != 1)
            printPossibilities(names);
        else {
            _state = "street";
            _query.clear();
            Checker();
        }
    } else {
        /*  std::cout << "C'est les addresses ici : "
              << ((City *)_current)->getName() << std::endl;*/
        std::list<Address> *tmp = ((City *)_current)->getAddresses();
        if (tmp->empty())
            return;
        if (tmp->size() == 1) {
            _state = "finish";
            _dictionary->printAddress((City *)_current, tmp->front());
            return;
        }
        for (auto &address:*tmp)
            if (boost::algorithm::to_lower_copy(
                address.getStreet().substr(0, _query.size())).find(_query) !=
                std::string::npos) {
                names.push_back(
                    boost::algorithm::to_lower_copy(address.getStreet()));
            }
        std::sort(names.begin(), names.end());
        if (names.size() == 1) {
            for (auto &address:*tmp) {
                if (boost::algorithm::to_lower_copy(address.getStreet()) ==
                    names.front()) {
                    _state = "finish";
                    _dictionary->printAddress((City *)_current, address);
                    return;
                }
            }
        }/*
        for (auto &item:names) {
            std::cout << "Address => " << item << std::endl;
        }*/
        printPossibilities(names);
    }
}

bool Diviner::onlyOneValue()
{
    City *city = &_dictionary->getCities()->front();
    std::list<Address> *addresses = city->getAddresses();
    if (addresses->size() == 1) {
        _dictionary->printAddress(city, addresses->front());
        return true;
    }
    _current = city;
    _state = "street";
    Checker();
    return false;
}

void Diviner::Launcher()
{
    std::string buffer;
    if (_dictionary->getCities()->size() == 1) {
        if (onlyOneValue())
            return;
    } else {
        //TODO: Faire une condition pour les premières lettres qui matchent
        Checker();
    }
    while (!std::cin.eof()) {
        std::getline(std::cin, buffer);
        if (buffer == "ABORT")
            break;
        if (buffer.length() > 1 || buffer.empty()) {
            throw std::runtime_error("Unknown address");
        } else {
            _query.append(boost::algorithm::to_lower_copy(buffer));
            if (_state == "choice")
                if (!answerChoice())
                    return;
            Checker();
            if (_state == "finish")
                return;
        }
    }
}

void Diviner::printChoices()
{
    auto it = _prob.begin();
    int max = 6;

    if (_prob.size() < 5)
        max = _prob.size() + 1;
    if (_query.empty())
        for (int i = 1; i < max; i++) {
            std::cout << "{" << it->first << "}";
            if (i + 1 < max)
                std::cout << " ";
            std::advance(it, 1);
        }
    std::cout << std::endl;
}

Diviner::~Diviner() = default;

Diviner::Diviner(Dictionary *dictionary)
{
    _dictionary = dictionary;
    _state = "city";
}
