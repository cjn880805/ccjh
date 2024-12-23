//chunjie_ts.h 唐诗三百首
//秦波 2002-03-26

EQUIP_BEGIN(CIchunjie_ts);

virtual void create(int nFlag = 0)	
{
	set_name( "唐诗三百首");	

    set("wield_position", WIELD_LEFT_HAND);		//set the position of wield
	set_weight(1000);		//set item weight
	
	set("unit", "本");
	set("long", "一本凝聚唐代众多诗人名家心血之作的诗集，经常阅读，会使你的文学修为得到提升！");
	set("value", 1);
	set("apply/int",10);

//	call_out(do_die, 100);	

};

virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"只见眼前金光一闪...好象是.....");

	destruct(this);
} 

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//检查系统时间
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;

	if(month>=2)
	{
		CContainer * env = load_room("jy");
		if(!env->query("活动"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);

}

EQUIP_END;



