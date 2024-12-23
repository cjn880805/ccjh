//hudie.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_hudie);

virtual void create()
{
		set_name("蝴蝶","hu die");

        set("race", "野兽");
        set("age", 8);
        set("long", "这是一只在花间翩翩飞舞的蝴蝶，似乎不怕人呢。");

        set("str", 20);
        set("dex", 50);

//        set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
//        set("verbs", ({ "bite", "poke" }) );
		CVector v;

		v.append("bite");
		v.append("poke");
		set("verbs", v);

        set_temp("apply/attack", 33);
        set_temp("apply/armor", 20);
	
};



NPC_END;
