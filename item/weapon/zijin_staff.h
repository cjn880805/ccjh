//zijin_staff.h
//�Ͻ�������

EQUIP_BEGIN(CIzijin_staff);

void create(int nFlag = 0)		
{
	set_name( "�Ͻ�������");

	set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "staff");		
	set_weight(10000);	

	set("unit", "��");
	set("long", "���������ٻ�̩ɽ�������Ͻ������ȡ�");
	set("value", 15000);
	set("material", "gold");
	set("wield_msg", "$N����һ��$n���������С�");
	set("unwield_msg", "$N�������е�$n��");

	set("apply/damage", 50 + random(150) );	
	
	set("duration", 200);
};

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIG$w��$n���ϻ���һ�����̣���ɢ�����ˡ���$COM";
	}
	
	return 0;
}

EQUIP_END;
