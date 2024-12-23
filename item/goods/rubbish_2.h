//rubbish_2.h
//垃圾
//Teapot 2001-02-03

ITEM_BEGIN(CIrubbish_2);

virtual void create(int nFlag = 0)	
{
	static struct{
		char name[20];
		char id[20];
		LONG weight;			//重量
		int  exp;				//所给经验
	} jian[8] = {
		{"冷却的杭州小龙包", "xiaolong bao",12000,50,},
		{"打破的玻璃", "sui boli",13000,60,},
		{"作废的飞机票", "feijipiao",  8000,70,},
		{"烧焦的地瓜饼", "diguabing", 10000,100,},
		{"碎唐三彩", "sui sancai", 20000,120,},
		{"瓜子壳", "guazi ke", 5000,140,},
		{"断掉的一晚十个郎", "shici lan", 12200,150,},
		{"刻坏的CD", "kuai cd", 14200,200,},
	};

	int lvl = random(8);

	if(nFlag) lvl = nFlag - 1;

	set_name( jian[lvl].name, jian[lvl].id);
	set_weight(jian[lvl].weight);
	set("exp", jian[lvl].exp);
		
	set("unit", "个");
	set("no_give", "把垃圾送人？……亏你想的出来。");
	set("no_drop", "请不要乱扔垃圾！");
	set("no_get", "你又不是检破烂的……");
	set("value", 0l);
	
	set("material", "steel");
};

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	char szTarget[40];
	char szNum[20];

	if(strcmp(comm, "give") == 0)
	{
		if(! strlen(arg)) return 0;
	
		analyse_string(arg, szTarget, 40);
		analyse_string(szTarget, szNum, 20);

		CContainer * obj = (me->environment())->Present(atol(szTarget));
		if(!obj) return 0;

		if(obj->query("rubbish"))
		{
			char msg[255];
			int i;

			i = random(query("exp")) + 1;
			me->add("combat_exp",i);
			 
			message_vision(snprintf(msg, 255, "$n对着$N磕了个头道：多谢这位%s。", query_respect(me)), me, obj);
			message_vision(snprintf(msg, 255, "$N获得了%d经验！", i), me, obj);

			destruct(this);
			return 1;
		}

		return notify_fail("把垃圾送人？……亏你想的出来。");
	}

	return 0;
}

ITEM_END;