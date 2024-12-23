//arrow.h

//Sample for ITEM: 凤尾箭
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIarrow1);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "凤尾箭");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set("unit", "束");
	set("value", 0l);
	set("base_unit", "支");
	set("base_weight", 300);
	set("base_value", 0l);
	set("material", "iron");
	set("long", "凤尾箭连珠箭发，势道凶猛。");
	set("wield_msg", "$N迅速地从箭袋中抽出一束凤尾箭，拉弦在手，就待发出！");
	set("unwield_msg","$N将手里剩下的凤尾箭放回箭袋中。");
	set_amount(20);
	set("apply/damage", 35);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp