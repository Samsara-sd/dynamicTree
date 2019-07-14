#include "parameters.h"
#include <QtDebug>
NodeState::NodeState() throw()
{
}
NodeState::NodeState(const NodeState& src) : row_(src.get_row()), order(src.get_order()),num(src.get_num()),state(src.get_state())
{
}
NodeState::NodeState(NodeState&& src)
{
    row_ = (src.get_row());
    order = (src.get_order());
    num = (src.get_num());
    state = (src.get_state());
}

NodeState& NodeState::operator=(const NodeState& src)
{
	if( this != &src ) {
        row_ = (src.get_row());
        order = (src.get_order());
        num = (src.get_num());
        state = (src.get_state());
	}
	return *this;
}
NodeState& NodeState::operator=(NodeState&& src)
{
	if( this != &src ) {
        row_ = (src.get_row());
        order = (src.get_order());
        num = (src.get_num());
        state = (src.get_state());
	}
	return *this;
}

const int& NodeState::get_row() const throw()
{
    return row_;
}
void NodeState::set_row(const int str)
{
    row_ = str;
}
const int& NodeState::get_order() const throw()
{
    return order;
}
void NodeState::set_order(const int& str)
{
    order = str;
}
const int& NodeState::get_num() const throw()
{
    return num;
}
void NodeState::set_num(const int& str)
{
    num = str;
}
const int& NodeState::get_state() const throw()
{
    return state;
}
void NodeState::set_state(const int& str)
{
    state = str;
}
