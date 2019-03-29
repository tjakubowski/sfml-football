#include "StateMachine.hpp"
#include <iostream>

namespace Football
{
	StateMachine::StateMachine() : _isRemoving(false), _isAdding(false), _isReplacing(false)
	{
	}

	void StateMachine::AddState( StateRef newState, bool isReplacing )
	{
		std::cout << "AddState" << std::endl;
		this->_isAdding = true;
		this->_isReplacing = isReplacing;

		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState()
	{
		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		if(this->_isRemoving && !this->_states.empty())
		{
			std::cout << "_isRemoving" << std::endl;
			this->_states.pop();

			if (!this->_states.empty())
				this->_states.top()->Resume();

			this->_isRemoving = false;
		}

		if(this->_isAdding)
		{
			std::cout << "_isAdding" << std::endl;
			if(!this->_states.empty())
			{
				if (this->_isReplacing)
					this->_states.pop();
				else
					this->_states.top()->Pause();
			}

			this->_states.push(std::move(this->_newState));
			this->_states.top()->init();
			this->_isAdding = false;
		}
	}

	StateRef& StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
}
