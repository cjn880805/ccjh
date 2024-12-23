//cwbdao.h

//Sample for ITEM: ��������
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIcwbdao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��������");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "��");
	set("value", 0l);
	set("material", "iron");
	set("long", "���Ǵ�����ʹ�ù��ĵ���������м���С�֡�" );
	set("wield_msg","һ���׹⣬$n����$N���У�ֻ��������䣬����͸�ǣ�����������Ĵ����ս��");
	set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������");
	set("apply/damage", 500);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp