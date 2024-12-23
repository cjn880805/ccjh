//xiaolouluo.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_xiaolouluo);

virtual void create()
{
	set_name("小喽罗","xiao louluo");
	
	set("icon", banditi);
	set("gender", "男性" );
	set("age", 18);
	set("long", "这是一个年纪不大的小喽罗，象是第一次出来做这无本生意。");
	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("combat_exp", 500);
	set("shen_type", -1);
	set("str", 25);
	set("dex", 20);
	set("con", 18);
	set("int", 15);
	set("attitude","aggressive");
	
	carry_object("cloth")->wear();
	add_money(100);
	
};

NPC_END;
