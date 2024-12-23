#include "../server/Container.h"

#define SAVEOBJ_BEGIN(obj_name)	class obj_name : public CISaveObject	{	public:	obj_name(){};	virtual ~obj_name(){};
#define SAVEOBJ_END		};	

//标准可存盘物件
//Lanwood 2001-02-03

class CISaveObject : public CContainer
{
public:
	CISaveObject(){};
	virtual ~CISaveObject(){};

	virtual LONG Query(int nAttr)
	{
		if(nAttr == CAN_SAVE)
			return 1;
		return CContainer::Query(nAttr);
	}
};