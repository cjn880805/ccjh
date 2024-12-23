// wei_fang.h 方瑜
// 秦波	2002、12、25

NPC_BEGIN(CNwei_fang);

virtual void create()
{
	set_name("方瑜", "fang yu" );
	set("gender", "女性");
	set("icon", young_woman3);
	set("long",  "她长的极美，其容色晶莹如玉，娇媚不可方物。");
	set("age", 20);
	set("per",31);

	set("str", 25);
	set("dex", 16);
	set("combat_exp", 80000);

	set_skill("unarmed", 170);
	set_skill("force", 170);
	set_skill("dodge", 170);
	set_skill("parry", 170);
	set_skill("sword", 170);

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	
	set("max_hp",15000);
	set("mp", 1400); 
	set("max_mp", 1400);
	set("mp_factor", 10);

	carry_object("changjian")->wield();

	call_out(do_die, 900);	
	set("no_kill",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(!querystr("owner")[0] && !query("ok"))
	{
		if(me->query_temp("wei/renwu6_1") && me->query_temp("wei/renwu6_10"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("询问关于小宝","xiaobao",me);
				if(!me->query_temp("wei/renwu6_4"))
				{
					if(me->query_temp("wei/renwu6_7"))
					{
						AddMenuItem("询问关于玉佩","yupei",me);
					}
					else
					{
						AddMenuItem("询问关于蒙面女子","mengmian",me);
						AddMenuItem("询问关于仇恨","chou",me);
					}
				}
				SendMenu(me);
			}
			else if(!strcmp(ask, "xiaobao") )
			{
				if(!me->query_temp("wei/renwu6_4") && !me->query_temp("wei/renwu6_8"))
				{
					me->set_temp("wei/renwu6_2",1);//方瑜不杀依恋不回家
					say("方瑜恨恨道：“杀不了依恋，我是不会回去的！”",me);	
					SendMenu(me);
				}
				else
				{
					me->set_temp("wei/renwu6_9",1);//方瑜答应回家
					tell_object(me,"\n$HIC方瑜道：“谢谢恩公帮我完成夙愿，我再无牵挂这就可以动身去找夫君了。”");	
					tell_object(me,"$HIC方瑜决定跟随你行动。\n");

					CChar * wei = load_npc("wei_fang");
					wei->move(load_room("杭州六和塔"));
					wei->set("owner",me->id(1));
					wei->set_leader(me);
					move(load_room("temp_fang"));
				}
			}
			else if(!strcmp(ask, "yupei") )
			{
				if(!me->query_temp("wei/renwu6_4") && me->query_temp("wei/renwu6_7") && !me->query_temp("wei/renwu6_8"))
				{
					CContainer * env = load_room("杭州六和塔");
					CContainer * wei1=env->present("zeng rou");
					if(wei1)
					{
						me->set_temp("wei/renwu6_8",1);//方瑜与依恋的恩怨了结
						tell_object(me,"\n$HIC方瑜满脸惊讶地看着曾雪颈间的玉佩。");	
						tell_object(me,"$HIC曾雪痛哭流涕地请求方瑜原谅。");
						tell_object(me,"$HIC曾雪向方瑜解释玉佩之事。");
						tell_object(me,"$HIC曾雪取下颈上挂着的玉佩交给了方瑜。");
						tell_object(me,"$HIC方瑜经过一番思考，终于原谅了曾雪。");
					}
					else
					{
						say("方瑜恨恨道：“依恋抢走了我的一块玉佩。此玉佩虽说不上价值连城，但毕竟是我家中祖传之物。”",me);		
						SendMenu(me);
					}
				}
			}
			else if(!strcmp(ask, "mengmian") )
			{
				say("方瑜恨恨道：“她就是依恋，我几经周折，总算打听到她躲在岳坟中。但不知为何始终找不到此地，只听说是在杭州青石大道6附近。”",me);			
				SendMenu(me);
			}
			else if(!strcmp(ask, "chou") )
			{
				say("方瑜恨恨道：“依恋抢走了我的一块玉佩。此玉佩虽说不上价值连城，但毕竟是我家中祖传之物。”",me);		
				SendMenu(me);
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->query("ok"))
		destruct(npc);
	else
		npc->call_out(do_die, 900);
}

NPC_END;