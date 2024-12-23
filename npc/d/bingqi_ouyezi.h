//tianjianshi.h
//code by zwb
//12-16

NPC_BEGIN(CNBingQi_ouyezi);

virtual void create()
{
		set_name("欧冶子","ou ye zi");

        set("nickname", "赤心剑胆");
		set("gender", "男性" );
        set("age", 60);
        set("long", "他头上包着头巾，三缕长髯飘洒胸前，面目清瘦但红晕有光，二目炯炯有神，烁烁闪着竟似是凛凛的剑光，浑身似乎都包围在一股剑气之中。");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 30);
        set("shen_type", 0l);
		set("max_hp", 15000);
		set("mp_factor",50);
 	set("icon",old_man2);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("claw",200);
        set_skill("jiuyin_zhua",200);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("bibo_shengong",100);
        set_skill("luoying_shenjian",100);
        set_skill("parry",90);
        set_skill("anying_fuxiang",100);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",50);

		create_family("玄天派",1,"弟子");

        set("combat_exp", 250000);
		set("score",0l);
	
        map_skill("force","bibo_shengong");
		map_skill("parry","luoying_shenjian");
		map_skill("sword","luoying_shenjian");
		map_skill("claw","jiuyin_zhua");
		map_skill("dodge","anying_fuxiang");

	
		set("attitude", "peaceful");
        
		set_inquiry("铸剑" , "铸剑可是件十分艰苦的事，要消耗人的精气和内力，你有决心和毅力吗？");
		set_inquiry("原料" , "铸剑可用千年玄铁。。。你找到了我才能帮你铸剑。");
		set_inquiry("兵器" , do_weapon);
   
   
        set("chat_chance", 3);
        carry_object("cloth")->wear();
        carry_object("changjian")->wield();
		set("no_huan",1);
};

virtual char * chat_msg(CChar * me)
{
	switch(random(3))
	{
	case 0:
		return "欧冶子抚剑而歌：巨阙神兵兮，人铸就。盖世宝剑兮，配英雄！";
	case 1:
		return "欧冶子低头沉吟，似乎在思考什么。";
	case 2:
		return "欧冶子叹了一口气：神兵配英雄，可英雄。。。。。。";
	}
	return "";
}

virtual int accept_object(CChar * player,CContainer * ob)
{
	char msg[255];

	string name = ob->querystr("name");

	if( name ==	"菩提子"
		|| name == "叫化鸡"
		|| name == "手镯"
		|| name == "辟邪剑谱"
		|| name == "白虎堂令牌"
		)
	{
		if(DIFFERSTR(player->querystr_temp("condition"), ob->querystr("name")) )
		{
			say("我对你说过我要这样东西么？", player);
			SendMenu(player);
			return 2;
		}
		else 
		{
			player->delete_temp("condition");
			say("很好很好！那我就帮你这一次吧！", player);
			player->set_temp("condition_ok",1);
			do_weapon(this,player);
			SendMenu(player);
			return 2;
		}
	}

	if(player->query("weapon/make"))
	{
		say("您已经有一把自造的武器了，还来干什么？难到不可手么？", player);
		SendMenu(player);
		return 2;
	}

	name = ob->querystr("id");

	if(name=="shen mu")
	{
		player->set_temp("or",1);
		player->set_temp("get_orc",1);
	}
	else if(name=="jin mu")
	{
		player->set_temp("or",2);
		player->set_temp("get_orc",1);
	}
	else if(name=="han zhu")
	{
		player->set_temp("or",3);
		player->set_temp("get_orc",1);
	}
	else 
	{
		say("这是什么！这不能用来打造兵器！", player);
		SendMenu(player);
		return 2;
	}

	say(snprintf(msg, 255, "这位%s要造什么兵器？决定了告诉我。", query_respect(player)));
	AddMenuItem("剑", "sword", player);
	AddMenuItem("刀", "blade", player);
	AddMenuItem("棍", "club", player);
	AddMenuItem("杖", "staff", player);
	AddMenuItem("锤", "hammer", player);
	AddMenuItem("鞭", "whip", player);
	SendMenu(player);
	player->set_temp("mark/欧冶子", 1);
	return 2;
}

virtual int do_talk(CChar * me, char * ask = NULL)
{
	CChar * player;
	player=me;

	if(player->query_temp("mark/欧冶子"))
	{
		player->delete_temp("mark/欧冶子");
		if(! ask || ! strlen(ask)) return 0;
		return do_answer(player, ask);
	}

	return CNpc::do_talk(player, ask);
}

int do_answer(CChar * player, string arg)
{
	//CChar * player;
	//player=me;

	if(! player->query_temp("get_orc") )
	{
		say("你找到原料了吗？", player);
		SendMenu(player);
		return 0;
	}
	
	if(arg == "sword" )
	{
		player->add_temp("sword", 1);
		say("带着原料去找侍剑吧！", player);
	}
	else if(arg == "blade")
	{
		player->add_temp("blade",1);
		say("带着原料去找侍刀吧！", player);
	}
	else if(arg == "club")
	{
		player->add_temp("club",1);
		say("带着原料去找侍棍吧！", player);
	}
	else if(arg == "staff" )
	{
		player->add_temp("staff",1);
		say("带着原料去找侍杖吧！", player);
	}
	else if(arg == "hammer")
	{
		player->add_temp("hammer",1);
		say("带着原料去找侍锤吧！", player);
	}
	else if(arg == "whip")
	{
		player->add_temp("whip",1);
		say("带着原料去找侍鞭吧！", player);
	}
	else
	{
		return notify_fail("欧冶子仔细的说：此事不可儿戏，请慎重!!");
	}

	SendMenu(player);

	CContainer * w_or;
	switch ( player->query_temp("or") ) 
	{
	  case 1:
		w_or = load_item("/d/npc/m_weapon/tan/item/shenmu");
		w_or->move(player);
		message_vision("欧冶子给了$N一块千年神木。", player);
		break;
	  case 2:
		w_or = load_item("/d/npc/m_weapon/tan/item/jinmu");
		w_or->move(player);
		message_vision("欧冶子给了$N一块海底金母。", player);
		break;
	  case 3:
		w_or = load_item("/d/npc/m_weapon/tan/item/hanzhu");
		w_or->move(player);
		message_vision("欧冶子给了$N一块寒丝羽竹。", player);
		break;
	}

	return 1;
}

static char * do_weapon(CNpc * npc , CChar * this_player)
{
	char w_id;
	CContainer * weapon;
	char msg[255];

	w_id=this_player->query("weapon/id");

	if(!this_player->query("weapon/make"))
	{
		npc->say("你造过兵器吗？",this_player);
		return "";
	}

	if(this_player->Present(w_id))
	{
		npc->say("欧冶子脸色一沉：您的武器不就在你手边么？还来干什么！",this_player);
		npc->SendMenu(this_player);
		return "";
	}

	if(this_player->query_temp("condition"))
	{
		npc->say(snprintf(msg,255,"欧冶子脸色一沉：不是让你去拿%s了么？还没拿到就回来干嘛！",this_player->query_temp("condition")),this_player);
		npc->SendMenu(this_player);
		return "";
	}

	if(!this_player->query_temp("condition_ok"))
	{
		npc->say(snprintf(msg,255,"这位%s想要重新得到兵器？这不难。不过你得找到我要的东西。",query_respect(this_player)),this_player);

		switch(random(5))
		{
		case 0:
			npc->say("你拿到菩提子，再来吧！",this_player);
			this_player->set_temp("condition","菩提子");
			break;
		case 1:
			npc->say("给我叫化鸡，我就帮你！！",this_player);
			this_player->set_temp("condition","叫化鸡");
			break;
		case 2:
			npc->say("嗯...你就拿黑木崖白虎堂令牌来换吧！！",this_player);
			this_player->set_temp("condition","白虎堂令牌");
			break;
		case 3:
			npc->say("....我想看看有名的手镯！",this_player);
			this_player->set_temp("condition","手镯");
			break;
		case 4:
			npc->say("如果你能替我找到辟邪剑谱的话......",this_player);
			this_player->set_temp("condition","辟邪剑谱");
			break;
		}
		npc->SendMenu(this_player);
	}
	else
	{
		this_player->delete_temp("condition_ok");
		weapon=create_weapon(this_player);
		weapon->move(this_player);
	}

	return "";
}

static CContainer * create_weapon(CChar * this_player)
{
	CContainer * weapon;
	string mask;	//the varible that record the type of weapon
	mask = this_player->query("weapon/type");

	if(mask=="剑")
	{
		weapon = load_item("m_sword");
		return weapon;
	}
	else if(mask=="刀")
	{
		weapon = load_item("m_blade");
		return weapon;
	}
	else if(mask=="棍")
	{
		weapon =load_item("m_club");
		return weapon;
	}
	else if(mask=="杖")
	{
		weapon =load_item("m_staff");
		return weapon;
	}
	else if(mask=="锤")
	{
		weapon =load_item("m_hammer");
		return weapon;
	}
	else if(mask=="鞭")
	{
		weapon =load_item("m_whip");
		return weapon;
	}
	
	return NULL;
}

NPC_END;
