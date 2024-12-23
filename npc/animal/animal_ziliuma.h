//ziliuma.h
//code by zwb
//12-16
//inherit F_UNIQUE;

NPC_BEGIN(CNAnimal_ziliuma);

virtual void create()
{
	set_name("������","ziliuma");

	set("icon", tiger);

	set("race", "Ұ��");
	set("gender", "����");
	set("age", 2+random(3));
	set("long", "����һƥ����������ǧ�ҹ�а˰١���ҿ���������ȥָ���ĵط�(ride)��");
	set("ridable", 1);
	set("int", 30);
	set("hp", 300);
	set("max_hp", 900);
	
	set("combat_exp",50000);
	set("attitude", "peaceful");

	CVector v;

	v.append("hoof");
	set("verbs", v);

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);
};


NPC_END;
