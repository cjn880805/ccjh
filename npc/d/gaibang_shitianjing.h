//shitianjing.h
//code by zwb
//12-16
//inherit F_MASTER;
//inherit F_UNIQUE;

NPC_BEGIN(CNgaibang_shitianjing);

virtual void create()
{
		set_name("石天惊","shi po tian");

        set("title", "长乐帮帮主");
        set("gender", "男性");
        set("age", 20);
        set("long", "他大约二十多岁，穿着一身破烂的衣服，却也挡不住他一身的英气。");
	 	set("icon",young_man4);

        set("attitude", "peaceful");

        set("str", 25);
        set("int", 35);
        set("con", 25);
        set("dex", 25);

        set("hp", 2000);
        set("max_hp", 6000);
        set("mp", 2000);
        set("max_mp", 2000);
        set("mp_factor", 100);

        set("combat_exp", 1000000);
        set("score", 30000);

        set_skill("force", 100);                 // 基本内功
        set_skill("huntian_qigong", 150);        // 混天气功
        set_skill("unarmed", 100);               // 基本拳脚
        set_skill("xianglong_zhang", 150);       // 降龙十八掌
        set_skill("dodge", 100);                 // 基本躲闪
        set_skill("xiaoyaoyou", 150);            // 逍遥游
        set_skill("parry", 100);                 // 基本招架
        set_skill("begging", 50);               // 叫化绝活
//        set_skill("checking", 50);              // 道听途说

        map_skill("force", "huntian_qigong");
        map_skill("unarmed", "xianglong_zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong_zhang");
        set("chat_chance", 8);

        set_inquiry("腊八粥","你去问龙岛主，试试你的运气吧。");
        set_inquiry("石中坚","他是我的兄弟，他现在在摩天崖。");
        set_inquiry("阿绣", "呀！你见过她吗?她还好吧。");
        set_inquiry("玄冰碧火酒","嘻嘻！多在侠客岛转转吧。");
        set_inquiry("赏善罚恶令","你可以用它来要腊八粥。");
        set_inquiry("威望",ask_weiwang );

        carry_object("cloth")->wear();
		set("no_huan",1);
};

virtual char * chat_msg(CChar *player)
{
	switch(random(5))
	{
	case 0:
		return "我来侠客岛这么多天了，也不知道阿绣和婆婆现在怎么样了。";
	case 1:
		return "江湖威望很重要，威望高大有好处啊。";
	case 2:
		return "不行，我不放心阿绣，我要去看看她。";
	case 3:
		return "矣！我的体内怎么好象有一群蝌蚪在动呢。";
	case 4:
		return "你能给我玄冰碧火酒吗?";
	}
	return "";
}

static char * ask_weiwang(CNpc * npc , CChar * player)
{
	char msg[255];

	npc->say(snprintf(msg,255,"%s你现在的江湖威望是%ld。",player->name(),player->query("weiwang")),player);
	npc->say("石天惊说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息",player);
	npc->say("石天惊又说：杀某些坏人或救某些好人可以提高江湖威望。",player);
	npc->SendMenu(player);

	return "";

}

virtual int recognize_apprentice(CChar * me)
{
	if(DIFFERSTR(me->querystr("party/party_name"), "天地会")
		|| me->query("weiwang") < 50)
		return 0;
	
	return 1;
}

virtual int accept_object(CChar * player , CContainer * item)
{
	CContainer * obj;
	if(!player)
		return 0;
	if(!item)
		return 0;
	if(EQUALSTR(item->querystr("id"), "xuanbingbihuo jiu"))
	{
		destruct(item);
		message_vision("石天惊激动的说：这位大哥，我该怎么谢你呢。?",player);
		obj=load_item("xuantie");
		obj->move(player);
		return 1;
	}
	return 0;
}
NPC_END;
