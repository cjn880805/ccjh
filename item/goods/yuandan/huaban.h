//huaban.h
EQUIP_BEGIN(CIhuaban)

virtual void create(int nFlag = 0)		
{
	set_name("花瓣", "hua ban");
	
    set("wield_position", WIELD_HEAD);	
	set_weight(8000);
	
	set("unit", "顶");
	set("value", 30000);
	set("material", "plant");

	set("long", "一片不知从何花上折下的花瓣，但觉浓香四溢，闻来神清气爽。");
	set("wear_msg", "$N带着笑，轻轻插上了一枚$n！");
	set("remove_msg", "$N含着泪，轻轻摘下了$n！");

	set("apply/per",15);
	set("apply/armor",15);

	call_out(do_die, 3600);	

};

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//检查系统时间
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;

	if(month!=1 ||day>13)
	{
		CContainer * env = load_room("jy");
		if(!env->query("活动"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);
}
EQUIP_END;
