//shenghuo_lingpro.h 增强圣火令

EQUIP_BEGIN(CIshenghuo_lingpro);


virtual void create(int nFlag = 0)		
{
	set_name("圣火令", "shenghuo ling");	

	set("wield_position", WIELD_RIGHT_HAND);		
 	set_weight(1000);		

	set("unit", "把");
 	set("long", "这是一柄两尺来长的黑牌，非金非铁。质地坚硬无比，似透明，令中隐隐似有火焰飞腾，实则是令质映光，颜色变幻。令上刻得有不少波斯文字。");
	set("value",  20000 );
	set("material", "steel");
	set("skill_type", "lingfa");
	set("wield_msg",  "$N“唰”的一声，从腰间抽出一片黑黝的铁牌握在手中。");
    set("unwield_msg",  "$N将圣火令插回腰间。" );
 	set("apply/damage", random(70)+80);	
	set("no_duo",1);
   
};
/*
virtual int do_look(CChar * me)
{
	say("这是一柄两尺来长的黑牌，非金非铁。质地坚硬无比，似透明，令中隐隐似有火焰飞腾，实则是令质映光，颜色变幻。令上刻得有不少波斯文字。", me);
	if(query("kill") && EQUALSTR(querystr("owner"),me->id(1)))
	{
		AddMenuItem("发布明教追杀令","$2zueisha $1 $2", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "zueisha") == 0)
		return do_zueisha(me, arg);
	return 0;
}

int do_zueisha(CChar *me,char * arg)
{
	char msg[255];
	if( !strlen(arg)) 
		return notify_fail("你想追杀谁呢？ ");

	if(query("kill"))
	{
		CChar * who = find_online(arg);
		if(! who)
			return notify_fail("只能对在线的玩家发布门派追杀令！");

		g_Channel.do_channel(me, NULL, "corps", 
			snprintf(msg, 255, "我宣布%s开始追杀%s(%s)！追杀%ld次！", env->name(), who->name(1), who->id(1), times));
	}

	return 1;
}
*/
EQUIP_END;




