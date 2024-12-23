NPC_BEGIN(CNPub_flowerg);

virtual void create()
{
	set_name("卖花姑娘","flowerg");
	
	set("icon", young_woman6);
	set("gender", "女性" );
	set("age", 18);
	set("long", "一个容貌清丽的小姑娘。");
	set("shen_type", 1);
	set("combat_exp", 5000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	set("max_hp", 300);
	set("mp", 100);
	set("max_mp", 100);
	set("score", 1000);
	
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
	carry_object("xiaoao")->wear();
	carry_object("wuming")->wear();
	carry_object("honghua")->wear();
	carry_object("duanchang")->wear();
	
	add_money(10);
	set("no_huan",1);
};

virtual char * greeting(CChar * me)
{
	char msg[255];
	return snprintf(msg, 255, "卖花姑娘说道：这位%s，买一朵花吧。", query_respect(me) );
}


int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query("wei/renwu1") && me->query_temp("wei/renwu5_10") && !me->query_temp("wei/renwu5_13"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("询问断肠花的问题","duanchuang",me);
			SendMenu(me);
			return 1;
		}
		else if(!strcmp(ask, "duanchuang") )
		{
			tell_object(me,"$HIC卖花姑娘向你摇了摇头！");
			tell_object(me,"卖花姑娘幽幽地叹了一口气：“我真的好孤独！有谁会在乎我这样一个小女人！”\n");
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}


virtual int accept_object(CChar * me, CContainer * ob)
{
	if(! ob->is_character() ) return 0;
	if(me->query("wei/renwu1") && me->query_temp("wei/renwu5_10") && !me->query_temp("wei/renwu5_13"))
	{
		if ( userp(ob) )
		{	
			say("卖花姑娘惊讶的叫了一声：这……我可不敢要啊。", me);
			SendMenu(me);
			return 0;
		}
		if ( DIFFERSTR(ob->querystr("gender"), "男性"))
		{	
			say("卖花姑娘惊讶的叫了一声：这……我可不敢要啊。", me);
			SendMenu(me);
			return 0;
		}
		if ( ob->query("age") <16 )
		{	
			say("卖花姑娘微微皱眉道：他……还没成熟呢。", me); 
			SendMenu(me);
			return 0;
		}
		if ( ob->query("age") >50 )
		{	 
			say("卖花姑娘唾了一口道：这种老骨头……我要他做什么！", me);
			SendMenu(me);
			return 0;
		}
		if ( ob->query("per") <22 )
		{	 
			say("卖花姑娘说道：这……也太难看了点……", me);
			SendMenu(me);
			return 0;
		}
		tell_object(me,"\n$HIC卖花姑娘呀地惊叹了一声！");
		tell_object(me,"$HIC卖花姑娘说道：好英俊的小伙子，他会喜欢我吗！");
		tell_object(me,"$HIC卖花姑娘向你表示由衷的感谢！");
		tell_object(me,"卖花姑娘交给你数量1的断肠花。");
		load_item("duanchang")->move(me);
		me->set_temp("wei/renwu5_13",1);//取得断肠花
		return 1;
	}
	return 0;
}

NPC_END;
