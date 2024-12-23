//snowwife.h
//任务NPC
//lanwood 2001-04-20

/*
	雪的任务：寻找999朵玫瑰花！
*/

NPC_BEGIN(CNwiz_snowwife);

void create()
{
	set_name("雪儿", "snow girl");
	set("long", "一个看上去很伤心的女孩子。");
	set("icon", young_woman2);
	
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
	
	set("combat_exp", 1500000);
	set("score", 1000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("hubo", 300);
	set_skill("literate", 100);
	set_skill("wudu_zhang", 100);
	set_skill("jiuyin_zhua", 100);
	set_skill("hengshan_sword", 200);
	set_skill("lingxu_bu", 200);
	set_skill("wudu_xinfa", 200);
	map_skill("force","wudu_xinfa");
	map_skill("dodge","lingxu_bu");
	map_skill("strike","wudu_zhang");
	map_skill("sword","hengshan_sword");
		
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}

int do_talk(CChar *me, char * ask)
{
	if(! me->querymap("coupler"))
	{
		say("你还没有所爱的人，又怎能体会伤心的痛苦？", me);
		SendMenu(me);
		return 1;
	}

	if(EQUALSTR(me->querystr("gender"), "男性"))
	{
	}
}

void relay_emote(CChar *me, string verb)
{
	if(DIFFERSTR(me->querystr("couple/gender"), "老公" ))
		return;

	if(verb == ":(" || verb == "cry")
		me->add_temp("pending/雪儿", 1);

	if(me->query_temp("pending/雪儿") == 5)
	{
		command(snprintf(msg, 255, "cry1 %ld", me->object_id()));
		//要任务
		say("为何见你伤心落泪，为何见你惘然若失。你的心很痛，是吧。先擦擦泪。", me);
		say("我理解你的苦。我也有丈夫。", me);
		say("从前，我们一起杀虎，一起练功。我们也曾度过美好的时光。", me);
		say("直到有一天，他不理解我的心意，毅然离开了我们扬州的家。");
		say("我无力筹办凝聚我们爱意的商铺，最终伤心的卖掉了它，开始我孤身行走江湖的旅程，去找他……", me);
		say("当我来到倒吊庵的时候，突然醒悟了什么。", me);
		say("从此，我看淡了人世间的情恨，再没人让我的心热起来。", me);
		AddMenuItem("安慰雪儿", "$0comfort $1", me);
		AddMenuItem("不听故事了", "", me);

		me->set_temp("pending/雪儿", 100);
		SendMenu(me);
		return;
	}

	if(verb == "comfort" && me->query_temp("pending/雪儿") == 100)
	{
		say("有一天他突然来到倒吊庵，求我回家。", me);
		say("然而，事情似已无可挽回……", me);
		AddMenuItem("你啊的一声", "$0ah", me);
		AddMenuItem("不听故事了", "", me);

		me->set_temp("pending/雪儿", 200);
		SendMenu(me);
		return;
	}

	if(verb == "ah" && me->query_temp("pending/雪儿") == 200)
	{
		say("他求了我三天三夜，最后，我对他说……", me);
		say("我想看春天的玫瑰……", me);
		say("我想看夏天的碧兰……", me);
		say("我想看秋天的百合……", me);
		say("我想看冬天的满天星……", me);
		say("你能给我吗？");
		
		AddMenuItem("你啊的一声", "$0ah", me);
		AddMenuItem("不听故事了", "", me);

		me->set_temp("pending/雪儿", 300);
		SendMenu(me);
		return;
	}

	if(verb == "ah" && me->query_temp("pending/雪儿") == 300)
	{
		say("他头也不回的走了。", me);
		say("一个月后，他来了，捧着一束鲜花。", me);
		say("我看到，18支玫瑰，18支碧兰，18支百合，和18支满天星！", me);
		say("我看到，他形容枯槁了许多，他头发蓬乱了许多，唯一不变的，是他亮闪闪的眼睛！", me);
		say("他说：回来吧，雪儿！", me);
		say("……", me);
		AddMenuItem("你叹了口气", "$0sigh", me);
		AddMenuItem("不听故事了", "", me);

		me->set_temp("pending/雪儿", 400);
		SendMenu(me);
		return;
	}

	if(verb == "sigh" && me->query_temp("")
}

NPC_END;
