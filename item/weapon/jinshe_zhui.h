//jinshe_zhui.h

//Sample for ITEM: 金蛇锥
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIjinshe_zhui);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "金蛇锥");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied

	set("long", "金蛇锥是黄金所铸，灿烂生光。长约二寸八分，打成昂首吐舌的蛇形，蛇舌尖端分成双叉，每一叉都是一个倒刺。");
	set("unit", "把");
	set("value", 0l);
	set("base_unit", "枚");
	set("base_weight", 10);
	set("base_value", 0l);
	set("damage", 50);
	set_amount(15);
//	init_throwing(50);
	set("apply/damage", 80);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp