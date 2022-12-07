#pragma once

#include"../ControllerBase.h"


class CPUController :public ControllerBase
{
public:

	void Init(Charactor* _user)override;

	void Update()override;

protected:

	virtual void SelectTarget() = 0;

	virtual void SelectDice() = 0;

	inline void SetPushButtonMaxCount(unsigned char _maxCount) { pushButtonMaxCount = _maxCount; }

	ChStd::Bool PushButtonUpdate();

private:

	void(CPUController::* selectFunction[2])(void);

	void SelectTargetFunction();

	void SelectDiceFunction();

	void DefaultAction();

	unsigned char pushButtonCounter = 0;
	unsigned char pushButtonMaxCount = 0;

	ChStd::Bool updateFlg = false;

};

class LVNormalCPUController :public CPUController
{
	void SelectTarget()override;

	void SelectDice()override;


};