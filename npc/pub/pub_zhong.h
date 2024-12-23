// pub_zhong.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_zhong);

virtual void create()
{
	set_name("钟谷主","zhong guzhu" );

	set("icon", young_man4);
	set("gender", "男性" );
	set("age", 52);
	set("str", 13);
	set("con", 13);
	set("dex", 13);
	set("per", 13);
	set("int", 13);
	set("long", "钟谷主张着好长的一张马脸，眼睛生的甚高，一个圆圆的大鼻子却和嘴巴挤在一块，以致眼睛与鼻子之间，留下了一大块一无所有的空白地，丑陋异常。");
	
	set("attitude", "friendly");
	set("max_mp", 500);
	set("mp", 500);
	set("force_factor", 20);
	set("combat_exp", 35000);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 90);
	set_skill("sword", 100);
	set_skill("force", 90);

	carry_object("qingpao")->wear();
	carry_object("bu_shoes")->wear();
}

void init(CChar * me)
{
 	CNpc::init(me);
	if( userp(me) && !is_fighting()) 
	{
        message_vision("钟谷主对$N说道：想要救木姑娘？你去死吧！",me);
		kill_ob(me);
	}
}

NPC_END;