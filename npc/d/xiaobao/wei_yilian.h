// wei_yilian.h 依恋
// 秦波	2002、12、25

NPC_BEGIN(CNwei_yilian);

virtual void create()
{
	set_name("依恋", "yi lian" );
	set("gender", "女性");
	set("icon", young_woman3);
	set("long",  "她长的很美，但却双眉紧蹙，似乎有着无限的心事。");
	set("age", 22);
	set("per",34);

	set_weight(50000000);

    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("hp", 22000);
    set("max_hp", 22000);
    
    set("mp", 10000);
    set("max_mp", 10000);
    set("mp_factor", 120);

    set("combat_exp", 17000000);

	set_skill("force", 330);
    set_skill("dodge", 280);
    set_skill("parry", 280);
	set_skill("unarmed", 300);
    set_skill("jiuyang_shengong", 330);
	set_skill("lingfa", 300);
	set_skill("shenghuo_lingfa", 300);
	set_skill("qiankun_danuoyi", 300);
	set_skill("shenghuo_xinfa", 280);
	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 150);
	set_temp("apply/damage", 130);
	
	carry_object("shenghuo_ling")->wield();
	set("no_kill",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!querystr("owner")[0])
	{
		if(me->query_temp("wei/renwu8_12"))
		{
			if(me->query_temp("wei/renwu7_6"))
			{
				if(! strlen(ask))
				{
					AddMenuItem("询问关于身世","shengshi",me);
					if(me->query_temp("wei/renwu7_7") && !me->query_temp("wei/renwu6_4"))
					{
						AddMenuItem("询问关于曾雪","zeng",me);
					}
					if(me->query_temp("wei/renwu6_3"))
					{
						AddMenuItem("询问关于方瑜","fang",me);
					}
					SendMenu(me);
				}
				else if(!strcmp(ask, "shengshi") )
				{
					me->set_temp("wei/renwu7_7",1);//和依恋对话
					tell_object(me,"\n依恋长叹道：我的先祖曾是岳将军手下的大将，在岳将军被害后，为了不让宵小之徒骚扰此地，就一直守护着这里。");
					tell_object(me,"依恋长叹道：如今传到我这里，已是数百年！\n");
					if(me->query_temp("wei/renwu6_2"))
					{
						tell_object(me,"你对依恋顿生好感，不忍依方瑜之意再杀依恋。！\n");
						me->set_temp("wei/renwu6_3",1);//不忍依方瑜之意杀依恋
					}
				}
				else if(!strcmp(ask, "fang") )
				{
					tell_object(me,"\n依恋道：她的玉佩是我拿的，但我不想多解释什么。");
				}
				else if(!strcmp(ask, "zeng") )
				{
					me->set_temp("wei/renwu7_8",1);//依恋答应去看曾雪
					tell_object(me,"\n依恋似乎想起什么事情，微微一笑：这小丫头，好久没见了，倒也怪想她的。");
					tell_object(me,"$HIC依恋决定跟随你行动。\n");
					
					CChar * wei = load_npc("wei_yilian");
					wei->move(load_room("杭州岳坟"));
					wei->set("owner",me->id(1));
					wei->set_leader(me);
					move(load_room("temp_yl"));
				}
				return 1;
			}
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual void die()
{
	CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
	if(me)
	{
		if(me->query_temp("wei/renwu6_2"))
		{
			me->set_temp("wei/renwu6_4",1);//杀死依恋
		}
	}
	CNpc::die();
}

NPC_END;