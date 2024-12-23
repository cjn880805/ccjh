//littlemonkey.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_littlemonkey);

virtual void create()
{
	set_name("小猴","little monkey");

	set("gender", "雄性");
	set("race", "野兽");
	set("age", 1);
	set("long", "这是一只调皮的小猴子，虽是畜牲，却喜欢模仿人样。");
	set("combat_exp", 500);
	set("shen_type", -1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
    set("attitude", "peaceful");

	CVector v;

	v.append("bite");
	v.append("claw");
	
	set("verbs", v);
};

NPC_END;
