//monkey.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_monkey);

virtual void create()
{
	set_name("猴子","monkey");

    set("gender", "雄性");
    set("race", "野兽");
    set("age", 5);
    set("long", "这只猴子在在桃树间跳上跳下，还不时津津有味地啃几口着蜜桃。");
    set("combat_exp", 5000);
    set("shen_type", -1);
    set("attitude", "peaceful");

   	CVector v;

	v.append("knock");
	v.append("bite");
	v.append("claw");
	
	set("verbs", v);

    set("apply/attack", 10);
    set("apply/defense", 10);


    set_skill("unarmed", 25);
    set_skill("parry", 20);
    set_skill("dodge", 20);
};


NPC_END;
