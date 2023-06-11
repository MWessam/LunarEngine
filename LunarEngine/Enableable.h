#pragma once
class Enableable
{
private:
	bool _isEnabled;
public:
	virtual ~Enableable() = default;
	bool getEnabledState() const;
	void setActive(bool active);
	virtual void onEnable() = 0;
	virtual void onDisable() = 0;
	virtual void init() = 0;
};

