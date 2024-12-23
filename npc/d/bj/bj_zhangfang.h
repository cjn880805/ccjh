//bj_zhangfang.h 帐房先生

NPC_BEGIN(CNbj_zhangfang);

virtual void create()
{
	set_name("帐房先生", "zhang fang");
	set("gender", "男性");
	set("age", 44);
	set("long","这位就是宰相府里的帐房先生。" );
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 30);
	set("int", 29);
	set("con", 29);
	set("dex", 29);
	set("icon",young_man1);
	set("no_talk",1);
	set("no_huan",1);
}

int do_talk(CChar * me, char * ask = NULL)
{	
	if(me->query("zhang/信任"))
	{
		AddMenuItem("打听宰相对自己的信任度", "$0pingju $1", me);
		me->set_temp("信任度",1);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(me->query_temp("信任度"))
	{
		if(strcmp(comm, "pingju") == 0 && me->query("zhang/信任"))
		{
			return pingju(me);
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

//查询自身的贸易评估
int pingju(CChar * me)
{
	if(me->query("zhang/信任"))
	{
		char msg[255];
		if(me->query_temp("xinren"))
		{
			say(snprintf(msg, 255,"宰相爷对你还是比较信任的，信任度现在可是%ld点呀！", me->query("zhang/信任")),me);
			me->delete_temp("xinren");
			me->delete_temp("信任度");
		}
		else
			say("宰相爷对你还是比较信任的，我只知道这么多。", me);
		SendMenu(me);
	}
	return 1;
}


int accept_object(CChar * me, CContainer * item)
{
	char msg[255];

	if(EQUALSTR(item->querystr("id"),"coin") && item->query("value") >=1000000 )
	{
		me->set_temp("xinren",1);
		tell_object(me,snprintf(msg, 255, "$HIW帐房先生收下了你%d的金币$COM",item->query("value")));
		destruct(item);
		return 1;
	}
	return 0;
}
NPC_END;



