//yaopin_1.h
//ҩƷ
//Lanwood 2001-02-03

YAOPIN_BEGIN(CIyaopin_1);

virtual void create(int nFlag = 0)
{
	static struct{
		char name[20], id[20];
		int hp, mp;				//�ָ���hp, mpֵ
		LONG weight;			//����
		LONG val;				//��ֵ	
		int drink;				//�Ƿ�ȵ�
	}yao[10] = {
		{"С����",	"xiaolong bao", 20, 0, 100, 40, 0,},
		{"��Ҷ��",   "chaye dan", 0, 20, 200, 60, 0,},
		{"�Ǻ�«",   "tang hulu", 40, 10, 200, 75, 0,},
		{"֥����",   "zhima su", 50, 0, 500, 100, 0,},
		{"��������",	 "beijing guopu", 50, 20, 2000, 150, 0,},
		{"����¶",	"xingren lu", 0, 50, 2000, 250, 1,},
		{"����",		"kao e", 75, 0, 5000, 300, 0,},
		{"����",		"cha tang", 0, 75, 1000, 400, 1,},
		{"����ͷ",	"er guo tou", 50, 50, 1000, 430, 1,},
		{"ţ���",	"niu rou geng", 100, 0, 1500, 450, 0,},
	};

	int lvl = random(10);

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