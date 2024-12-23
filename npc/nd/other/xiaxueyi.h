// xiaxueyi.h 夏雪宜
//by sound 2001-07-10

NPC_BEGIN(CNxiaxueyi);

virtual void create()
{
	set_name("冬雪宜", "xia xueyi");
	set("nickname", "金蛇郎君");
	set("gender", "男性");
	set("age", 40);
	set("long", 
		"夏雪宜性情古怪，为人阴狠，武功便正如其人般诡异难测。\n"
		"江湖上人人闻其名而为之色变，乃是出名的难缠人物。\n");

	set("attitude", "aggressive");		//设置NPC态度
	set("icon",young_man6);			//设置人物形象
	
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);			//设置自动聊天触发率
	set("chat_chance_combat", 50);		//设置NPC使用绝招的几率
	
	set_inquiry("何红药", "咳，那个妹妹有恩于我，但我不爱她。");
	set_inquiry("温仪", "你见到她了？她现在可好？");
	set_inquiry("温家五老", "我恨不得可以生吃他们的肉，喝他们的血，穿他们的皮！");
	set_inquiry("袁承志", "那是我的小兄弟，人长的够帅。");
	set_inquiry("金蛇秘籍", "你敢打我秘籍的主意，不想活了？");
	
	set("hp", 6000);
	set("max_hp", 6000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 400);
	
	set("combat_exp", 6000000);
	set("score", -500000);
	 
	set_skill("force", 250);			// 基本内功
	set_skill("wudu_shengong", 250);	// 五毒神功
	set_skill("unarmed", 250);			// 基本拳脚
	set_skill("sword", 250);			// 基本剑法
	set_skill("jinshe_zhang", 250);		// 金蛇游身掌
	set_skill("jinshe_jian", 250);		// 金蛇剑法
	set_skill("throwing", 250);			// 基本投掷
	set_skill("jinshe_zhui", 250);		// 金蛇锥法
	set_skill("dodge", 250);			// 基本躲闪
	set_skill("guimei_shenfa", 250);	// 鬼魅身法
	set_skill("parry", 250);			// 基本招架
	
	map_skill("force", "wudu_shengong");		//设置NPC当前内功为五毒神功
	map_skill("unarmed", "jinshe_zhang");		//设置NPC的基本拳脚装备金蛇游身掌
	map_skill("throwing", "jinshe_zhui");			//设置NPC的基本投掷装备金蛇锥法
	map_skill("dodge", "guimei_shenfa");		//设置NPC的基本轻工装备鬼魅身法
	map_skill("parry", "jinshe_jian");			//设置NPC的基本招架装备金蛇剑法

	carry_object("jinshe_jian")->wield();
	carry_object("jinshe_zhui")->wield();
}

virtual char * chat_msg()		//NPC自动聊天
{
	switch(random(2))
	{
	case 0:
		return 	"我要报仇，我一定要找温家那五个老家伙报仇。";
	case 1:
		return 	"温仪现在过的可好，我真的很想念他，我实在太想念她了。";
	}

	return 0;
}

virtual char * chat_msg_combat()	//NPC自动发绝招
{
	switch(random(4))
	{
	case 0:
		perform_action("sword suo", 1);			//金蛇剑法的绝招
		break;
	case 1:
		perform_action("unarmed fugu", 1);		//金蛇游身掌的绝招
		break;
	case 2:
		perform_action("throwing tuwu", 1);		//降龙掌的绝招
		break;
	case 3:
		perform_action("force recover", 0);		//自动吸气
		break;
	}

	return 0;
}

NPC_END;
