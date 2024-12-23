NPC_BEGIN(CNPub_ya);

virtual void create()
{
	set_name( "牙将");

	set("icon", guarder);
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "这是一个大宋将领，满脸征尘。");
	set("combat_exp", 35000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("changquan", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("mp", 400); 
	set("max_mp", 400);
	set("mp_factor", 10);

	carry_object("changqiang")->Do_Action(DO_WIELD);
	carry_object("tiejia")->Do_Action(DO_WIELD);
	carry_object("toukui")->Do_Action(DO_WIELD);
};

NPC_END;
