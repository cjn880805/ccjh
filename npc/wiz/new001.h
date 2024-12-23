//new001.h
//接引使 新手辅导员
//Lanwood 2001-05-07

NPC_BEGIN(CNnew001);

void create()
{
	set_name("武妹妹", "wudang");
	set("long", "一个女孩子。");
	set("icon", young_woman1);
	
	set("gender", "女性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "fighter");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	
	set("max_hp", 3500);
	set("mp", 3500);
	set("max_mp", 3500);
	set("mp_factor", 1000);
	
	set("combat_exp", 800000);
	
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	
	set_skill("wudu_zhang", 100);
	set_skill("jiuyin_zhua", 100);
	set_skill("hengshan_sword", 100);
	set_skill("lingxu_bu", 100);
	set_skill("wudu_xinfa", 100);
	map_skill("force","wudu_xinfa");
	map_skill("dodge","lingxu_bu");
	map_skill("strike","wudu_zhang");
	map_skill("sword","hengshan_sword");
	create_family("旺财派", 5, "弟子");
	
	carry_object("changjian")->wield();	
	set("no_talk",1);
};

int do_talk(CChar * me, char * ask = NULL)
{
	char msg[255];
	
	//1，第一次问
	if(! strlen(ask))	
	{
		if(me->query("level") < 2)
		{
			say("你好，我是志愿者，有什么麻烦吗。希望我能为您提供帮助。",  me);
			
			AddMenuItem("谢谢你，那么，我该怎样开始呢。", "1", me);
			AddMenuItem("请先讲讲如何操作吧。", "2", me);
		}
		else
		{
			say("这位出色的人，你好，你愿意听听旺财的故事吗？", me);
			AddMenuItem("哦，我没兴趣。", "", me);
		}

		SendMenu(me);
		return 1;
	}

	string answer = ask;
			
	//2，下级选择
	if(answer == "1")	//背景介绍
	{
		say("这是一个以武侠为背景的世界。只要你肯努力，总有一天会赢得其他人的尊重的。", me);
		say("江湖里共有十几个门派，如果你愿意，我可以为您介绍每个门派的特点。", me);
		AddMenuItem("");
	}
	else if(answer == "2")
	{
	
	}
	else 
		return 0;

	SendMenu(me);
	return 1;	
}


NPC_END;
