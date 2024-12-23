// 红琴
// redqin 2001-04-04

EQUIP_BEGIN(CIredqin);

virtual void create(int nFlag = 0)
{
	set_name("「绝情」", "red qin");
	set_weight(1000);
    
	set("wield_position", WIELD_RIGHT_HAND);
	
	set("unit", "件");
	set("long", "一架精致的木琴。");
	set("value", 10000);
				
	set("apply/damage", 200);
	set("apply/per", 10);
	
	set("no_sell", 1);
	set("skill_type", "music");
	set("music_type", "qin");
	
	set("wield_msg", "$MAG$N轻轻叹气，挥袖处，落出一把$n$MAG，再抬眼，竟现点点泪光。");
	set("unwield_msg", "$MAG只听「铮」的一响，$n$MAG断了一弦，$N轻叹口气，指上留下一道殷殷血痕！");
//	call_out(do_die, 3600);	
}

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
		destruct(ob);
	else
		ob->call_out(do_die, 3600);
}

EQUIP_END;