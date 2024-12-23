//dongfang.h
//code by zwb
//12-16
//inherit F_MASTER;

ZUSHI_BEGIN(CNry_dongfang);

virtual void create()
{

	set_name("东方爱莲","dong fang");

    set("nickname",  "天下无敌" );
    set("title", "日月神教教主");
    set("gender", "男性");
    set("shen_type", -1);
    set("age", 42);
    set("long","他就是日月神教教主。号称无人可敌，最近不知道为什么改名为「东方爱莲」。");
    set("attitude", "peaceful");
 	set("icon",old_man2);

    set("per", 21);
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("hp", 22000);
    set("max_hp", 22000);
    set("mp", 16500);
    set("max_mp", 16500);
    set("mp_factor", 400);

    set("combat_exp", 52500000);
    
    set_skill("force", 250);             // 基本内功
    set_skill("hand", 250);            // 基本指法
    set_skill("unarmed", 280);           // 基本拳脚
    set_skill("dodge", 250);             // 基本躲闪
    set_skill("parry", 250);             // 基本招架
    set_skill("sword", 400);             // 基本剑法
    set_skill("pixie_jian", 350);        // 辟邪剑法
    set_skill("changquan", 280);         // 太祖长拳
    set_skill("literate", 100);          // 读书识字
    set_skill("kuihua_xinfa", 250);      // 葵花心法

    map_skill("force", "kuihua_xinfa");
    map_skill("sword", "pixie_jian");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "pixie_jian");

    create_family("日月神教", 2, "教主");

    carry_object("xiuhua")->wield();
    carry_object("yan_dress")->wear();
	if (random(3)==0)
		carry_object("heiyugao");

	set("apply/armor", 380);
    set("apply/damage", 200);

	set("no_kill",1);
	set("no_缠字决",1);
	set_temp("apply/no_连字诀",1);
	set_temp("apply/no_千环套狗",1);
	set_temp("apply/no_相思无用",1);
	set_temp("apply/no_势合形离",1);
	
	set("bigboss",1);
}

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query_temp("ry/renwu4_1")  && !me->query_temp("ry/renwu4_2")) 
	{
		tell_object(me,"\n$HIR东方爱莲道：“没想到你竟然能闯过重重守卫，最终还是杀到这里来了，我只好先解决掉你再来绣完这「陪你去看流星雨」了。”");
		tell_object(me,"$HIR东方爱莲道：“可惜可惜，枉你一身好武功今天却要葬于我手。”\n");
		me->set_temp("ry/renwu4_2",1);//最后的决战：挑战东方爱莲
		set("owner",me->id(1));
		this->kill_ob(me);
	}
}


virtual void die()
{
	if(querystr("owner")[0])
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me)
		{
			if(me->query_temp("ry/renwu4_2")  && EQUALSTR(querystr("owner"), me->id(1)))
			{
				char msg[255];
				me->delete_temp("no_fei");
				me->add("xkd/ry",1);//完成日月任务：不可能完成的任务
				me->set("ry/jq",me->query("age"));//限制一岁只能做一次

				tell_object(me, "\n$HIC东方爱莲道：“啊、啊、啊，没想到，真是没想到。”");
				tell_object(me, "$HIC东方爱莲道：“若在多给我几天时间我就可以练完这本《葵花宝典》进阶版了，那时你终将不是我的对手……”\n");
				g_Channel.do_channel(&g_Channel, 0, "news", 
					snprintf(msg, 255, "$HIC%s弟子%s(%s)$HIY豪气冲天，独闯黑木崖大败$HIC日月神教教主$HIY东方爱莲。$COM",  me->querystr("family/family_name"),me->name(1),me->id(1)));

				int exp=int(me->query("age")*me->query("level")*0.87);
				if(exp<3000)
					exp=2000+random(3000);
				int repute=random(int(exp/2))+exp;
				if(me->query("repute")<0)
					repute=-repute;
				me->add("repute",repute);

				if(DIFFERSTR(me->querystr("family/family_name"), "日月神教"))
				{
					me->add("combat_exp",exp);
					g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, "$HIC%s获得$HIY%d$HIC点的任务经验奖励，同时获得了%d点的江湖声望。\n$COM",me->name(1), exp,repute));
					message_vision (snprintf(msg, 255, "$HIR$N获得了%d的任务经验奖励，同时获得了%d点的江湖声望。",exp,repute),me);
				}
				else
				{
					CContainer * bot = load_item("kuihua_pro");
					bot->set("owner",me->id(1));
					bot->set("time",24);
					bot->move(me);
					me->add("combat_exp",exp);
					message_vision (snprintf(msg, 255, "$HIR$N获得了%d的任务经验奖励，同时获得了%d点的江湖声望",exp,repute),me);
					g_Channel.do_channel(&g_Channel, 0, "new", snprintf(msg, 255, "$HIC%s获得$HIY%d$HIC点的任务经验奖励、一本$HIY《葵花宝典》进阶版$HIC，同时获得了%d点的江湖声望。\n$COM",  me->name(1),exp,repute));
					g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s(%s)获得了《葵花宝典》进阶版。", me->name(1),me->id(1)));
				}
			}
		}
	}
	CNpc::die();
}


ZUSHI_END;