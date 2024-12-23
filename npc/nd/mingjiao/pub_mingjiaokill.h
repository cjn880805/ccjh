//pub_mingjiaokill.h 明教杀手
//秦波 2002、3、22

NPC_BEGIN(CNmingjiaokii);

void create()
{
	set_name("明教杀手", "MingJiao ShaShou");
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("icon", young_man3);

	set("time",1000);
	set("renwu",1);//任务开关
	call_out(do_renwu, 60);
};


static void do_renwu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	time_t t;	
	struct tm * newtime;
	time(&t);
	newtime = localtime(&t); 

	int day = newtime->tm_mday;
	
	if((day%10)!=8 && newtime->tm_hour != 16)//每月8、18、28日20点开始启动“围攻光明顶”的任务
	{
//		int passtime = newtime->tm_min * 60 + newtime->tm_sec;	//已经过去的秒
		me->remove_call_out(do_renwu);
		me->call_out(do_kill, 60);
		//	call_out(do_renew, 3600 - passtime);
	}
	else
		me->call_out(do_renwu, 3600);
}

static void do_kill(CContainer * ob, LONG param1, LONG param2)
{	
	CChar * me = (CChar *)ob;
	char msg[255];
	me->add("time",-1);
	if(me->query("time")==1)
	{
		me->set("time",10000);
		g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s想了想心里越来越发虚，倒记时的数字突然变成了%d秒。\n\n$COM",  me->name(1),me->query("time")));
	}
	else
		g_Channel.do_channel(&g_Channel, 0, "chat", snprintf(msg, 255, "$HIC%s开始在叫嚣着要围剿$HIY明教光明顶$HIC,倒记时开始，还剩%d秒。\n\n$COM",  me->name(1),me->query("time")));
	me->call_out(do_renwu, 1);
}

NPC_END;




