//heima.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_heima);

virtual void create()
{
		set_name("黑马","hei ma");

		set("icon", tiger);

		set("animal", tiger);

        set("long","一匹骏马，全身漆黑，无一根杂毛。\n");
        set("race", "野兽");
        set("age", 5);
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 30);
        set("int", 18);
        set("repute", 1);
        set("combat_exp", 1000);

		CVector v;

		v.append("bite");
		v.append("hoof");
		set("verbs", v);
	
};


NPC_END;
