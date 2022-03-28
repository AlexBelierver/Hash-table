#include "Element.h"

bool Element::operator==(const Element& el2) const
{
    if ((this->key == el2.key) && (this->value == el2.value))
        return true;
    return false;
}
