#include <iostream>

using namespace std;

class State{

public:

inline int get_state();
inline void set_state(int state);

private:

int state_ = 0; // 0 es muerta, 1 es viva


};



int State::get_state()
{

return state_;

}

void State::set_state(int state)
{

state_ = state;

}
