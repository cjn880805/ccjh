//yaopin_2.h
//药品
//Lanwood 2001-02-03

YAOPIN_BEGIN(CIyaopin_2);

virtual void create(int nFlag = 0)
{
	static struct{
		char name[20], id[20];
		int hp, mp;				//恢复的hp, mp值
		LONG weight;			//重量
		LONG val;				//价值	
		int drink;				//是否喝的
	}yao[11] = {
		{"归元丹",  "guiyuan dan",		100, 0,		1200, 360, 0,},
		{"回神膏",   "huishen gao",		150, 0,		1500, 360, 0,},
		{"补气丸",	 "buqi wan",		250, 0,		2000, 360, 0,},
		{"百花聚精膏", "baihua gao",		0, 100,		2000, 360, 0,},
		{"回血膏",		"huixue gao",	400, 0,		2000, 480, 0,},
		{"接骨散",	"jiegu san",		500, 0,	1000, 480, 0,},
		{"天仙玉露",	"tianxian yulu",	250, 250,	3000, 600, 1,},
		{"九转回神丹",   "jiuzhuan dan",	500, 100,	3500, 1200, 0,},
		{"天香续命膏", "tianxiang gao",	1000, 0,	1000, 1800, 0,},
		{"大还丹", "dahuan dan",			0, 250,		2500, 1800, 0,},
		{"宫廷秘方",	"gongting mifang",	1500, 0,	1000, 1800, 0,},
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
		set("eat_msg", "$N将$n一饮而尽。");
	}
	else
		set("eat_msg", "$N将$n吃掉了。");

	set("food_remaining", 1);

	set_amount(1);
};

YAOPIN_END;
//last, register the item into ../server/ItemSetup.cpp