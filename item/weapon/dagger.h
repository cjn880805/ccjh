//dagger.h

EQUIP_BEGIN(CIdagger);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("普通匕首", "dagger");
	set_weight(6000);
	set("wield_position", WIELD_HAND);
	
	set("unit", "把");
	set("skill_type", "dagger");			//set the skill applied
	set("long", "这是一把普通的小匕首。用来暗算别人比较合适。");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N从兜里掏出一把$n握在手中。");
	set("unwield_msg", "$N将手中的$n放会兜里。");
	
	set("apply/damage", 25);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp