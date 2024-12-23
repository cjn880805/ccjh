// baishu.h С����
// �ز�	2002��12��25

NPC_BEGIN(CNbaishu);

virtual void create()
{
	set_name("С����","bai shu");
	set("icon", 49);

	set("race", "Ұ��");
	set("age", 2);
	set("long", "����һֻ����ѩ�׵�С����");
	set("str", 20);
	set("cor", 20);
	
	CVector v;

	v.append("bite");
	set("verbs", v);

	set("combat_exp", 3000+random(5000));

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",15);
};

virtual int do_look(CChar * me)
{
	say("����һֻ����ѩ�׵�С����", me);
	SendMenu(me);
	return 1;
}

NPC_END;




