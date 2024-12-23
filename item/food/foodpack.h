FOOD_BEGIN(CIfoodpack);

virtual void create(int nFlag = 0)
{
	set_name( "浆糊补充包");

	set("wield_position", WIELD_HEAD);	
 	set_weight(20000);

	set("unit", "包");
	set("long", "这是一包特制的浆糊补充包。在打开之前你看不到里面有什么。");
	set("value",30000);
};


virtual int do_use(CChar * me, CContainer * target)
{
	say("一包包装精美的浆糊补充包。", me);
	AddMenuItem("现在拆开。", "$0open $1", me);
	AddMenuItem("等下再说", "", me); 
	SendMenu(me);

    return 1; 
}

virtual int Can_Use()
{
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{

	if(strcmp(comm, "open") == 0)
		return do_open(me,arg);

	return CItem::handle_action(comm, me, arg);
}



int do_open(CChar * me, char * arg)
{
/*	static struct{
		char name[20], id[20];
		int hp, mp;				//恢复的hp, mp值
		LONG weight;			//重量
		LONG val;				//价值	
		int drink;				//是否喝的
	}yao[21] = {
		{"七叶一枝花",	"xiaolong bao", 20, 0, 100, 40, 0,},
		{"紫花景天",   "chaye dan", 0, 20, 200, 60, 0,},
		{"石南藤",   "tang hulu", 40, 10, 200, 75, 0,},
		{"翻天印",   "zhima su", 50, 0, 500, 100, 0,},
		{"九子连环草",	 "beijing guopu", 50, 20, 2000, 150, 0,},
		{"透",	"xingren lu", 0, 50, 2000, 250, 1,},
		{"烤鹅",		"kao e", 75, 0, 5000, 300, 0,},
		{"茶汤",		"cha tang", 0, 75, 1000, 400, 1,},
		{"二锅头",	"er guo tou", 50, 50, 1000, 430, 1,},
		{"牛肉羹",	"niu rou geng", 100, 0, 1500, 450, 0,},
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

	int lvl = random(21);

	set("index", lvl + 1);

	CContainer * 

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

	return 1;
*/
	message_vision("$N动作熟练的撕开了一包浆糊补充包。",me);
	CContainer * drug;
	drug=load_item("yaopin_1");
	drug->move(me);
	drug=load_item("yaopin_1");
	drug->move(me);
	drug=load_item("yaopin_1");
	drug->move(me);
	drug=load_item("yaopin_1");
	drug->move(me);
	drug=load_item("yaopin_2");
	drug->move(me);
	drug=load_item("yaopin_2");
	drug->move(me);
	drug=load_item("yaopin_4");
	drug->move(me);
	message_vision("$N将包里的东西取出来，认真看了一遍。",me);
	if (random(4))
		me->command("sigh");
	else
		me->command("ah");
	destruct(this);
	return 1;
	
}

FOOD_END;
