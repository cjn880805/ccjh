//yapu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yapu);

virtual void create()
{
	set_name("哑仆","yapu");
	
	set("icon", young_man2);
	set("age", 18);
	set("gender", "男性");
	set("long","这是一个桃花岛的哑仆。他们全是十恶不赦的混蛋，黄老怪刺哑他们，充为下御。");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", 1);
	
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 80);
	set_skill("force", 60);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 80);
	
	carry_object("cloth")->wear();
	
};

NPC_END;
