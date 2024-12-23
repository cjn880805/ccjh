//lamb.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_lamb);

virtual void create()
{
		set_name("野黄羊","lamb");

        set("long","一只野黄羊，正低头认真地吃着草。");
        set("race", "野兽");
        set("age", 5);
        set("int", 30);
        set("ridable", "1");
        set("hp", 300);
        set("max_hp", 900);
        
        set("combat_exp",500);
        set("attitude", "peaceful");

//        set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
//        set("verbs", ({ "bite","hoof" }) );
		CVector v;

		v.append("bite");
		v.append("hoof");
		set("verbs", v);

        set_temp("apply/attack", 10);
        set_temp("apply/armor", 5);
        set_temp("apply/damage", 15);
	
};

NPC_END;
