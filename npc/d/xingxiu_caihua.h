// xingxiu_caihua.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxingxiu_caihua);

virtual void create()
{
	set_name("拈花子", "caihua zi" );
	set("gender", "男性" );
	set("title", "星宿淫贼");
	set("nickname", "赛伯光");
	set("age", 38);
	set("long", "拈花子是星宿派的一个小喽罗，武功虽不好，但生性淫邪，经常奸淫良家妇女，是官府通缉的犯人，故而星宿派名义上也不承认有这个弟子。 ");
	set("str", 25);
	set("dex", 30);
	set("con", 17);
	set("int", 15);
	set("shen_type", -1);
        set("icon",young_man4);
	
	set_skill("unarmed", 20);
	set_skill("force", 50);
	set_skill("dodge", 95);
	set_skill("zhaixinggong", 95);
	map_skill("dodge","zhaixinggong");
	
	set("combat_exp", 25000);
	
	set("max_hp", 900);
	set("mp", 500);
	set("max_mp", 500);
	
	create_family("星宿派", 5, "弟子");
	
	set("attitude", "peaceful");
	
	carry_object("pink_cloth")->wear();
	add_money( 1000);

	set_inquiry("name","我也记不清我姓甚名谁了，江湖朋友送我雅号拈花子。");
	set_inquiry("采花","那可是学问，我不能随便教。");
	set("no_huan",1);
}

virtual void init(CChar * me)
{
	CNpc::init(me);
	if(userp(me) && !is_fighting())
	{
		if ( EQUALSTR(me->querystr("family/family_name"), "星宿派") )
			say("我昨天从山下捉了个小妞来，水灵极了，就关在我的逍遥洞里，你要不要进去试试？");
		me->set_temp("marks/花",0l);
	}
}


virtual void attempt_apprentice(CChar * ob)
{
	say("想学我的采花神技？没门儿！", ob);
	SendMenu(ob);
	return;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if (DIFFERSTR(me->querystr("family/family_name"), "星宿派")) 
		say("少跟我套近乎。", me);
	else 
	{
		if (DIFFERSTR(ob->querystr("base_name"), "coin") ) 
		{
			if (EQUALSTR(me->querystr("gender"), "女性"))
			{
				say("拈花子轻轻的亲了你的脸颊一下。", me);
				say("想不到师姐也有这个爱好。", me);
			}
			else 
			{
				say("拈花子给你深深的鞠了一躬。",me);
                say("多谢师兄。", me);
            }

            say("对不起，那小妞昨天晚上被不知道哪个混蛋救走了，不过你可以进洞睡一觉。", me);
			me->set_temp("marks/花", 1);
		}
		else
		{
			say("钱我有的是，你还是给我点别的什么吧。", me);
		}
	}

	SendMenu(me);
	return 1;
}

NPC_END;