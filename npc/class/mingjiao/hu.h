//hu.h
//lanwood
//2001-01-09

NPC_BEGIN(CNmingjiao_hu);

virtual void create()
{
	set_name("胡铁牛", "hu tieniu");
	set("long","他就是明教号称见死不救的胡铁牛，据说他精通医理，可以起死回生。但他从不医教外人士。");
	set("gender", "男性");
	set("title", "明教教众");
	set("nickname","蝶谷医仙");
	set("age", 50);
	set("class", "shaman");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("icon",young_man5);
	set_weight(50000000);
	
	set("max_hp", 4500);
	set("hp",  1500);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 60);
	set("combat_exp", 150000);
	set("score", 80000);
	
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed",180);
	set_skill("parry", 180);
	
	create_family("明教", 35, "弟子");
	
	carry_object("cloth")->wear();
	set_inquiry("疗伤",ask_me);
	set_inquiry("护教任务",ask_hujiao);
}

static char * ask_me(CNpc *who,CChar *me)
{
	char msg[80];
	if (DIFFERSTR(me->querystr("party/party_name"), "明教"))
		return "你不是我明尊座下弟子，我不可以为你疗伤。";
	if ( me->query("eff_hp") == me->query("max_hp"))
	{
		who->command(snprintf(msg,80,"? %ld",me->object_id() ));     
		who->say(" 你没有受任何伤啊？");
	}
	else
	{
		message_vision("胡铁牛喂$N服下一颗药丸,然后盘膝坐下，双掌贴着$N的背心。", me);
		who->remove_call_out(recover);
		who->call_out(recover,2,me->object_id() );
	}
	return "";
}

static char * ask_hujiao(CNpc *who,CChar *me)
{
	char msg[255];
	CContainer * r = load_room("明教烈火旗牌坊");
	CContainer * bot;
	if(me->query_temp("mj/胡青牛"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "明教") && r->query_temp("dan_count"))
		{
			tell_object(me, "胡青牛说道:这次护教你出力不少，救了不少教中的兄弟们！");
			tell_object(me, "我这里有刚研制出来的一种新药，有起死回生之效，送给你一颗吧！");
			bot = load_item("baomingdan");
			bot->move(me);
			r->add_temp("dan_count",-1);
		}
		else
		{
			tell_object(me, "胡青牛说道:这次护教你出力不少，救了不少教中的兄弟们，可惜我新研制出来的药已经全部送完了。。");
			int exp=(random(30)+40)*me->query("level");
			me->add("combat_exp", exp);
			tell_object(me, snprintf(msg, 255, "$HIY胡青牛传授了你%ld点的实战经验！", exp));
		}
		me->delete_temp("mj/胡青牛");
	}
	else
		tell_object(me, "胡青牛：什么？？");
	return "";
}

static void recover(CContainer *ob,LONG param1,LONG param2)
{
	CChar * me=(CChar *)(ob->environment())->Present(param1);
	if (!me) return;

	me->set("eff_hp",  me->query("max_hp"));
	me->FlushMyInfo();
	message_vision("大约过了一盅茶的时份，胡铁牛慢慢地站了起来。",me);
	message_vision("胡铁牛说道：你的伤势已经全好了,可以走啦。", me);
	return ;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	CContainer * env = load_room("pk");
	if((strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0 )&& env->query("mj/start") && userp(me))
	{
		message_vision("$n横眉怒视$N，恨道：“在这大敌当前之际，你到底想做什么！！”", me, this);
		me->delete_temp("mf/exp");
		me->add("hp",-me->query("hp")/2);
		me->UpdateMe();
		me->start_busy(3);
		return 1;
	}
	return CNpc::handle_action(comm, me, arg);
}

void die()
{
	char msg[255];
	CContainer * env = load_room("pk");
	if(env->query("mj/start"))
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me && !env->query(snprintf(msg, 255,"mj/kill_%s",this->name(1))))
		{
			env->add(snprintf(msg, 255,"mj/kill_%s",this->name(1)),1);
			env->add("mj/count",1);
			g_Channel.do_channel(&g_Channel, 0, "chat", 
				snprintf(msg, 255, "$HIY%s$HIC新立奇功，斩获明教魔头$HIY%s$HIC！",me->name(1),this->name(1)));
		}
	}
	CNpc::die();
}
NPC_END;



