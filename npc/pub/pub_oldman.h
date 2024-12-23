NPC_BEGIN(CNPub_oldman);

virtual void create()
{
	set_name("摆夷老叟","oldman");
	
	set("icon", old_man1);
	set("gender", "男性" );
	set("age", 72);
	set("long","一个摆夷老叟大大咧咧地坐在竹篱板舍门口，甩着三四个巴掌大的棕吕树叶，瞧着道上来来往往的人们，倒也快活自在。");
	set_temp("apply/defense", 5);
	set("combat_exp", 700);
	set("shen_type", 1);
	set("per", 13);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("cloth")->wear();
	
};


NPC_END;
