//lengyue_baodao.h

//Sample for ITEM 冷月宝刀
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CILengYueBaoDao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "冷月宝刀");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(10000);		//set item weight

	set("unit", "把");
	set("long", "这是一把锋利的宝刀，刀柄上用金丝银丝镶着一钩眉毛月之形。");
	set("value", 100000);
	set("material", "steel");
	set("weapon/strength", 10);
	set("wield_msg",  "只见冷森森的一道青光激射而出。寒光闪烁不定,冷月宝刀已入$N的手里!" );
	set("unwield_msg",  "「唰」的一声，寒光已不见。冷月宝刀被$N收入鞘中。" );

	set("apply/damage", 1000);					//set the modifiers of attribute
 
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp