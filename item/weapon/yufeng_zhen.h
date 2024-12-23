//yufeng_zhen.h

//Sample for ITEM: �����
//coded by cat
//data: 2001-4-2

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIyufeng_zhen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�����");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set("unit", "��");
	set("value", 0l);
	set("base_unit", "֧");
	set("base_weight", 300);
	set("base_value", 0l);
	set("material", "iron");
	set("long", "��������䶾���ɵİ�����");
	set("wield_msg", "$N������ó�һ���������������");
	set("unwield_msg","$N������ʣ�µ���������ɵر����½��ϡ�");
	set_amount(20);
	set("apply/damage", 50);					//set the modifiers of attribute
	
};

virtual const char * hit_ob(CChar *me, CChar *victim, LONG damage)
{
	if(me->query_skill("yunv_xinfa",1) < 30)
		return 0;
	victim->apply_condition("yufeng_poison", 10);
	return 0;
}

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp