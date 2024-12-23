//jinshe_jian.h

//Sample for ITEM: 金蛇剑
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIjinshe_jian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "金蛇剑");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(10000);		//set item weight

	set("unit", "柄");
	set("long", "这剑金光灿烂，握在手中甚是沉重，看来竟是黄金混和了其他五金所铸，剑身上一道血痕，发出碧油油的暗光，极是诡异。剑的形状甚是奇特，整柄剑就如是一条蛇盘曲而成，蛇尾勾成剑柄，蛇头则是剑尖，蛇舌伸出分叉，是以剑尖竟有两叉。");
	set("value", 10000);
	set("material", "gold");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中，顿时全身凉飕飕地只感寒气逼人。");
	set("unwield_msg", "$N将手中的$n插回剑鞘。");
//	init_sword(150);
	set("apply/damage",150 );					//set the modifiers of attribute

};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp