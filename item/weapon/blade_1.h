//blade_1.h
//����
//Teapot 2001-02-03

EQUIP_BEGIN(CIblade_1);

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
		int lvl;				//װ���ȼ�
	} jian[8] = {
		{"�޳�", "wuchang dao", 40, "str", 2, 500, 10000, 20,},
		{"����", "huche dao", 50, "str", 4, 650, 12000, 30,},
		{"����һ����", "fuganyi wenzi",  70, "dex", 3, 680, 8000, 35,},
		{"��һ����", "jvyi wenzi", 70, "int", 3, 750, 15000, 40,},
		{"����", "changchuang dao", 70, "dex", 4, 750, 12000, 40,},
		{"����", "zhangguang dao", 80, "str", 5, 800, 30000, 43,},
		{"����", "zhengheng dao", 100, "str", 5, 850, 20000, 45,},
		{"����", "hanyu dao", 150, "str", 5, 900, 18000, 45,},
	};

	int lvl = random(8);

	if(nFlag) lvl = nFlag - 1;

	set_name(jian[lvl].name, jian[lvl].id);
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

	if(lvl == 6) set("apply/dex", 3);
	if(lvl == 7) set("apply/dex", 4);
*/
};

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIM$w��$n���ϻ���һ���Ϲ⣬��ɢ�����ˡ���$COM";
	}
	
	return 0;
}

EQUIP_END;