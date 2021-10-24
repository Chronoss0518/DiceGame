#pragma once

class Charactor;

enum class ButtonFlgNames :unsigned char
{
	Up, Down, Decision, ThrowDice, Cancel
};

class ControllerBase
{
public:

	inline virtual void Init(Charactor* _user) { user = _user; }

	ChStd::Bool Up();

	ChStd::Bool Down();

	ChStd::Bool Decision();

	ChStd::Bool ThrowDice();

	ChStd::Bool Cancel();

	virtual void Update() = 0;

protected:

	void SetTrueUpFlg();

	void SetTrueDownFlg();

	void SetTrueDecisionFlg();

	void SetTrueThrowDiceFlg();

	void SetTrueCancelFlg();

	Charactor& GetUser();

private:

	ChCpp::BitBool flgs = ChCpp::BitBool(1);

	Charactor* user = nullptr;

};