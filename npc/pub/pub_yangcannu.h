//yangcannu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yangcannu);

virtual void create()
{
	set_name("养蚕女","yangcannu");

	set("icon", young_woman10);
	set("gender", "女性" );
	set("age", 21);
	set("long", "一个年轻的摆夷村妇，养蚕纺丝为生。");
	set_temp("apply/defense", 5);
	set("combat_exp", 5000);
	set("shen_type", 1);
	set("per", 21);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	
	carry_object("bduanqun")->wear();
	
};



NPC_END;
