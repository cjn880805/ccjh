//liandao.h ��ң�����������

EQUIP_BEGIN(CIliandao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("����", "liao dao");
	
	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(7000);		//set item weight
	
	set("unit", "��");
	set("long", "����һ������ͨ��������");
	set("value", 1000);
	set("material", "steel");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n��ؿ�����");
	set("apply/damage", 5);					//set the modifiers of attribute
	
};

EQUIP_END;




