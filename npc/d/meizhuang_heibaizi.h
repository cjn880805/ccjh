// meizhuang_heibaizi.c
//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNmeizhuang_heibaizi);

virtual void create()
{
	set_name("霜天晓角", "shuangtian xiaojiao");
	set("title", "梅庄二庄主");
	set("long","他就是梅庄四位庄主排行第二的霜天晓角。身穿一件干干净净的黑色长袍。他已年愈五旬，身材高大，双眼神光内敛, 一望便知是一位内家的高手。");
	set("gender", "男性");
	set("age", 52);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
 	set("icon",old_man2);
	
	set("max_hp", 2000);
	set("hp", 2000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 80);
	set("combat_exp", 1000000);
	set("repute", 15000);
	set("score", 60000);
	
	set_skill("force", 120);
	set_skill("wuzheng_xinfa", 120);
	set_skill("dodge", 100);
	set_skill("piaoyibu", 110);
	set_skill("parry", 120);
	set_skill("finger", 200);
	set_skill("xuantian_zhi", 140);
	set_skill("literate", 130);
	set_skill("xuantian_shengong", 140);
	map_skill("force", "wuzheng_xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "pogu_bifa");
	map_skill("finger", "xuantian_zhi");
	prepare_skill("finger", "xuantian_zhi");
	
	create_family("梅庄", 1, "庄主");
	
	carry_object("zhanyi")->wear();
	set("no_talk",1);
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if ( ob->query_skill("wuzheng_xinfa",1) < 90)
	{
		say("我是不轻易收徒的。", ob);
		say(snprintf(msg,255,"在我梅庄的内功上，%s是否还应该多下点功夫？",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}

	say("好吧，在下就收下你了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("ry/renwu1_2") ==2)
	{
		if(! strlen(ask))
		{
			AddMenuItem("询问关于前教主被关押的事","jiaozhu",me);
			AddMenuItem("就是白送的！希望你喜欢","song",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "jiaozhu") )
		{
			tell_object(me,"\n$HIR霜天晓角脸色顿时阴了下来，哼道：“看你来时鬼鬼祟祟的就知道没安好心，果然不出所料是来找那个老家伙的！废话少说，看招吧！”\n");
			((CUser *)this)->Ready_PK();
			((CUser *)me)->Ready_PK();
			me->kill_ob(this);	
			this->kill_ob(me);
			set("owner",me->object_id());
		}
		else if(!strcmp(ask, "song") )
		{
			say("霜天晓角笑说道：“不错不错！”",me);
			tell_object(me,"\n$HIC你完成了送票的任务，得到金钱50元的奖励。\n");
			me->delete_temp("ry");
			me->delete_temp("no_fei");
			CMoney::Pay_Player(me, 50);
			SendMenu(me);
		}
		return 1;
	}
	else if(! strlen(ask))
	{
		AddMenuItem("向霜天晓角请教关于东方爱莲的问题", "dongfang",me);	
		AddMenuItem("向霜天晓角请教关于任无月的问题", "ren",me);
		AddMenuItem("向霜天晓角请教关于梅花令的问题", "meihua",me);

		if(me->query_temp("xy/renwu1_62") && !me->query_temp("xy/renwu1_66"))
		{
			AddMenuItem("向霜天晓角打听范千岁的行踪","fang",me);
			if(me->query_temp("xy/renwu1_620") )
			{
				AddMenuItem("向霜天晓角借血棋衣","xue",me);
			}
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "dongfang") )
	{
		say( "东方教主文成武德，千秋万载，一桶浆糊。 ",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "ren") )
	{
		say( "……。 ",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "meihua") )
	{
		say( "梅花令乃我梅庄信物。 ",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "fang") )
	{
		if (me->query_temp("xy/renwu1_62") && !me->query_temp("xy/renwu1_620") && !me->query_temp("xy/renwu1_66"))
		{
			me->set_temp("xy/renwu1_620",1);//向霜天晓角打听范千岁的行踪
			say("霜天晓角气呼呼地说道：“他这家伙，得了刘仲甫对骊山仙姥的‘呕血谱’，也不给我看，还想借我的血棋衣去参考，我自然是不肯借给他，他就傻楞楞的走了，也不知道躲到哪个棋室里钻研去了！”",me);
		}
		else
			say("什么？",me);
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "xue") )
	{
		if (me->query_temp("xy/renwu1_620") && !me->query_temp("xy/renwu1_66"))
		{
			me->delete_temp("xy/renwu1_620");
			say("霜天晓角怒道：“你是什么人，这宝贝比我性命都重要，连我朋友都不会借的东西，我又如何能借给你这陌不相识的外人！”",me);
		}
		else
			say("什么？",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me, ask);
}

virtual int accept_object(CChar * me , CContainer * item)
{

	if (item->query("ry/menpiao") &&  EQUALSTR(item->querystr("owner1"), me->id(1)))
	{
		if (me->query_temp("ry/renwu1_1")) 
		{
			char msg[255];
			say(snprintf(msg,255,"霜天晓角看了看你递过来的「%s」，说道：咦！这个宝贝真的肯送给我吗？一定有什么企图，你就老实说吧！”",item->querystr("name")), me);
			me->set_temp("ry/renwu1_2",2);//送给二庄主门票
			SendMenu(me);
			destruct(item);
			return 1;
		}
	}
	return 0;
}

virtual void die()
{
	if(query("owner"))
	{
		CChar * killer;
		CChar * owner;
		if( (killer = (CChar *)find_object(query_temp("last_damage_from"), 1)) )
		{
			//检查owner
			owner = (CChar *)find_object(query_temp("fight/owner"), 1);
			if(owner && owner->query_temp("fight/will_nk") == object_id())
				killer = owner;
			
			CContainer * obj = load_item("baozi");
			obj->set_name("水下石室钥匙","yao si");
			obj->set("long","这是一枚钥匙。");
			obj->set("owner1",killer->id(1));
			obj->set("ry/yaosi",1);
			obj->move(environment());
		}
	}
	CNpc::die();
}
NPC_END;