// hufei.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_hufei);

virtual void create()
{
	set_name("胡飞", "hu fei");
	set("gender", "男性");
	set("nickname", "雪山飞狐");
	set("age", 25);
	set("long", 
		"他就是胡大刀之子，因其武功高强神出鬼没。在江湖上人送外号「雪山飞狐」。他身穿一件白色长衫，腰间别着一把看起来很旧的刀。他满腮虬髯，根根如铁，一头浓发，却不结辫。");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("icon",young_man2);	
	
	set("chat_chance", 20);	
	set("chat_chance_combat", 90);
        	
	set("hp", 3000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);
	set("combat_exp", 890000);
	set("shen_type", 1);
	 
	set_skill("force", 210);             // 基本内功
	set_skill("hujia_daofa", 250);       // 胡家刀法	
	set_skill("blade", 220);             // 基本刀法
	set_skill("hunyuan_yiqi", 220);      // 混元一气功
	set_skill("dodge", 220);             // 基本躲闪
	set_skill("shaolin_shenfa", 220);    // 胡家身法
	set_skill("parry", 220);             // 基本招架
		
	map_skill("force", "hunyuan_yiqi");
	map_skill("blade", "hujia_daofa");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "hujia_daofa");
        set_temp("apply/attack", 220);
        set_temp("apply/defense", 220);
        set_temp("apply/armor", 220);
        set_temp("apply/damage", 320);

	set_inquiry("阎极", "阎基这个狗贼我非杀了他不可。");
	set_inquiry("胡三刀", "辽东大侠胡三刀是我爹。不过我从没见过他。");
	set_inquiry("苗天龙", "苗人凤虽和家父齐名，家父却死在他的剑下。");
	set_inquiry("苗小兰", "不知什么时候还能再见到若兰姑娘。");
	set_inquiry("小兰", "不知什么时候还能再见到若兰姑娘。");
	set_inquiry("小兰姑娘", "不知什么时候还能再见到若兰姑娘。");
	set_inquiry("郑灵素", "二妹是为我而死的。");
	set_inquiry("赵半水", "你见我赵三哥了? ");
	set_inquiry("燕紫衣", "算了，别提这伤心事了。");
//	set_inquiry("宝刀",ask_me);
	/*
	set("inquiry",([
		"刀谱":     (: ask_book :),
		"胡家刀谱": (: ask_book :),
	]));

	set("baodao_count",1);
	set("book_count",1);
*/
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}

virtual char * chat_msg()				//NPC自动聊天
{
	switch(random(3))
	{
	case 0:
		return 	"胡飞叹了口气道：“不知什么时候还能再见到小兰姑娘。";
	case 1:
		return 	"胡飞恨恨道：“苗天龙是我杀父仇人，我必报此仇！”";
	case 2:
		return 	"胡飞切齿恨道：“阎极老贼暗中下毒，我必手刃此獠！”";
	}	
	return 0;
}
virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(3))
	{
	case 0:
		perform_action("blade huanying", 1);
		break;
	case 1:
		perform_action("blade lian", 1);
		break;
	case 2:
		perform_action("blade lian", 1);
		break;
	}	
	return 0;
}

/*

int accept_object(object me, object ob)
{
	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if ( (string)ob->query("id") == "yan ji") 
	{
		write(HIC "\n胡斐说道：这位" + RANK_D->query_respect(me)+"，如此大恩大德，在下实不知何以为报。\n");
		write(HIC "\n胡斐大喜道：狗贼！想不到你也有今天！！手起刀落，将阎基剁为两段。\n"NOR);
                call_out("destroying", 1, this_object(), ob);
//		ob->die();
		me->set_temp("marks/hujiadaopu",1);
        }
	return 1;
}

string ask_book()
{
	object ob, me;
	
	me = this_player();
	if (!me->query_temp("marks/hujiadaopu",1)) return "你说什么? \n";
	if((int)(me->query("shen")<100000))
		return "刀谱落入宵小之手，难免是阎基第二。\n";

   	else 
	{
		if(query("book_count") > 0)
		{		
		write(HIC "胡斐说着转身从阎基尸身上搜出一本破旧书本，递了给你。\n");
	    		call_out("waiting",0,me,ob);
			add("book_count", -1);
    			ob = new ("/clone/book/blade_book");
    			ob->move(this_player());
			command("rumor "+me->query("name")+"拿到胡家刀谱啦。\n");
			return "这本刀谱被这狗贼霸占多时了，现在就赠与你吧。\n";
		}
		else return "你来晚了，现在刀谱已不在此处。\n";
	}

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

static char * ask_me(CNpc *who,CChar *me)
{
	CContainer * obj;
	if( me->query("repute") < 0)
	{
		who->call_out(do_kill,1,me->object_id());
		return "";
	}

	if( me->query("repute") < 100000 )
	    return "以你目前的作为是不能拿这把刀的。";

   	if(me->query("baodao_count") > 1)
	{		
    //	call_out(waiting,0,me,ob->object_id());
		me->add("baodao_count", -1);
    	obj = load_item ("cwbdao");//闯王宝刀
    	obj->move(me);
		return " 好吧，这把闯王宝刀就赠与你，希望你好好利用它。";
	}
	
	return "你来晚了, 现在这把刀已不在此处。";
}
*/
static void do_kill(CContainer *ob,LONG param1,LONG param2)
{
	CChar * npc = (CChar *)ob;
	CChar * me=(CChar *)(npc->environment())->Present(param1);
	if (!me) return;
 
    if ((me->environment())->query("no_fight"))
	    (me->environment())->set("no_fight", 0l);
 
    if (userp(me))
    {
        npc->say("你这恶贼竟敢打我宝刀的主意, 给我纳命来！");
		npc->kill_ob(me);
    }
}

NPC_END;