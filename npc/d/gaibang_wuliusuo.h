//wuliusuo.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNgaibang_wuliusuo);

virtual void create()
{
	set_name("吴六索","wu liu suo");

	set("title", "天地会洪顺堂香主");
	set("nickname", "血中铁丐");
	set("gender", "男性");
	set("age", 50);
	set("long","这个老叫化，便是天下闻名的“血中铁丐”吴六索，向来嫉恶如仇。他在官居广东提督之时，手握一省重兵，受了查良用的劝导，心存反清复明之志，暗入天地会，任职洪顺堂香主。");
 	set("icon",old_man1);

	set("attitude", "peaceful");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("hp", 1500);
	set("max_hp", 4500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	
	set("combat_exp", 150000);
	set("score", 30000);
	
	set_skill("force", 95);			// 基本内功
	set_skill("huntian_qigong", 90);	// 混天气功
	set_skill("unarmed", 90);		// 基本拳脚
	set_skill("xianglong_zhang", 85);	// 降龙十八掌
	set_skill("dodge", 90);			// 基本躲闪
	set_skill("xiaoyaoyou", 95);		// 逍遥游
	set_skill("parry", 85);			// 基本招架
	set_skill("begging", 50);		// 叫化绝活
//	set_skill("checking", 50);		// 道听途说
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	set("chat_chance", 3);

	set_inquiry("陈远北","想见总舵主可不容易啊。");
	set_inquiry("天地会","只要是英雄好汉，都可以入我天地会");
	set_inquiry("入会","只要入了我天地会，可以向会中各位好手学武功。");
    set_inquiry("反清复明","去药铺和棺材店仔细瞧瞧吧！");
    set_inquiry("威望",ask_weiwang );

	carry_object("cloth")->wear();
};

virtual char * chat_msg(CChar * me)
{
	switch(random(5))
	{
	case 0:
		return "吴六索忽然放开喉咙唱起曲来：“走江边，满腔愤恨向谁言？。。。。";
	case 1:
		return "。。。。。。寒涛东卷，万事付空烟。精魂显大招，声逐海天远。";
	case 2:
		return "江湖威望很重要，威望高大有好处啊。";
	case 3:
		return "吴六索突然说道: 松柏二枝分左右，中节洪华结义亭";
	case 4:
		return "吴六索突然说道: 福德祠前来誓愿，反清复明我洪英。";
	}
	return "";
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{

	char msg[255];

	npc->say(snprintf(msg,255,"你的江湖威望是%ld",player->query("weiwang")),player);
	npc->say("吴六索说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息",player);
	npc->say("吴六奇又说：杀某些坏人或救某些好人可以提高江湖威望。",player);
	npc->SendMenu(player);

	return "";

}

virtual int recognize_apprentice(CChar * player)
{
	if(DIFFERSTR(player->querystr("party/party_name"), "天地会"))
		return 0;
	
	return 1;
}

NPC_END;