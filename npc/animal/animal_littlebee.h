//littlebee.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_littlebee);

virtual void create()
{
	set_name("小蜜蜂","little bee");

	set("race", "野兽");
	set("age", 2);
	set("long", "一只飞来飞去的小蜜蜂。\n");
	
	set("str", 30);
	set("dex", 40);

//	set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
//	set("verbs", ({ "bite", "poke" }) );

	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	
	CVector v;

	v.append("bite");
	v.append("poke");
		
	set("verbs", v);
};

NPC_END;
