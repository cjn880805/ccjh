//sword_1.h
//����

EQUIP_BEGIN(CIsword_1);

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
	} jian[8] = {
		{"��ľ��", "taomu jian", 15, "dex", 1,	150, 2000,},
		{"����", "chang jian", 18, "", 0,		200, 5000,},
		{"�ֽ�", "gang jian", 15, "", 0,			200, 5000,},
		{"˫�н�", "shuang jian", 15, "str", 2,	280, 8000,},
		{"��ľ��", "black sword", 18, "int", 1,	360, 10000,},
		{"�̽�", "duan jian", 20, "", 0,			120, 3000,},
		{"����", "tie jian", 30, "dex", -1,		200, 15000,},
		{"�۽�", "dun jian", 25, "con", 2,		250, 8000,},
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
	
	if(jian[lvl].apply_value)
	{
		char str[40];
		set(snprintf(str, 40, "apply/%s", jian[lvl].apply), jian[lvl].apply_value);
	}
};

EQUIP_END;