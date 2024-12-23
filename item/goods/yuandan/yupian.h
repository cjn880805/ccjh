//yupian.h
AUTOCOMBINE_BEGIN(CIyupian)

virtual void create(int nFlag = 0)		
{
	set_name("玉片", "yu pian");
	set("long",	"一块不知是什么玉做成了薄片，其色晶莹剔透。你可以用它来向八仙换取礼物！");
	set("unit", "片");
	set_weight(500);

	set_amount(1);
	
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

AUTOCOMBINE_END;




