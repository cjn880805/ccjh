//shigu.h

//Sample for ITEM: ʬ��
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIshigu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ʬ��");	//set item name

	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(200);		//set item weight
  
	set("unit", "ֻ");
	set("value", 50);
	set("material", "wood");
	set("long", "����һ����ɭɭ��ʬ�ǡ�");
	set("wield_msg","$N������סһ��$n������¶����а��Ц�⡣");
	set("unwield_msg", "$N��$n������䣬��ɫ��ʱҲ�ָ���������");
//	init_hammer(100);
	set("apply/damage", 100);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp