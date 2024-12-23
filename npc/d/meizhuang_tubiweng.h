// meizhuang_tubiweng.c
//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNmeizhuang_tubiweng);

virtual void create()
{
	set_name("叶君临", "ye junlin");
	set("title", "梅庄三庄主");
	set("long","他就是梅庄四位庄主排行第三的墨池翁。身穿一件干干净净的白色长袍。他已年愈五旬，身材矮小，顶上光光, 一看就知道是个极易动怒的人。");
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
	set_skill("dagger", 200);
	set_skill("shigu_bifa", 140);
	set_skill("literate", 130);
	
	map_skill("force", "wuzheng_xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "shigu_bifa");
	map_skill("dagger", "shigu_bifa");

	set_inquiry("东方爱莲","东方教主文成武德，千秋万载，一桶浆糊。");
	set_inquiry("任无月","……。");
	set_inquiry("梅花令","梅花令乃我梅庄信物。");
	
	create_family("梅庄", 1, "庄主");
	
	carry_object("panguanbi")->wield();
	set("no_huan",1);
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	if ( ob->query_skill("wuzheng_xinfa",1) < 60) 
	{
		say("我是不轻易收徒的。", ob);
		say(snprintf(msg,255,"在我梅庄的内功上，%s是否还应该多下点功夫？",query_respect(ob) ), ob);
		SendMenu(ob);
		return;
	}
	say("好吧，在下就收下你了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}


virtual int accept_object(CChar * me , CContainer * item)
{

	if (item->query("ry/menpiao") &&  EQUALSTR(item->querystr("owner1"), me->id(1)))
	{
		if (me->query_temp("ry/renwu1_1")) 
		{
			char msg[255];
			say(snprintf(msg,255,"叶君临看了看你递过来的「%s」，说道：咦！这个宝贝真的肯送给我吗？一定有什么企图，你就老实说吧！”",item->querystr("name")), me);
			me->set_temp("ry/renwu1_2",3);//送给三庄主门票
			SendMenu(me);
			destruct(item);
			return 1;
		}
	}
	return 0;
}


int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("ry/renwu1_2") ==3)
	{
		if(! strlen(ask))
		{
			AddMenuItem("询问关于前教主被关押的事","jiaozhu",me);
			AddMenuItem("就是白送的！希望你喜欢","song",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "jiaozhu") )
		{
			tell_object(me,"\n$HIR叶君临脸色顿时阴了下来，哼道：“看你来时鬼鬼祟祟的就知道没安好心，果然不出所料是来找那个老家伙的！废话少说，看招吧！”\n");
			((CUser *)this)->Ready_PK();
			((CUser *)me)->Ready_PK();
			me->kill_ob(this);	
			this->kill_ob(me);
			set("owner",me->object_id());
		}
		else if(!strcmp(ask, "song") )
		{
			say("叶君临笑说道：“不错不错！”",me);
			tell_object(me,"\n$HIC你完成了送票的任务，得到金钱50元的奖励。\n");
			me->delete_temp("ry");
			me->delete_temp("no_fei");
			CMoney::Pay_Player(me, 50);
			SendMenu(me);
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
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