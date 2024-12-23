//yaopin_2.h
//ҩƷ
//Lanwood 2001-02-03

YAOPIN_BEGIN(CIyaopin_2);

virtual void create(int nFlag = 0)
{
	static struct{
		char name[20], id[20];
		int hp, mp;				//�ָ���hp, mpֵ
		LONG weight;			//����
		LONG val;				//��ֵ	
		int drink;				//�Ƿ�ȵ�
	}yao[11] = {
		{"��Ԫ��",  "guiyuan dan",		100, 0,		1200, 360, 0,},
		{"�����",   "huishen gao",		150, 0,		1500, 360, 0,},
		{"������",	 "buqi wan",		250, 0,		2000, 360, 0,},
		{"�ٻ��۾���", "baihua gao",		0, 100,		2000, 360, 0,},
		{"��Ѫ��",		"huixue gao",	400, 0,		2000, 480, 0,},
		{"�ӹ�ɢ",	"jiegu san",		500, 0,	1000, 480, 0,},
		{"������¶",	"tianxian yulu",	250, 250,	3000, 600, 1,},
		{"��ת����",   "jiuzhuan dan",	500, 100,	3500, 1200, 0,},
		{"����������", "tianxiang gao",	1000, 0,	1000, 1800, 0,},
		{"�󻹵�", "dahuan dan",			0, 250,		2500, 1800, 0,},
		{"��͢�ط�",	"gongting mifang",	1500, 0,	1000, 1800, 0,},
	};

	int lvl = random(11);

	if(nFlag) lvl = nFlag - 1;

	set("index", lvl + 1);

	set_name(yao[lvl].name, yao[lvl].id);

	set("hp_supply", yao[lvl].hp);
	set("mp_supply", yao[lvl].mp);

	set("base_value", yao[lvl].val);
	set("base_weight", yao[lvl].weight);
		
	if(yao[lvl].drink)
	{
		set("eat_msg", "$N��$nһ��������");
	}
	else
		set("eat_msg", "$N��$n�Ե��ˡ�");

	set("food_remaining", 1);

	set_amount(1);
};

YAOPIN_END;
//last, register the item into ../server/ItemSetup.cpp