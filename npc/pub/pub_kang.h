// pub_kang.c 康亲王

// code by Fisho
// date:2000-12-17
//inherit F_UNIQUE;

NPC_BEGIN(CNpub_kang);

virtual void create()
{
	set_name("康亲王","kang qinwang");

	set("icon", officer);
	set("gender", "男性");
	set("age", 42);
	set("str", 25);
	set("dex", 20);
	set("long", "只见他一身锦衣，笑容满面，任谁见了他都生不起气来。此人深谙为官之道，极善察言观色、溜须拍马，颇得皇帝欢心。");
	set("combat_exp", 50000);
	set("score", 5000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 25);
	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 500); 
	set("max_mp", 500);
	set("mp_factor", 50);
	
	set_inquiry("鳌拜", "鳌拜这厮横行霸道，我早就想除了他。");
	set_inquiry("玉骢马","你想要我就送与你吧，不过它可不一定会服你。");
	set_inquiry("魅力",ask_meili);
	set_inquiry("当官",ask_meili);
	
	carry_object("cloth")->wear();
	add_money(5000);
}

static char * ask_meili(CNpc *who,CChar *me)
{
	char msg[80];
	who->say(snprintf(msg, 80, "你现在的魅力值是 %ld" , me->query("per")), me);
	who->say("要想当官魅力不高可不行啊。", me);
	who->say("多跟达官显贵们交往，魅力自然会提高的。", me);
	who->SendMenu(me);

	return "";
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 1, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env = me->environment();
	CChar * who = (CChar *)env->Present(param1);
	CNpc * man;
	char msg[255];

	if(! who) return;

	if ( env != load_room("北京康亲王书房") )	//没有该场景
		return;

	if( who->query("per")<10)
	{
        message_vision("康亲王一见$N, 顿时勃然大怒，叫道：“来人啊！将这厮给我拿下！”", who);

        if( !env->present("shi") )
		{
			message_vision("登时门外冲进几个侍卫，挥刀向$N直扑过来。", who);
		//	man=load_item("/d/huanggon/npc/shiwei2");
			man=load_npc("pub_shiwei2");//侍卫
			man->move(env);
		//	man=load_item("/d/huanggon/npc/shiwei2");
			man=load_npc("pub_shiwei2");//侍卫
			man->move(env);
		//	man=load_item("/d/huanggon/npc/shiwei2");
			man=load_npc("pub_shiwei2");//侍卫
			man->move(env);
		}
		return;        
	}

	switch( random(5) )
	{
	case 0:
        message_vision(snprintf(msg,255,"$N刚一进门, 康亲王便抢着迎了出来，笑道：“这位%s ，请进请进。",query_respect(who) ), who);
		if(who->query("per")<30)
		{
			who->add("per",1);
			message_vision("$N的魅力值提高了！"  , who);
			tell_object(who, snprintf(msg,255,"你现在的魅力值是 %ld", who->query("per")) );
		}
		break;
	default:
		message_vision(snprintf(msg,255,"康亲王笑道：不知这位%s，光临寒舍有何贵干？",query_respect(who) ), who);
		break;
	}
}

NPC_END;