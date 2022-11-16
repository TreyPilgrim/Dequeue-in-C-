/*
 * Delcaration of the Node Class
 */
#pragma once
#include <string>
#include <memory>
using std::string;
class Node;
using ptr = std::shared_ptr<Node>;
class Node {

public:


    ptr next = std::make_shared<Node>();
    ptr prev = std::make_shared<Node>();

    string foodType;
    int foodSize {0};

    Node() : next{nullptr}, prev {nullptr} {}
    explicit Node(string &type) : next{nullptr}, prev {nullptr}, foodType {type} {}


};
