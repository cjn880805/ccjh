//axe.h

EQUIP_BEGIN(CIaxe);

//under, we will custom our item

virtual void create(int nFlag = 0)		
{
	set_name( "ɥ�Ÿ�");	
	
	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "axe");			
	set_weight(5000);		
	
	set("unit", "��");
	set("long", "����һ���������صĴ󸫡�");
	set("value", 1500);
	set("rigidity",100);
	set("material", "steel");
	set("wield_msg", "$N����һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n��������");
	set("apply/damage", 300);			
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp