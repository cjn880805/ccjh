// diyun.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_diyun);

virtual void create()
{
	set_name("狄雨", "di yun");
	set("gender", "男性");
	set("nickname", "连城剑");
	set("age", 25);
	set("long", 
		"他就是狄海的大弟子，因其武功高强神出鬼没。在江湖上人送外号「连城剑」。他看上去就像一个乡下的农民。");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 25);
	set("icon",young_man4);	
	
	set("chat_chance", 20);
	set("chat_chance_combat", 90);
	
	set("hp", 3000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);
	set("combat_exp", 890000);
	set("score", 20000);
	
	set_skill("force", 110);             // 基本内功
	set_skill("doomsword", 250);		 // 连城剑
	set_skill("sword", 220);             // 基本刀法
	set_skill("hunyuan_yiqi", 220);      // 混元一气功
	set_skill("dodge", 120);             // 基本躲闪
	set_skill("shaolin_shenfa", 220);    // 胡家身法
	set_skill("parry", 220);             // 基本招架
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("sword", "doomsword");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "hujia_daofa");
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/armor", 120);
	set_temp("apply/damage", 520);
	
	set_inquiry("万震河", "万震山这个狗贼我非杀了他不可。");
	/*
	set("inquiry",([
	"剑谱":     (: ask_book :),
	]));
	set("baodao_count",1);
	set("book_count",1);
	*/
	carry_object("gangjian")->wield();
	carry_object("cloth")->wear();
}

virtual char * chat_msg()				//NPC自动聊天
{
	switch(random(3))
	{
	case 0:
		return 	"狄雨叹了口气道：“不知什么时候还能再见到师妹。";
	case 1:
		return 	"狄雨恨恨道：“万震河是我杀师仇人，我必报此仇！”";
	case 2:
		return 	"狄雨切齿恨道：“万老贼暗下毒手，我必手刃此人！”";
	}	
	return 0;
}

virtual char * chat_msg_combat()			//NPC自动发绝招
{
	switch(random(2))
	{
	case 0:
		perform_action("sword zhuang", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}	
	return 0;
}
/*
void do_kill(object ob)
{
	object me, room1;       
	me = this_object();
//	room1 = environment(me);
 
//	if (room1->query("no_fight"))
//	    room1->set("no_fight", 0);
 
	if (interactive(ob))
	{
		command("say 你这恶贼竟敢打我剑谱的主意，给我纳命来！\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
 
}	

int accept_object(object me, object ob)
{
	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if ( (string)ob->query("id") == "wanzhenshan") 
	{
		write(HIC "\n狄云说道：这位" + RANK_D->query_respect(me)+"，如此大恩大德，在下实不知何以为报。\n");
		write(HIC "\n狄云大喜道：狗贼！想不到你也有今天！！手起刀落，将阎基剁为两段。\n"NOR);
                call_out("destroying", 1, this_object(), ob);
//		ob->die();
		me->set_temp("marks/lianchenpu",1);
        }
	return 1;
}

string ask_book()
{
	object ob, me;
	
	me = this_player();
	if (!me->query_temp("marks/lianchenpu",1)) return "你说什么? \n";
	if((int)(me->query("shen")<100000))
		return "剑谱落入宵小之手，难免是万震河第二。\n";

   	else 
	{
		if(query("book_count") > 0)
		{		
		write(HIC "狄云说着转身从万震河尸身上搜出一本破旧书本，递了给你。\n");
	    		call_out("waiting",0,me,ob);
			add("book_count", -1);
    			ob = new ("/clone/book/lian_book");
    			ob->move(this_player());
			command("rumor "+me->query("name")+"拿到连城剑谱啦。\n");
			return "这本连城剑谱被这狗贼霸占多时了，现在就赠与你吧。\n";
		}
		else return "你来晚了，现在连城剑谱已不在此处。\n";
	}

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
*/
NPC_END;