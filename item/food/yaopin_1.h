//yaopin_1.h
//药品
//Lanwood 2001-02-03

YAOPIN_BEGIN(CIyaopin_1);

virtual void create(int nFlag = 0)
{
	static struct{
		char name[20], id[20];
		int hp, mp;				//恢复的hp, mp值
		LONG weight;			//重量
		LONG val;				//价值	
		int drink;				//是否喝的
	}yao[10] = {
		{"小笼包",	"xiaolong bao", 20, 0, 100, 40, 0,},
		{"茶叶蛋",   "chaye dan", 0, 20, 200, 60, 0,},
		{"糖葫芦",   "tang hulu", 40, 10, 200, 75, 0,},
		{"芝麻酥",   "zhima su", 50, 0, 500, 100, 0,},
		{"北京果脯",	 "beijing guopu", 50, 20, 2000, 150, 0,},
		{"杏仁露",	"xingren lu", 0, 50, 2000, 250, 1,},
		{"烤鹅",		"kao e", 75, 0, 5000, 300, 0,},
		{"茶汤",		"cha tang", 0, 75, 1000, 400, 1,},
		{"二锅头",	"er guo tou", 50, 50, 1000, 430, 1,},
		{"牛肉羹",	"niu rou geng", 100, 0, 1500, 450, 0,},
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
		set("eat_msg", "$N将$n一饮而尽。");
	}
	else
		set("eat_msg", "$N将$n吃掉了。");

	set("food_remaining", 1);

	set_amount(1);
};

YAOPIN_END;
//last, register the item into ../server/ItemSetup.cpp