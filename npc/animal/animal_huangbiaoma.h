//huangbiaoma.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_huangbiaoma);

virtual void create()
{
	set_name("������","huang biao ma");

	set("icon", tiger);

	

	set("race", "Ұ��");
	set("gender", "����");
	set("age", 2+random(3));
	set("long", "����һƥ��������ȫ���ƣ�û��һ˿��ë����ҿ���������ȥָ���ĵط�");
	set("ridable", 1);
	set("int", 30);
	set("hp", 300);
	set("max_hp", 900);
	
	set("combat_exp",50000);
	set("attitude", "peaceful");

//	set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
//	set("verbs", ({ "bite","hoof" }) );
	CVector v;

	v.append("bite");
	v.append("hoof");
	set("verbs", v);

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);
	
};



NPC_END;
