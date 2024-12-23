//liuma.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_liuma);

virtual void create()
{
	set_name("æòÂí","liu ma");

	set("icon", tiger);

        set("long","Ò»Æ¥¿¥Âí¡£");
        set("race", "Ò°ÊÞ");
        set("age", 5);
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 30);
        set("int", 18);
        set("repute", 1);
        set("combat_exp", 1000);

		CVector v;

		v.append("knock");
		v.append("bite");
		v.append("hoof");
			
		set("verbs", v);
	
};



NPC_END;
