#include "StateManager.h"

StateManager::StateManager()
{
    //ctor
}

void StateManager::Update()
{
    if(current_state == NULL)
    {
        std::cout << "[WARN] State does not exsist!\n";
        return;
    }
    std::string ret = current_state->Update();
    if(ret != "")
    {
        SetCurrentState(ret);
    }
}

void StateManager::SetCurrentState(std::string name)
{
    if(states[name] != NULL)
    {
        current_state = states[name];
        current_state->Init(window);
        std::cout << "[state] Set current state to " << name << std::endl;
    }
    else
    {
        std::cout << "[WARN] State with name " << name << " does not exsist!\n";
    }
}

void StateManager::RegisterState(std::string name, State* state)
{
    if(states[name] == NULL)
    {
        states[name] = state;
        std::cout << "[state] Registered state " << name << std::endl;
    }
    else
    {
        std::cout << "[WARN] State with name " << name << " already exsists!\n";
    }
}

void StateManager::RegisterState(std::string name, State& state)
{
    if(states[name] == NULL)
    {
        states[name] = &state;
        std::cout << "[state] Registered state " << name << std::endl;
    }
    else
    {
        std::cout << "[WARN] State with name " << name << " already exsists!\n";
    }
}
