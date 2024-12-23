//blade_2.h
//����
//Lanwood 2001-02-03

EQUIP_BEGIN(CIblade_2);

virtual void create(int nFlag = 0)	
{
	static struct{
		char name[20];
		char id[20];
		int  damage;			//�˺���
		char apply[20];	   		//��������
		int	 apply_value;		//����ֵ
		LONG val;				//��ֵ
		LONG weight;			//����
		int  lvl;				//װ���ȼ�����
	} jian[8] = {
		{"����խ�е�", "long blade", 180, "str", 5, 1000, 10000, 48,},
		{"���µ�", "wang blade", 200, "str", 5, 1500, 12000, 50,},
		{"��ȱ���º�", "guyuehan",  220, "dex", 5, 2000, 10000, 55,},
		{"��������", "Moon Blade", 250, "int", 6, 2500, 18000, 60,},
		{"С¥һҹ������", "Spring blade", 280, "str", 8, 3000, 20000, 70,},
		{"һ��ʮ�ε�", "Tiger blade", 10, "str", 30, 0, 30000, 70,},
		{"��ѩ����ն", "Snow blade", 300, "int", 15, 3500, 2000, 90,},
		{"��絶", "Wind blade", 350, "str", 15, 4000, 50000, 100,},
	};

	int lvl = random(8);

	if(nFlag) lvl = nFlag - 1;

	set_name( jian[lvl].name, jian[lvl].id);
	set("index", lvl + 1);
	
	set("wield_position", WIELD_RIGHT_HAND);
	set("skill_type", "blade");
	set_weight(jian[lvl].weight);
		
	set("unit", "��");
	set("value", jian[lvl].val);
	set("material", "steel");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n��ص��ʡ�");
	set("apply/damage", jian[lvl].damage);	
	set("equip_lvl", jian[lvl].lvl);

	set("duration", 100);
	
	/*
	if(jian[lvl].apply_value)
	{
		char str[40];
		set(snprintf(str, 40, "apply/%s", jian[lvl].apply), jian[lvl].apply_value);
	}

	if(lvl == 5) set("apply/dex", 30);
	if(lvl == 6) set("apply/dex", 10);
	if(lvl == 6) set("apply/dodge", 10);
	if(lvl == 7) set("apply/int", 3);
	if(lvl == 7) set("apply/dex", 5);
*/
};

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIC$w��$n���ϻ���һ����⣬��ɢ�����ˡ���$COM";
	}
	
	return 0;
}

EQUIP_END;