#pragma once

#include <string>

//parameters

class NodeState
{
public:
    NodeState() throw();
    NodeState(const NodeState& src);
    NodeState(NodeState&& src);

    NodeState& operator=(const NodeState& src);
    NodeState& operator=(NodeState&& src);

    const int& get_row() const throw();
    void set_row(const int str);
    const int& get_order() const throw();
    void set_order(const int& str);
    const int& get_num() const throw();
    void set_num(const int& str);
    const int& get_state() const throw();
    void set_state(const int& str);

//private:
    int row_;
    int order;
    int num;
    int state;

};
