//sword_3.h
//����
//Lanwood 2001-02-03

EQUIP_BEGIN(CIsword_3);

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
		{"������", "longdan jian", 150, "str", 5, 1000, 10000, 20,},
		{"���潣", "lieyan jian", 150, "str", 5, 1500, 12000, 25,},
		{"�����", "qingfen ren",  160, "dex", 5, 1800, 10000, 25,},
		{"����", "poyu jian", 170, "int", 6, 2000, 18000, 25,},
		{"�ɽ���", "ganjian jian", 180, "str", 8, 2200, 20000, 30,},
		{"Īа��", "moye jian", 200, "dex", 8, 2500, 20000, 30,},
		{"��ԯ��", "xuyuan jian", 220, "str", 10, 2800, 25000, 40,},
		{"�̹Ž�", "pangu jian", 250, "str", 10, 3000, 20000, 50,},
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
	set("apply/damage", jian[lvl].damage);	
	set("equip_lvl", jian[lvl].lvl);
	
	set("duration", 150);
/*
	if(jian[lvl].apply_value)
	{
		char str[40];
		set(snprintf(str, 40, "apply/%s", jian[lvl].apply), jian[lvl].apply_value);
	}

	if(lvl == 6) set("apply/dex", 5);
	if(lvl == 7) set("apply/dex", 5);
*/
};

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIW$w��$n���ϻ���һ���׹⣬��ɢ�����ˡ���$COM";
	}
	
	return 0;
}

EQUIP_END;