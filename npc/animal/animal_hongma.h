//hongma.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_hongma);

virtual void create()
{
		set_name("����","hong ma");

		set("icon", tiger);

		set("animal", tiger);

        set("long","һƥ������ȫ����죬��һ����ë��\n");
        set("race", "Ұ��");
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