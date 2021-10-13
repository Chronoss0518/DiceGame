#pragma once

class Charactor;

class ControllerBase
{
public:

	inline void Init(Charactor* _user) { user = _user; }

	virtual ChStd::Bool Up() = 0;

	virtual ChStd::Bool Down() = 0;

	virtual ChStd::Bool Decision() = 0;

	virtual ChStd::Bool ThrowDice() = 0;

	virtual ChStd::Bool Cancel() = 0;

private:

	Charactor* user = nullptr;

};