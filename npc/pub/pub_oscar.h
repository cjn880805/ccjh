NPC_BEGIN(CNPub_oscar);

virtual void create()
{
	set_name("庞华伟","oscar");

	set("icon", boy2);
	set("nickname", "乖孩子");
	set("gender", "男性");
	set("age", 20);
	set("long","他就是乖孩子。");

	carry_object("jinduan")->wear();

};


NPC_END;
