//dog.h
//code by zwb
//12-16

NPC_BEGIN(CNAnimal_dog);

virtual void create()
{
	set_name("Ұ��","dog");
	set("icon", dog);

	set("animal", "dog");

	set("race", "Ұ��");
	set("age", 3);
	set("long", "һֻ�����������Ұ����");
	
	set("str", 32);
	set("dex", 36);

	CVector v;

	v.append("bite");
	v.append("claw");
	set("verbs", v);
		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
}

virtual int accept_object(CChar * player , CContainer * ob)
{
	if(EQUALSTR(ob->querystr("base_name"), "bone"))
	{
		message_vision("Ұ�����˵�����ӯ����",player);
		return 1;
	}
	return 0;
}


NPC_END;
