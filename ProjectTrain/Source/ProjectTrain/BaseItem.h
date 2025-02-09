// Made By: Roberto Valentino Reynoso (RvRproduct)

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class PROJECTTRAIN_API BaseItem
{
public:
	BaseItem();
	virtual ~BaseItem();

protected:
	virtual void activate() = 0;
};
