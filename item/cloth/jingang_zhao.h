//jingang_zhao.h

//Sample for ITEM: 金刚罩
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIjingang_zhao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "金刚罩");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(2000);		//set item weight
	
	set("material", "cloth");
	set("unit", "件");
	set("value", 2000000);
	set("wear_msg",  "只听「哗」的一声，$N展开一件金光闪闪的袈裟披在身上。瞬时间日月为之失色，瑞气千条，祥云朵朵，一派庄严气象。" );
	set("remove_msg",  "$N将金刚罩从身上脱了下来，折叠成小小的一团。" );
	set("apply/armor", 1000);
	set("long", "这是一件金光闪闪的袈裟，通体用天山雪蚕丝织成，坚韧无比刀剑不能伤。此袈裟数百年前由达摩老祖携入中原，邪魔见之辟易，乃是佛家无上降魔法宝。");

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp