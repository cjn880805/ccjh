//xblade.h ĞşÌúÖØ½£
//Lanwood 2001-02-07

EQUIP_BEGIN(CIxuantiesword);

//under, we will custom our item

virtual void create(int nFlag = 0)	
{
	set_name("ĞşÌúÖØ½£", "xuantie zhongjian");
	
	set("wield_position", WIELD_RIGHT_HAND);
	set("skill_type", "sword");			//set the skill applied
	set_weight(80000);

	set("unit", "°Ñ");
	set("value", 0l);
	set("material", "steel");
	set("apply/damage", 120);
	set("item_make",1);
};


EQUIP_END;
