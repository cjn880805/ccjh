
EQUIP_BEGIN(CIshezhang);

void create(int nFlag = 0)		
{
	set_name( "����");	

	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "staff");		
	set_weight(2000);	

	set("unit", "��");
	set("long", "����һ������, ��ͷһ��С��, ��������, ʮ�ֹ��졣");
	set("value", 300);
	set("material", "leather");
	set("wield_msg", "$N��ৡ���һ������һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n�ջر���");

	set("apply/damage", 35);				
};

EQUIP_END;
