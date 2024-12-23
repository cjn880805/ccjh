//bj_hunaliangjin.h	呼那两斤
//秦波 2003、6、5

NPC_BEGIN(CNbj_hunaliangjin);

void create()
{
	set_name("呼那两斤","hu na");
	set("long", "呼那两斤身长一丈，腰大十围，肌肉虬结，虎臂熊腰，手持六百斤双刃宣花战斧，本是边陲蛮族领袖，蛮族被官兵征讨时裸衣上阵杀人无算，日抢三关，夜夺八寨，一日间连下十六城，十八骑追得招讨大元帅饮恨自尽，并扬言不日杀上京城。海内震动，后被招安，编入王求仁配下。");
	set("title", "中路先锋官");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "peaceful");
	set("icon",general);
	set("per", 10);
	set("str", 41);
	set("int", 24);
	set("con", 38);
	set("dex", 32);
	set("no_kill",1);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

	set("combat_exp", 800000);
	set_skill("force", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("axe",250);
	set_skill("unarmed", 250);
	set_skill("celestrike", 250);
	set_skill("tiexue_steps",250);
	set_skill("xiaowuxiang", 250);
	set_skill("duanyun_fu", 250);
  
	map_skill("force", "xiaowuxiang");
    map_skill("dodge", "tiexue_steps");
    map_skill("unarmed", "celestrike");
	map_skill("parry", "celestrike");
	map_skill("axe", "duanyun_fu");

	set("apply/armor", 300);
    set("apply/damage", 200);
	carry_object("axe");
	set("no_talk",1);
	set("no_huan",1);
};

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("zhang/冯力强") && !me->query_temp("zhang/renwu6_1"))
	{
		if(me->query("level")<130)
		{
			char msg[255];
			say("只见呼那两斤糊里糊涂地咕哝道：“那厮，你是谁人的部下？不要在某家营里乱走。快去快去！走迟了小心军法处置。”", me);
			say("你见就这样轻易被放行通过，心不由泛起一阵疑虑。", me);
			me->set_temp("zhang/renwu6_1",1);
			CNpc * feng = load_npc("bj_fengziqiang");
			feng->set("owner",me->id(1));
			feng->move(load_room(snprintf(msg, 255,"关外后军营帐%d",random(4)+1)));
			SendMenu(me);
		}
		else
		{
			if(me->query("zhang/问题1")&& me->query("zhang/问题1")<3)
			{
				say("只见呼那两斤懒洋洋地打了个哈欠，对你说道：“想进去？可以，不过某家因为过于神勇无敌，没有对手，十分无聊，要是你能找个对手和我打打，那么……”", me);
				say("你冷笑道：“在下愿领教土司神功。”", me);
				say("呼那两斤斜着眼从上到下瞥了瞥你的身形，狂笑不已，“就你那身材，还不够某家塞牙缝的，哈哈哈……别人会笑我呼那两斤虐待儿童的，哈哈哈……不用多说，这是封战书。你帮我找个相当的对手，到时候我再放你进军营。”", me);
				if(!me->query_temp("zhang/renwu6_2"))
				{
					load_item("zhanshu")->move(me);
					me->set_temp("zhang/renwu6_2",1);
				}
				SendMenu(me);
			}
			else
			{
				tell_object(me,"\n$HIR呼那两斤伸出如铜柱般的巨手将你拦住，问道：“高手？奸细？”");
				tell_object(me,"你皮笑肉不笑的打了个哈哈，道：“原来是猛将兄，幸会、幸会，只是今天实在不幸，在下还有要事在身，再见、再见。”");
				tell_object(me,"呼那两斤狂笑道：“想走，难得有此对手，怎能放过你，只要你赢过我，这先锋军营就任你进出。”\n");
				set("owner",me->id(1));
				me->set_temp("zhang/renwu6_4",1);
				CFightRoom * obj;
				CContainer * env = environment();
				obj = (CFightRoom *)load_item("fight_room");		
				
				obj->set("room_locked", FIGHT_NO_JOIN);
				obj->set_name( "呼那两斤的战斗", "fight_room");		
				obj->move(env);
				me->move(obj);
				obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
				this->move(obj);
				obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
				obj->Begin_Fight(0);

				SendMenu(me);
			}
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!me->query_temp("zhang/renwu6_3") && me->query_temp("zhang/renwu6_1"))
		return 0;
	if(DIFFERSTR(ob->querystr("owner1"), me->id(1)))
		return 0;
	if(DIFFERSTR(ob->querystr("name"), "战书") )
		return 0;
	if(!ob->query("use") )
		return 0;

	char msg[255];
	tell_object(me, "$HIR\n呼那两斤满意的说道：“你要战，那便战--好、好、好，看来你帮我找了个好对手啊！某家也是守诺重信之人，你走吧。”\n");
	me->set_temp("zhang/renwu6_1",1);
	CNpc * feng = load_npc("bj_fengziqiang");
	feng->set("owner",me->id(1));
	feng->move(load_room(snprintf(msg, 255,"关外后军营帐%d",random(4)+1)));
	destruct(ob);
	return 1;
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me)
		{
			if(me->query_temp("zhang/renwu6_4")  && EQUALSTR(querystr("owner"), me->id(1)))
			{			
				char msg[255];
				tell_object(me, "呼那两斤满意的说道：“好功夫，虽然你是靠武功胜了我而不是靠力量，不过某家说话算数——儿郎们，让开。”");
				me->set_temp("zhang/renwu6_1",1);
				CNpc * feng = load_npc("bj_fengziqiang");
				feng->set("owner",me->id(1));
				feng->move(load_room(snprintf(msg, 255,"关外后军营帐%d",random(4)+1)));
				del("owner");
				set("hp",query("max_hp"));
				set("mp",query("max_mp"));
				set("eff_hp",query("max_hp"));
			}
		}
	}
	else
		CNpc::die();
}

NPC_END;




