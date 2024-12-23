#if !defined(_DRUG_H)
#define _DRUG_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../server/Item.h"

#define DRUG_BEGIN(item_name)	class item_name : public CIdrug	{	public:	item_name(){};	virtual ~item_name(){};
#define DRUG_END		};	

ITEM_BEGIN(CIdrug);

virtual int Can_Use()
{
	return 1;
}

ITEM_END;

#endif 
