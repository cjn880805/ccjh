//littlebee.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_littlebee);

virtual void create()
{
	set_name("С�۷�","little bee");

	set("race", "Ұ��");
	set("age", 2);
	set("long", "һֻ������ȥ��С�۷䡣\n");
	
	set("str", 30);
	set("dex", 40);

//	set("limbs", ({ "ͷ��", "����", "���", "β��" }) );
//	set("verbs", ({ "bite", "poke" }) );

	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	
	CVector v;

	v.append("bite");
	v.append("poke");
		
	set("verbs", v);
};

NPC_END;
