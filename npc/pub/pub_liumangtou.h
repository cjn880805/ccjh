//liumangtou.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_liumangtou);

virtual void create()
{
	set_name("流氓头","liumangtou");

	set("icon", cateran);
	set("gender", "男性");
	set("age", 25);
	set("long", "他长得奸嘴猴腮的，一看就不像是个好人。");
	
	set("combat_exp", 7000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	carry_object("cloth")->wear();
	add_money(20);
};


int do_talk(CChar * me, char * ask = NULL)
{
	if(EQUALSTR(environment()->querystr("base_name"),"杭州青石大道6" ))
	{
		if((me->query_temp("wei/renwu7_6") && !me->query_temp("wei/renwu8_2"))
			||(me->query_temp("wei/renwu6_2") && !me->query_temp("wei/renwu8_2")))
		{
			if(! strlen(ask))
			{
				AddMenuItem("询问关于岳廊","yue",me);
			}
			else if(!strcmp(ask, "yue") )
			{
				say("流氓头嘴角一瘪，斜眼道：大爷不知道。",me);
				if(me->query_temp("wei/renwu8_1")>=3 )
				{
					say("一气之下，你飞起一脚，用力踢在流氓头身上，结果流氓头的身体就像稻草人一样，呼的一声飞出老远，砸在不远处的一个隆起的小土丘上。",me);
					say("小土丘碎成一块块的硬泥块，在硬泥块中，露出一个沾满泥尘的木桩子。",me);
					me->set_temp("wei/renwu8_2",1);//发现了秘密
				}
				else
				{
					me->add_temp("wei/renwu8_1",1);//和流氓头对话（要四次以上）
				}
			}
			SendMenu(me);
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}
NPC_END;
