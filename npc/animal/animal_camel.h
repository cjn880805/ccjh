//camel.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_camel);

virtual void create()
{
		set_name("������","camel");

        set("long","һƥ�����ա�");
        set("race", "Ұ��");
        set("age", 5);
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 40);
        set("int", 10);
        set("repute", 1);
        set("combat_exp", 2000);

		CVector v;

		v.append("bite");
		v.append("hoof");
		set("verbs", v);
};


NPC_END;
