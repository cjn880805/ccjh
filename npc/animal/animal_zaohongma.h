//zaohongma.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_zaohongma);

virtual void create()
{
	set_name("�����","zao hong ma");

	set("icon", tiger);

    set("long","һƥ����ȫ���죬��һ����ë����ҿ���������ȥָ���ĵط�(ride)��");
    set("race", "Ұ��");
    set("age", 5);
	set("ridable", 1);
	set("int", 30);
	set("hp", 300);
	set("max_hp", 900);
	
	set("combat_exp",50000);
	set("attitude", "peaceful");

//	set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
	CVector v;

	v.append("bite");
	v.append("hoof"); 
	set("verbs", v);

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);
};

NPC_END;
