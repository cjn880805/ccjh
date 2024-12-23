//pang.h
//Lanwood
//2001-03-11

NPC_BEGIN(CNshenlong_pang);

virtual void create()
{
	set_name("胖头陀", "pang toutuo");

	set("icon",young_man2);	
	set("title", "神龙教左护法");
	set("nickname", "辽东胖尊者");
	set("long", "这头陀身材奇高,而且瘦得出奇;脸上皮包骨头,双目深陷,当真便如僵尸一般." );
	set("gender", "男性");

	set("age", 44);
	set("str", 35);
	set("dex", 20);
	set("con", 30);

	set("max_hp", 12500);
    set("hp",6000);
	set("max_mp",1500);
    set("mp",1500);
	set("mp_factor", 80);
	set("combat_exp", 900000);
	set("score", 40000);
	set("shen_type", -1);

	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);

    set_skill("force", 150);
    set_skill("dodge", 150);
    set_skill("unarmed", 150);
    set_skill("strike", 130);
    set_skill("parry", 150);
    set_skill("staff", 130);
    set_skill("sword", 130);
	set_skill("literate", 120);
	
	set_skill("shenlong_xinfa", 130);
	set_skill("yixingbu", 130);
	set_skill("shenlong_bashi", 130);
	set_skill("huagu_mianzhang", 130);
	set_skill("shedao_qigong", 130);
	
	map_skill("force", "shenlong_xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("unarmed", "shenlong_bashi");
	map_skill("strike", "huagu_mianzhang");
	map_skill("parry", "shedao_qigong");
    map_skill("sword", "shedao_qigong");
	prepare_skill("strike", "huagu_mianzhang");
	prepare_skill("unarmed", "shenlong_bashi");

	create_family("神龙教",2,"弟子");

	set_inquiry("教主",  "教主脾气不好,要讨他欢心才好。");
	set_inquiry("口号", "万年不老!永享仙福!寿与天齐!文武仁圣!");       
	
	carry_object("cloth")->wear();
	add_money(1000);
}

virtual void attempt_apprentice(CChar * me)
{
	char msg[80];

	if (DIFFERSTR(me->querystr("party/party_name"), "神龙教")) 
	{
		say("你不是本教教众, 想来找死啊!", me);
		SendMenu(me);
		return;
	}

	if (me->query_skill("shenlong_xinfa",1) < 50 ) 
	{
		say ("你的本门内功心法太低了，还是努努力先提高一下吧!",me);
		SendMenu(me);
		return;
	}

	if(me->query_skill("shedao_qigong",1) < 50 ) 
	{
		say(" 你的本门奇功太低了，还是努努力先提高一下吧!",me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") > -10000  ) 
	{
		say("我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！", me);
		SendMenu(me);
		return;
	}

	say("很好，很好。");
	command(snprintf(msg, 80, "recruit %ld", me->object_id()));
}

SHENLONG_END;