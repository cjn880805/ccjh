//littlemonkey.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_littlemonkey);

virtual void create()
{
	set_name("С��","little monkey");

	set("gender", "����");
	set("race", "Ұ��");
	set("age", 1);
	set("long", "����һֻ��Ƥ��С���ӣ�����������ȴϲ��ģ��������");
	set("combat_exp", 500);
	set("shen_type", -1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
    set("attitude", "peaceful");

	CVector v;

	v.append("bite");
	v.append("claw");
	
	set("verbs", v);
};

NPC_END;
