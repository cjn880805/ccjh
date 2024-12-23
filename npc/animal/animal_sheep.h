//sheep.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_sheep);

virtual void create()
{
	set_name("野羊","sheep");

    set("gender", "雄性");
    set("race", "野兽");
    set("age", 2);
    set("long","这只野羊在低头吃草，见了人也不惊避。");
    set("combat_exp", 5000);
    set("shen_type", -1);
    set("attitude", "peaceful");

    set("water", 200);
    set("food", 200);

	CVector v;

	v.append("bite");
	v.append("knock"); 
	set("verbs", v);

    set("apply/attack", 10);
    set("apply/defense", 10);
};


NPC_END;
