//arrow.h

//Sample for ITEM: ��β��
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
AUTOCOMBINE_BEGIN(CIarrow);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��β��");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set("unit", "��");
	set("value", 2000);
	set("base_unit", "֧");
	set("base_weight", 300);
	set("base_value", 1);
	set("material", "iron");
	set("long", "��β������������Ƶ����͡�");
	set("wield_msg", "$NѸ�ٵشӼ����г��һ����β�����������֣��ʹ�������");
	set("unwield_msg","$N������ʣ�µķ�β���Żؼ����С�");
	set_amount(80);
	set("apply/damage", 35);					//set the modifiers of attribute
	
};

AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



