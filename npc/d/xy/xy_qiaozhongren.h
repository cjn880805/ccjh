//xy_qiaozhongren.h	敲钟人
//秦波 2003、4、3

NPC_BEGIN(CNxy_qiaozhongren);

void create()
{
	set_name("敲钟人","qiao zhong ren");
	set("gender", "男性");
	set("age", 27);

	set("attitude", "peaceful");
	set("icon",young_man2);

	set("shen_type", 1);
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("combat_exp", 100000);
	set("score", 20000);

	set("no_kill",1);

};

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("xy/renwu7_1") && !me->query("xy/renwu8") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("询问关于经幢7的问题","jingtong",me);
		}
		else if(!strcmp(ask, "jingtong") )
		{
			say("敲钟人露出蔑视的神色：“这7也能把你难住？7不就等于1+1+1+1+1+1+1嘛！”",me);
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;




