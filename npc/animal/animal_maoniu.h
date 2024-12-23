//maoniu.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_maoniu);

virtual void create()
{
	set_name("牦牛","mao niu");

	set("race", "野兽");
	set("age", 5);
    set("long", "一只身强体壮的牦牛，全身长着长毛，似乎在觅食。\n");
	set("attitude", "peaceful");
    set("str",60);
    set("max_hp",2000);
    set("hp",1000);
    
	CVector v;

	v.append("knock");
	v.append("bite");
	v.append("hoof");
	
	set("verbs", v);

    set("combat_exp", 50000);

    set_temp("apply/attack", 200);
    set_temp("apply/defense", 500);
    set_temp("apply/damage", 20);
    set_temp("apply/armor", 100);
};


NPC_END;
