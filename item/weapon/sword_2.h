//sword_2.h
//����
//Lanwood 2001-02-03

EQUIP_BEGIN(CIsword_2);

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
		int lvl;
	} jian[8] = {
		{"��Ѫ��", "bixue jian", 50, "str", 2, 500, 10000, 10,},
		{"�㳦��", "yuchang jian", 50, "str", 4, 650, 12000, 12,},
		{"��Ů��", "yunv jian",  60, "dex", 3, 680, 8000, 13,},
		{"���ӽ�", "junzi jian", 70, "int", 3, 750, 15000, 14,},
		{"��Ů��", "shunv jian", 80, "dex", 4, 750, 12000, 14,},
		{"������", "xuantie jian", 90, "str", 5, 800, 30000, 15,},
		{"��罣", "tie jian", 100, "str", 5, 850, 20000, 15,},
		{"������", "dragon sword", 120, "str", 5, 900, 18000, 15,},
	};

	int lvl = random(8);

	if(nFlag) lvl = nFlag - 1;

	set_name( jian[lvl].name, jian[lvl].id);
	set("index", lvl + 1);
	
	set("wield_position", WIELD_RIGHT_HAND);
	set("skill_type", "sword");
	set_weight(jian[lvl].weight);
		
	set("unit", "��");
	set("value", jian[lvl].val);
	set("material", "steel");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n��ؽ��ʡ�");
	set("apply/damage", jian[lvl].damage );	
	set("equip_lvl", jian[lvl].lvl);

	set("duration", 150);
/*
	if(jian[lvl].apply_value)
	{
		char str[40];
		set(snprintf(str, 40, "apply/%s", jian[lvl].apply), jian[lvl].apply_value);
	}

	if(lvl == 6) set("apply/dex", 3);
	if(lvl == 7) set("apply/dex", 4);
*/
};

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIR$w��$n���ϻ���һ����⣬��ɢ�����ˡ���$COM";
	}
	
	return 0;
}

EQUIP_END;