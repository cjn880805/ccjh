//yufeng.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_yufeng);

virtual void create()
{
		set_name("玉蜂","yu feng");

        set("race", "野兽");
        set("age", 8);
        set("long", "这是一只玉色的蜜蜂，个头比普通蜜蜂大得多，翅膀上被人用尖针刺有字。");

        set("str", 40);
        set("dex", 50);

//        set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
//        set("verbs", ({ "bite", "poke" }) );

		CVector v;

		v.append("bite");
		v.append("poke"); 
		set("verbs", v);

        set_temp("apply/attack", 35);
        set_temp("apply/armor", 25);
};

NPC_END;
