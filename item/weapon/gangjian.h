EQUIP_BEGIN(CIGangJian);

virtual void create(int nFlag = 0)		
{
	set_name( "�ֽ�");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied

	set_weight(6000);		//set item weight

	set("unit", "��");
	set("long", "����һ�������Ƴɵĸֽ������ֽ��ڽ���֮��ǳ����С�");
	set("value", 400);
	set("material", "steel");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n��ؽ��ʡ�");

	set("apply/damage", 20);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp