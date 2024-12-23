//cwbdao.h

//Sample for ITEM: 闯王宝刀
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIcwbdao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "闯王宝刀");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "柄");
	set("value", 0l);
	set("material", "iron");
	set("long", "这是闯王所使用过的刀，上面刻有几行小字。" );
	set("wield_msg","一道白光，$n已在$N手中，只觉青光四射，寒气透骨，不禁机伶伶的打个冷战。");
	set("unwield_msg", "$N将$n插回腰间，华光顿敛，天地间只闻龙鸣。");
	set("apply/damage", 500);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp