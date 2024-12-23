//dagger.h

EQUIP_BEGIN(CIdagger);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("��ͨذ��", "dagger");
	set_weight(6000);
	set("wield_position", WIELD_HAND);
	
	set("unit", "��");
	set("skill_type", "dagger");			//set the skill applied
	set("long", "����һ����ͨ��Сذ�ס�����������˱ȽϺ��ʡ�");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N�Ӷ����ͳ�һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n�Żᶵ�");
	
	set("apply/damage", 25);
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp