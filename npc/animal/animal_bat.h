//bat.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_bat);

virtual void create()
{
		set_name("蝙蝠","bat");

        set("race", "野兽");
        set("age", 8);
        set("long", "这是一只蝙蝠，正倒挂在洞顶。\n");

        set("str", 40);
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
