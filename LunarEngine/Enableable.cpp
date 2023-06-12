#include "Enableable.h"

bool Enableable::getEnabledState() const
{
    return _isEnabled;
} 

void Enableable::setActive(bool active)
{
    _isEnabled = active;
}
