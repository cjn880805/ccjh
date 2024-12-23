//pub_gu.c
//code by Fisho
//date : 2000-12-14


NPC_BEGIN(CNpub_gu);

virtual void create()
{
	set_name("������",  "gu yanwu"  );

	set("icon", old_man2);
	set("long", "����������Ϊ������һ����ѧ�ң��������īˮ�Ⱥ���Ҫ�");
	set("gender", "����");
	set("age", 65);
	
	set_skill("literate", 300);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	
	set("combat_exp", 400000);
	set("shen_type", 1);
	
	set("chat_chance", 3);
 	carry_object("cloth")->wear();
	set("no_huan",1);
}

virtual char *chat_msg()
{
	switch (random(4))
	{
	case 0:
		return "������˵��������֮�£�Ī������������֮����Ī��������";
	case 1:
		return "������˵���������ˣ�С�������ɣ����������δ������֮��";
	case 2:
		return "������˵������ѧ֮�����������¡���������ֹ�����ơ� ";
	case 3:
		return "������˵����������֪���������ģ�������ң��ι�ƽ���¡�";
	}
	return "";
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(DIFFERSTR(arg, "literate")) return 1;

	me->add_temp("mark/��", -1);
	if(! me->query_temp("mark/��"))
	{
		DownLoad(me);
		return 1;
	}

	return 0;
}

int recognize_apprentice(CChar *ob)
{
	if (! ob->query_temp("mark/��") )
		return 0; 
	return 1;
}

virtual int accept_object(CChar * who, CContainer *ob)
{
	if (EQUALSTR(ob->querystr("base_name"), "coin") && ob->query("value") >= 5000) 
	{
		message_vision("������ͬ��ָ��$NһЩ����ʶ�ֵ����⡣", who);
		who->add_temp("mark/��", ob->query("value") / 1000);
		DownLoad(who);
		destruct(ob);
		return 1;
	}

	return 0;
}
NPC_END;