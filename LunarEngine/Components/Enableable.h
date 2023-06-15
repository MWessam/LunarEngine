#pragma once
class Enableable	// Inherit from this class to have the ability to activate/deactivate ur objects.
{
private:
	bool _isEnabled;
public:
	virtual ~Enableable() = default;

	//Getters
	bool getEnabledState() const;

	//Setters
	void setActive(bool active);

	//Event driven methods
	virtual void onEnable() = 0;
	virtual void onDisable() = 0;
	virtual void init() = 0;
};

